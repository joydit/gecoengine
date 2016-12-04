/*
 * Geco Gaming Company
 * All Rights Reserved.
 * Copyright (c)  2016 GECOEngine.
 *
 * GECOEngine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GECOEngine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "timestamp.h"
#include "../ultils/affinity.h"

#if defined(PLAYSTATION3)
static uint64 calc_stamps_pe_sec()
{
	return sys_time_get_timebase_frequency();
}
#elif defined(_WIN32)
#ifndef _XBOX360
#include <windows.h>
#endif // _XBOX360
#ifdef GECO_USE_RDTSC
uint64 g_busyIdleCounter = 0;  // global to avoid over-zealous optimiser
volatile static bool continueBusyIdle;
static DWORD WINAPI busy_ldle_thread(LPVOID arg)
{
	// Set this thread to run on the first cpu.
	// We want to throttle up only the cpu that the main thread runs on
	affinity_update();
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_LOWEST);
	while (continueBusyIdle) ++g_busyIdleCounter;
	return 0;
}
static uint64 calc_stamps_pe_sec()
{
	LARGE_INTEGER tvBefore, tvAfter;
	DWORD tvSleep = 500;
	uint64 stampBefore, stampAfter;

	// Set this thread to run on the first cpu.
	// Timestamps can be out of sync on separate cores/cpu's
	affinity_update();

	// start a low-priority busy idle thread to use 100% CPU on laptops
	continueBusyIdle = true;
	DWORD busyIdleThreadID = 0;
	HANDLE thread = CreateThread(NULL, 0, &busy_ldle_thread, NULL, 0, &busyIdleThreadID);
	Sleep(100);// a chance for CPU speed to adjust

	QueryPerformanceCounter(&tvBefore);
	QueryPerformanceCounter(&tvBefore);
	QueryPerformanceCounter(&tvBefore);
	stampBefore = gettimestamp();

	Sleep(tvSleep);

	QueryPerformanceCounter(&tvAfter);
	QueryPerformanceCounter(&tvAfter);
	QueryPerformanceCounter(&tvAfter);
	stampAfter = gettimestamp();

	uint64 countDelta = tvAfter.QuadPart - tvBefore.QuadPart;
	uint64 stampDelta = stampAfter - stampBefore;

	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	continueBusyIdle = false;
	CloseHandle(thread);
	return (uint64)((stampDelta * uint64(frequency.QuadPart)) / countDelta);
	// the multiply above won't overflow until we get over 4THz processors :)
	//  (assuming the performance counter stays at about 1MHz)
}
#else
static uint64 calc_stamps_pe_sec()
{
	LARGE_INTEGER rate;
	QueryPerformanceFrequency(&rate);
	return rate.QuadPart;
}
#endif
#else
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
static uint64 calc_stamps_pe_sec()
{
	struct timeval tvBefore, tvSleep =
	{ 0, 500000 }, tvAfter;
	uint64 stampBefore, stampAfter;

	// Prime it (just in cache)
	gettimeofday(&tvBefore, NULL);
	gettimeofday(&tvBefore, NULL);
	/* If we do these in the same order, then as long as the offset of
	 the time returned by gettimeofday is consistent, we should be ok. */
	gettimeofday(&tvBefore, NULL);
	stampBefore = gettimestamp();
	select(0, NULL, NULL, NULL, &tvSleep);

	// And again
	gettimeofday(&tvAfter, NULL);
	gettimeofday(&tvAfter, NULL);
	gettimeofday(&tvAfter, NULL);
	stampAfter = gettimestamp();

	uint64 microDelta = (tvAfter.tv_usec + 1000000 - tvBefore.tv_usec) % 1000000;
	uint64 stampDelta = stampAfter - stampBefore;
	return (stampDelta * 1000000ULL) / microDelta;
	// the multiply above won't overflow until we get over 4THz processors :)
}
#endif

uint64 stamps_per_sec()
{
	static uint64 stampsPerSecondCache = calc_stamps_pe_sec();
	return stampsPerSecondCache;
}
double stamps_per_sec_double()
{
	static double stampsPerSecondCacheD = double(stamps_per_sec());
	return stampsPerSecondCacheD;
}
double stamps2sec(uint64 stamps)
{
	static double val = stamps_per_sec_double();
	return stamps / val;
}
time_stamp_t time_stamp_t::fromSecs(double seconds)
{
	return uint64(seconds * stamps_per_sec_double());
}

