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

#include "affinity.h"
#if defined(_WIN32)
#include <windows.h>
#endif

#if !defined( _XBOX360) && defined(_WIN32)
		static uint32 processor_mask = 0;

		// this function returns an available processor number
		// it favours processorHint, but if this one is not
		// available
		static uint32 availableProcessor(uint32 processorHint)
		{
			uint32 ret = processorHint;
			uint count;
			// First get the available processors
#ifdef _AMD64_
			DWORD64 processAffinity = 0;
			DWORD64 systemAffinity = 0;
			count = 64;
			uint64 i;
#else
			DWORD processAffinity = 0;
			DWORD systemAffinity = 0;
			count = 32;
			uint32 i;
#endif
			HRESULT hr = GetProcessAffinityMask(GetCurrentProcess(), &processAffinity, &systemAffinity);
			// If hint is available, use it, otherwise find the first available processor
			if (SUCCEEDED(hr) && !(processAffinity & (1 << processorHint)))
			{
				for (i = 0; i < count; i++)
				{
					if (processAffinity & (1 << i))
					{
						ret = i;
						break;
					}
				}
			}
			return ret;
		}

		void affinity_set(uint32 processorHint)
		{
			// get an available processor
			processor_mask = availableProcessor(processorHint);
			SetThreadAffinityMask(GetCurrentThread(), 1 << processor_mask);
			if (processor_mask != processorHint)
			{
				fprintf(stderr, "ProcessorAffinity::set - unable to set processor "
					"affinity to %d setting to %d instead\n", processorHint, processor_mask);
			}
		}
		uint32 affinity_get()
		{
			return processor_mask;
		}
		void affinity_update()
		{
			affinity_set(processor_mask);
		}
#endif
