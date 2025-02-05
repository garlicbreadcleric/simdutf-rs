/* auto-generated on 2022-07-25 16:36:20 -0400. Do not edit! */
/* begin file include/simdutf.h */
#ifndef SIMDUTF_H
#define SIMDUTF_H
#include <string>
#include <cstring>
#include <vector>

/* begin file include/simdutf/compiler_check.h */
#ifndef SIMDUTF_COMPILER_CHECK_H
#define SIMDUTF_COMPILER_CHECK_H

#ifndef __cplusplus
#error simdutf requires a C++ compiler
#endif

#ifndef SIMDUTF_CPLUSPLUS
#if defined(_MSVC_LANG) && !defined(__clang__)
#define SIMDUTF_CPLUSPLUS (_MSC_VER == 1900 ? 201103L : _MSVC_LANG)
#else
#define SIMDUTF_CPLUSPLUS __cplusplus
#endif
#endif

#if !defined(SIMDUTF_CPLUSPLUS17) && (SIMDUTF_CPLUSPLUS >= 201703L)
#define SIMDUTF_CPLUSPLUS17 1
#endif

#if !defined(SIMDUTF_CPLUSPLUS14) && (SIMDUTF_CPLUSPLUS >= 201402L)
#define SIMDUTF_CPLUSPLUS14 1
#endif

#if !defined(SIMDUTF_CPLUSPLUS11) && (SIMDUTF_CPLUSPLUS >= 201103L)
#define SIMDUTF_CPLUSPLUS11 1
#endif

#ifndef SIMDUTF_CPLUSPLUS11
#error simdutf requires a compiler compliant with the C++11 standard
#endif

#endif // SIMDUTF_COMPILER_CHECK_H
/* end file include/simdutf/compiler_check.h */
/* begin file include/simdutf/common_defs.h */
#ifndef SIMDUTF_COMMON_DEFS_H
#define SIMDUTF_COMMON_DEFS_H

#include <cassert>
/* begin file include/simdutf/portability.h */
#ifndef SIMDUTF_PORTABILITY_H
#define SIMDUTF_PORTABILITY_H

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cfloat>
#include <cassert>
#ifndef _WIN32
#include <strings.h>
#endif

#ifdef _MSC_VER
#define SIMDUTF_VISUAL_STUDIO 1
/**
 * We want to differentiate carefully between
 * clang under visual studio and regular visual
 * studio.
 *
 * Under clang for Windows, we enable:
 *  * target pragmas so that part and only part of the
 *     code gets compiled for advanced instructions.
 *
 */
#ifdef __clang__
#define SIMDUTF_CLANG_VISUAL_STUDIO 1
#else
#define SIMDUTF_REGULAR_VISUAL_STUDIO 1
#endif // __clang__
#endif // _MSC_VER

#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
#include <iso646.h>
#endif

#if defined(__x86_64__) || defined(_M_AMD64)
#define SIMDUTF_IS_X86_64 1
#elif defined(__aarch64__) || defined(_M_ARM64)
#define SIMDUTF_IS_ARM64 1
#elif defined(__PPC64__) || defined(_M_PPC64)
#pragma message("The simdutf library does yet support SIMD acceleration under\
POWER processors. Please see https://github.com/lemire/simdutf/issues/51")
#else
#define SIMDUTF_IS_32BITS 1

#if defined(_M_IX86) || defined(__i386__)
#define SIMDUTF_IS_X86_32BITS 1
#elif defined(__arm__) || defined(_M_ARM)
#define SIMDUTF_IS_ARM_32BITS 1
#elif defined(__PPC__) || defined(_M_PPC)
#define SIMDUTF_IS_PPC_32BITS 1
#endif

#endif // defined(__x86_64__) || defined(_M_AMD64)

#ifdef SIMDUTF_IS_32BITS
#ifndef SIMDUTF_NO_PORTABILITY_WARNING
#pragma message("The simdutf library is designed \
for 64-bit processors and it seems that you are not \
compiling for a known 64-bit platform. All fast kernels \
will be disabled and performance may be poor. Please \
use a 64-bit target such as x64, 64-bit ARM or 64-bit PPC.")
#endif // SIMDUTF_NO_PORTABILITY_WARNING
#endif // SIMDUTF_IS_32BITS

#undef STRINGIFY_IMPLEMENTATION_
#undef STRINGIFY
#define STRINGIFY_IMPLEMENTATION_(a) #a
#define STRINGIFY(a) STRINGIFY_IMPLEMENTATION_(a)



#ifdef SIMDUTF_IS_X86_64
#ifdef __clang__
#define SIMDUTF_TARGET_REGION(T)                                                       \
  _Pragma(STRINGIFY(                                                           \
      clang attribute push(__attribute__((target(T))), apply_to = function)))
#define SIMDUTF_UNTARGET_REGION _Pragma("clang attribute pop")
#elif defined(__GNUC__)
#define SIMDUTF_TARGET_REGION(T)                                                       \
  _Pragma("GCC push_options") _Pragma(STRINGIFY(GCC target(T)))
#define SIMDUTF_UNTARGET_REGION _Pragma("GCC pop_options")
#endif // clang then gcc

#endif // x86

#ifndef SIMDUTF_TARGET_REGION
#define SIMDUTF_TARGET_REGION(T)
#define SIMDUTF_UNTARGET_REGION
#endif

#if defined(_REENTRANT) || defined(_MT)
#ifndef SIMDUTF_THREADS_ENABLED
#define SIMDUTF_THREADS_ENABLED
#endif
#endif

#ifdef __APPLE__
#ifndef __OPTIMIZE__
#undef SIMDUTF_THREADS_ENABLED
#endif
#endif


#if defined(__clang__)
#define NO_SANITIZE_UNDEFINED __attribute__((no_sanitize("undefined")))
#elif defined(__GNUC__)
#define NO_SANITIZE_UNDEFINED __attribute__((no_sanitize_undefined))
#else
#define NO_SANITIZE_UNDEFINED
#endif

#ifdef SIMDUTF_VISUAL_STUDIO
#define simdutf_strcasecmp _stricmp
#define simdutf_strncasecmp _strnicmp
#else
#define simdutf_strcasecmp strcasecmp
#define simdutf_strncasecmp strncasecmp
#endif

#ifdef NDEBUG

#ifdef SIMDUTF_VISUAL_STUDIO
#define SIMDUTF_UNREACHABLE() __assume(0)
#define SIMDUTF_ASSUME(COND) __assume(COND)
#else
#define SIMDUTF_UNREACHABLE() __builtin_unreachable();
#define SIMDUTF_ASSUME(COND) do { if (!(COND)) __builtin_unreachable(); } while (0)
#endif

#else // NDEBUG

#define SIMDUTF_UNREACHABLE() assert(0);
#define SIMDUTF_ASSUME(COND) assert(COND)

#endif

#endif // SIMDUTF_PORTABILITY_H
/* end file include/simdutf/portability.h */


#if defined(__GNUC__)
  #define SIMDUTF_BEGIN_DEBUG_BLOCK(name) __asm volatile("# LLVM-MCA-BEGIN " #name);
  #define SIMDUTF_END_DEBUG_BLOCK(name) __asm volatile("# LLVM-MCA-END " #name);
  #define SIMDUTF_DEBUG_BLOCK(name, block) BEGIN_DEBUG_BLOCK(name); block; END_DEBUG_BLOCK(name);
#else
  #define SIMDUTF_BEGIN_DEBUG_BLOCK(name)
  #define SIMDUTF_END_DEBUG_BLOCK(name)
  #define SIMDUTF_DEBUG_BLOCK(name, block)
#endif

#define SIMDUTF_ROUNDUP_N(a, n) (((a) + ((n)-1)) & ~((n)-1))
#define SIMDUTF_ROUNDDOWN_N(a, n) ((a) & ~((n)-1))

#define SIMDUTF_ISALIGNED_N(ptr, n) (((uintptr_t)(ptr) & ((n)-1)) == 0)

#if defined(SIMDUTF_REGULAR_VISUAL_STUDIO)

  #define simdutf_really_inline __forceinline
  #define simdutf_never_inline __declspec(noinline)

  #define simdutf_unused
  #define simdutf_warn_unused

  #ifndef simdutf_likely
  #define simdutf_likely(x) x
  #endif
  #ifndef simdutf_unlikely
  #define simdutf_unlikely(x) x
  #endif

  #define SIMDUTF_PUSH_DISABLE_WARNINGS __pragma(warning( push ))
  #define SIMDUTF_PUSH_DISABLE_ALL_WARNINGS __pragma(warning( push, 0 ))
  #define SIMDUTF_DISABLE_VS_WARNING(WARNING_NUMBER) __pragma(warning( disable : WARNING_NUMBER ))
  #ifdef __has_include
  #if __has_include(<CppCoreCheck\Warnings.h>)
  #include <CppCoreCheck\Warnings.h>
  #define SIMDUTF_DISABLE_UNDESIRED_WARNINGS SIMDUTF_DISABLE_VS_WARNING(ALL_CPPCORECHECK_WARNINGS)
  #endif
  #endif

  #ifndef SIMDUTF_DISABLE_UNDESIRED_WARNINGS
  #define SIMDUTF_DISABLE_UNDESIRED_WARNINGS
  #endif

  #define SIMDUTF_DISABLE_DEPRECATED_WARNING SIMDUTF_DISABLE_VS_WARNING(4996)
  #define SIMDUTF_DISABLE_STRICT_OVERFLOW_WARNING
  #define SIMDUTF_POP_DISABLE_WARNINGS __pragma(warning( pop ))

#else // SIMDUTF_REGULAR_VISUAL_STUDIO

  #define simdutf_really_inline inline __attribute__((always_inline))
  #define simdutf_never_inline inline __attribute__((noinline))

  #define simdutf_unused __attribute__((unused))
  #define simdutf_warn_unused __attribute__((warn_unused_result))

  #ifndef simdutf_likely
  #define simdutf_likely(x) __builtin_expect(!!(x), 1)
  #endif
  #ifndef simdutf_unlikely
  #define simdutf_unlikely(x) __builtin_expect(!!(x), 0)
  #endif

  #define SIMDUTF_PUSH_DISABLE_WARNINGS _Pragma("GCC diagnostic push")
  #define SIMDUTF_PUSH_DISABLE_ALL_WARNINGS SIMDUTF_PUSH_DISABLE_WARNINGS \
    SIMDUTF_DISABLE_GCC_WARNING(-Weffc++) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wall) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wconversion) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wextra) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wattributes) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wimplicit-fallthrough) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wnon-virtual-dtor) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wreturn-type) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wshadow) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wunused-parameter) \
    SIMDUTF_DISABLE_GCC_WARNING(-Wunused-variable)
  #define SIMDUTF_PRAGMA(P) _Pragma(#P)
  #define SIMDUTF_DISABLE_GCC_WARNING(WARNING) SIMDUTF_PRAGMA(GCC diagnostic ignored #WARNING)
  #if defined(SIMDUTF_CLANG_VISUAL_STUDIO)
  #define SIMDUTF_DISABLE_UNDESIRED_WARNINGS SIMDUTF_DISABLE_GCC_WARNING(-Wmicrosoft-include)
  #else
  #define SIMDUTF_DISABLE_UNDESIRED_WARNINGS
  #endif
  #define SIMDUTF_DISABLE_DEPRECATED_WARNING SIMDUTF_DISABLE_GCC_WARNING(-Wdeprecated-declarations)
  #define SIMDUTF_DISABLE_STRICT_OVERFLOW_WARNING SIMDUTF_DISABLE_GCC_WARNING(-Wstrict-overflow)
  #define SIMDUTF_POP_DISABLE_WARNINGS _Pragma("GCC diagnostic pop")



#endif // MSC_VER

#if defined(SIMDUTF_VISUAL_STUDIO)
    /**
     * It does not matter here whether you are using
     * the regular visual studio or clang under visual
     * studio.
     */
    #if SIMDUTF_USING_LIBRARY
    #define SIMDUTF_DLLIMPORTEXPORT __declspec(dllimport)
    #else
    #define SIMDUTF_DLLIMPORTEXPORT __declspec(dllexport)
    #endif
#else
    #define SIMDUTF_DLLIMPORTEXPORT
#endif

#define SIMDUTF_TRY(EXPR) { auto _err = (EXPR); if (_err) { return _err; } }


#endif // SIMDUTF_COMMON_DEFS_H
/* end file include/simdutf/common_defs.h */
/* begin file include/simdutf/encoding_types.h */
#include <string>

namespace simdutf {

enum encoding_type {
        UTF16_LE,   // BOM 0xff 0xfe
        UTF16_BE,   // BOM 0xfe 0xff
        UTF32_LE,   // BOM 0xff 0xfe 0x00 0x00
        UTF32_BE,   // BOM 0x00 0x00 0xfe 0xff
        UTF8,       // BOM 0xef 0xbb 0xbf
        unspecified
};

enum endianness {
        LITTLE,
        BIG
};

std::string to_string(encoding_type bom);

namespace BOM {

/**
 * Checks for a BOM. If not, returns unspecified
 * @param input         the string to process
 * @param length        the length of the string in words
 * @return the corresponding encoding
 */

encoding_type check_bom(const uint8_t* byte, size_t length);
encoding_type check_bom(const char* byte, size_t length);
/**
 * Returns the size, in bytes, of the BOM for a given encoding type.
 * Note that UTF8 BOM are discouraged.
 * @param bom         the encoding type
 * @return the size in bytes of the corresponding BOM
 */
size_t bom_byte_size(encoding_type bom);

} // BOM namespace
} // simdutf namespace
/* end file include/simdutf/encoding_types.h */

SIMDUTF_PUSH_DISABLE_WARNINGS
SIMDUTF_DISABLE_UNDESIRED_WARNINGS

/* begin file include/simdutf/simdutf_version.h */
#ifndef SIMDUTF_SIMDUTF_VERSION_H
#define SIMDUTF_SIMDUTF_VERSION_H

/** The version of simdutf being used (major.minor.revision) */
#define SIMDUTF_VERSION 1.0.1

namespace simdutf {
enum {
  /**
   * The major version (MAJOR.minor.revision) of simdutf being used.
   */
  SIMDUTF_VERSION_MAJOR = 1,
  /**
   * The minor version (major.MINOR.revision) of simdutf being used.
   */
  SIMDUTF_VERSION_MINOR = 0,
  /**
   * The revision (major.minor.REVISION) of simdutf being used.
   */
  SIMDUTF_VERSION_REVISION = 1
};
} // namespace simdutf

#endif // SIMDUTF_SIMDUTF_VERSION_H
/* end file include/simdutf/simdutf_version.h */
/* begin file include/simdutf/implementation.h */
#ifndef SIMDUTF_IMPLEMENTATION_H
#define SIMDUTF_IMPLEMENTATION_H
#include <string>
#if !defined(SIMDUTF_NO_THREADS)
#include <atomic>
#endif
#include <vector>
/* begin file include/simdutf/internal/isadetection.h */
/* From
https://github.com/endorno/pytorch/blob/master/torch/lib/TH/generic/simd/simd.h
Highly modified.

Copyright (c) 2016-     Facebook, Inc            (Adam Paszke)
Copyright (c) 2014-     Facebook, Inc            (Soumith Chintala)
Copyright (c) 2011-2014 Idiap Research Institute (Ronan Collobert)
Copyright (c) 2012-2014 Deepmind Technologies    (Koray Kavukcuoglu)
Copyright (c) 2011-2012 NEC Laboratories America (Koray Kavukcuoglu)
Copyright (c) 2011-2013 NYU                      (Clement Farabet)
Copyright (c) 2006-2010 NEC Laboratories America (Ronan Collobert, Leon Bottou,
Iain Melvin, Jason Weston) Copyright (c) 2006      Idiap Research Institute
(Samy Bengio) Copyright (c) 2001-2004 Idiap Research Institute (Ronan Collobert,
Samy Bengio, Johnny Mariethoz)

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the names of Facebook, Deepmind Technologies, NYU, NEC Laboratories
America and IDIAP Research Institute nor the names of its contributors may be
   used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SIMDutf_INTERNAL_ISADETECTION_H
#define SIMDutf_INTERNAL_ISADETECTION_H

#include <cstdint>
#include <cstdlib>
#if defined(_MSC_VER)
#include <intrin.h>
#elif defined(HAVE_GCC_GET_CPUID) && defined(USE_GCC_GET_CPUID)
#include <cpuid.h>
#endif

namespace simdutf {
namespace internal {


enum instruction_set {
  DEFAULT = 0x0,
  NEON = 0x1,
  AVX2 = 0x4,
  SSE42 = 0x8,
  PCLMULQDQ = 0x10,
  BMI1 = 0x20,
  BMI2 = 0x40,
  ALTIVEC = 0x80,
  AVX512F = 0x100,
  AVX512BW = 0x200,
  AVX512DQ = 0x400
};

#if defined(__PPC64__)

static inline uint32_t detect_supported_architectures() {
  return instruction_set::ALTIVEC;
}

#elif defined(__arm__) || defined(__aarch64__) // incl. armel, armhf, arm64

#if defined(__ARM_NEON)

static inline uint32_t detect_supported_architectures() {
  return instruction_set::NEON;
}

#else // ARM without NEON

static inline uint32_t detect_supported_architectures() {
  return instruction_set::DEFAULT;
}

#endif

#elif defined(__x86_64__) || defined(_M_AMD64) // x64


namespace {
namespace cpuid_bit {

    constexpr uint32_t pclmulqdq = uint32_t(1) << 1; ///< @private bit  1 of ECX for EAX=0x1
    constexpr uint32_t sse42 = uint32_t(1) << 20;    ///< @private bit 20 of ECX for EAX=0x1

    namespace ebx {
      constexpr uint32_t bmi1 = uint32_t(1) << 3;
      constexpr uint32_t avx2 = uint32_t(1) << 5;
      constexpr uint32_t bmi2 = uint32_t(1) << 8;
      constexpr uint32_t avx512f = uint32_t(1) << 16;
      constexpr uint32_t avx512dq = uint32_t(1) << 17;
      constexpr uint32_t avx512ifma = uint32_t(1) << 21;
      constexpr uint32_t avx512cd = uint32_t(1) << 28;
      constexpr uint32_t avx512bw = uint32_t(1) << 30;
      constexpr uint32_t avx512vl = uint32_t(1) << 31;
    }

    namespace ecx {
      constexpr uint32_t avx512vbmi = uint32_t(1) << 1;
      constexpr uint32_t avx512vbmi2 = uint32_t(1) << 6;
      constexpr uint32_t avx512vnni = uint32_t(1) << 11;
      constexpr uint32_t avx512bitalg = uint32_t(1) << 12;
      constexpr uint32_t avx512vpopcnt = uint32_t(1) << 14;
    }
    namespace edx {
      constexpr uint32_t avx512vp2intersect = uint32_t(1) << 8;
    }
  }
}



static inline void cpuid(uint32_t *eax, uint32_t *ebx, uint32_t *ecx,
                         uint32_t *edx) {
#if defined(_MSC_VER)
  int cpu_info[4];
  __cpuid(cpu_info, *eax);
  *eax = cpu_info[0];
  *ebx = cpu_info[1];
  *ecx = cpu_info[2];
  *edx = cpu_info[3];
#elif defined(HAVE_GCC_GET_CPUID) && defined(USE_GCC_GET_CPUID)
  uint32_t level = *eax;
  __get_cpuid(level, eax, ebx, ecx, edx);
#else
  uint32_t a = *eax, b, c = *ecx, d;
  asm volatile("cpuid\n\t" : "+a"(a), "=b"(b), "+c"(c), "=d"(d));
  *eax = a;
  *ebx = b;
  *ecx = c;
  *edx = d;
#endif
}

static inline uint32_t detect_supported_architectures() {
  uint32_t eax;
  uint32_t ebx = 0;
  uint32_t ecx = 0;
  uint32_t edx = 0;
  uint32_t host_isa = 0x0;

  eax = 0x1;
  cpuid(&eax, &ebx, &ecx, &edx);

  if (ecx & cpuid_bit::sse42) {
    host_isa |= instruction_set::SSE42;
  }

  if (ecx & cpuid_bit::pclmulqdq) {
    host_isa |= instruction_set::PCLMULQDQ;
  }

  eax = 0x7;
  ecx = 0x0; // Sub-leaf = 0
  cpuid(&eax, &ebx, &ecx, &edx);
  if (ebx & cpuid_bit::ebx::avx2) {
    host_isa |= instruction_set::AVX2;
  }
  if (ebx & cpuid_bit::ebx::bmi1) {
    host_isa |= instruction_set::BMI1;
  }
  if (ebx & cpuid_bit::ebx::bmi2) {
    host_isa |= instruction_set::BMI2;
  }
  if (ebx & cpuid_bit::ebx::avx512f) {
    host_isa |= instruction_set::AVX512F;
  }
  if (ebx & cpuid_bit::ebx::avx512bw) {
    host_isa |= instruction_set::AVX512BW;
  }
  if (ebx & cpuid_bit::ebx::avx512dq) {
    host_isa |= instruction_set::AVX512DQ;
  }

  return host_isa;
}
#else // fallback


static inline uint32_t detect_supported_architectures() {
  return instruction_set::DEFAULT;
}


#endif // end SIMD extension detection code

} // namespace internal
} // namespace simdutf

#endif // SIMDutf_INTERNAL_ISADETECTION_H
/* end file include/simdutf/internal/isadetection.h */


namespace simdutf {

/**
 * Autodetect the encoding of the input.
 *
 * @param input the string to analyze.
 * @param length the length of the string in bytes.
 * @return the detected encoding type
 */
simdutf_warn_unused simdutf::encoding_type autodetect_encoding(const char * input, size_t length) noexcept;
simdutf_really_inline simdutf_warn_unused simdutf::encoding_type autodetect_encoding(const uint8_t * input, size_t length) noexcept {
  return autodetect_encoding(reinterpret_cast<const char *>(input), length);
}


/**
 * Validate the UTF-8 string.
 *
 * Overridden by each implementation.
 *
 * @param buf the UTF-8 string to validate.
 * @param len the length of the string in bytes.
 * @return true if and only if the string is valid UTF-8.
 */
simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) noexcept;

/**
 * Validate the ASCII string.
 *
 * Overridden by each implementation.
 *
 * @param buf the ASCII string to validate.
 * @param len the length of the string in bytes.
 * @return true if and only if the string is valid ASCII.
 */
simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) noexcept;

/**
 * Validate the UTF-16LE string.
 *
 * Overridden by each implementation.
 *
 * This function is not BOM-aware.
 *
 * @param buf the UTF-16LE string to validate.
 * @param len the length of the string in number of 2-byte words (char16_t).
 * @return true if and only if the string is valid UTF-16LE.
 */
simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) noexcept;

/**
 * Validate the UTF-16BE string.
 *
 * Overridden by each implementation.
 *
 * This function is not BOM-aware.
 *
 * @param buf the UTF-16BE string to validate.
 * @param len the length of the string in number of 2-byte words (char16_t).
 * @return true if and only if the string is valid UTF-16BE.
 */
simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) noexcept;

/**
 * Validate the UTF-32LE string.
 *
 * Overridden by each implementation.
 *
 * This function is not BOM-aware.
 *
 * @param buf the UTF-32LE string to validate.
 * @param len the length of the string in number of 4-byte words (char32_t).
 * @return true if and only if the string is valid UTF-32LE.
 */
simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) noexcept;

/**
 * Convert possibly broken UTF-8 string into UTF-16LE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in bytes
 * @param utf16_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char16_t; 0 if the input was not valid UTF-8 string
 */
simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * input, size_t length, char16_t* utf16_output) noexcept;

/**
 * Convert possibly broken UTF-8 string into UTF-16BE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in bytes
 * @param utf16_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char16_t; 0 if the input was not valid UTF-8 string
 */
simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * input, size_t length, char16_t* utf16_output) noexcept;

/**
 * Convert possibly broken UTF-8 string into UTF-32LE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in bytes
 * @param utf32_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char32_t; 0 if the input was not valid UTF-8 string
 */
simdutf_warn_unused size_t convert_utf8_to_utf32(const char * input, size_t length, char32_t* utf32_output) noexcept;

/**
 * Convert valid UTF-8 string into UTF-16LE string.
 *
 * This function assumes that the input string is valid UTF-8.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in bytes
 * @param utf16_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char16_t
 */
simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * input, size_t length, char16_t* utf16_buffer) noexcept;

/**
 * Convert valid UTF-8 string into UTF-16BE string.
 *
 * This function assumes that the input string is valid UTF-8.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in bytes
 * @param utf16_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char16_t
 */
simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * input, size_t length, char16_t* utf16_buffer) noexcept;

/**
 * Convert valid UTF-8 string into UTF-32LE string.
 *
 * This function assumes that the input string is valid UTF-8.
 *
 * @param input         the UTF-8 string to convert
 * @param length        the length of the string in bytes
 * @param utf32_buffer  the pointer to buffer that can hold conversion result
 * @return the number of written char32_t
 */
simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * input, size_t length, char32_t* utf32_buffer) noexcept;

/**
 * Compute the number of 2-byte words that this UTF-8 string would require in UTF-16LE format.
 *
 * This function does not validate the input.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-8 string to process
 * @param length        the length of the string in bytes
 * @return the number of char16_t words required to encode the UTF-8 string as UTF-16LE
 */
simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) noexcept;

/**
 * Compute the number of 4-byte words that this UTF-8 string would require in UTF-32LE format.
 *
 * This function is equivalent to count_utf8
 *
 * This function does not validate the input.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-8 string to process
 * @param length        the length of the string in bytes
 * @return the number of char32_t words required to encode the UTF-8 string as UTF-32LE
 */
simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) noexcept;

/**
 * Convert possibly broken UTF-16LE string into UTF-8 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-16LE string
 */
simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into UTF-8 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-16LE string
 */
simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) noexcept;

/**
 * Convert valid UTF-16LE string into UTF-8 string.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) noexcept;

/**
 * Convert valid UTF-16BE string into UTF-8 string.
 *
 * This function assumes that the input string is valid UTF-16BE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf8_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-16LE string into UTF-32LE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-16LE string
 */
simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) noexcept;

/**
 * Convert possibly broken UTF-16BE string into UTF-32LE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-16LE string
 */
simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) noexcept;

/**
 * Convert valid UTF-16LE string into UTF-32LE string.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) noexcept;

/**
 * Convert valid UTF-16BE string into UTF-32LE string.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param utf32_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) noexcept;

/**
 * Compute the number of bytes that this UTF-16LE string would require in UTF-8 format.
 *
 * This function does not validate the input.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16BE string would require in UTF-8 format.
 *
 * This function does not validate the input.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @return the number of bytes required to encode the UTF-16BE string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) noexcept;

/**
 * Convert possibly broken UTF-32LE string into UTF-8 string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @param utf8_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-32LE string
 */
simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * input, size_t length, char* utf8_buffer) noexcept;

/**
 * Convert valid UTF-32LE string into UTF-8 string.
 *
 * This function assumes that the input string is valid UTF-32LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @param utf8_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * input, size_t length, char* utf8_buffer) noexcept;

/**
 * Convert possibly broken UTF-32LE string into UTF-16LE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-32LE string
 */
simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * input, size_t length, char16_t* utf16_buffer) noexcept;

/**
 * Convert possibly broken UTF-32LE string into UTF-16BE string.
 *
 * During the conversion also validation of the input string is done.
 * This function is suitable to work with inputs from untrusted sources.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold conversion result
 * @return number of written words; 0 if input is not a valid UTF-32LE string
 */
simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * input, size_t length, char16_t* utf16_buffer) noexcept;

/**
 * Convert valid UTF-32LE string into UTF-16LE string.
 *
 * This function assumes that the input string is valid UTF-32LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * input, size_t length, char16_t* utf16_buffer) noexcept;

/**
 * Convert valid UTF-32LE string into UTF-16BE string.
 *
 * This function assumes that the input string is valid UTF-32LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @param utf16_buffer   the pointer to buffer that can hold the conversion result
 * @return number of written words; 0 if conversion is not possible
 */
simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * input, size_t length, char16_t* utf16_buffer) noexcept;

/**
 * Change the endianness of the input. Can be used to go from UTF-16LE to UTF-16BE or
 * from UTF-16BE to UTF-16LE.
 *
 * This function does not validate the input.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16 string to process
 * @param length        the length of the string in 2-byte words (char16_t)
 * @param output        the pointer to buffer that can hold the conversion result
 */
void change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) noexcept;

/**
 * Compute the number of bytes that this UTF-32LE string would require in UTF-8 format.
 *
 * This function does not validate the input.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @return the number of bytes required to encode the UTF-32LE string as UTF-8
 */
simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) noexcept;

/**
 * Compute the number of two-byte words that this UTF-32LE string would require in UTF-16 format.
 *
 * This function does not validate the input.
 *
 * @param input         the UTF-32LE string to convert
 * @param length        the length of the string in 4-byte words (char32_t)
 * @return the number of bytes required to encode the UTF-32LE string as UTF-16
 */
simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16LE string would require in UTF-32LE format.
 *
 * This function is equivalent to count_utf16le.
 *
 * This function does not validate the input.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @return the number of bytes required to encode the UTF-16LE string as UTF-32LE
 */
simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) noexcept;

/**
 * Compute the number of bytes that this UTF-16BE string would require in UTF-32LE format.
 *
 * This function is equivalent to count_utf16be.
 *
 * This function does not validate the input.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to convert
 * @param length        the length of the string in 2-byte words (char16_t)
 * @return the number of bytes required to encode the UTF-16BE string as UTF-32LE
 */
simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) noexcept;

/**
 * Count the number of code points (characters) in the string assuming that
 * it is valid.
 *
 * This function assumes that the input string is valid UTF-16LE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16LE string to process
 * @param length        the length of the string in 2-byte words (char16_t)
 * @return number of code points
 */
simdutf_warn_unused size_t count_utf16le(const char16_t * input, size_t length) noexcept;

/**
 * Count the number of code points (characters) in the string assuming that
 * it is valid.
 *
 * This function assumes that the input string is valid UTF-16BE.
 *
 * This function is not BOM-aware.
 *
 * @param input         the UTF-16BE string to process
 * @param length        the length of the string in 2-byte words (char16_t)
 * @return number of code points
 */
simdutf_warn_unused size_t count_utf16be(const char16_t * input, size_t length) noexcept;

/**
 * Count the number of code points (characters) in the string assuming that
 * it is valid.
 *
 * This function assumes that the input string is valid UTF-8.
 *
 * @param input         the UTF-8 string to process
 * @param length        the length of the string in bytes
 * @return number of code points
 */
simdutf_warn_unused size_t count_utf8(const char * input, size_t length) noexcept;

/**
 * An implementation of simdutf for a particular CPU architecture.
 *
 * Also used to maintain the currently active implementation. The active implementation is
 * automatically initialized on first use to the most advanced implementation supported by the host.
 */
class implementation {
public:

  /**
   * The name of this implementation.
   *
   *     const implementation *impl = simdutf::active_implementation;
   *     cout << "simdutf is optimized for " << impl->name() << "(" << impl->description() << ")" << endl;
   *
   * @return the name of the implementation, e.g. "haswell", "westmere", "arm64"
   */
  virtual const std::string &name() const { return _name; }

  /**
   * The description of this implementation.
   *
   *     const implementation *impl = simdutf::active_implementation;
   *     cout << "simdutf is optimized for " << impl->name() << "(" << impl->description() << ")" << endl;
   *
   * @return the name of the implementation, e.g. "haswell", "westmere", "arm64"
   */
  virtual const std::string &description() const { return _description; }

  /**
   * The instruction sets this implementation is compiled against
   * and the current CPU match. This function may poll the current CPU/system
   * and should therefore not be called too often if performance is a concern.
   *
   *
   * @return true if the implementation can be safely used on the current system (determined at runtime)
   */
  bool supported_by_runtime_system() const;

  /**
   * This function will try to detect the encoding
   * @param input the string to identify
   * @param length the length of the string in bytes.
   * @return the encoding type detected
   */
  virtual encoding_type autodetect_encoding(const char * input, size_t length) const noexcept;

  /**
   * @private For internal implementation use
   *
   * The instruction sets this implementation is compiled against.
   *
   * @return a mask of all required `internal::instruction_set::` values
   */
  virtual uint32_t required_instruction_sets() const { return _required_instruction_sets; };


  /**
   * Validate the UTF-8 string.
   *
   * Overridden by each implementation.
   *
   * @param buf the UTF-8 string to validate.
   * @param len the length of the string in bytes.
   * @return true if and only if the string is valid UTF-8.
   */
  simdutf_warn_unused virtual bool validate_utf8(const char *buf, size_t len) const noexcept = 0;

  /**
   * Validate the ASCII string.
   *
   * Overridden by each implementation.
   *
   * @param buf the ASCII string to validate.
   * @param len the length of the string in bytes.
   * @return true if and only if the string is valid ASCII.
   */
  simdutf_warn_unused virtual bool validate_ascii(const char *buf, size_t len) const noexcept = 0;

  /**
   * Validate the UTF-16LE string.
   *
   * Overridden by each implementation.
   *
   * This function is not BOM-aware.
   *
   * @param buf the UTF-16LE string to validate.
   * @param len the length of the string in number of 2-byte words (char16_t).
   * @return true if and only if the string is valid UTF-16LE.
   */
  simdutf_warn_unused virtual bool validate_utf16le(const char16_t *buf, size_t len) const noexcept = 0;

  /**
   * Validate the UTF-16BE string.
   *
   * Overridden by each implementation.
   *
   * This function is not BOM-aware.
   *
   * @param buf the UTF-16BE string to validate.
   * @param len the length of the string in number of 2-byte words (char16_t).
   * @return true if and only if the string is valid UTF-16BE.
   */
  simdutf_warn_unused virtual bool validate_utf16be(const char16_t *buf, size_t len) const noexcept = 0;

  /**
   * Validate the UTF-32LE string.
   *
   * Overridden by each implementation.
   *
   * This function is not BOM-aware.
   *
   * @param buf the UTF-32LE string to validate.
   * @param len the length of the string in number of 4-byte words (char32_t).
   * @return true if and only if the string is valid UTF-32LE.
   */
  simdutf_warn_unused virtual bool validate_utf32(const char32_t *buf, size_t len) const noexcept = 0;

  /**
   * Convert possibly broken UTF-8 string into UTF-16LE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * @param input         the UTF-8 string to convert
   * @param length        the length of the string in bytes
   * @param utf16_buffer  the pointer to buffer that can hold conversion result
   * @return the number of written char16_t; 0 if the input was not valid UTF-8 string
   */
  simdutf_warn_unused virtual size_t convert_utf8_to_utf16le(const char * input, size_t length, char16_t* utf16_output) const noexcept = 0;

  /**
   * Convert possibly broken UTF-8 string into UTF-16BE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * @param input         the UTF-8 string to convert
   * @param length        the length of the string in bytes
   * @param utf16_buffer  the pointer to buffer that can hold conversion result
   * @return the number of written char16_t; 0 if the input was not valid UTF-8 string
   */
  simdutf_warn_unused virtual size_t convert_utf8_to_utf16be(const char * input, size_t length, char16_t* utf16_output) const noexcept = 0;

  /**
   * Convert possibly broken UTF-8 string into UTF-32LE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * @param input         the UTF-8 string to convert
   * @param length        the length of the string in bytes
   * @param utf32_buffer  the pointer to buffer that can hold conversion result
   * @return the number of written char16_t; 0 if the input was not valid UTF-8 string
   */
  simdutf_warn_unused virtual size_t convert_utf8_to_utf32(const char * input, size_t length, char32_t* utf32_output) const noexcept = 0;

  /**
   * Convert valid UTF-8 string into UTF-16LE string.
   *
   * This function assumes that the input string is valid UTF-8.
   *
   * @param input         the UTF-8 string to convert
   * @param length        the length of the string in bytes
   * @param utf16_buffer  the pointer to buffer that can hold conversion result
   * @return the number of written char16_t
   */
  simdutf_warn_unused virtual size_t convert_valid_utf8_to_utf16le(const char * input, size_t length, char16_t* utf16_buffer) const noexcept = 0;

/**
   * Convert valid UTF-8 string into UTF-16BE string.
   *
   * This function assumes that the input string is valid UTF-8.
   *
   * @param input         the UTF-8 string to convert
   * @param length        the length of the string in bytes
   * @param utf16_buffer  the pointer to buffer that can hold conversion result
   * @return the number of written char16_t
   */
  simdutf_warn_unused virtual size_t convert_valid_utf8_to_utf16be(const char * input, size_t length, char16_t* utf16_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-8 string into UTF-32LE string.
   *
   * This function assumes that the input string is valid UTF-8.
   *
   * @param input         the UTF-8 string to convert
   * @param length        the length of the string in bytes
   * @param utf16_buffer  the pointer to buffer that can hold conversion result
   * @return the number of written char32_t
   */
  simdutf_warn_unused virtual size_t convert_valid_utf8_to_utf32(const char * input, size_t length, char32_t* utf32_buffer) const noexcept = 0;

  /**
   * Compute the number of 2-byte words that this UTF-8 string would require in UTF-16LE format.
   *
   * This function does not validate the input.
   *
   * @param input         the UTF-8 string to process
   * @param length        the length of the string in bytes
   * @return the number of char16_t words required to encode the UTF-8 string as UTF-16LE
   */
  simdutf_warn_unused virtual size_t utf16_length_from_utf8(const char * input, size_t length) const noexcept = 0;

   /**
   * Compute the number of 4-byte words that this UTF-8 string would require in UTF-32LE format.
   *
   * This function is equivalent to count_utf8.
   *
   * This function does not validate the input.
   *
   * @param input         the UTF-8 string to process
   * @param length        the length of the string in bytes
   * @return the number of char32_t words required to encode the UTF-8 string as UTF-32LE
   */
  simdutf_warn_unused virtual size_t utf32_length_from_utf8(const char * input, size_t length) const noexcept = 0;

  /**
   * Convert possibly broken UTF-16LE string into UTF-8 string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf8_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-16LE string
   */
  simdutf_warn_unused virtual size_t convert_utf16le_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) const noexcept = 0;

  /**
   * Convert possibly broken UTF-16BE string into UTF-8 string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf8_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-16BE string
   */
  simdutf_warn_unused virtual size_t convert_utf16be_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-16LE string into UTF-8 string.
   *
   * This function assumes that the input string is valid UTF-16LE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf8_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf16le_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-16BE string into UTF-8 string.
   *
   * This function assumes that the input string is valid UTF-16BE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf8_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf16be_to_utf8(const char16_t * input, size_t length, char* utf8_buffer) const noexcept = 0;

  /**
   * Convert possibly broken UTF-16LE string into UTF-32LE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf32_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-16LE string
   */
  simdutf_warn_unused virtual size_t convert_utf16le_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) const noexcept = 0;

  /**
   * Convert possibly broken UTF-16BE string into UTF-32LE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf32_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-16BE string
   */
  simdutf_warn_unused virtual size_t convert_utf16be_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-16LE string into UTF-32LE string.
   *
   * This function assumes that the input string is valid UTF-16LE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf32_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf16le_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-16LE string into UTF-32BE string.
   *
   * This function assumes that the input string is valid UTF-16BE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param utf32_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf16be_to_utf32(const char16_t * input, size_t length, char32_t* utf32_buffer) const noexcept = 0;

  /**
   * Compute the number of bytes that this UTF-16LE string would require in UTF-8 format.
   *
   * This function does not validate the input.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @return the number of bytes required to encode the UTF-16LE string as UTF-8
   */
  simdutf_warn_unused virtual size_t utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept = 0;

  /**
   * Compute the number of bytes that this UTF-16BE string would require in UTF-8 format.
   *
   * This function does not validate the input.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @return the number of bytes required to encode the UTF-16BE string as UTF-8
   */
  simdutf_warn_unused virtual size_t utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept = 0;

  /**
   * Convert possibly broken UTF-32LE string into UTF-8 string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @param utf8_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-32LE string
   */
  simdutf_warn_unused virtual size_t convert_utf32_to_utf8(const char32_t * input, size_t length, char* utf8_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-32LE string into UTF-8 string.
   *
   * This function assumes that the input string is valid UTF-32LE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @param utf8_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf32_to_utf8(const char32_t * input, size_t length, char* utf8_buffer) const noexcept = 0;

  /**
   * Convert possibly broken UTF-32LE string into UTF-16LE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @param utf16_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-32LE string
   */
  simdutf_warn_unused virtual size_t convert_utf32_to_utf16le(const char32_t * input, size_t length, char16_t* utf16_buffer) const noexcept = 0;

  /**
   * Convert possibly broken UTF-32LE string into UTF-16BE string.
   *
   * During the conversion also validation of the input string is done.
   * This function is suitable to work with inputs from untrusted sources.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @param utf16_buffer   the pointer to buffer that can hold conversion result
   * @return number of written words; 0 if input is not a valid UTF-32LE string
   */
  simdutf_warn_unused virtual size_t convert_utf32_to_utf16be(const char32_t * input, size_t length, char16_t* utf16_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-32LE string into UTF-16LE string.
   *
   * This function assumes that the input string is valid UTF-32LE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @param utf16_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf32_to_utf16le(const char32_t * input, size_t length, char16_t* utf16_buffer) const noexcept = 0;

  /**
   * Convert valid UTF-32LE string into UTF-16BE string.
   *
   * This function assumes that the input string is valid UTF-32LE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @param utf16_buffer   the pointer to buffer that can hold the conversion result
   * @return number of written words; 0 if conversion is not possible
   */
  simdutf_warn_unused virtual size_t convert_valid_utf32_to_utf16be(const char32_t * input, size_t length, char16_t* utf16_buffer) const noexcept = 0;

  /**
   * Change the endianness of the input. Can be used to go from UTF-16LE to UTF-16BE or
   * from UTF-16BE to UTF-16LE.
   *
   * This function does not validate the input.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16 string to process
   * @param length        the length of the string in 2-byte words (char16_t)
   * @param output        the pointer to buffer that can hold the conversion result
   */
  virtual void change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) const noexcept = 0;

  /**
   * Compute the number of bytes that this UTF-32LE string would require in UTF-8 format.
   *
   * This function does not validate the input.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @return the number of bytes required to encode the UTF-32LE string as UTF-8
   */
  simdutf_warn_unused virtual size_t utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept = 0;

  /**
   * Compute the number of two-byte words that this UTF-32LE string would require in UTF-16 format.
   *
   * This function does not validate the input.
   *
   * @param input         the UTF-32LE string to convert
   * @param length        the length of the string in 4-byte words (char32_t)
   * @return the number of bytes required to encode the UTF-32LE string as UTF-16
   */
  simdutf_warn_unused virtual size_t utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept = 0;

  /*
   * Compute the number of bytes that this UTF-16LE string would require in UTF-32LE format.
   *
   * This function is equivalent to count_utf16le.
   *
   * This function does not validate the input.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @return the number of bytes required to encode the UTF-16LE string as UTF-32LE
   */
  simdutf_warn_unused virtual size_t utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept = 0;

  /*
   * Compute the number of bytes that this UTF-16BE string would require in UTF-32LE format.
   *
   * This function is equivalent to count_utf16be.
   *
   * This function does not validate the input.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to convert
   * @param length        the length of the string in 2-byte words (char16_t)
   * @return the number of bytes required to encode the UTF-16BE string as UTF-32LE
   */
  simdutf_warn_unused virtual size_t utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept = 0;

  /**
   * Count the number of code points (characters) in the string assuming that
   * it is valid.
   *
   * This function assumes that the input string is valid UTF-16LE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16LE string to process
   * @param length        the length of the string in 2-byte words (char16_t)
   * @return number of code points
   */
  simdutf_warn_unused virtual size_t count_utf16le(const char16_t * input, size_t length) const noexcept = 0;

  /**
   * Count the number of code points (characters) in the string assuming that
   * it is valid.
   *
   * This function assumes that the input string is valid UTF-16BE.
   *
   * This function is not BOM-aware.
   *
   * @param input         the UTF-16BE string to process
   * @param length        the length of the string in 2-byte words (char16_t)
   * @return number of code points
   */
  simdutf_warn_unused virtual size_t count_utf16be(const char16_t * input, size_t length) const noexcept = 0;


  /**
   * Count the number of code points (characters) in the string assuming that
   * it is valid.
   *
   * This function assumes that the input string is valid UTF-8.
   *
   * @param input         the UTF-8 string to process
   * @param length        the length of the string in bytes
   * @return number of code points
   */
  simdutf_warn_unused virtual size_t count_utf8(const char * input, size_t length) const noexcept = 0;



protected:
  /** @private Construct an implementation with the given name and description. For subclasses. */
  simdutf_really_inline implementation(
    std::string name,
    std::string description,
    uint32_t required_instruction_sets
  ) :
    _name(name),
    _description(description),
    _required_instruction_sets(required_instruction_sets)
  {
  }
  virtual ~implementation()=default;

private:
  /**
   * The name of this implementation.
   */
  const std::string _name;

  /**
   * The description of this implementation.
   */
  const std::string _description;

  /**
   * Instruction sets required for this implementation.
   */
  const uint32_t _required_instruction_sets;
};

/** @private */
namespace internal {

/**
 * The list of available implementations compiled into simdutf.
 */
class available_implementation_list {
public:
  /** Get the list of available implementations compiled into simdutf */
  simdutf_really_inline available_implementation_list() {}
  /** Number of implementations */
  size_t size() const noexcept;
  /** STL const begin() iterator */
  const implementation * const *begin() const noexcept;
  /** STL const end() iterator */
  const implementation * const *end() const noexcept;

  /**
   * Get the implementation with the given name.
   *
   * Case sensitive.
   *
   *     const implementation *impl = simdutf::available_implementations["westmere"];
   *     if (!impl) { exit(1); }
   *     if (!imp->supported_by_runtime_system()) { exit(1); }
   *     simdutf::active_implementation = impl;
   *
   * @param name the implementation to find, e.g. "westmere", "haswell", "arm64"
   * @return the implementation, or nullptr if the parse failed.
   */
  const implementation * operator[](const std::string &name) const noexcept {
    for (const implementation * impl : *this) {
      if (impl->name() == name) { return impl; }
    }
    return nullptr;
  }

  /**
   * Detect the most advanced implementation supported by the current host.
   *
   * This is used to initialize the implementation on startup.
   *
   *     const implementation *impl = simdutf::available_implementation::detect_best_supported();
   *     simdutf::active_implementation = impl;
   *
   * @return the most advanced supported implementation for the current host, or an
   *         implementation that returns UNSUPPORTED_ARCHITECTURE if there is no supported
   *         implementation. Will never return nullptr.
   */
  const implementation *detect_best_supported() const noexcept;
};

template<typename T>
class atomic_ptr {
public:
  atomic_ptr(T *_ptr) : ptr{_ptr} {}

#if defined(SIMDUTF_NO_THREADS)
  operator const T*() const { return ptr; }
  const T& operator*() const { return *ptr; }
  const T* operator->() const { return ptr; }

  operator T*() { return ptr; }
  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }
  atomic_ptr& operator=(T *_ptr) { ptr = _ptr; return *this; }

#else
  operator const T*() const { return ptr.load(); }
  const T& operator*() const { return *ptr; }
  const T* operator->() const { return ptr.load(); }

  operator T*() { return ptr.load(); }
  T& operator*() { return *ptr; }
  T* operator->() { return ptr.load(); }
  atomic_ptr& operator=(T *_ptr) { ptr = _ptr; return *this; }

#endif

private:
#if defined(SIMDUTF_NO_THREADS)
  T* ptr;
#else
  std::atomic<T*> ptr;
#endif
};

} // namespace internal

/**
 * The list of available implementations compiled into simdutf.
 */
extern SIMDUTF_DLLIMPORTEXPORT const internal::available_implementation_list available_implementations;

/**
  * The active implementation.
  *
  * Automatically initialized on first use to the most advanced implementation supported by this hardware.
  */
extern SIMDUTF_DLLIMPORTEXPORT internal::atomic_ptr<const implementation> active_implementation;

} // namespace simdutf

#endif // SIMDUTF_IMPLEMENTATION_H
/* end file include/simdutf/implementation.h */




SIMDUTF_POP_DISABLE_WARNINGS

#endif // SIMDUTF_H
/* end file include/simdutf.h */
