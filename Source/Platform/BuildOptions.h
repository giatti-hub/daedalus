#ifndef PLATFORM_BUILDOPTIONS_H_
#define PLATFORM_BUILDOPTIONS_H_

//
//	Platform options
//
#undef  DAEDALUS_ENABLE_DYNAREC					// Define this is dynarec is supported on the platform
#undef  DAEDALUS_ENABLE_OS_HOOKS				// Define this to enable OS HLE
#undef  DAEDALUS_BREAKPOINTS_ENABLED			// Define this to enable breakpoint support
#undef	DAEDALUS_ENDIAN_MODE					// Define this to specify whether the platform is big or little endian

// DAEDALUS_ENDIAN_MODE should be defined as one of:
//
#define DAEDALUS_ENDIAN_LITTLE 1
#define DAEDALUS_ENDIAN_BIG 2

//
//	Set up your preprocessor flags to search Source/SysXYZ/Include first, where XYZ is your target platform
//	If certain options are not defined, defaults are provided below
//
#include "Platform.h"

// The endianness should really be defined
#ifndef DAEDALUS_ENDIAN_MODE
#error DAEDALUS_ENDIAN_MODE was not specified in Platform.h
#endif

// Calling convention for the R4300 instruction handlers.
// This is only defined for W32, so provide a default if it's not set up
#ifndef R4300_CALL_TYPE
#define R4300_CALL_TYPE
#endif

// Calling convention for threads
#ifndef DAEDALUS_THREAD_CALL_TYPE
#define DAEDALUS_THREAD_CALL_TYPE
#endif

// Calling convention for vararg functions
#ifndef DAEDALUS_VARARG_CALL_TYPE
#define DAEDALUS_VARARG_CALL_TYPE
#endif

#ifndef DAEDALUS_ZLIB_CALL_TYPE
#define DAEDALUS_ZLIB_CALL_TYPE
#endif

//	Branch prediction
#ifndef DAEDALUS_EXPECT_LIKELY
#define DAEDALUS_EXPECT_LIKELY(c) (c)
#endif
#ifndef DAEDALUS_EXPECT_UNLIKELY
#define DAEDALUS_EXPECT_UNLIKELY(c) (c)
#endif

#ifndef DAEDALUS_ATTRIBUTE_NOINLINE
#define DAEDALUS_ATTRIBUTE_NOINLINE
#endif

#ifndef MAKE_UNCACHED_PTR
#define MAKE_UNCACHED_PTR(x)	(x)
#endif

//
//	Configuration options. These are not really platform-specific, but control various features
//
#if defined(DAEDALUS_CONFIG_RELEASE)
#include "Base/Release/BuildConfig.h"
#elif defined(DAEDALUS_CONFIG_PROFILE)
#include "Base/Profile/BuildConfig.h"
#elif defined(DAEDALUS_CONFIG_DEV)
#include "Base/Dev/BuildConfig.h"
#else
#error Unknown compilation mode
#endif


#endif // PLATFORM_BUILDOPTIONS_H_