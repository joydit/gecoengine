/////////////////////////////////////////////////////////////////////////////
// EASprintf.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <EABase/eabase.h>
#include <stdio.h>

namespace EA {
	namespace StdC {
		 int Vsnprintf(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat, va_list arguments)
		{
			return vsnprintf(pDestination, n, pFormat, arguments);
		}

		int Vsnprintf(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat, va_list arguments)
		{
			return vswprintf((wchar_t*)pDestination, n, (wchar_t*)pFormat, arguments);
		}

		int Vsnprintf(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat, va_list arguments)
		{
			return vswprintf((wchar_t*)pDestination, n, (wchar_t*)pFormat, arguments);
		}

#if defined(EA_WCHAR_UNIQUE) && EA_WCHAR_UNIQUE
		int Vsnprintf(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
		{
			return vswprintf(pDestination, n, pFormat, arguments);
		}
#endif

	}
}