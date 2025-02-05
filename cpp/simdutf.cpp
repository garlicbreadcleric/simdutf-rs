/* auto-generated on 2022-07-25 16:36:20 -0400. Do not edit! */
/* begin file src/simdutf.cpp */
#include "simdutf.h"
/* begin file src/implementation.cpp */
#include <initializer_list>
#include <string>
#include <climits>

namespace simdutf {
namespace {

template <typename T>
std::string toBinaryString(T b) {
   std::string binary = "";
   T mask = T(1) << (sizeof(T) * CHAR_BIT - 1);
   while (mask > 0) {
    binary += ((b & mask) == 0) ? '0' : '1';
    mask >>= 1;
  }
  return binary;
}
}
}

/* begin file src/simdutf/arm64.h */
#ifndef SIMDUTF_ARM64_H
#define SIMDUTF_ARM64_H

#ifdef SIMDUTF_FALLBACK_H
#error "arm64.h must be included before fallback.h"
#endif


#ifndef SIMDUTF_IMPLEMENTATION_ARM64
#define SIMDUTF_IMPLEMENTATION_ARM64 (SIMDUTF_IS_ARM64)
#endif
#define SIMDUTF_CAN_ALWAYS_RUN_ARM64 SIMDUTF_IMPLEMENTATION_ARM64 && SIMDUTF_IS_ARM64



#if SIMDUTF_IMPLEMENTATION_ARM64

namespace simdutf {
/**
 * Implementation for NEON (ARMv8).
 */
namespace arm64 {
} // namespace arm64
} // namespace simdutf

/* begin file src/simdutf/arm64/implementation.h */
#ifndef SIMDUTF_ARM64_IMPLEMENTATION_H
#define SIMDUTF_ARM64_IMPLEMENTATION_H


namespace simdutf {
namespace arm64 {

namespace {
using namespace simdutf;
}

class implementation final : public simdutf::implementation {
public:
  simdutf_really_inline implementation() : simdutf::implementation("arm64", "ARM NEON", internal::instruction_set::NEON) {}
  simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  void change_endianness_utf16(const char16_t * buf, size_t length, char16_t * output) const noexcept final;
  simdutf_warn_unused size_t count_utf16le(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf16be(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf8(const char * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) const noexcept;
};

} // namespace arm64
} // namespace simdutf

#endif // SIMDUTF_ARM64_IMPLEMENTATION_H
/* end file src/simdutf/arm64/implementation.h */

/* begin file src/simdutf/arm64/begin.h */
/* end file src/simdutf/arm64/begin.h */

/* begin file src/simdutf/arm64/intrinsics.h */
#ifndef SIMDUTF_ARM64_INTRINSICS_H
#define SIMDUTF_ARM64_INTRINSICS_H


#include <arm_neon.h>

#endif //  SIMDUTF_ARM64_INTRINSICS_H
/* end file src/simdutf/arm64/intrinsics.h */
/* begin file src/simdutf/arm64/bitmanipulation.h */
#ifndef SIMDUTF_ARM64_BITMANIPULATION_H
#define SIMDUTF_ARM64_BITMANIPULATION_H

namespace simdutf {
namespace arm64 {
namespace {

/* result might be undefined when input_num is zero */
simdutf_really_inline int count_ones(uint64_t input_num) {
   return vaddv_u8(vcnt_u8(vcreate_u8(input_num)));
}

} // unnamed namespace
} // namespace arm64
} // namespace simdutf

#endif // SIMDUTF_ARM64_BITMANIPULATION_H
/* end file src/simdutf/arm64/bitmanipulation.h */
/* begin file src/simdutf/arm64/simd.h */
#ifndef SIMDUTF_ARM64_SIMD_H
#define SIMDUTF_ARM64_SIMD_H

#include <type_traits>


namespace simdutf {
namespace arm64 {
namespace {
namespace simd {

#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
namespace {


/**
 * make_uint8x16_t initializes a SIMD register (uint8x16_t).
 * This is needed because, incredibly, the syntax uint8x16_t x = {1,2,3...}
 * is not recognized under Visual Studio! This is a workaround.
 * Using a std::initializer_list<uint8_t>  as a parameter resulted in
 * inefficient code. With the current approach, if the parameters are
 * compile-time constants,
 * GNU GCC compiles it to ldr, the same as uint8x16_t x = {1,2,3...}.
 * You should not use this function except for compile-time constants:
 * it is not efficient.
 */
simdutf_really_inline uint8x16_t make_uint8x16_t(uint8_t x1,  uint8_t x2,  uint8_t x3,  uint8_t x4,
                                         uint8_t x5,  uint8_t x6,  uint8_t x7,  uint8_t x8,
                                         uint8_t x9,  uint8_t x10, uint8_t x11, uint8_t x12,
                                         uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16) {
  uint8x16_t x{};
  x = vsetq_lane_u8(x1, x, 0);
  x = vsetq_lane_u8(x2, x, 1);
  x = vsetq_lane_u8(x3, x, 2);
  x = vsetq_lane_u8(x4, x, 3);
  x = vsetq_lane_u8(x5, x, 4);
  x = vsetq_lane_u8(x6, x, 5);
  x = vsetq_lane_u8(x7, x, 6);
  x = vsetq_lane_u8(x8, x, 7);
  x = vsetq_lane_u8(x9, x, 8);
  x = vsetq_lane_u8(x10, x, 9);
  x = vsetq_lane_u8(x11, x, 10);
  x = vsetq_lane_u8(x12, x, 11);
  x = vsetq_lane_u8(x13, x, 12);
  x = vsetq_lane_u8(x14, x, 13);
  x = vsetq_lane_u8(x15, x, 14);
  x = vsetq_lane_u8(x16, x, 15);
  return x;
}

simdutf_really_inline int8x16_t make_int8x16_t(int8_t x1,  int8_t x2,  int8_t x3,  int8_t x4,
                                       int8_t x5,  int8_t x6,  int8_t x7,  int8_t x8,
                                       int8_t x9,  int8_t x10, int8_t x11, int8_t x12,
                                       int8_t x13, int8_t x14, int8_t x15, int8_t x16) {
  int8x16_t x{};
  x = vsetq_lane_s8(x1, x, 0);
  x = vsetq_lane_s8(x2, x, 1);
  x = vsetq_lane_s8(x3, x, 2);
  x = vsetq_lane_s8(x4, x, 3);
  x = vsetq_lane_s8(x5, x, 4);
  x = vsetq_lane_s8(x6, x, 5);
  x = vsetq_lane_s8(x7, x, 6);
  x = vsetq_lane_s8(x8, x, 7);
  x = vsetq_lane_s8(x9, x, 8);
  x = vsetq_lane_s8(x10, x, 9);
  x = vsetq_lane_s8(x11, x, 10);
  x = vsetq_lane_s8(x12, x, 11);
  x = vsetq_lane_s8(x13, x, 12);
  x = vsetq_lane_s8(x14, x, 13);
  x = vsetq_lane_s8(x15, x, 14);
  x = vsetq_lane_s8(x16, x, 15);
  return x;
}

simdutf_really_inline uint8x8_t make_uint8x8_t(uint8_t x1,  uint8_t x2,  uint8_t x3,  uint8_t x4,
                                         uint8_t x5,  uint8_t x6,  uint8_t x7,  uint8_t x8) {
  uint8x8_t x{};
  x = vset_lane_u8(x1, x, 0);
  x = vset_lane_u8(x2, x, 1);
  x = vset_lane_u8(x3, x, 2);
  x = vset_lane_u8(x4, x, 3);
  x = vset_lane_u8(x5, x, 4);
  x = vset_lane_u8(x6, x, 5);
  x = vset_lane_u8(x7, x, 6);
  x = vset_lane_u8(x8, x, 7);
  return x;
}

simdutf_really_inline uint16x8_t make_uint16x8_t(uint16_t x1,  uint16_t x2,  uint16_t x3,  uint16_t x4,
                                       uint16_t x5,  uint16_t x6,  uint16_t x7,  uint16_t x8) {
  uint16x8_t x{};
  x = vsetq_lane_u16(x1, x, 0);
  x = vsetq_lane_u16(x2, x, 1);
  x = vsetq_lane_u16(x3, x, 2);
  x = vsetq_lane_u16(x4, x, 3);
  x = vsetq_lane_u16(x5, x, 4);
  x = vsetq_lane_u16(x6, x, 5);
  x = vsetq_lane_u16(x7, x, 6);
  x = vsetq_lane_u16(x8, x, 7);;
  return x;
}

simdutf_really_inline int16x8_t make_int16x8_t(int16_t x1,  int16_t x2,  int16_t x3,  int16_t x4,
                                       int16_t x5,  int16_t x6,  int16_t x7,  int16_t x8) {
  uint16x8_t x{};
  x = vsetq_lane_s16(x1, x, 0);
  x = vsetq_lane_s16(x2, x, 1);
  x = vsetq_lane_s16(x3, x, 2);
  x = vsetq_lane_s16(x4, x, 3);
  x = vsetq_lane_s16(x5, x, 4);
  x = vsetq_lane_s16(x6, x, 5);
  x = vsetq_lane_s16(x7, x, 6);
  x = vsetq_lane_s16(x8, x, 7);;
  return x;
}


} // namespace
#endif // SIMDUTF_REGULAR_VISUAL_STUDIO


  template<typename T>
  struct simd8;

  template<typename T, typename Mask=simd8<bool>>
  struct base_u8 {
    uint8x16_t value;
    static const int SIZE = sizeof(value);

    simdutf_really_inline base_u8(const uint8x16_t _value) : value(_value) {}
    simdutf_really_inline operator const uint8x16_t&() const { return this->value; }
    simdutf_really_inline operator uint8x16_t&() { return this->value; }
    simdutf_really_inline T first() const { return vgetq_lane_u8(*this,0); }
    simdutf_really_inline T last() const { return vgetq_lane_u8(*this,15); }

    simdutf_really_inline simd8<T> operator|(const simd8<T> other) const { return vorrq_u8(*this, other); }
    simdutf_really_inline simd8<T> operator&(const simd8<T> other) const { return vandq_u8(*this, other); }
    simdutf_really_inline simd8<T> operator^(const simd8<T> other) const { return veorq_u8(*this, other); }
    simdutf_really_inline simd8<T> bit_andnot(const simd8<T> other) const { return vbicq_u8(*this, other); }
    simdutf_really_inline simd8<T> operator~() const { return *this ^ 0xFFu; }
    simdutf_really_inline simd8<T>& operator|=(const simd8<T> other) { auto this_cast = static_cast<simd8<T>*>(this); *this_cast = *this_cast | other; return *this_cast; }
    simdutf_really_inline simd8<T>& operator&=(const simd8<T> other) { auto this_cast = static_cast<simd8<T>*>(this); *this_cast = *this_cast & other; return *this_cast; }
    simdutf_really_inline simd8<T>& operator^=(const simd8<T> other) { auto this_cast = static_cast<simd8<T>*>(this); *this_cast = *this_cast ^ other; return *this_cast; }

    simdutf_really_inline Mask operator==(const simd8<T> other) const { return vceqq_u8(*this, other); }

    template<int N=1>
    simdutf_really_inline simd8<T> prev(const simd8<T> prev_chunk) const {
      return vextq_u8(prev_chunk, *this, 16 - N);
    }
  };

  template<>
  struct simd8<bool>: base_u8<bool> {
    typedef uint16_t bitmask_t;
    typedef uint32_t bitmask2_t;

    static simdutf_really_inline simd8<bool> splat(bool _value) { return vmovq_n_u8(uint8_t(-(!!_value))); }

    simdutf_really_inline simd8(const uint8x16_t _value) : base_u8<bool>(_value) {}
    simdutf_really_inline simd8() : simd8(vdupq_n_u8(0)) {}
    simdutf_really_inline simd8(bool _value) : simd8(splat(_value)) {}
    simdutf_really_inline void store(uint8_t dst[16]) const { return vst1q_u8(dst, *this); }

    simdutf_really_inline uint32_t to_bitmask() const {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
      const uint8x16_t bit_mask =  make_uint8x16_t(0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
                                                   0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
#else
      const uint8x16_t bit_mask =  {0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
                                    0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
#endif
      auto minput = *this & bit_mask;
      uint8x16_t tmp = vpaddq_u8(minput, minput);
      tmp = vpaddq_u8(tmp, tmp);
      tmp = vpaddq_u8(tmp, tmp);
      return vgetq_lane_u16(vreinterpretq_u16_u8(tmp), 0);
    }

    simdutf_really_inline uint64_t to_bitmask64() const {
      return vget_lane_u64(vreinterpret_u64_u8(vshrn_n_u16(vreinterpretq_u16_u8(*this), 4)), 0);
    }

    simdutf_really_inline bool any() const { return vmaxvq_u8(*this) != 0; }
    simdutf_really_inline bool none() const { return vmaxvq_u8(*this) == 0; }
    simdutf_really_inline bool all() const { return vminvq_u8(*this) == 0xFF; }


  };

  template<>
  struct simd8<uint8_t>: base_u8<uint8_t> {
    static simdutf_really_inline simd8<uint8_t> splat(uint8_t _value) { return vmovq_n_u8(_value); }
    static simdutf_really_inline simd8<uint8_t> zero() { return vdupq_n_u8(0); }
    static simdutf_really_inline simd8<uint8_t> load(const uint8_t* values) { return vld1q_u8(values); }
    simdutf_really_inline simd8(const uint8x16_t _value) : base_u8<uint8_t>(_value) {}
    simdutf_really_inline simd8() : simd8(zero()) {}
    simdutf_really_inline simd8(const uint8_t values[16]) : simd8(load(values)) {}
    simdutf_really_inline simd8(uint8_t _value) : simd8(splat(_value)) {}
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
    simdutf_really_inline simd8(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) : simd8(make_uint8x16_t(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    )) {}
#else
    simdutf_really_inline simd8(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) : simd8(uint8x16_t{
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    }) {}
#endif

    simdutf_really_inline static simd8<uint8_t> repeat_16(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) {
      return simd8<uint8_t>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }

    simdutf_really_inline void store(uint8_t dst[16]) const { return vst1q_u8(dst, *this); }

    simdutf_really_inline simd8<uint8_t> saturating_add(const simd8<uint8_t> other) const { return vqaddq_u8(*this, other); }
    simdutf_really_inline simd8<uint8_t> saturating_sub(const simd8<uint8_t> other) const { return vqsubq_u8(*this, other); }

    simdutf_really_inline simd8<uint8_t> operator+(const simd8<uint8_t> other) const { return vaddq_u8(*this, other); }
    simdutf_really_inline simd8<uint8_t> operator-(const simd8<uint8_t> other) const { return vsubq_u8(*this, other); }
    simdutf_really_inline simd8<uint8_t>& operator+=(const simd8<uint8_t> other) { *this = *this + other; return *this; }
    simdutf_really_inline simd8<uint8_t>& operator-=(const simd8<uint8_t> other) { *this = *this - other; return *this; }

    simdutf_really_inline uint8_t max_val() const { return vmaxvq_u8(*this); }
    simdutf_really_inline uint8_t min_val() const { return vminvq_u8(*this); }
    simdutf_really_inline simd8<uint8_t> max_val(const simd8<uint8_t> other) const { return vmaxq_u8(*this, other); }
    simdutf_really_inline simd8<uint8_t> min_val(const simd8<uint8_t> other) const { return vminq_u8(*this, other); }
    simdutf_really_inline simd8<bool> operator<=(const simd8<uint8_t> other) const { return vcleq_u8(*this, other); }
    simdutf_really_inline simd8<bool> operator>=(const simd8<uint8_t> other) const { return vcgeq_u8(*this, other); }
    simdutf_really_inline simd8<bool> operator<(const simd8<uint8_t> other) const { return vcltq_u8(*this, other); }
    simdutf_really_inline simd8<bool> operator>(const simd8<uint8_t> other) const { return vcgtq_u8(*this, other); }
    simdutf_really_inline simd8<uint8_t> gt_bits(const simd8<uint8_t> other) const { return simd8<uint8_t>(*this > other); }
    simdutf_really_inline simd8<uint8_t> lt_bits(const simd8<uint8_t> other) const { return simd8<uint8_t>(*this < other); }

    simdutf_really_inline simd8<bool> any_bits_set(simd8<uint8_t> bits) const { return vtstq_u8(*this, bits); }
    simdutf_really_inline bool is_ascii() const { return this->max_val() < 0b10000000u; }

    simdutf_really_inline bool any_bits_set_anywhere() const { return this->max_val() != 0; }
    simdutf_really_inline bool any_bits_set_anywhere(simd8<uint8_t> bits) const { return (*this & bits).any_bits_set_anywhere(); }
    template<int N>
    simdutf_really_inline simd8<uint8_t> shr() const { return vshrq_n_u8(*this, N); }
    template<int N>
    simdutf_really_inline simd8<uint8_t> shl() const { return vshlq_n_u8(*this, N); }

    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(simd8<L> lookup_table) const {
      return lookup_table.apply_lookup_16_to(*this);
    }


    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(
        L replace0,  L replace1,  L replace2,  L replace3,
        L replace4,  L replace5,  L replace6,  L replace7,
        L replace8,  L replace9,  L replace10, L replace11,
        L replace12, L replace13, L replace14, L replace15) const {
      return lookup_16(simd8<L>::repeat_16(
        replace0,  replace1,  replace2,  replace3,
        replace4,  replace5,  replace6,  replace7,
        replace8,  replace9,  replace10, replace11,
        replace12, replace13, replace14, replace15
      ));
    }

    template<typename T>
    simdutf_really_inline simd8<uint8_t> apply_lookup_16_to(const simd8<T> original) const {
      return vqtbl1q_u8(*this, simd8<uint8_t>(original));
    }
  };

  template<>
  struct simd8<int8_t> {
    int8x16_t value;

    static simdutf_really_inline simd8<int8_t> splat(int8_t _value) { return vmovq_n_s8(_value); }
    static simdutf_really_inline simd8<int8_t> zero() { return vdupq_n_s8(0); }
    static simdutf_really_inline simd8<int8_t> load(const int8_t values[16]) { return vld1q_s8(values); }
    template <endianness big_endian>
    simdutf_really_inline void store_ascii_as_utf16(char16_t * p) const {
      uint16x8_t first = vmovl_u8(vget_low_u8 (vreinterpretq_u8_s8(this->value)));
      uint16x8_t second = vmovl_high_u8(vreinterpretq_u8_s8(this->value));
      if (big_endian) {
        #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
        const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
        #else
        const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
        #endif
        first = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(first), swap));
        second = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(second), swap));
      }
      vst1q_u16(reinterpret_cast<uint16_t*>(p), first);
      vst1q_u16(reinterpret_cast<uint16_t*>(p + 8), second);
    }
    simdutf_really_inline void store_ascii_as_utf32(char32_t * p) const {
      vst1q_u32(reinterpret_cast<uint32_t*>(p), vmovl_u16(vget_low_u16(vmovl_u8(vget_low_u8 (vreinterpretq_u8_s8(this->value))))));
      vst1q_u32(reinterpret_cast<uint32_t*>(p + 4), vmovl_high_u16(vmovl_u8(vget_low_u8 (vreinterpretq_u8_s8(this->value)))));
      vst1q_u32(reinterpret_cast<uint32_t*>(p + 8), vmovl_u16(vget_low_u16(vmovl_high_u8(vreinterpretq_u8_s8(this->value)))));
      vst1q_u32(reinterpret_cast<uint32_t*>(p + 12), vmovl_high_u16(vmovl_high_u8(vreinterpretq_u8_s8(this->value))));
    }
    simdutf_really_inline simd8(const int8x16_t _value) : value{_value} {}
    simdutf_really_inline operator const int8x16_t&() const { return this->value; }
    simdutf_really_inline operator const uint8x16_t() const { return vreinterpretq_u8_s8(this->value); }
    simdutf_really_inline operator int8x16_t&() { return this->value; }

    simdutf_really_inline simd8() : simd8(zero()) {}
    simdutf_really_inline simd8(int8_t _value) : simd8(splat(_value)) {}
    simdutf_really_inline simd8(const int8_t* values) : simd8(load(values)) {}
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
    simdutf_really_inline simd8(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3, int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) : simd8(make_int8x16_t(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    )) {}
#else
    simdutf_really_inline simd8(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3, int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) : simd8(int8x16_t{
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    }) {}
#endif
    simdutf_really_inline static simd8<int8_t> repeat_16(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3,  int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) {
      return simd8<int8_t>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }

    simdutf_really_inline void store(int8_t dst[16]) const { return vst1q_s8(dst, value); }
#ifndef SIMDUTF_REGULAR_VISUAL_STUDIO
    simdutf_really_inline explicit simd8(const uint8x16_t other): simd8(vreinterpretq_s8_u8(other)) {}
#endif
    simdutf_really_inline operator simd8<uint8_t>() const { return vreinterpretq_u8_s8(this->value); }

    simdutf_really_inline simd8<int8_t> operator|(const simd8<int8_t> other) const { return vorrq_s8(value, other.value); }
    simdutf_really_inline simd8<int8_t> operator&(const simd8<int8_t> other) const { return vandq_s8(value, other.value); }
    simdutf_really_inline simd8<int8_t> operator^(const simd8<int8_t> other) const { return veorq_s8(value, other.value); }
    simdutf_really_inline simd8<int8_t> bit_andnot(const simd8<int8_t> other) const { return vbicq_s8(value, other.value); }

    simdutf_really_inline simd8<int8_t> operator+(const simd8<int8_t> other) const { return vaddq_s8(value, other.value); }
    simdutf_really_inline simd8<int8_t> operator-(const simd8<int8_t> other) const { return vsubq_s8(value, other.value); }
    simdutf_really_inline simd8<int8_t>& operator+=(const simd8<int8_t> other) { *this = *this + other; return *this; }
    simdutf_really_inline simd8<int8_t>& operator-=(const simd8<int8_t> other) { *this = *this - other; return *this; }

    simdutf_really_inline int8_t max_val() const { return vmaxvq_s8(value); }
    simdutf_really_inline int8_t min_val() const { return vminvq_s8(value); }
    simdutf_really_inline bool is_ascii() const { return this->min_val() >= 0; }

    simdutf_really_inline simd8<int8_t> max_val(const simd8<int8_t> other) const { return vmaxq_s8(value, other.value); }
    simdutf_really_inline simd8<int8_t> min_val(const simd8<int8_t> other) const { return vminq_s8(value, other.value); }
    simdutf_really_inline simd8<bool> operator>(const simd8<int8_t> other) const { return vcgtq_s8(value, other.value); }
    simdutf_really_inline simd8<bool> operator<(const simd8<int8_t> other) const { return vcltq_s8(value, other.value); }
    simdutf_really_inline simd8<bool> operator==(const simd8<int8_t> other) const { return vceqq_s8(value, other.value); }

    template<int N=1>
    simdutf_really_inline simd8<int8_t> prev(const simd8<int8_t> prev_chunk) const {
      return vextq_s8(prev_chunk, *this, 16 - N);
    }

    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(simd8<L> lookup_table) const {
      return lookup_table.apply_lookup_16_to(*this);
    }
    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(
        L replace0,  L replace1,  L replace2,  L replace3,
        L replace4,  L replace5,  L replace6,  L replace7,
        L replace8,  L replace9,  L replace10, L replace11,
        L replace12, L replace13, L replace14, L replace15) const {
      return lookup_16(simd8<L>::repeat_16(
        replace0,  replace1,  replace2,  replace3,
        replace4,  replace5,  replace6,  replace7,
        replace8,  replace9,  replace10, replace11,
        replace12, replace13, replace14, replace15
      ));
    }

    template<typename T>
    simdutf_really_inline simd8<int8_t> apply_lookup_16_to(const simd8<T> original) {
      return vqtbl1q_s8(*this, simd8<uint8_t>(original));
    }
  };

  template<typename T>
  struct simd8x64 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd8<T>);
    static_assert(NUM_CHUNKS == 4, "ARM kernel should use four registers per 64-byte block.");
    simd8<T> chunks[NUM_CHUNKS];

    simd8x64(const simd8x64<T>& o) = delete; // no copy allowed
    simd8x64<T>& operator=(const simd8<T> other) = delete; // no assignment allowed
    simd8x64() = delete; // no default constructor allowed

    simdutf_really_inline simd8x64(const simd8<T> chunk0, const simd8<T> chunk1, const simd8<T> chunk2, const simd8<T> chunk3) : chunks{chunk0, chunk1, chunk2, chunk3} {}
    simdutf_really_inline simd8x64(const T* ptr) : chunks{simd8<T>::load(ptr), simd8<T>::load(ptr+sizeof(simd8<T>)/sizeof(T)), simd8<T>::load(ptr+2*sizeof(simd8<T>)/sizeof(T)), simd8<T>::load(ptr+3*sizeof(simd8<T>)/sizeof(T))} {}

    simdutf_really_inline void store(T* ptr) const {
      this->chunks[0].store(ptr+sizeof(simd8<T>)*0/sizeof(T));
      this->chunks[1].store(ptr+sizeof(simd8<T>)*1/sizeof(T));
      this->chunks[2].store(ptr+sizeof(simd8<T>)*2/sizeof(T));
      this->chunks[3].store(ptr+sizeof(simd8<T>)*3/sizeof(T));
    }


    simdutf_really_inline simd8x64<T>& operator |=(const simd8x64<T> &other) {
      this->chunks[0] |= other.chunks[0];
      this->chunks[1] |= other.chunks[1];
      this->chunks[2] |= other.chunks[2];
      this->chunks[3] |= other.chunks[3];
      return *this;
    }

    simdutf_really_inline simd8<T> reduce_or() const {
      return (this->chunks[0] | this->chunks[1]) | (this->chunks[2] | this->chunks[3]);
    }

    simdutf_really_inline bool is_ascii() const {
      return reduce_or().is_ascii();
    }

    template <endianness endian>
    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      this->chunks[0].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*0);
      this->chunks[1].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*1);
      this->chunks[2].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*2);
      this->chunks[3].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*3);
    }

    simdutf_really_inline void store_ascii_as_utf32(char32_t * ptr) const {
      this->chunks[0].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*0);
      this->chunks[1].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*1);
      this->chunks[2].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*2);
      this->chunks[3].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*3);
    }

    simdutf_really_inline uint64_t to_bitmask() const {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
      const uint8x16_t bit_mask = make_uint8x16_t(
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80
      );
#else
      const uint8x16_t bit_mask = {
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80
      };
#endif
      uint8x16_t sum0 = vpaddq_u8(vandq_u8(uint8x16_t(this->chunks[0]), bit_mask), vandq_u8(uint8x16_t(this->chunks[1]), bit_mask));
      uint8x16_t sum1 = vpaddq_u8(vandq_u8(uint8x16_t(this->chunks[2]), bit_mask), vandq_u8(uint8x16_t(this->chunks[3]), bit_mask));
      sum0 = vpaddq_u8(sum0, sum1);
      sum0 = vpaddq_u8(sum0, sum0);
      return vgetq_lane_u64(vreinterpretq_u64_u8(sum0), 0);
    }

    simdutf_really_inline uint64_t eq(const T m) const {
    const simd8<T> mask = simd8<T>::splat(m);
    return  simd8x64<bool>(
      this->chunks[0] == mask,
      this->chunks[1] == mask,
      this->chunks[2] == mask,
      this->chunks[3] == mask
    ).to_bitmask();
  }

  simdutf_really_inline uint64_t lteq(const T m) const {
    const simd8<T> mask = simd8<T>::splat(m);
    return  simd8x64<bool>(
      this->chunks[0] <= mask,
      this->chunks[1] <= mask,
      this->chunks[2] <= mask,
      this->chunks[3] <= mask
    ).to_bitmask();
  }

    simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);

      return  simd8x64<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);
      return  simd8x64<bool>(
        (this->chunks[0] > mask_high) | (this->chunks[0] < mask_low),
        (this->chunks[1] > mask_high) | (this->chunks[1] < mask_low),
        (this->chunks[2] > mask_high) | (this->chunks[2] < mask_low),
        (this->chunks[3] > mask_high) | (this->chunks[3] < mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t lt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] < mask,
        this->chunks[1] < mask,
        this->chunks[2] < mask,
        this->chunks[3] < mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] > mask,
        this->chunks[1] > mask,
        this->chunks[2] > mask,
        this->chunks[3] > mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gteq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] >= mask,
        this->chunks[1] >= mask,
        this->chunks[2] >= mask,
        this->chunks[3] >= mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gteq_unsigned(const uint8_t m) const {
      const simd8<uint8_t> mask = simd8<uint8_t>::splat(m);
      return  simd8x64<bool>(
        simd8<uint8_t>(uint8x16_t(this->chunks[0])) >= mask,
        simd8<uint8_t>(uint8x16_t(this->chunks[1])) >= mask,
        simd8<uint8_t>(uint8x16_t(this->chunks[2])) >= mask,
        simd8<uint8_t>(uint8x16_t(this->chunks[3])) >= mask
      ).to_bitmask();
    }
  }; // struct simd8x64<T>
/* begin file src/simdutf/arm64/simd16-inl.h */
template<typename T>
struct simd16;

  template<typename T, typename Mask=simd16<bool>>
  struct base_u16 {
    uint16x8_t value;
    static const int SIZE = sizeof(value);

    simdutf_really_inline base_u16() = default;
    simdutf_really_inline base_u16(const uint16x8_t _value) : value(_value) {}
    simdutf_really_inline operator const uint16x8_t&() const { return this->value; }
    simdutf_really_inline operator uint16x8_t&() { return this->value; }
    simdutf_really_inline simd16<T> operator|(const simd16<T> other) const { return vorrq_u16(*this, other); }
    simdutf_really_inline simd16<T> operator&(const simd16<T> other) const { return vandq_u16(*this, other); }
    simdutf_really_inline simd16<T> operator^(const simd16<T> other) const { return veorq_u16(*this, other); }
    simdutf_really_inline simd16<T> bit_andnot(const simd16<T> other) const { return vbicq_u16(*this, other); }
    simdutf_really_inline simd16<T> operator~() const { return *this ^ 0xFFu; }
    simdutf_really_inline simd16<T>& operator|=(const simd16<T> other) { auto this_cast = static_cast<simd16<T>*>(this); *this_cast = *this_cast | other; return *this_cast; }
    simdutf_really_inline simd16<T>& operator&=(const simd16<T> other) { auto this_cast = static_cast<simd16<T>*>(this); *this_cast = *this_cast & other; return *this_cast; }
    simdutf_really_inline simd16<T>& operator^=(const simd16<T> other) { auto this_cast = static_cast<simd16<T>*>(this); *this_cast = *this_cast ^ other; return *this_cast; }

    simdutf_really_inline Mask operator==(const simd16<T> other) const { return vceqq_u16(*this, other); }

    template<int N=1>
    simdutf_really_inline simd16<T> prev(const simd16<T> prev_chunk) const {
      return vextq_u18(prev_chunk, *this, 8 - N);
    }
  };

template<typename T, typename Mask=simd16<bool>>
struct base16: base_u16<T> {
  typedef uint16_t bitmask_t;
  typedef uint32_t bitmask2_t;

  simdutf_really_inline base16() : base_u16<T>() {}
  simdutf_really_inline base16(const uint16x8_t _value) : base_u16<T>(_value) {}
  template <typename Pointer>
  simdutf_really_inline base16(const Pointer* ptr) : base16(vld1q_u16(ptr)) {}

  simdutf_really_inline Mask operator==(const simd16<T> other) const { return vceqq_u16(*this, other); }

  static const int SIZE = sizeof(base_u16<T>::value);

  template<int N=1>
  simdutf_really_inline simd16<T> prev(const simd16<T> prev_chunk) const {
    return vextq_u18(prev_chunk, *this, 8 - N);
  }
};

template<>
struct simd16<bool>: base16<bool> {
  static simdutf_really_inline simd16<bool> splat(bool _value) { return vmovq_n_u16(uint16_t(-(!!_value))); }

  simdutf_really_inline simd16<bool>() : base16() {}
  simdutf_really_inline simd16<bool>(const uint16x8_t _value) : base16<bool>(_value) {}
  simdutf_really_inline simd16<bool>(bool _value) : base16<bool>(splat(_value)) {}

};

template<typename T>
struct base16_numeric: base16<T> {
  static simdutf_really_inline simd16<T> splat(T _value) { return vmovq_n_u16(_value); }
  static simdutf_really_inline simd16<T> zero() { return vdupq_n_u16(0); }
  static simdutf_really_inline simd16<T> load(const T values[8]) {
    return vld1q_u16(reinterpret_cast<const uint16_t*>(values));
  }

  simdutf_really_inline base16_numeric() : base16<T>() {}
  simdutf_really_inline base16_numeric(const uint16x8_t _value) : base16<T>(_value) {}

  simdutf_really_inline void store(T dst[8]) const { return vst1q_u16(dst, *this); }

  simdutf_really_inline simd16<T> operator~() const { return *this ^ 0xFFu; }

  simdutf_really_inline simd16<T> operator+(const simd16<T> other) const { return vaddq_u8(*this, other); }
  simdutf_really_inline simd16<T> operator-(const simd16<T> other) const { return vsubq_u8(*this, other); }
  simdutf_really_inline simd16<T>& operator+=(const simd16<T> other) { *this = *this + other; return *static_cast<simd16<T>*>(this); }
  simdutf_really_inline simd16<T>& operator-=(const simd16<T> other) { *this = *this - other; return *static_cast<simd16<T>*>(this); }
};

template<>
struct simd16<int16_t> : base16_numeric<int16_t> {
  simdutf_really_inline simd16() : base16_numeric<int16_t>() {}
#ifndef SIMDUTF_REGULAR_VISUAL_STUDIO
  simdutf_really_inline simd16(const uint16x8_t _value) : base16_numeric<int16_t>(_value) {}
#endif
  simdutf_really_inline simd16(const int16x8_t _value) : base16_numeric<int16_t>(vreinterpretq_u16_s16(_value)) {}

  simdutf_really_inline simd16(int16_t _value) : simd16(splat(_value)) {}
  simdutf_really_inline simd16(const int16_t* values) : simd16(load(values)) {}
  simdutf_really_inline simd16(const char16_t* values) : simd16(load(reinterpret_cast<const int16_t*>(values))) {}
  simdutf_really_inline operator simd16<uint16_t>() const;
  simdutf_really_inline operator const uint16x8_t&() const { return this->value; }
  simdutf_really_inline operator const int16x8_t() const { return vreinterpretq_s16_u16(this->value); }

  simdutf_really_inline int16_t max_val() const { return vmaxvq_s16(vreinterpretq_s16_u16(this->value)); }
  simdutf_really_inline int16_t min_val() const { return vminvq_s16(vreinterpretq_s16_u16(this->value)); }
  simdutf_really_inline simd16<int16_t> max_val(const simd16<int16_t> other) const { return vmaxq_s16(vreinterpretq_s16_u16(this->value), vreinterpretq_s16_u16(other.value)); }
  simdutf_really_inline simd16<int16_t> min_val(const simd16<int16_t> other) const { return vmaxq_s16(vreinterpretq_s16_u16(this->value), vreinterpretq_s16_u16(other.value)); }
  simdutf_really_inline simd16<bool> operator>(const simd16<int16_t> other) const { return vcgtq_s16(vreinterpretq_s16_u16(this->value), vreinterpretq_s16_u16(other.value)); }
  simdutf_really_inline simd16<bool> operator<(const simd16<int16_t> other) const { return vcltq_s16(vreinterpretq_s16_u16(this->value), vreinterpretq_s16_u16(other.value)); }
};




template<>
struct simd16<uint16_t>: base16_numeric<uint16_t>  {
  simdutf_really_inline simd16() : base16_numeric<uint16_t>() {}
  simdutf_really_inline simd16(const uint16x8_t _value) : base16_numeric<uint16_t>(_value) {}

  simdutf_really_inline simd16(uint16_t _value) : simd16(splat(_value)) {}
  simdutf_really_inline simd16(const uint16_t* values) : simd16(load(values)) {}
  simdutf_really_inline simd16(const char16_t* values) : simd16(load(reinterpret_cast<const uint16_t*>(values))) {}


  simdutf_really_inline int16_t max_val() const { return vmaxvq_u16(*this); }
  simdutf_really_inline int16_t min_val() const { return vminvq_u16(*this); }
  simdutf_really_inline simd16<uint16_t> saturating_add(const simd16<uint16_t> other) const { return vqaddq_u16(*this, other); }
  simdutf_really_inline simd16<uint16_t> saturating_sub(const simd16<uint16_t> other) const { return vqsubq_u16(*this, other); }

  simdutf_really_inline simd16<uint16_t> max_val(const simd16<uint16_t> other) const { return vmaxq_u16(*this, other); }
  simdutf_really_inline simd16<uint16_t> min_val(const simd16<uint16_t> other) const { return vminq_u16(*this, other); }
  simdutf_really_inline simd16<uint16_t> gt_bits(const simd16<uint16_t> other) const { return this->saturating_sub(other); }
  simdutf_really_inline simd16<uint16_t> lt_bits(const simd16<uint16_t> other) const { return other.saturating_sub(*this); }
  simdutf_really_inline simd16<bool> operator<=(const simd16<uint16_t> other) const { return vcleq_u16(*this, other); }
  simdutf_really_inline simd16<bool> operator>=(const simd16<uint16_t> other) const { return vcgeq_u16(*this, other); }
  simdutf_really_inline simd16<bool> operator>(const simd16<uint16_t> other) const { return  vcgtq_u16(*this, other); }
  simdutf_really_inline simd16<bool> operator<(const simd16<uint16_t> other) const { return vcltq_u16(*this, other); }

  simdutf_really_inline simd16<bool> bits_not_set() const { return *this == uint16_t(0); }
  template<int N>
  simdutf_really_inline simd16<uint16_t> shr() const { return simd16<uint16_t>(vshrq_n_u16(*this, N)); }
  template<int N>
  simdutf_really_inline simd16<uint16_t> shl() const { return simd16<uint16_t>(vshlq_n_u16(*this, N)); }

  simdutf_really_inline simd16<uint16_t> operator|(const simd16<uint16_t> other) const { return vorrq_u16(*this, other); }
  simdutf_really_inline simd16<uint16_t> operator&(const simd16<uint16_t> other) const { return vandq_u16(*this, other); }
  simdutf_really_inline simd16<uint16_t> operator^(const simd16<uint16_t> other) const { return veorq_u16(*this, other); }

  static simdutf_really_inline simd8<uint8_t> pack(const simd16<uint16_t>& v0, const simd16<uint16_t>& v1) {
    return vqmovn_high_u16(vqmovn_u16(v0), v1);
  }

  simdutf_really_inline simd16<uint16_t> swap_bytes() const {
    #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
    const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    #else
    const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
    #endif
    return vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(*this), swap));
  }
};
simdutf_really_inline simd16<int16_t>::operator simd16<uint16_t>() const { return this->value; }


  template<typename T>
  struct simd16x32 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd16<T>);
    static_assert(NUM_CHUNKS == 4, "ARM kernel should use four registers per 64-byte block.");
    simd16<T> chunks[NUM_CHUNKS];

    simd16x32(const simd16x32<T>& o) = delete; // no copy allowed
    simd16x32<T>& operator=(const simd16<T> other) = delete; // no assignment allowed
    simd16x32() = delete; // no default constructor allowed

    simdutf_really_inline simd16x32(const simd16<T> chunk0, const simd16<T> chunk1, const simd16<T> chunk2, const simd16<T> chunk3) : chunks{chunk0, chunk1, chunk2, chunk3} {}
    simdutf_really_inline simd16x32(const T* ptr) : chunks{simd16<T>::load(ptr), simd16<T>::load(ptr+sizeof(simd16<T>)/sizeof(T)), simd16<T>::load(ptr+2*sizeof(simd16<T>)/sizeof(T)), simd16<T>::load(ptr+3*sizeof(simd16<T>)/sizeof(T))} {}

    simdutf_really_inline void store(T* ptr) const {
      this->chunks[0].store(ptr+sizeof(simd16<T>)*0/sizeof(T));
      this->chunks[1].store(ptr+sizeof(simd16<T>)*1/sizeof(T));
      this->chunks[2].store(ptr+sizeof(simd16<T>)*2/sizeof(T));
      this->chunks[3].store(ptr+sizeof(simd16<T>)*3/sizeof(T));
    }

    simdutf_really_inline simd16<T> reduce_or() const {
      return (this->chunks[0] | this->chunks[1]) | (this->chunks[2] | this->chunks[3]);
    }

    simdutf_really_inline bool is_ascii() const {
      return reduce_or().is_ascii();
    }

    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      this->chunks[0].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*0);
      this->chunks[1].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*1);
      this->chunks[2].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*2);
      this->chunks[3].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*3);
    }

    simdutf_really_inline uint64_t to_bitmask() const {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
      const uint8x16_t bit_mask = make_uint8x16_t(
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80
      );
#else
      const uint8x16_t bit_mask = {
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
        0x01, 0x02, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80
      };
#endif
      uint8x16_t sum0 = vpaddq_u8(vreinterpretq_u8_u16(this->chunks[0] & vreinterpretq_u16_u8(bit_mask)), vreinterpretq_u8_u16(this->chunks[1] & vreinterpretq_u16_u8(bit_mask)));
      uint8x16_t sum1 = vpaddq_u8(vreinterpretq_u8_u16(this->chunks[2] & vreinterpretq_u16_u8(bit_mask)), vreinterpretq_u8_u16(this->chunks[3] & vreinterpretq_u16_u8(bit_mask)));
      sum0 = vpaddq_u8(sum0, sum1);
      sum0 = vpaddq_u8(sum0, sum0);
      return vgetq_lane_u64(vreinterpretq_u64_u8(sum0), 0);
    }

    simdutf_really_inline void swap_bytes() {
      this->chunks[0] = this->chunks[0].swap_bytes();
      this->chunks[1] = this->chunks[1].swap_bytes();
      this->chunks[2] = this->chunks[2].swap_bytes();
      this->chunks[3] = this->chunks[3].swap_bytes();
    }

    simdutf_really_inline uint64_t eq(const T m) const {
    const simd16<T> mask = simd16<T>::splat(m);
    return  simd16x32<bool>(
      this->chunks[0] == mask,
      this->chunks[1] == mask,
      this->chunks[2] == mask,
      this->chunks[3] == mask
    ).to_bitmask();
  }

  simdutf_really_inline uint64_t lteq(const T m) const {
    const simd16<T> mask = simd16<T>::splat(m);
    return  simd16x32<bool>(
      this->chunks[0] <= mask,
      this->chunks[1] <= mask,
      this->chunks[2] <= mask,
      this->chunks[3] <= mask
    ).to_bitmask();
  }

    simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd16<T> mask_low = simd16<T>::splat(low);
      const simd16<T> mask_high = simd16<T>::splat(high);

      return  simd16x32<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd16<T> mask_low = simd16<T>::splat(low);
      const simd16<T> mask_high = simd16<T>::splat(high);
      return  simd16x32<bool>(
        (this->chunks[0] > mask_high) | (this->chunks[0] < mask_low),
        (this->chunks[1] > mask_high) | (this->chunks[1] < mask_low),
        (this->chunks[2] > mask_high) | (this->chunks[2] < mask_low),
        (this->chunks[3] > mask_high) | (this->chunks[3] < mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t lt(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] < mask,
        this->chunks[1] < mask,
        this->chunks[2] < mask,
        this->chunks[3] < mask
      ).to_bitmask();
    }

  }; // struct simd16x32<T>
  template<>
  simdutf_really_inline uint64_t simd16x32<uint16_t>::not_in_range(const uint16_t low, const uint16_t high) const {
      const simd16<uint16_t> mask_low = simd16<uint16_t>::splat(low);
      const simd16<uint16_t> mask_high = simd16<uint16_t>::splat(high);
      simd16x32<uint16_t> x(
        simd16<uint16_t>((this->chunks[0] > mask_high) | (this->chunks[0] < mask_low)),
        simd16<uint16_t>((this->chunks[1] > mask_high) | (this->chunks[1] < mask_low)),
        simd16<uint16_t>((this->chunks[2] > mask_high) | (this->chunks[2] < mask_low)),
        simd16<uint16_t>((this->chunks[3] > mask_high) | (this->chunks[3] < mask_low))
      );
      return  x.to_bitmask();
    }
/* end file src/simdutf/arm64/simd16-inl.h */
} // namespace simd
} // unnamed namespace
} // namespace arm64
} // namespace simdutf

#endif // SIMDUTF_ARM64_SIMD_H
/* end file src/simdutf/arm64/simd.h */

/* begin file src/simdutf/arm64/end.h */
/* end file src/simdutf/arm64/end.h */

#endif // SIMDUTF_IMPLEMENTATION_ARM64

#endif // SIMDUTF_ARM64_H
/* end file src/simdutf/arm64.h */
/* begin file src/simdutf/haswell.h */
#ifndef SIMDUTF_HASWELL_H
#define SIMDUTF_HASWELL_H

#ifdef SIMDUTF_WESTMERE_H
#error "haswell.h must be included before westmere.h"
#endif
#ifdef SIMDUTF_FALLBACK_H
#error "haswell.h must be included before fallback.h"
#endif


#ifndef SIMDUTF_IMPLEMENTATION_HASWELL
#define SIMDUTF_IMPLEMENTATION_HASWELL (SIMDUTF_IS_X86_64)
#endif
#define SIMDUTF_CAN_ALWAYS_RUN_HASWELL ((SIMDUTF_IMPLEMENTATION_HASWELL) && (SIMDUTF_IS_X86_64) && (__AVX2__))

#if SIMDUTF_IMPLEMENTATION_HASWELL

#define SIMDUTF_TARGET_HASWELL SIMDUTF_TARGET_REGION("avx2,bmi,pclmul,lzcnt")

namespace simdutf {
/**
 * Implementation for Haswell (Intel AVX2).
 */
namespace haswell {
} // namespace haswell
} // namespace simdutf

/* begin file src/simdutf/haswell/implementation.h */
#ifndef SIMDUTF_HASWELL_IMPLEMENTATION_H
#define SIMDUTF_HASWELL_IMPLEMENTATION_H


namespace simdutf {
namespace haswell {

using namespace simdutf;

class implementation final : public simdutf::implementation {
public:
  simdutf_really_inline implementation() : simdutf::implementation(
      "haswell",
      "Intel/AMD AVX2",
      internal::instruction_set::AVX2 | internal::instruction_set::PCLMULQDQ | internal::instruction_set::BMI1 | internal::instruction_set::BMI2
  ) {}
  simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  void change_endianness_utf16(const char16_t * buf, size_t length, char16_t * output) const noexcept final;
  simdutf_warn_unused size_t count_utf16le(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf16be(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf8(const char * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) const noexcept;
};

} // namespace haswell
} // namespace simdutf

#endif // SIMDUTF_HASWELL_IMPLEMENTATION_H
/* end file src/simdutf/haswell/implementation.h */
/* begin file src/simdutf/haswell/intrinsics.h */
#ifndef SIMDUTF_HASWELL_INTRINSICS_H
#define SIMDUTF_HASWELL_INTRINSICS_H


#ifdef SIMDUTF_VISUAL_STUDIO
#include <intrin.h>  // visual studio or clang
#else
#include <x86intrin.h> // elsewhere
#endif // SIMDUTF_VISUAL_STUDIO

#ifdef SIMDUTF_CLANG_VISUAL_STUDIO
/**
 * You are not supposed, normally, to include these
 * headers directly. Instead you should either include intrin.h
 * or x86intrin.h. However, when compiling with clang
 * under Windows (i.e., when _MSC_VER is set), these headers
 * only get included *if* the corresponding features are detected
 * from macros:
 * e.g., if __AVX2__ is set... in turn,  we normally set these
 * macros by compiling against the corresponding architecture
 * (e.g., arch:AVX2, -mavx2, etc.) which compiles the whole
 * software with these advanced instructions. In simdutf, we
 * want to compile the whole program for a generic target,
 * and only target our specific kernels. As a workaround,
 * we directly include the needed headers. These headers would
 * normally guard against such usage, but we carefully included
 * <x86intrin.h>  (or <intrin.h>) before, so the headers
 * are fooled.
 */
#include <bmiintrin.h>   // for _blsr_u64
#include <lzcntintrin.h> // for  __lzcnt64
#include <immintrin.h>   // for most things (AVX2, AVX512, _popcnt64)
#include <smmintrin.h>
#include <tmmintrin.h>
#include <avxintrin.h>
#include <avx2intrin.h>
#include <wmmintrin.h>   // for  _mm_clmulepi64_si128
#ifndef _blsr_u64
SIMDUTF_TARGET_HASWELL
static simdutf_really_inline uint64_t _blsr_u64(uint64_t n) {
  return (n - 1) & n;
}
SIMDUTF_UNTARGET_REGION
#endif //  _blsr_u64
#endif // SIMDUTF_CLANG_VISUAL_STUDIO

#endif // SIMDUTF_HASWELL_INTRINSICS_H
/* end file src/simdutf/haswell/intrinsics.h */

/* begin file src/simdutf/haswell/begin.h */
SIMDUTF_TARGET_HASWELL
/* end file src/simdutf/haswell/begin.h */

/* begin file src/simdutf/haswell/bitmanipulation.h */
#ifndef SIMDUTF_HASWELL_BITMANIPULATION_H
#define SIMDUTF_HASWELL_BITMANIPULATION_H

namespace simdutf {
namespace haswell {
namespace {

#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
simdutf_really_inline unsigned __int64 count_ones(uint64_t input_num) {
  return __popcnt64(input_num);// Visual Studio wants two underscores
}
#else
simdutf_really_inline long long int count_ones(uint64_t input_num) {
  return _popcnt64(input_num);
}
#endif

} // unnamed namespace
} // namespace haswell
} // namespace simdutf

#endif // SIMDUTF_HASWELL_BITMANIPULATION_H
/* end file src/simdutf/haswell/bitmanipulation.h */
/* begin file src/simdutf/haswell/simd.h */
#ifndef SIMDUTF_HASWELL_SIMD_H
#define SIMDUTF_HASWELL_SIMD_H


namespace simdutf {
namespace haswell {
namespace {
namespace simd {

  template<typename Child>
  struct base {
    __m256i value;

    simdutf_really_inline base() : value{__m256i()} {}

    simdutf_really_inline base(const __m256i _value) : value(_value) {}
    simdutf_really_inline operator const __m256i&() const { return this->value; }
    simdutf_really_inline operator __m256i&() { return this->value; }
    template <endianness big_endian>
    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      __m256i first = _mm256_cvtepu8_epi16(_mm256_castsi256_si128(*this));
      __m256i second = _mm256_cvtepu8_epi16(_mm256_extractf128_si256(*this,1));
      if (big_endian) {
        const __m256i swap = _mm256_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14,
                                  17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30);
        first = _mm256_shuffle_epi8(first, swap);
        second = _mm256_shuffle_epi8(second, swap);
      }
      _mm256_storeu_si256(reinterpret_cast<__m256i *>(ptr), first);
      _mm256_storeu_si256(reinterpret_cast<__m256i *>(ptr + 16), second);
    }
    simdutf_really_inline void store_ascii_as_utf32(char32_t * ptr) const {
      _mm256_storeu_si256(reinterpret_cast<__m256i *>(ptr), _mm256_cvtepu8_epi32(_mm256_castsi256_si128(*this)));
      _mm256_storeu_si256(reinterpret_cast<__m256i *>(ptr+8), _mm256_cvtepu8_epi32(_mm256_castsi256_si128(_mm256_srli_si256(*this,8))));
      _mm256_storeu_si256(reinterpret_cast<__m256i *>(ptr + 16), _mm256_cvtepu8_epi32(_mm256_extractf128_si256(*this,1)));
      _mm256_storeu_si256(reinterpret_cast<__m256i *>(ptr + 24), _mm256_cvtepu8_epi32(_mm_srli_si128(_mm256_extractf128_si256(*this,1),8)));
    }
    simdutf_really_inline Child operator|(const Child other) const { return _mm256_or_si256(*this, other); }
    simdutf_really_inline Child operator&(const Child other) const { return _mm256_and_si256(*this, other); }
    simdutf_really_inline Child operator^(const Child other) const { return _mm256_xor_si256(*this, other); }
    simdutf_really_inline Child bit_andnot(const Child other) const { return _mm256_andnot_si256(other, *this); }
    simdutf_really_inline Child& operator|=(const Child other) { auto this_cast = static_cast<Child*>(this); *this_cast = *this_cast | other; return *this_cast; }
    simdutf_really_inline Child& operator&=(const Child other) { auto this_cast = static_cast<Child*>(this); *this_cast = *this_cast & other; return *this_cast; }
    simdutf_really_inline Child& operator^=(const Child other) { auto this_cast = static_cast<Child*>(this); *this_cast = *this_cast ^ other; return *this_cast; }
  };

  template<typename T>
  struct simd8;

  template<typename T, typename Mask=simd8<bool>>
  struct base8: base<simd8<T>> {
    typedef uint32_t bitmask_t;
    typedef uint64_t bitmask2_t;

    simdutf_really_inline base8() : base<simd8<T>>() {}
    simdutf_really_inline base8(const __m256i _value) : base<simd8<T>>(_value) {}
    simdutf_really_inline T first() const { return _mm256_extract_epi8(*this,0); }
    simdutf_really_inline T last() const { return _mm256_extract_epi8(*this,31); }
    simdutf_really_inline Mask operator==(const simd8<T> other) const { return _mm256_cmpeq_epi8(*this, other); }

    static const int SIZE = sizeof(base<T>::value);

    template<int N=1>
    simdutf_really_inline simd8<T> prev(const simd8<T> prev_chunk) const {
      return _mm256_alignr_epi8(*this, _mm256_permute2x128_si256(prev_chunk, *this, 0x21), 16 - N);
    }
  };

  template<>
  struct simd8<bool>: base8<bool> {
    static simdutf_really_inline simd8<bool> splat(bool _value) { return _mm256_set1_epi8(uint8_t(-(!!_value))); }

    simdutf_really_inline simd8<bool>() : base8() {}
    simdutf_really_inline simd8<bool>(const __m256i _value) : base8<bool>(_value) {}
    simdutf_really_inline simd8<bool>(bool _value) : base8<bool>(splat(_value)) {}

    simdutf_really_inline uint32_t to_bitmask() const { return uint32_t(_mm256_movemask_epi8(*this)); }
    simdutf_really_inline bool any() const { return !_mm256_testz_si256(*this, *this); }
    simdutf_really_inline bool none() const { return _mm256_testz_si256(*this, *this); }
    simdutf_really_inline bool all() const { return static_cast<uint32_t>(_mm256_movemask_epi8(*this)) == 0xFFFFFFFF; }
    simdutf_really_inline simd8<bool> operator~() const { return *this ^ true; }
  };

  template<typename T>
  struct base8_numeric: base8<T> {
    static simdutf_really_inline simd8<T> splat(T _value) { return _mm256_set1_epi8(_value); }
    static simdutf_really_inline simd8<T> zero() { return _mm256_setzero_si256(); }
    static simdutf_really_inline simd8<T> load(const T values[32]) {
      return _mm256_loadu_si256(reinterpret_cast<const __m256i *>(values));
    }
    static simdutf_really_inline simd8<T> repeat_16(
      T v0,  T v1,  T v2,  T v3,  T v4,  T v5,  T v6,  T v7,
      T v8,  T v9,  T v10, T v11, T v12, T v13, T v14, T v15
    ) {
      return simd8<T>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15,
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }

    simdutf_really_inline base8_numeric() : base8<T>() {}
    simdutf_really_inline base8_numeric(const __m256i _value) : base8<T>(_value) {}

    simdutf_really_inline void store(T dst[32]) const { return _mm256_storeu_si256(reinterpret_cast<__m256i *>(dst), *this); }

    simdutf_really_inline simd8<T> operator+(const simd8<T> other) const { return _mm256_add_epi8(*this, other); }
    simdutf_really_inline simd8<T> operator-(const simd8<T> other) const { return _mm256_sub_epi8(*this, other); }
    simdutf_really_inline simd8<T>& operator+=(const simd8<T> other) { *this = *this + other; return *static_cast<simd8<T>*>(this); }
    simdutf_really_inline simd8<T>& operator-=(const simd8<T> other) { *this = *this - other; return *static_cast<simd8<T>*>(this); }

    simdutf_really_inline simd8<T> operator~() const { return *this ^ 0xFFu; }

    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(simd8<L> lookup_table) const {
      return _mm256_shuffle_epi8(lookup_table, *this);
    }

    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(
        L replace0,  L replace1,  L replace2,  L replace3,
        L replace4,  L replace5,  L replace6,  L replace7,
        L replace8,  L replace9,  L replace10, L replace11,
        L replace12, L replace13, L replace14, L replace15) const {
      return lookup_16(simd8<L>::repeat_16(
        replace0,  replace1,  replace2,  replace3,
        replace4,  replace5,  replace6,  replace7,
        replace8,  replace9,  replace10, replace11,
        replace12, replace13, replace14, replace15
      ));
    }
  };


  template<>
  struct simd8<int8_t> : base8_numeric<int8_t> {
    simdutf_really_inline simd8() : base8_numeric<int8_t>() {}
    simdutf_really_inline simd8(const __m256i _value) : base8_numeric<int8_t>(_value) {}

    simdutf_really_inline simd8(int8_t _value) : simd8(splat(_value)) {}
    simdutf_really_inline simd8(const int8_t values[32]) : simd8(load(values)) {}
    simdutf_really_inline operator simd8<uint8_t>() const;
    simdutf_really_inline simd8(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3,  int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15,
      int8_t v16, int8_t v17, int8_t v18, int8_t v19, int8_t v20, int8_t v21, int8_t v22, int8_t v23,
      int8_t v24, int8_t v25, int8_t v26, int8_t v27, int8_t v28, int8_t v29, int8_t v30, int8_t v31
    ) : simd8(_mm256_setr_epi8(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15,
      v16,v17,v18,v19,v20,v21,v22,v23,
      v24,v25,v26,v27,v28,v29,v30,v31
    )) {}
    simdutf_really_inline static simd8<int8_t> repeat_16(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3,  int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) {
      return simd8<int8_t>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15,
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }
    simdutf_really_inline bool is_ascii() const { return _mm256_movemask_epi8(*this) == 0; }
    simdutf_really_inline simd8<int8_t> max_val(const simd8<int8_t> other) const { return _mm256_max_epi8(*this, other); }
    simdutf_really_inline simd8<int8_t> min_val(const simd8<int8_t> other) const { return _mm256_min_epi8(*this, other); }
    simdutf_really_inline simd8<bool> operator>(const simd8<int8_t> other) const { return _mm256_cmpgt_epi8(*this, other); }
    simdutf_really_inline simd8<bool> operator<(const simd8<int8_t> other) const { return _mm256_cmpgt_epi8(other, *this); }
  };

  template<>
  struct simd8<uint8_t>: base8_numeric<uint8_t> {
    simdutf_really_inline simd8() : base8_numeric<uint8_t>() {}
    simdutf_really_inline simd8(const __m256i _value) : base8_numeric<uint8_t>(_value) {}
    simdutf_really_inline simd8(uint8_t _value) : simd8(splat(_value)) {}
    simdutf_really_inline simd8(const uint8_t values[32]) : simd8(load(values)) {}
    simdutf_really_inline simd8(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15,
      uint8_t v16, uint8_t v17, uint8_t v18, uint8_t v19, uint8_t v20, uint8_t v21, uint8_t v22, uint8_t v23,
      uint8_t v24, uint8_t v25, uint8_t v26, uint8_t v27, uint8_t v28, uint8_t v29, uint8_t v30, uint8_t v31
    ) : simd8(_mm256_setr_epi8(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15,
      v16,v17,v18,v19,v20,v21,v22,v23,
      v24,v25,v26,v27,v28,v29,v30,v31
    )) {}
    simdutf_really_inline static simd8<uint8_t> repeat_16(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) {
      return simd8<uint8_t>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15,
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }


    simdutf_really_inline simd8<uint8_t> saturating_add(const simd8<uint8_t> other) const { return _mm256_adds_epu8(*this, other); }
    simdutf_really_inline simd8<uint8_t> saturating_sub(const simd8<uint8_t> other) const { return _mm256_subs_epu8(*this, other); }

    simdutf_really_inline simd8<uint8_t> max_val(const simd8<uint8_t> other) const { return _mm256_max_epu8(*this, other); }
    simdutf_really_inline simd8<uint8_t> min_val(const simd8<uint8_t> other) const { return _mm256_min_epu8(other, *this); }
    simdutf_really_inline simd8<uint8_t> gt_bits(const simd8<uint8_t> other) const { return this->saturating_sub(other); }
    simdutf_really_inline simd8<uint8_t> lt_bits(const simd8<uint8_t> other) const { return other.saturating_sub(*this); }
    simdutf_really_inline simd8<bool> operator<=(const simd8<uint8_t> other) const { return other.max_val(*this) == other; }
    simdutf_really_inline simd8<bool> operator>=(const simd8<uint8_t> other) const { return other.min_val(*this) == other; }
    simdutf_really_inline simd8<bool> operator>(const simd8<uint8_t> other) const { return this->gt_bits(other).any_bits_set(); }
    simdutf_really_inline simd8<bool> operator<(const simd8<uint8_t> other) const { return this->lt_bits(other).any_bits_set(); }

    simdutf_really_inline simd8<bool> bits_not_set() const { return *this == uint8_t(0); }
    simdutf_really_inline simd8<bool> bits_not_set(simd8<uint8_t> bits) const { return (*this & bits).bits_not_set(); }
    simdutf_really_inline simd8<bool> any_bits_set() const { return ~this->bits_not_set(); }
    simdutf_really_inline simd8<bool> any_bits_set(simd8<uint8_t> bits) const { return ~this->bits_not_set(bits); }
    simdutf_really_inline bool is_ascii() const { return _mm256_movemask_epi8(*this) == 0; }
    simdutf_really_inline bool bits_not_set_anywhere() const { return _mm256_testz_si256(*this, *this); }
    simdutf_really_inline bool any_bits_set_anywhere() const { return !bits_not_set_anywhere(); }
    simdutf_really_inline bool bits_not_set_anywhere(simd8<uint8_t> bits) const { return _mm256_testz_si256(*this, bits); }
    simdutf_really_inline bool any_bits_set_anywhere(simd8<uint8_t> bits) const { return !bits_not_set_anywhere(bits); }
    template<int N>
    simdutf_really_inline simd8<uint8_t> shr() const { return simd8<uint8_t>(_mm256_srli_epi16(*this, N)) & uint8_t(0xFFu >> N); }
    template<int N>
    simdutf_really_inline simd8<uint8_t> shl() const { return simd8<uint8_t>(_mm256_slli_epi16(*this, N)) & uint8_t(0xFFu << N); }
    template<int N>
    simdutf_really_inline int get_bit() const { return _mm256_movemask_epi8(_mm256_slli_epi16(*this, 7-N)); }
  };
  simdutf_really_inline simd8<int8_t>::operator simd8<uint8_t>() const { return this->value; }


  template<typename T>
  struct simd8x64 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd8<T>);
    static_assert(NUM_CHUNKS == 2, "Haswell kernel should use two registers per 64-byte block.");
    simd8<T> chunks[NUM_CHUNKS];

    simd8x64(const simd8x64<T>& o) = delete; // no copy allowed
    simd8x64<T>& operator=(const simd8<T> other) = delete; // no assignment allowed
    simd8x64() = delete; // no default constructor allowed

    simdutf_really_inline simd8x64(const simd8<T> chunk0, const simd8<T> chunk1) : chunks{chunk0, chunk1} {}
    simdutf_really_inline simd8x64(const T* ptr) : chunks{simd8<T>::load(ptr), simd8<T>::load(ptr+sizeof(simd8<T>)/sizeof(T))} {}

    simdutf_really_inline void store(T* ptr) const {
      this->chunks[0].store(ptr+sizeof(simd8<T>)*0/sizeof(T));
      this->chunks[1].store(ptr+sizeof(simd8<T>)*1/sizeof(T));
    }

    simdutf_really_inline uint64_t to_bitmask() const {
      uint64_t r_lo = uint32_t(this->chunks[0].to_bitmask());
      uint64_t r_hi =                       this->chunks[1].to_bitmask();
      return r_lo | (r_hi << 32);
    }

    simdutf_really_inline simd8x64<T>& operator|=(const simd8x64<T> &other) {
      this->chunks[0] |= other.chunks[0];
      this->chunks[1] |= other.chunks[1];
      return *this;
    }

    simdutf_really_inline simd8<T> reduce_or() const {
      return this->chunks[0] | this->chunks[1];
    }

    simdutf_really_inline bool is_ascii() const {
      return this->reduce_or().is_ascii();
    }

    template <endianness endian>
    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      this->chunks[0].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*0);
      this->chunks[1].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*1);
    }

    simdutf_really_inline void store_ascii_as_utf32(char32_t * ptr) const {
      this->chunks[0].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*0);
      this->chunks[1].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*1);
    }

    simdutf_really_inline simd8x64<T> bit_or(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return simd8x64<T>(
        this->chunks[0] | mask,
        this->chunks[1] | mask
      );
    }

    simdutf_really_inline uint64_t eq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] == mask,
        this->chunks[1] == mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t eq(const simd8x64<uint8_t> &other) const {
      return  simd8x64<bool>(
        this->chunks[0] == other.chunks[0],
        this->chunks[1] == other.chunks[1]
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t lteq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] <= mask,
        this->chunks[1] <= mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);

      return  simd8x64<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);
      return  simd8x64<bool>(
        (this->chunks[0] > mask_high) | (this->chunks[0] < mask_low),
        (this->chunks[1] > mask_high) | (this->chunks[1] < mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t lt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] < mask,
        this->chunks[1] < mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t gt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] > mask,
        this->chunks[1] > mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gteq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] >= mask,
        this->chunks[1] >= mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gteq_unsigned(const uint8_t m) const {
      const simd8<uint8_t> mask = simd8<uint8_t>::splat(m);
      return  simd8x64<bool>(
        (simd8<uint8_t>(__m256i(this->chunks[0])) >= mask),
        (simd8<uint8_t>(__m256i(this->chunks[1])) >= mask)
      ).to_bitmask();
    }
  }; // struct simd8x64<T>

/* begin file src/simdutf/haswell/simd16-inl.h */
#ifdef __GNUC__
#if __GNUC__ < 8
#define _mm256_set_m128i(xmm1, xmm2) _mm256_permute2f128_si256(_mm256_castsi128_si256(xmm1), _mm256_castsi128_si256(xmm2), 2)
#define _mm256_setr_m128i(xmm2, xmm1)  _mm256_permute2f128_si256(_mm256_castsi128_si256(xmm1), _mm256_castsi128_si256(xmm2), 2)
#endif
#endif

template<typename T>
struct simd16;

template<typename T, typename Mask=simd16<bool>>
struct base16: base<simd16<T>> {
  using bitmask_type = uint32_t;

  simdutf_really_inline base16() : base<simd16<T>>() {}
  simdutf_really_inline base16(const __m256i _value) : base<simd16<T>>(_value) {}
  template <typename Pointer>
  simdutf_really_inline base16(const Pointer* ptr) : base16(_mm256_loadu_si256(reinterpret_cast<const __m256i*>(ptr))) {}

  simdutf_really_inline Mask operator==(const simd16<T> other) const { return _mm256_cmpeq_epi16(*this, other); }

  static const int SIZE = sizeof(base<simd16<T>>::value);

  static const int ELEMENTS = SIZE / sizeof(T);

  template<int N=1>
  simdutf_really_inline simd16<T> prev(const simd16<T> prev_chunk) const {
    return _mm256_alignr_epi8(*this, prev_chunk, 16 - N);
  }
};

template<>
struct simd16<bool>: base16<bool> {
  static simdutf_really_inline simd16<bool> splat(bool _value) { return _mm256_set1_epi16(uint16_t(-(!!_value))); }

  simdutf_really_inline simd16<bool>() : base16() {}
  simdutf_really_inline simd16<bool>(const __m256i _value) : base16<bool>(_value) {}
  simdutf_really_inline simd16<bool>(bool _value) : base16<bool>(splat(_value)) {}

  simdutf_really_inline bitmask_type to_bitmask() const { return _mm256_movemask_epi8(*this); }
  simdutf_really_inline bool any() const { return !_mm256_testz_si256(*this, *this); }
  simdutf_really_inline simd16<bool> operator~() const { return *this ^ true; }
};

template<typename T>
struct base16_numeric: base16<T> {
  static simdutf_really_inline simd16<T> splat(T _value) { return _mm256_set1_epi16(_value); }
  static simdutf_really_inline simd16<T> zero() { return _mm256_setzero_si256(); }
  static simdutf_really_inline simd16<T> load(const T values[8]) {
    return _mm256_loadu_si256(reinterpret_cast<const __m256i *>(values));
  }

  simdutf_really_inline base16_numeric() : base16<T>() {}
  simdutf_really_inline base16_numeric(const __m256i _value) : base16<T>(_value) {}

  simdutf_really_inline void store(T dst[8]) const { return _mm256_storeu_si256(reinterpret_cast<__m256i *>(dst), *this); }

  simdutf_really_inline simd16<T> operator~() const { return *this ^ 0xFFFFu; }

  simdutf_really_inline simd16<T> operator+(const simd16<T> other) const { return _mm256_add_epi16(*this, other); }
  simdutf_really_inline simd16<T> operator-(const simd16<T> other) const { return _mm256_sub_epi16(*this, other); }
  simdutf_really_inline simd16<T>& operator+=(const simd16<T> other) { *this = *this + other; return *static_cast<simd16<T>*>(this); }
  simdutf_really_inline simd16<T>& operator-=(const simd16<T> other) { *this = *this - other; return *static_cast<simd16<T>*>(this); }
};

template<>
struct simd16<int16_t> : base16_numeric<int16_t> {
  simdutf_really_inline simd16() : base16_numeric<int16_t>() {}
  simdutf_really_inline simd16(const __m256i _value) : base16_numeric<int16_t>(_value) {}
  simdutf_really_inline simd16(int16_t _value) : simd16(splat(_value)) {}
  simdutf_really_inline simd16(const int16_t* values) : simd16(load(values)) {}
  simdutf_really_inline simd16(const char16_t* values) : simd16(load(reinterpret_cast<const int16_t*>(values))) {}
  simdutf_really_inline simd16<int16_t> max_val(const simd16<int16_t> other) const { return _mm256_max_epi16(*this, other); }
  simdutf_really_inline simd16<int16_t> min_val(const simd16<int16_t> other) const { return _mm256_min_epi16(*this, other); }
  simdutf_really_inline simd16<bool> operator>(const simd16<int16_t> other) const { return _mm256_cmpgt_epi16(*this, other); }
  simdutf_really_inline simd16<bool> operator<(const simd16<int16_t> other) const { return _mm256_cmpgt_epi16(other, *this); }
};

template<>
struct simd16<uint16_t>: base16_numeric<uint16_t>  {
  simdutf_really_inline simd16() : base16_numeric<uint16_t>() {}
  simdutf_really_inline simd16(const __m256i _value) : base16_numeric<uint16_t>(_value) {}

  simdutf_really_inline simd16(uint16_t _value) : simd16(splat(_value)) {}
  simdutf_really_inline simd16(const uint16_t* values) : simd16(load(values)) {}
  simdutf_really_inline simd16(const char16_t* values) : simd16(load(reinterpret_cast<const uint16_t*>(values))) {}

  simdutf_really_inline simd16<uint16_t> saturating_add(const simd16<uint16_t> other) const { return _mm256_adds_epu16(*this, other); }
  simdutf_really_inline simd16<uint16_t> saturating_sub(const simd16<uint16_t> other) const { return _mm256_subs_epu16(*this, other); }

  simdutf_really_inline simd16<uint16_t> max_val(const simd16<uint16_t> other) const { return _mm256_max_epu16(*this, other); }
  simdutf_really_inline simd16<uint16_t> min_val(const simd16<uint16_t> other) const { return _mm256_min_epu16(*this, other); }
  simdutf_really_inline simd16<uint16_t> gt_bits(const simd16<uint16_t> other) const { return this->saturating_sub(other); }
  simdutf_really_inline simd16<uint16_t> lt_bits(const simd16<uint16_t> other) const { return other.saturating_sub(*this); }
  simdutf_really_inline simd16<bool> operator<=(const simd16<uint16_t> other) const { return other.max_val(*this) == other; }
  simdutf_really_inline simd16<bool> operator>=(const simd16<uint16_t> other) const { return other.min_val(*this) == other; }
  simdutf_really_inline simd16<bool> operator>(const simd16<uint16_t> other) const { return this->gt_bits(other).any_bits_set(); }
  simdutf_really_inline simd16<bool> operator<(const simd16<uint16_t> other) const { return this->gt_bits(other).any_bits_set(); }

  simdutf_really_inline simd16<bool> bits_not_set() const { return *this == uint16_t(0); }
  simdutf_really_inline simd16<bool> bits_not_set(simd16<uint16_t> bits) const { return (*this & bits).bits_not_set(); }
  simdutf_really_inline simd16<bool> any_bits_set() const { return ~this->bits_not_set(); }
  simdutf_really_inline simd16<bool> any_bits_set(simd16<uint16_t> bits) const { return ~this->bits_not_set(bits); }

  simdutf_really_inline bool bits_not_set_anywhere() const { return _mm256_testz_si256(*this, *this); }
  simdutf_really_inline bool any_bits_set_anywhere() const { return !bits_not_set_anywhere(); }
  simdutf_really_inline bool bits_not_set_anywhere(simd16<uint16_t> bits) const { return _mm256_testz_si256(*this, bits); }
  simdutf_really_inline bool any_bits_set_anywhere(simd16<uint16_t> bits) const { return !bits_not_set_anywhere(bits); }
  template<int N>
  simdutf_really_inline simd16<uint16_t> shr() const { return simd16<uint16_t>(_mm256_srli_epi16(*this, N)); }
  template<int N>
  simdutf_really_inline simd16<uint16_t> shl() const { return simd16<uint16_t>(_mm256_slli_epi16(*this, N)); }
  template<int N>
  simdutf_really_inline int get_bit() const { return _mm256_movemask_epi8(_mm256_slli_epi16(*this, 15-N)); }

  simdutf_really_inline simd16<uint16_t> swap_bytes() const {
    const __m256i swap = _mm256_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14,
                                  17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30);
    return _mm256_shuffle_epi8(*this, swap);
  }

  static simdutf_really_inline simd8<uint8_t> pack(const simd16<uint16_t>& v0, const simd16<uint16_t>& v1) {

    const __m128i lo_0 = _mm256_extracti128_si256(v0, 0);
    const __m128i lo_1 = _mm256_extracti128_si256(v1, 0);

    const __m128i hi_0 = _mm256_extracti128_si256(v0, 1);
    const __m128i hi_1 = _mm256_extracti128_si256(v1, 1);

    const __m256i t0 = _mm256_set_m128i(lo_1, lo_0);
    const __m256i t1 = _mm256_set_m128i(hi_1, hi_0);

    return _mm256_packus_epi16(t0, t1);
  }
};


  template<typename T>
  struct simd16x32 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd16<T>);
    static_assert(NUM_CHUNKS == 2, "Haswell kernel should use two registers per 64-byte block.");
    simd16<T> chunks[NUM_CHUNKS];

    simd16x32(const simd16x32<T>& o) = delete; // no copy allowed
    simd16x32<T>& operator=(const simd16<T> other) = delete; // no assignment allowed
    simd16x32() = delete; // no default constructor allowed

    simdutf_really_inline simd16x32(const simd16<T> chunk0, const simd16<T> chunk1) : chunks{chunk0, chunk1} {}
    simdutf_really_inline simd16x32(const T* ptr) : chunks{simd16<T>::load(ptr), simd16<T>::load(ptr+sizeof(simd16<T>)/sizeof(T))} {}

    simdutf_really_inline void store(T* ptr) const {
      this->chunks[0].store(ptr+sizeof(simd16<T>)*0/sizeof(T));
      this->chunks[1].store(ptr+sizeof(simd16<T>)*1/sizeof(T));
    }

    simdutf_really_inline uint64_t to_bitmask() const {
      uint64_t r_lo = uint32_t(this->chunks[0].to_bitmask());
      uint64_t r_hi =                       this->chunks[1].to_bitmask();
      return r_lo | (r_hi << 32);
    }

    simdutf_really_inline simd16<T> reduce_or() const {
      return this->chunks[0] | this->chunks[1];
    }

    simdutf_really_inline bool is_ascii() const {
      return this->reduce_or().is_ascii();
    }

    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      this->chunks[0].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*0);
      this->chunks[1].store_ascii_as_utf16(ptr+sizeof(simd16<T>));
    }

    simdutf_really_inline simd16x32<T> bit_or(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return simd16x32<T>(
        this->chunks[0] | mask,
        this->chunks[1] | mask
      );
    }

    simdutf_really_inline void swap_bytes() {
      this->chunks[0] = this->chunks[0].swap_bytes();
      this->chunks[1] = this->chunks[1].swap_bytes();
    }

    simdutf_really_inline uint64_t eq(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] == mask,
        this->chunks[1] == mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t eq(const simd16x32<uint16_t> &other) const {
      return  simd16x32<bool>(
        this->chunks[0] == other.chunks[0],
        this->chunks[1] == other.chunks[1]
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t lteq(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] <= mask,
        this->chunks[1] <= mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd16<T> mask_low = simd16<T>::splat(low);
      const simd16<T> mask_high = simd16<T>::splat(high);

      return  simd16x32<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd16<T> mask_low = simd16<T>::splat(static_cast<T>(low-1));
      const simd16<T> mask_high = simd16<T>::splat(static_cast<T>(high+1));
      return simd16x32<bool>(
        (this->chunks[0] >= mask_high) | (this->chunks[0] <= mask_low),
        (this->chunks[1] >= mask_high) | (this->chunks[1] <= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t lt(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] < mask,
        this->chunks[1] < mask
      ).to_bitmask();
    }
  }; // struct simd16x32<T>
/* end file src/simdutf/haswell/simd16-inl.h */

} // namespace simd

} // unnamed namespace
} // namespace haswell
} // namespace simdutf

#endif // SIMDUTF_HASWELL_SIMD_H
/* end file src/simdutf/haswell/simd.h */

/* begin file src/simdutf/haswell/end.h */
SIMDUTF_UNTARGET_REGION
/* end file src/simdutf/haswell/end.h */

#endif // SIMDUTF_IMPLEMENTATION_HASWELL
#endif // SIMDUTF_HASWELL_COMMON_H
/* end file src/simdutf/haswell.h */
/* begin file src/simdutf/westmere.h */
#ifndef SIMDUTF_WESTMERE_H
#define SIMDUTF_WESTMERE_H

#ifdef SIMDUTF_FALLBACK_H
#error "westmere.h must be included before fallback.h"
#endif


#ifndef SIMDUTF_IMPLEMENTATION_WESTMERE
#define SIMDUTF_IMPLEMENTATION_WESTMERE (SIMDUTF_IS_X86_64)
#endif
#define SIMDUTF_CAN_ALWAYS_RUN_WESTMERE (SIMDUTF_IMPLEMENTATION_WESTMERE && SIMDUTF_IS_X86_64 && __SSE4_2__ && __PCLMUL__)

#if SIMDUTF_IMPLEMENTATION_WESTMERE

#define SIMDUTF_TARGET_WESTMERE SIMDUTF_TARGET_REGION("sse4.2,pclmul")

namespace simdutf {
/**
 * Implementation for Westmere (Intel SSE4.2).
 */
namespace westmere {
} // namespace westmere
} // namespace simdutf

/* begin file src/simdutf/westmere/implementation.h */
#ifndef SIMDUTF_WESTMERE_IMPLEMENTATION_H
#define SIMDUTF_WESTMERE_IMPLEMENTATION_H


namespace simdutf {
namespace westmere {

namespace {
using namespace simdutf;
}

class implementation final : public simdutf::implementation {
public:
  simdutf_really_inline implementation() : simdutf::implementation("westmere", "Intel/AMD SSE4.2", internal::instruction_set::SSE42 | internal::instruction_set::PCLMULQDQ) {}
  simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  void change_endianness_utf16(const char16_t * buf, size_t length, char16_t * output) const noexcept final;
  simdutf_warn_unused size_t count_utf16le(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf16be(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf8(const char * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) const noexcept;
};

} // namespace westmere
} // namespace simdutf

#endif // SIMDUTF_WESTMERE_IMPLEMENTATION_H
/* end file src/simdutf/westmere/implementation.h */
/* begin file src/simdutf/westmere/intrinsics.h */
#ifndef SIMDUTF_WESTMERE_INTRINSICS_H
#define SIMDUTF_WESTMERE_INTRINSICS_H

#ifdef SIMDUTF_VISUAL_STUDIO
#include <intrin.h> // visual studio or clang
#else
#include <x86intrin.h> // elsewhere
#endif // SIMDUTF_VISUAL_STUDIO


#ifdef SIMDUTF_CLANG_VISUAL_STUDIO
/**
 * You are not supposed, normally, to include these
 * headers directly. Instead you should either include intrin.h
 * or x86intrin.h. However, when compiling with clang
 * under Windows (i.e., when _MSC_VER is set), these headers
 * only get included *if* the corresponding features are detected
 * from macros:
 */
#include <smmintrin.h>  // for _mm_alignr_epi8
#include <wmmintrin.h>  // for  _mm_clmulepi64_si128
#endif



#endif // SIMDUTF_WESTMERE_INTRINSICS_H
/* end file src/simdutf/westmere/intrinsics.h */

/* begin file src/simdutf/westmere/begin.h */
SIMDUTF_TARGET_WESTMERE
/* end file src/simdutf/westmere/begin.h */

/* begin file src/simdutf/westmere/bitmanipulation.h */
#ifndef SIMDUTF_WESTMERE_BITMANIPULATION_H
#define SIMDUTF_WESTMERE_BITMANIPULATION_H

namespace simdutf {
namespace westmere {
namespace {

#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
simdutf_really_inline unsigned __int64 count_ones(uint64_t input_num) {
  return __popcnt64(input_num);// Visual Studio wants two underscores
}
#else
simdutf_really_inline long long int count_ones(uint64_t input_num) {
  return _popcnt64(input_num);
}
#endif

} // unnamed namespace
} // namespace westmere
} // namespace simdutf

#endif // SIMDUTF_WESTMERE_BITMANIPULATION_H
/* end file src/simdutf/westmere/bitmanipulation.h */
/* begin file src/simdutf/westmere/simd.h */
#ifndef SIMDUTF_WESTMERE_SIMD_H
#define SIMDUTF_WESTMERE_SIMD_H

namespace simdutf {
namespace westmere {
namespace {
namespace simd {

  template<typename Child>
  struct base {
    __m128i value;

    simdutf_really_inline base() : value{__m128i()} {}

    simdutf_really_inline base(const __m128i _value) : value(_value) {}
    simdutf_really_inline operator const __m128i&() const { return this->value; }
    simdutf_really_inline operator __m128i&() { return this->value; }
    template <endianness big_endian>
    simdutf_really_inline void store_ascii_as_utf16(char16_t * p) const {
      __m128i first = _mm_cvtepu8_epi16(*this);
      __m128i second = _mm_cvtepu8_epi16(_mm_srli_si128(*this,8));
      if (big_endian) {
        const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
        first = _mm_shuffle_epi8(first, swap);
        second = _mm_shuffle_epi8(second, swap);
      }
      _mm_storeu_si128(reinterpret_cast<__m128i *>(p), first);
      _mm_storeu_si128(reinterpret_cast<__m128i *>(p+8), second);
    }
    simdutf_really_inline void store_ascii_as_utf32(char32_t * p) const {
      _mm_storeu_si128(reinterpret_cast<__m128i *>(p), _mm_cvtepu8_epi32(*this));
      _mm_storeu_si128(reinterpret_cast<__m128i *>(p+4), _mm_cvtepu8_epi32(_mm_srli_si128(*this,4)));
      _mm_storeu_si128(reinterpret_cast<__m128i *>(p+8), _mm_cvtepu8_epi32(_mm_srli_si128(*this,8)));
      _mm_storeu_si128(reinterpret_cast<__m128i *>(p+12), _mm_cvtepu8_epi32(_mm_srli_si128(*this,12)));
    }
    simdutf_really_inline Child operator|(const Child other) const { return _mm_or_si128(*this, other); }
    simdutf_really_inline Child operator&(const Child other) const { return _mm_and_si128(*this, other); }
    simdutf_really_inline Child operator^(const Child other) const { return _mm_xor_si128(*this, other); }
    simdutf_really_inline Child bit_andnot(const Child other) const { return _mm_andnot_si128(other, *this); }
    simdutf_really_inline Child& operator|=(const Child other) { auto this_cast = static_cast<Child*>(this); *this_cast = *this_cast | other; return *this_cast; }
    simdutf_really_inline Child& operator&=(const Child other) { auto this_cast = static_cast<Child*>(this); *this_cast = *this_cast & other; return *this_cast; }
    simdutf_really_inline Child& operator^=(const Child other) { auto this_cast = static_cast<Child*>(this); *this_cast = *this_cast ^ other; return *this_cast; }
  };

  template<typename T>
  struct simd8;

  template<typename T, typename Mask=simd8<bool>>
  struct base8: base<simd8<T>> {
    typedef uint16_t bitmask_t;
    typedef uint32_t bitmask2_t;

    simdutf_really_inline T first() const { return _mm_extract_epi8(*this,0); }
    simdutf_really_inline T last() const { return _mm_extract_epi8(*this,15); }
    simdutf_really_inline base8() : base<simd8<T>>() {}
    simdutf_really_inline base8(const __m128i _value) : base<simd8<T>>(_value) {}

    simdutf_really_inline Mask operator==(const simd8<T> other) const { return _mm_cmpeq_epi8(*this, other); }

    static const int SIZE = sizeof(base<simd8<T>>::value);

    template<int N=1>
    simdutf_really_inline simd8<T> prev(const simd8<T> prev_chunk) const {
      return _mm_alignr_epi8(*this, prev_chunk, 16 - N);
    }
  };

  template<>
  struct simd8<bool>: base8<bool> {
    static simdutf_really_inline simd8<bool> splat(bool _value) { return _mm_set1_epi8(uint8_t(-(!!_value))); }

    simdutf_really_inline simd8<bool>() : base8() {}
    simdutf_really_inline simd8<bool>(const __m128i _value) : base8<bool>(_value) {}
    simdutf_really_inline simd8<bool>(bool _value) : base8<bool>(splat(_value)) {}

    simdutf_really_inline int to_bitmask() const { return _mm_movemask_epi8(*this); }
    simdutf_really_inline bool any() const { return !_mm_testz_si128(*this, *this); }
    simdutf_really_inline bool none() const { return _mm_testz_si128(*this, *this); }
    simdutf_really_inline bool all() const { return _mm_movemask_epi8(*this) == 0xFFFF; }
    simdutf_really_inline simd8<bool> operator~() const { return *this ^ true; }
  };

  template<typename T>
  struct base8_numeric: base8<T> {
    static simdutf_really_inline simd8<T> splat(T _value) { return _mm_set1_epi8(_value); }
    static simdutf_really_inline simd8<T> zero() { return _mm_setzero_si128(); }
    static simdutf_really_inline simd8<T> load(const T values[16]) {
      return _mm_loadu_si128(reinterpret_cast<const __m128i *>(values));
    }
    static simdutf_really_inline simd8<T> repeat_16(
      T v0,  T v1,  T v2,  T v3,  T v4,  T v5,  T v6,  T v7,
      T v8,  T v9,  T v10, T v11, T v12, T v13, T v14, T v15
    ) {
      return simd8<T>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }

    simdutf_really_inline base8_numeric() : base8<T>() {}
    simdutf_really_inline base8_numeric(const __m128i _value) : base8<T>(_value) {}

    simdutf_really_inline void store(T dst[16]) const { return _mm_storeu_si128(reinterpret_cast<__m128i *>(dst), *this); }

    simdutf_really_inline simd8<T> operator~() const { return *this ^ 0xFFu; }

    simdutf_really_inline simd8<T> operator+(const simd8<T> other) const { return _mm_add_epi8(*this, other); }
    simdutf_really_inline simd8<T> operator-(const simd8<T> other) const { return _mm_sub_epi8(*this, other); }
    simdutf_really_inline simd8<T>& operator+=(const simd8<T> other) { *this = *this + other; return *static_cast<simd8<T>*>(this); }
    simdutf_really_inline simd8<T>& operator-=(const simd8<T> other) { *this = *this - other; return *static_cast<simd8<T>*>(this); }

    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(simd8<L> lookup_table) const {
      return _mm_shuffle_epi8(lookup_table, *this);
    }

    template<typename L>
    simdutf_really_inline simd8<L> lookup_16(
        L replace0,  L replace1,  L replace2,  L replace3,
        L replace4,  L replace5,  L replace6,  L replace7,
        L replace8,  L replace9,  L replace10, L replace11,
        L replace12, L replace13, L replace14, L replace15) const {
      return lookup_16(simd8<L>::repeat_16(
        replace0,  replace1,  replace2,  replace3,
        replace4,  replace5,  replace6,  replace7,
        replace8,  replace9,  replace10, replace11,
        replace12, replace13, replace14, replace15
      ));
    }
  };

  template<>
  struct simd8<int8_t> : base8_numeric<int8_t> {
    simdutf_really_inline simd8() : base8_numeric<int8_t>() {}
    simdutf_really_inline simd8(const __m128i _value) : base8_numeric<int8_t>(_value) {}
    simdutf_really_inline simd8(int8_t _value) : simd8(splat(_value)) {}
    simdutf_really_inline simd8(const int8_t* values) : simd8(load(values)) {}
    simdutf_really_inline simd8(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3,  int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) : simd8(_mm_setr_epi8(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    )) {}
    simdutf_really_inline static simd8<int8_t> repeat_16(
      int8_t v0,  int8_t v1,  int8_t v2,  int8_t v3,  int8_t v4,  int8_t v5,  int8_t v6,  int8_t v7,
      int8_t v8,  int8_t v9,  int8_t v10, int8_t v11, int8_t v12, int8_t v13, int8_t v14, int8_t v15
    ) {
      return simd8<int8_t>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }
    simdutf_really_inline operator simd8<uint8_t>() const;
    simdutf_really_inline bool is_ascii() const { return _mm_movemask_epi8(*this) == 0; }

    simdutf_really_inline simd8<int8_t> max_val(const simd8<int8_t> other) const { return _mm_max_epi8(*this, other); }
    simdutf_really_inline simd8<int8_t> min_val(const simd8<int8_t> other) const { return _mm_min_epi8(*this, other); }
    simdutf_really_inline simd8<bool> operator>(const simd8<int8_t> other) const { return _mm_cmpgt_epi8(*this, other); }
    simdutf_really_inline simd8<bool> operator<(const simd8<int8_t> other) const { return _mm_cmpgt_epi8(other, *this); }
  };

  template<>
  struct simd8<uint8_t>: base8_numeric<uint8_t>  {
    simdutf_really_inline simd8() : base8_numeric<uint8_t>() {}
    simdutf_really_inline simd8(const __m128i _value) : base8_numeric<uint8_t>(_value) {}

    simdutf_really_inline simd8(uint8_t _value) : simd8(splat(_value)) {}
    simdutf_really_inline simd8(const uint8_t* values) : simd8(load(values)) {}
    simdutf_really_inline simd8(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) : simd8(_mm_setr_epi8(
      v0, v1, v2, v3, v4, v5, v6, v7,
      v8, v9, v10,v11,v12,v13,v14,v15
    )) {}
    simdutf_really_inline static simd8<uint8_t> repeat_16(
      uint8_t v0,  uint8_t v1,  uint8_t v2,  uint8_t v3,  uint8_t v4,  uint8_t v5,  uint8_t v6,  uint8_t v7,
      uint8_t v8,  uint8_t v9,  uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15
    ) {
      return simd8<uint8_t>(
        v0, v1, v2, v3, v4, v5, v6, v7,
        v8, v9, v10,v11,v12,v13,v14,v15
      );
    }

    simdutf_really_inline simd8<uint8_t> saturating_add(const simd8<uint8_t> other) const { return _mm_adds_epu8(*this, other); }
    simdutf_really_inline simd8<uint8_t> saturating_sub(const simd8<uint8_t> other) const { return _mm_subs_epu8(*this, other); }

    simdutf_really_inline simd8<uint8_t> max_val(const simd8<uint8_t> other) const { return _mm_max_epu8(*this, other); }
    simdutf_really_inline simd8<uint8_t> min_val(const simd8<uint8_t> other) const { return _mm_min_epu8(*this, other); }
    simdutf_really_inline simd8<uint8_t> gt_bits(const simd8<uint8_t> other) const { return this->saturating_sub(other); }
    simdutf_really_inline simd8<uint8_t> lt_bits(const simd8<uint8_t> other) const { return other.saturating_sub(*this); }
    simdutf_really_inline simd8<bool> operator<=(const simd8<uint8_t> other) const { return other.max_val(*this) == other; }
    simdutf_really_inline simd8<bool> operator>=(const simd8<uint8_t> other) const { return other.min_val(*this) == other; }
    simdutf_really_inline simd8<bool> operator>(const simd8<uint8_t> other) const { return this->gt_bits(other).any_bits_set(); }
    simdutf_really_inline simd8<bool> operator<(const simd8<uint8_t> other) const { return this->gt_bits(other).any_bits_set(); }

    simdutf_really_inline simd8<bool> bits_not_set() const { return *this == uint8_t(0); }
    simdutf_really_inline simd8<bool> bits_not_set(simd8<uint8_t> bits) const { return (*this & bits).bits_not_set(); }
    simdutf_really_inline simd8<bool> any_bits_set() const { return ~this->bits_not_set(); }
    simdutf_really_inline simd8<bool> any_bits_set(simd8<uint8_t> bits) const { return ~this->bits_not_set(bits); }
    simdutf_really_inline bool is_ascii() const { return _mm_movemask_epi8(*this) == 0; }

    simdutf_really_inline bool bits_not_set_anywhere() const { return _mm_testz_si128(*this, *this); }
    simdutf_really_inline bool any_bits_set_anywhere() const { return !bits_not_set_anywhere(); }
    simdutf_really_inline bool bits_not_set_anywhere(simd8<uint8_t> bits) const { return _mm_testz_si128(*this, bits); }
    simdutf_really_inline bool any_bits_set_anywhere(simd8<uint8_t> bits) const { return !bits_not_set_anywhere(bits); }
    template<int N>
    simdutf_really_inline simd8<uint8_t> shr() const { return simd8<uint8_t>(_mm_srli_epi16(*this, N)) & uint8_t(0xFFu >> N); }
    template<int N>
    simdutf_really_inline simd8<uint8_t> shl() const { return simd8<uint8_t>(_mm_slli_epi16(*this, N)) & uint8_t(0xFFu << N); }
    template<int N>
    simdutf_really_inline int get_bit() const { return _mm_movemask_epi8(_mm_slli_epi16(*this, 7-N)); }
  };
  simdutf_really_inline simd8<int8_t>::operator simd8<uint8_t>() const { return this->value; }

  template<>
  struct simd8<uint16_t>: base<uint16_t> {
    static simdutf_really_inline simd8<uint16_t> splat(uint16_t _value) { return _mm_set1_epi16(_value); }
    static simdutf_really_inline simd8<uint16_t> load(const uint16_t values[8]) {
      return _mm_loadu_si128(reinterpret_cast<const __m128i *>(values));
    }

    simdutf_really_inline simd8() : base<uint16_t>() {}
    simdutf_really_inline simd8(const __m128i _value) : base<uint16_t>(_value) {}
    simdutf_really_inline simd8(uint16_t _value) : simd8(splat(_value)) {}
    simdutf_really_inline simd8(const uint16_t* values) : simd8(load(values)) {}
    simdutf_really_inline simd8(
      uint16_t v0,  uint16_t v1,  uint16_t v2,  uint16_t v3,  uint16_t v4,  uint16_t v5,  uint16_t v6,  uint16_t v7
    ) : simd8(_mm_setr_epi16(
      v0, v1, v2, v3, v4, v5, v6, v7
    )) {}

    simdutf_really_inline simd8<uint16_t> saturating_add(const simd8<uint16_t> other) const { return _mm_adds_epu16(*this, other); }
    simdutf_really_inline simd8<uint16_t> saturating_sub(const simd8<uint16_t> other) const { return _mm_subs_epu16(*this, other); }

    simdutf_really_inline simd8<uint16_t> max_val(const simd8<uint16_t> other) const { return _mm_max_epu16(*this, other); }
    simdutf_really_inline simd8<uint16_t> min_val(const simd8<uint16_t> other) const { return _mm_min_epu16(*this, other); }
    simdutf_really_inline simd8<uint16_t> gt_bits(const simd8<uint16_t> other) const { return this->saturating_sub(other); }
    simdutf_really_inline simd8<uint16_t> lt_bits(const simd8<uint16_t> other) const { return other.saturating_sub(*this); }
    simdutf_really_inline simd8<bool> operator<=(const simd8<uint16_t> other) const { return other.max_val(*this) == other; }
    simdutf_really_inline simd8<bool> operator>=(const simd8<uint16_t> other) const { return other.min_val(*this) == other; }
    simdutf_really_inline simd8<bool> operator==(const simd8<uint16_t> other) const { return _mm_cmpeq_epi16(*this, other); }
    simdutf_really_inline simd8<bool> operator&(const simd8<uint16_t> other) const { return _mm_and_si128(*this, other); }
    simdutf_really_inline simd8<bool> operator|(const simd8<uint16_t> other) const { return _mm_or_si128(*this, other); }

    simdutf_really_inline simd8<bool> bits_not_set() const { return *this == uint16_t(0); }
    simdutf_really_inline simd8<bool> any_bits_set() const { return ~this->bits_not_set(); }

    simdutf_really_inline bool bits_not_set_anywhere() const { return _mm_testz_si128(*this, *this); }
    simdutf_really_inline bool any_bits_set_anywhere() const { return !bits_not_set_anywhere(); }
    simdutf_really_inline bool bits_not_set_anywhere(simd8<uint16_t> bits) const { return _mm_testz_si128(*this, bits); }
    simdutf_really_inline bool any_bits_set_anywhere(simd8<uint16_t> bits) const { return !bits_not_set_anywhere(bits); }
     };
  template<typename T>
  struct simd8x64 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd8<T>);
    static_assert(NUM_CHUNKS == 4, "Westmere kernel should use four registers per 64-byte block.");
    simd8<T> chunks[NUM_CHUNKS];

    simd8x64(const simd8x64<T>& o) = delete; // no copy allowed
    simd8x64<T>& operator=(const simd8<T> other) = delete; // no assignment allowed
    simd8x64() = delete; // no default constructor allowed

    simdutf_really_inline simd8x64(const simd8<T> chunk0, const simd8<T> chunk1, const simd8<T> chunk2, const simd8<T> chunk3) : chunks{chunk0, chunk1, chunk2, chunk3} {}
    simdutf_really_inline simd8x64(const T* ptr) : chunks{simd8<T>::load(ptr), simd8<T>::load(ptr+sizeof(simd8<T>)/sizeof(T)), simd8<T>::load(ptr+2*sizeof(simd8<T>)/sizeof(T)), simd8<T>::load(ptr+3*sizeof(simd8<T>)/sizeof(T))} {}

    simdutf_really_inline void store(T* ptr) const {
      this->chunks[0].store(ptr+sizeof(simd8<T>)*0/sizeof(T));
      this->chunks[1].store(ptr+sizeof(simd8<T>)*1/sizeof(T));
      this->chunks[2].store(ptr+sizeof(simd8<T>)*2/sizeof(T));
      this->chunks[3].store(ptr+sizeof(simd8<T>)*3/sizeof(T));
    }

    simdutf_really_inline simd8x64<T>& operator |=(const simd8x64<T> &other) {
      this->chunks[0] |= other.chunks[0];
      this->chunks[1] |= other.chunks[1];
      this->chunks[2] |= other.chunks[2];
      this->chunks[3] |= other.chunks[3];
      return *this;
    }

    simdutf_really_inline simd8<T> reduce_or() const {
      return (this->chunks[0] | this->chunks[1]) | (this->chunks[2] | this->chunks[3]);
    }

    simdutf_really_inline bool is_ascii() const {
      return this->reduce_or().is_ascii();
    }

    template <endianness endian>
    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      this->chunks[0].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*0);
      this->chunks[1].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*1);
      this->chunks[2].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*2);
      this->chunks[3].template store_ascii_as_utf16<endian>(ptr+sizeof(simd8<T>)*3);
    }

    simdutf_really_inline void store_ascii_as_utf32(char32_t * ptr) const {
      this->chunks[0].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*0);
      this->chunks[1].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*1);
      this->chunks[2].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*2);
      this->chunks[3].store_ascii_as_utf32(ptr+sizeof(simd8<T>)*3);
    }

    simdutf_really_inline uint64_t to_bitmask() const {
      uint64_t r0 = uint32_t(this->chunks[0].to_bitmask() );
      uint64_t r1 =          this->chunks[1].to_bitmask() ;
      uint64_t r2 =          this->chunks[2].to_bitmask() ;
      uint64_t r3 =          this->chunks[3].to_bitmask() ;
      return r0 | (r1 << 16) | (r2 << 32) | (r3 << 48);
    }

    simdutf_really_inline uint64_t eq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] == mask,
        this->chunks[1] == mask,
        this->chunks[2] == mask,
        this->chunks[3] == mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t eq(const simd8x64<uint8_t> &other) const {
      return  simd8x64<bool>(
        this->chunks[0] == other.chunks[0],
        this->chunks[1] == other.chunks[1],
        this->chunks[2] == other.chunks[2],
        this->chunks[3] == other.chunks[3]
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t lteq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] <= mask,
        this->chunks[1] <= mask,
        this->chunks[2] <= mask,
        this->chunks[3] <= mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);

      return  simd8x64<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low-1);
      const simd8<T> mask_high = simd8<T>::splat(high+1);
      return simd8x64<bool>(
        (this->chunks[0] >= mask_high) | (this->chunks[0] <= mask_low),
        (this->chunks[1] >= mask_high) | (this->chunks[1] <= mask_low),
        (this->chunks[2] >= mask_high) | (this->chunks[2] <= mask_low),
        (this->chunks[3] >= mask_high) | (this->chunks[3] <= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t lt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] < mask,
        this->chunks[1] < mask,
        this->chunks[2] < mask,
        this->chunks[3] < mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t gt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] > mask,
        this->chunks[1] > mask,
        this->chunks[2] > mask,
        this->chunks[3] > mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gteq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] >= mask,
        this->chunks[1] >= mask,
        this->chunks[2] >= mask,
        this->chunks[3] >= mask
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t gteq_unsigned(const uint8_t m) const {
      const simd8<uint8_t> mask = simd8<uint8_t>::splat(m);
      return  simd8x64<bool>(
        simd8<uint8_t>(__m128i(this->chunks[0])) >= mask,
        simd8<uint8_t>(__m128i(this->chunks[1])) >= mask,
        simd8<uint8_t>(__m128i(this->chunks[2])) >= mask,
        simd8<uint8_t>(__m128i(this->chunks[3])) >= mask
      ).to_bitmask();
    }
  }; // struct simd8x64<T>

/* begin file src/simdutf/westmere/simd16-inl.h */
template<typename T>
struct simd16;

template<typename T, typename Mask=simd16<bool>>
struct base16: base<simd16<T>> {
  typedef uint16_t bitmask_t;
  typedef uint32_t bitmask2_t;

  simdutf_really_inline base16() : base<simd16<T>>() {}
  simdutf_really_inline base16(const __m128i _value) : base<simd16<T>>(_value) {}
  template <typename Pointer>
  simdutf_really_inline base16(const Pointer* ptr) : base16(_mm_loadu_si128(reinterpret_cast<const __m128i*>(ptr))) {}

  simdutf_really_inline Mask operator==(const simd16<T> other) const { return _mm_cmpeq_epi16(*this, other); }

  static const int SIZE = sizeof(base<simd16<T>>::value);

  template<int N=1>
  simdutf_really_inline simd16<T> prev(const simd16<T> prev_chunk) const {
    return _mm_alignr_epi8(*this, prev_chunk, 16 - N);
  }
};

template<>
struct simd16<bool>: base16<bool> {
  static simdutf_really_inline simd16<bool> splat(bool _value) { return _mm_set1_epi16(uint16_t(-(!!_value))); }

  simdutf_really_inline simd16<bool>() : base16() {}
  simdutf_really_inline simd16<bool>(const __m128i _value) : base16<bool>(_value) {}
  simdutf_really_inline simd16<bool>(bool _value) : base16<bool>(splat(_value)) {}

  simdutf_really_inline int to_bitmask() const { return _mm_movemask_epi8(*this); }
  simdutf_really_inline bool any() const { return !_mm_testz_si128(*this, *this); }
  simdutf_really_inline simd16<bool> operator~() const { return *this ^ true; }
};

template<typename T>
struct base16_numeric: base16<T> {
  static simdutf_really_inline simd16<T> splat(T _value) { return _mm_set1_epi16(_value); }
  static simdutf_really_inline simd16<T> zero() { return _mm_setzero_si128(); }
  static simdutf_really_inline simd16<T> load(const T values[8]) {
    return _mm_loadu_si128(reinterpret_cast<const __m128i *>(values));
  }

  simdutf_really_inline base16_numeric() : base16<T>() {}
  simdutf_really_inline base16_numeric(const __m128i _value) : base16<T>(_value) {}

  simdutf_really_inline void store(T dst[8]) const { return _mm_storeu_si128(reinterpret_cast<__m128i *>(dst), *this); }

  simdutf_really_inline simd16<T> operator~() const { return *this ^ 0xFFu; }

  simdutf_really_inline simd16<T> operator+(const simd16<T> other) const { return _mm_add_epi16(*this, other); }
  simdutf_really_inline simd16<T> operator-(const simd16<T> other) const { return _mm_sub_epi16(*this, other); }
  simdutf_really_inline simd16<T>& operator+=(const simd16<T> other) { *this = *this + other; return *static_cast<simd16<T>*>(this); }
  simdutf_really_inline simd16<T>& operator-=(const simd16<T> other) { *this = *this - other; return *static_cast<simd16<T>*>(this); }
};

template<>
struct simd16<int16_t> : base16_numeric<int16_t> {
  simdutf_really_inline simd16() : base16_numeric<int16_t>() {}
  simdutf_really_inline simd16(const __m128i _value) : base16_numeric<int16_t>(_value) {}
  simdutf_really_inline simd16(int16_t _value) : simd16(splat(_value)) {}
  simdutf_really_inline simd16(const int16_t* values) : simd16(load(values)) {}
  simdutf_really_inline simd16(const char16_t* values) : simd16(load(reinterpret_cast<const int16_t*>(values))) {}
  simdutf_really_inline simd16(
    int16_t v0, int16_t v1, int16_t v2, int16_t v3, int16_t v4, int16_t v5, int16_t v6, int16_t v7)
    : simd16(_mm_setr_epi16(v0, v1, v2, v3, v4, v5, v6, v7)) {}
  simdutf_really_inline operator simd16<uint16_t>() const;

  simdutf_really_inline simd16<int16_t> max_val(const simd16<int16_t> other) const { return _mm_max_epi16(*this, other); }
  simdutf_really_inline simd16<int16_t> min_val(const simd16<int16_t> other) const { return _mm_min_epi16(*this, other); }
  simdutf_really_inline simd16<bool> operator>(const simd16<int16_t> other) const { return _mm_cmpgt_epi16(*this, other); }
  simdutf_really_inline simd16<bool> operator<(const simd16<int16_t> other) const { return _mm_cmpgt_epi16(other, *this); }
};

template<>
struct simd16<uint16_t>: base16_numeric<uint16_t>  {
  simdutf_really_inline simd16() : base16_numeric<uint16_t>() {}
  simdutf_really_inline simd16(const __m128i _value) : base16_numeric<uint16_t>(_value) {}

  simdutf_really_inline simd16(uint16_t _value) : simd16(splat(_value)) {}
  simdutf_really_inline simd16(const uint16_t* values) : simd16(load(values)) {}
  simdutf_really_inline simd16(const char16_t* values) : simd16(load(reinterpret_cast<const uint16_t*>(values))) {}
  simdutf_really_inline simd16(
    uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3, uint16_t v4, uint16_t v5, uint16_t v6, uint16_t v7)
  : simd16(_mm_setr_epi16(v0, v1, v2, v3, v4, v5, v6, v7)) {}
  simdutf_really_inline static simd16<uint16_t> repeat_16(
    uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3, uint16_t v4, uint16_t v5, uint16_t v6, uint16_t v7
  ) {
    return simd16<uint16_t>(v0, v1, v2, v3, v4, v5, v6, v7);
  }

  simdutf_really_inline simd16<uint16_t> saturating_add(const simd16<uint16_t> other) const { return _mm_adds_epu16(*this, other); }
  simdutf_really_inline simd16<uint16_t> saturating_sub(const simd16<uint16_t> other) const { return _mm_subs_epu16(*this, other); }

  simdutf_really_inline simd16<uint16_t> max_val(const simd16<uint16_t> other) const { return _mm_max_epu16(*this, other); }
  simdutf_really_inline simd16<uint16_t> min_val(const simd16<uint16_t> other) const { return _mm_min_epu16(*this, other); }
  simdutf_really_inline simd16<uint16_t> gt_bits(const simd16<uint16_t> other) const { return this->saturating_sub(other); }
  simdutf_really_inline simd16<uint16_t> lt_bits(const simd16<uint16_t> other) const { return other.saturating_sub(*this); }
  simdutf_really_inline simd16<bool> operator<=(const simd16<uint16_t> other) const { return other.max_val(*this) == other; }
  simdutf_really_inline simd16<bool> operator>=(const simd16<uint16_t> other) const { return other.min_val(*this) == other; }
  simdutf_really_inline simd16<bool> operator>(const simd16<uint16_t> other) const { return this->gt_bits(other).any_bits_set(); }
  simdutf_really_inline simd16<bool> operator<(const simd16<uint16_t> other) const { return this->gt_bits(other).any_bits_set(); }

  simdutf_really_inline simd16<bool> bits_not_set() const { return *this == uint16_t(0); }
  simdutf_really_inline simd16<bool> bits_not_set(simd16<uint16_t> bits) const { return (*this & bits).bits_not_set(); }
  simdutf_really_inline simd16<bool> any_bits_set() const { return ~this->bits_not_set(); }
  simdutf_really_inline simd16<bool> any_bits_set(simd16<uint16_t> bits) const { return ~this->bits_not_set(bits); }

  simdutf_really_inline bool bits_not_set_anywhere() const { return _mm_testz_si128(*this, *this); }
  simdutf_really_inline bool any_bits_set_anywhere() const { return !bits_not_set_anywhere(); }
  simdutf_really_inline bool bits_not_set_anywhere(simd16<uint16_t> bits) const { return _mm_testz_si128(*this, bits); }
  simdutf_really_inline bool any_bits_set_anywhere(simd16<uint16_t> bits) const { return !bits_not_set_anywhere(bits); }
  template<int N>
  simdutf_really_inline simd16<uint16_t> shr() const { return simd16<uint16_t>(_mm_srli_epi16(*this, N)); }
  template<int N>
  simdutf_really_inline simd16<uint16_t> shl() const { return simd16<uint16_t>(_mm_slli_epi16(*this, N)); }
  template<int N>
  simdutf_really_inline int get_bit() const { return _mm_movemask_epi8(_mm_slli_epi16(*this, 7-N)); }

  simdutf_really_inline simd16<uint16_t> swap_bytes() const {
    const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    return _mm_shuffle_epi8(*this, swap);
  }

  static simdutf_really_inline simd8<uint8_t> pack(const simd16<uint16_t>& v0, const simd16<uint16_t>& v1) {
    return _mm_packus_epi16(v0, v1);
  }
};
simdutf_really_inline simd16<int16_t>::operator simd16<uint16_t>() const { return this->value; }

template<typename T>
  struct simd16x32 {
    static constexpr int NUM_CHUNKS = 64 / sizeof(simd16<T>);
    static_assert(NUM_CHUNKS == 4, "Westmere kernel should use four registers per 64-byte block.");
    simd16<T> chunks[NUM_CHUNKS];

    simd16x32(const simd16x32<T>& o) = delete; // no copy allowed
    simd16x32<T>& operator=(const simd16<T> other) = delete; // no assignment allowed
    simd16x32() = delete; // no default constructor allowed

    simdutf_really_inline simd16x32(const simd16<T> chunk0, const simd16<T> chunk1, const simd16<T> chunk2, const simd16<T> chunk3) : chunks{chunk0, chunk1, chunk2, chunk3} {}
    simdutf_really_inline simd16x32(const T* ptr) : chunks{simd16<T>::load(ptr), simd16<T>::load(ptr+sizeof(simd16<T>)/sizeof(T)), simd16<T>::load(ptr+2*sizeof(simd16<T>)/sizeof(T)), simd16<T>::load(ptr+3*sizeof(simd16<T>)/sizeof(T))} {}

    simdutf_really_inline void store(T* ptr) const {
      this->chunks[0].store(ptr+sizeof(simd16<T>)*0/sizeof(T));
      this->chunks[1].store(ptr+sizeof(simd16<T>)*1/sizeof(T));
      this->chunks[2].store(ptr+sizeof(simd16<T>)*2/sizeof(T));
      this->chunks[3].store(ptr+sizeof(simd16<T>)*3/sizeof(T));
    }

    simdutf_really_inline simd16<T> reduce_or() const {
      return (this->chunks[0] | this->chunks[1]) | (this->chunks[2] | this->chunks[3]);
    }

    simdutf_really_inline bool is_ascii() const {
      return this->reduce_or().is_ascii();
    }

    simdutf_really_inline void store_ascii_as_utf16(char16_t * ptr) const {
      this->chunks[0].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*0);
      this->chunks[1].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*1);
      this->chunks[2].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*2);
      this->chunks[3].store_ascii_as_utf16(ptr+sizeof(simd16<T>)*3);
    }

    simdutf_really_inline uint64_t to_bitmask() const {
      uint64_t r0 = uint32_t(this->chunks[0].to_bitmask() );
      uint64_t r1 =          this->chunks[1].to_bitmask() ;
      uint64_t r2 =          this->chunks[2].to_bitmask() ;
      uint64_t r3 =          this->chunks[3].to_bitmask() ;
      return r0 | (r1 << 16) | (r2 << 32) | (r3 << 48);
    }

    simdutf_really_inline void swap_bytes() {
      this->chunks[0] = this->chunks[0].swap_bytes();
      this->chunks[1] = this->chunks[1].swap_bytes();
      this->chunks[2] = this->chunks[2].swap_bytes();
      this->chunks[3] = this->chunks[3].swap_bytes();
    }

    simdutf_really_inline uint64_t eq(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] == mask,
        this->chunks[1] == mask,
        this->chunks[2] == mask,
        this->chunks[3] == mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t eq(const simd16x32<uint16_t> &other) const {
      return  simd16x32<bool>(
        this->chunks[0] == other.chunks[0],
        this->chunks[1] == other.chunks[1],
        this->chunks[2] == other.chunks[2],
        this->chunks[3] == other.chunks[3]
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t lteq(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] <= mask,
        this->chunks[1] <= mask,
        this->chunks[2] <= mask,
        this->chunks[3] <= mask
      ).to_bitmask();
    }

    simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd16<T> mask_low = simd16<T>::splat(low);
      const simd16<T> mask_high = simd16<T>::splat(high);

      return  simd16x32<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd16<T> mask_low = simd16<T>::splat(static_cast<T>(low-1));
      const simd16<T> mask_high = simd16<T>::splat(static_cast<T>(high+1));
      return simd16x32<bool>(
        (this->chunks[0] >= mask_high) | (this->chunks[0] <= mask_low),
        (this->chunks[1] >= mask_high) | (this->chunks[1] <= mask_low),
        (this->chunks[2] >= mask_high) | (this->chunks[2] <= mask_low),
        (this->chunks[3] >= mask_high) | (this->chunks[3] <= mask_low)
      ).to_bitmask();
    }
    simdutf_really_inline uint64_t lt(const T m) const {
      const simd16<T> mask = simd16<T>::splat(m);
      return  simd16x32<bool>(
        this->chunks[0] < mask,
        this->chunks[1] < mask,
        this->chunks[2] < mask,
        this->chunks[3] < mask
      ).to_bitmask();
    }
  }; // struct simd16x32<T>
/* end file src/simdutf/westmere/simd16-inl.h */

} // namespace simd
} // unnamed namespace
} // namespace westmere
} // namespace simdutf

#endif // SIMDUTF_WESTMERE_SIMD_INPUT_H
/* end file src/simdutf/westmere/simd.h */

/* begin file src/simdutf/westmere/end.h */
SIMDUTF_UNTARGET_REGION
/* end file src/simdutf/westmere/end.h */

#endif // SIMDUTF_IMPLEMENTATION_WESTMERE
#endif // SIMDUTF_WESTMERE_COMMON_H
/* end file src/simdutf/westmere.h */
/* begin file src/simdutf/ppc64.h */
#ifndef SIMDUTF_PPC64_H
#define SIMDUTF_PPC64_H

#ifdef SIMDUTF_FALLBACK_H
#error "ppc64.h must be included before fallback.h"
#endif


#ifndef SIMDUTF_IMPLEMENTATION_PPC64
#define SIMDUTF_IMPLEMENTATION_PPC64 (SIMDUTF_IS_PPC64)
#endif
#define SIMDUTF_CAN_ALWAYS_RUN_PPC64 SIMDUTF_IMPLEMENTATION_PPC64 && SIMDUTF_IS_PPC64



#if SIMDUTF_IMPLEMENTATION_PPC64

namespace simdutf {
/**
 * Implementation for ALTIVEC (PPC64).
 */
namespace ppc64 {
} // namespace ppc64
} // namespace simdutf

/* begin file src/simdutf/ppc64/implementation.h */
#ifndef SIMDUTF_PPC64_IMPLEMENTATION_H
#define SIMDUTF_PPC64_IMPLEMENTATION_H


namespace simdutf {
namespace ppc64 {

namespace {
using namespace simdutf;
} // namespace

class implementation final : public simdutf::implementation {
public:
  simdutf_really_inline implementation()
      : simdutf::implementation("ppc64", "PPC64 ALTIVEC",
                                 internal::instruction_set::ALTIVEC) {}
  simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  void change_endianness_utf16(const char16_t * buf, size_t length, char16_t * output) const noexcept final;
  simdutf_warn_unused size_t count_utf16le(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf16be(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf8(const char * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) const noexcept;
};

} // namespace ppc64
} // namespace simdutf

#endif // SIMDUTF_PPC64_IMPLEMENTATION_H
/* end file src/simdutf/ppc64/implementation.h */

/* begin file src/simdutf/ppc64/begin.h */
/* end file src/simdutf/ppc64/begin.h */

/* begin file src/simdutf/ppc64/intrinsics.h */
#ifndef SIMDUTF_PPC64_INTRINSICS_H
#define SIMDUTF_PPC64_INTRINSICS_H


#include <altivec.h>

#ifdef bool
#undef bool
#endif

#ifdef vector
#undef vector
#endif

#endif //  SIMDUTF_PPC64_INTRINSICS_H
/* end file src/simdutf/ppc64/intrinsics.h */
/* begin file src/simdutf/ppc64/bitmanipulation.h */
#ifndef SIMDUTF_PPC64_BITMANIPULATION_H
#define SIMDUTF_PPC64_BITMANIPULATION_H

namespace simdutf {
namespace ppc64 {
namespace {

#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
simdutf_really_inline int count_ones(uint64_t input_num) {
  return __popcnt64(input_num); // Visual Studio wants two underscores
}
#else
simdutf_really_inline int count_ones(uint64_t input_num) {
  return __builtin_popcountll(input_num);
}
#endif

} // unnamed namespace
} // namespace ppc64
} // namespace simdutf

#endif // SIMDUTF_PPC64_BITMANIPULATION_H
/* end file src/simdutf/ppc64/bitmanipulation.h */
/* begin file src/simdutf/ppc64/simd.h */
#ifndef SIMDUTF_PPC64_SIMD_H
#define SIMDUTF_PPC64_SIMD_H

#include <type_traits>

namespace simdutf {
namespace ppc64 {
namespace {
namespace simd {

using __m128i = __vector unsigned char;

template <typename Child> struct base {
  __m128i value;

  simdutf_really_inline base() : value{__m128i()} {}

  simdutf_really_inline base(const __m128i _value) : value(_value) {}

  simdutf_really_inline operator const __m128i &() const {
    return this->value;
  }
  simdutf_really_inline operator __m128i &() { return this->value; }

  simdutf_really_inline Child operator|(const Child other) const {
    return vec_or(this->value, (__m128i)other);
  }
  simdutf_really_inline Child operator&(const Child other) const {
    return vec_and(this->value, (__m128i)other);
  }
  simdutf_really_inline Child operator^(const Child other) const {
    return vec_xor(this->value, (__m128i)other);
  }
  simdutf_really_inline Child bit_andnot(const Child other) const {
    return vec_andc(this->value, (__m128i)other);
  }
  simdutf_really_inline Child &operator|=(const Child other) {
    auto this_cast = static_cast<Child*>(this);
    *this_cast = *this_cast | other;
    return *this_cast;
  }
  simdutf_really_inline Child &operator&=(const Child other) {
    auto this_cast = static_cast<Child*>(this);
    *this_cast = *this_cast & other;
    return *this_cast;
  }
  simdutf_really_inline Child &operator^=(const Child other) {
    auto this_cast = static_cast<Child*>(this);
    *this_cast = *this_cast ^ other;
    return *this_cast;
  }
};

template <typename T> struct simd8;

template <typename T, typename Mask = simd8<bool>>
struct base8 : base<simd8<T>> {
  typedef uint16_t bitmask_t;
  typedef uint32_t bitmask2_t;

  simdutf_really_inline base8() : base<simd8<T>>() {}
  simdutf_really_inline base8(const __m128i _value) : base<simd8<T>>(_value) {}

  simdutf_really_inline Mask operator==(const simd8<T> other) const {
    return (__m128i)vec_cmpeq(this->value, (__m128i)other);
  }

  static const int SIZE = sizeof(base<simd8<T>>::value);

  template <int N = 1>
  simdutf_really_inline simd8<T> prev(simd8<T> prev_chunk) const {
    __m128i chunk = this->value;
#ifdef __LITTLE_ENDIAN__
    chunk = (__m128i)vec_reve(this->value);
    prev_chunk = (__m128i)vec_reve((__m128i)prev_chunk);
#endif
    chunk = (__m128i)vec_sld((__m128i)prev_chunk, (__m128i)chunk, 16 - N);
#ifdef __LITTLE_ENDIAN__
    chunk = (__m128i)vec_reve((__m128i)chunk);
#endif
    return chunk;
  }
};

template <> struct simd8<bool> : base8<bool> {
  static simdutf_really_inline simd8<bool> splat(bool _value) {
    return (__m128i)vec_splats((unsigned char)(-(!!_value)));
  }

  simdutf_really_inline simd8<bool>() : base8() {}
  simdutf_really_inline simd8<bool>(const __m128i _value)
      : base8<bool>(_value) {}
  simdutf_really_inline simd8<bool>(bool _value)
      : base8<bool>(splat(_value)) {}

  simdutf_really_inline int to_bitmask() const {
    __vector unsigned long long result;
    const __m128i perm_mask = {0x78, 0x70, 0x68, 0x60, 0x58, 0x50, 0x48, 0x40,
                               0x38, 0x30, 0x28, 0x20, 0x18, 0x10, 0x08, 0x00};

    result = ((__vector unsigned long long)vec_vbpermq((__m128i)this->value,
                                                       (__m128i)perm_mask));
#ifdef __LITTLE_ENDIAN__
    return static_cast<int>(result[1]);
#else
    return static_cast<int>(result[0]);
#endif
  }
  simdutf_really_inline bool any() const {
    return !vec_all_eq(this->value, (__m128i)vec_splats(0));
  }
  simdutf_really_inline simd8<bool> operator~() const {
    return this->value ^ (__m128i)splat(true);
  }
};

template <typename T> struct base8_numeric : base8<T> {
  static simdutf_really_inline simd8<T> splat(T value) {
    (void)value;
    return (__m128i)vec_splats(value);
  }
  static simdutf_really_inline simd8<T> zero() { return splat(0); }
  static simdutf_really_inline simd8<T> load(const T values[16]) {
    return (__m128i)(vec_vsx_ld(0, reinterpret_cast<const uint8_t *>(values)));
  }
  static simdutf_really_inline simd8<T> repeat_16(T v0, T v1, T v2, T v3, T v4,
                                                   T v5, T v6, T v7, T v8, T v9,
                                                   T v10, T v11, T v12, T v13,
                                                   T v14, T v15) {
    return simd8<T>(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,
                    v14, v15);
  }

  simdutf_really_inline base8_numeric() : base8<T>() {}
  simdutf_really_inline base8_numeric(const __m128i _value)
      : base8<T>(_value) {}

  simdutf_really_inline void store(T dst[16]) const {
    vec_vsx_st(this->value, 0, reinterpret_cast<__m128i *>(dst));
  }

  simdutf_really_inline simd8<T> operator~() const { return *this ^ 0xFFu; }

  simdutf_really_inline simd8<T> operator+(const simd8<T> other) const {
    return (__m128i)((__m128i)this->value + (__m128i)other);
  }
  simdutf_really_inline simd8<T> operator-(const simd8<T> other) const {
    return (__m128i)((__m128i)this->value - (__m128i)other);
  }
  simdutf_really_inline simd8<T> &operator+=(const simd8<T> other) {
    *this = *this + other;
    return *static_cast<simd8<T> *>(this);
  }
  simdutf_really_inline simd8<T> &operator-=(const simd8<T> other) {
    *this = *this - other;
    return *static_cast<simd8<T> *>(this);
  }

  template <typename L>
  simdutf_really_inline simd8<L> lookup_16(simd8<L> lookup_table) const {
    return (__m128i)vec_perm((__m128i)lookup_table, (__m128i)lookup_table, this->value);
  }

  template <typename L>
  simdutf_really_inline simd8<L>
  lookup_16(L replace0, L replace1, L replace2, L replace3, L replace4,
            L replace5, L replace6, L replace7, L replace8, L replace9,
            L replace10, L replace11, L replace12, L replace13, L replace14,
            L replace15) const {
    return lookup_16(simd8<L>::repeat_16(
        replace0, replace1, replace2, replace3, replace4, replace5, replace6,
        replace7, replace8, replace9, replace10, replace11, replace12,
        replace13, replace14, replace15));
  }
};

template <> struct simd8<int8_t> : base8_numeric<int8_t> {
  simdutf_really_inline simd8() : base8_numeric<int8_t>() {}
  simdutf_really_inline simd8(const __m128i _value)
      : base8_numeric<int8_t>(_value) {}

  simdutf_really_inline simd8(int8_t _value) : simd8(splat(_value)) {}
  simdutf_really_inline simd8(const int8_t *values) : simd8(load(values)) {}
  simdutf_really_inline simd8(int8_t v0, int8_t v1, int8_t v2, int8_t v3,
                               int8_t v4, int8_t v5, int8_t v6, int8_t v7,
                               int8_t v8, int8_t v9, int8_t v10, int8_t v11,
                               int8_t v12, int8_t v13, int8_t v14, int8_t v15)
      : simd8((__m128i)(__vector signed char){v0, v1, v2, v3, v4, v5, v6, v7,
                                              v8, v9, v10, v11, v12, v13, v14,
                                              v15}) {}
  simdutf_really_inline static simd8<int8_t>
  repeat_16(int8_t v0, int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t v5,
            int8_t v6, int8_t v7, int8_t v8, int8_t v9, int8_t v10, int8_t v11,
            int8_t v12, int8_t v13, int8_t v14, int8_t v15) {
    return simd8<int8_t>(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12,
                         v13, v14, v15);
  }

  simdutf_really_inline simd8<int8_t>
  max_val(const simd8<int8_t> other) const {
    return (__m128i)vec_max((__vector signed char)this->value,
                            (__vector signed char)(__m128i)other);
  }
  simdutf_really_inline simd8<int8_t>
  min_val(const simd8<int8_t> other) const {
    return (__m128i)vec_min((__vector signed char)this->value,
                            (__vector signed char)(__m128i)other);
  }
  simdutf_really_inline simd8<bool>
  operator>(const simd8<int8_t> other) const {
    return (__m128i)vec_cmpgt((__vector signed char)this->value,
                              (__vector signed char)(__m128i)other);
  }
  simdutf_really_inline simd8<bool>
  operator<(const simd8<int8_t> other) const {
    return (__m128i)vec_cmplt((__vector signed char)this->value,
                              (__vector signed char)(__m128i)other);
  }
};

template <> struct simd8<uint8_t> : base8_numeric<uint8_t> {
  simdutf_really_inline simd8() : base8_numeric<uint8_t>() {}
  simdutf_really_inline simd8(const __m128i _value)
      : base8_numeric<uint8_t>(_value) {}
  simdutf_really_inline simd8(uint8_t _value) : simd8(splat(_value)) {}
  simdutf_really_inline simd8(const uint8_t *values) : simd8(load(values)) {}
  simdutf_really_inline
  simd8(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5,
        uint8_t v6, uint8_t v7, uint8_t v8, uint8_t v9, uint8_t v10,
        uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15)
      : simd8((__m128i){v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12,
                        v13, v14, v15}) {}
  simdutf_really_inline static simd8<uint8_t>
  repeat_16(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4,
            uint8_t v5, uint8_t v6, uint8_t v7, uint8_t v8, uint8_t v9,
            uint8_t v10, uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14,
            uint8_t v15) {
    return simd8<uint8_t>(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12,
                          v13, v14, v15);
  }

  simdutf_really_inline simd8<uint8_t>
  saturating_add(const simd8<uint8_t> other) const {
    return (__m128i)vec_adds(this->value, (__m128i)other);
  }
  simdutf_really_inline simd8<uint8_t>
  saturating_sub(const simd8<uint8_t> other) const {
    return (__m128i)vec_subs(this->value, (__m128i)other);
  }

  simdutf_really_inline simd8<uint8_t>
  max_val(const simd8<uint8_t> other) const {
    return (__m128i)vec_max(this->value, (__m128i)other);
  }
  simdutf_really_inline simd8<uint8_t>
  min_val(const simd8<uint8_t> other) const {
    return (__m128i)vec_min(this->value, (__m128i)other);
  }
  simdutf_really_inline simd8<uint8_t>
  gt_bits(const simd8<uint8_t> other) const {
    return this->saturating_sub(other);
  }
  simdutf_really_inline simd8<uint8_t>
  lt_bits(const simd8<uint8_t> other) const {
    return other.saturating_sub(*this);
  }
  simdutf_really_inline simd8<bool>
  operator<=(const simd8<uint8_t> other) const {
    return other.max_val(*this) == other;
  }
  simdutf_really_inline simd8<bool>
  operator>=(const simd8<uint8_t> other) const {
    return other.min_val(*this) == other;
  }
  simdutf_really_inline simd8<bool>
  operator>(const simd8<uint8_t> other) const {
    return this->gt_bits(other).any_bits_set();
  }
  simdutf_really_inline simd8<bool>
  operator<(const simd8<uint8_t> other) const {
    return this->gt_bits(other).any_bits_set();
  }

  simdutf_really_inline simd8<bool> bits_not_set() const {
    return (__m128i)vec_cmpeq(this->value, (__m128i)vec_splats(uint8_t(0)));
  }
  simdutf_really_inline simd8<bool> bits_not_set(simd8<uint8_t> bits) const {
    return (*this & bits).bits_not_set();
  }
  simdutf_really_inline simd8<bool> any_bits_set() const {
    return ~this->bits_not_set();
  }
  simdutf_really_inline simd8<bool> any_bits_set(simd8<uint8_t> bits) const {
    return ~this->bits_not_set(bits);
  }

  simdutf_really_inline bool is_ascii() const {
      return this->saturating_sub(0b01111111u).bits_not_set_anywhere();
  }

  simdutf_really_inline bool bits_not_set_anywhere() const {
    return vec_all_eq(this->value, (__m128i)vec_splats(0));
  }
  simdutf_really_inline bool any_bits_set_anywhere() const {
    return !bits_not_set_anywhere();
  }
  simdutf_really_inline bool bits_not_set_anywhere(simd8<uint8_t> bits) const {
    return vec_all_eq(vec_and(this->value, (__m128i)bits),
                      (__m128i)vec_splats(0));
  }
  simdutf_really_inline bool any_bits_set_anywhere(simd8<uint8_t> bits) const {
    return !bits_not_set_anywhere(bits);
  }
  template <int N> simdutf_really_inline simd8<uint8_t> shr() const {
    return simd8<uint8_t>(
        (__m128i)vec_sr(this->value, (__m128i)vec_splat_u8(N)));
  }
  template <int N> simdutf_really_inline simd8<uint8_t> shl() const {
    return simd8<uint8_t>(
        (__m128i)vec_sl(this->value, (__m128i)vec_splat_u8(N)));
  }
};

template <typename T> struct simd8x64 {
  static constexpr int NUM_CHUNKS = 64 / sizeof(simd8<T>);
  static_assert(NUM_CHUNKS == 4,
                "PPC64 kernel should use four registers per 64-byte block.");
  simd8<T> chunks[NUM_CHUNKS];

  simd8x64(const simd8x64<T> &o) = delete; // no copy allowed
  simd8x64<T> &
  operator=(const simd8<T> other) = delete; // no assignment allowed
  simd8x64() = delete;                      // no default constructor allowed

  simdutf_really_inline simd8x64(const simd8<T> chunk0, const simd8<T> chunk1,
                                  const simd8<T> chunk2, const simd8<T> chunk3)
      : chunks{chunk0, chunk1, chunk2, chunk3} {}

  simdutf_really_inline simd8x64(const T* ptr) : chunks{simd8<T>::load(ptr), simd8<T>::load(ptr+sizeof(simd8<T>)/sizeof(T)), simd8<T>::load(ptr+2*sizeof(simd8<T>)/sizeof(T)), simd8<T>::load(ptr+3*sizeof(simd8<T>)/sizeof(T))} {}

  simdutf_really_inline void store(T* ptr) const {
    this->chunks[0].store(ptr + sizeof(simd8<T>) * 0/sizeof(T));
    this->chunks[1].store(ptr + sizeof(simd8<T>) * 1/sizeof(T));
    this->chunks[2].store(ptr + sizeof(simd8<T>) * 2/sizeof(T));
    this->chunks[3].store(ptr + sizeof(simd8<T>) * 3/sizeof(T));
  }


  simdutf_really_inline simd8x64<T>& operator |=(const simd8x64<T> &other) {
      this->chunks[0] |= other.chunks[0];
      this->chunks[1] |= other.chunks[1];
      this->chunks[2] |= other.chunks[2];
      this->chunks[3] |= other.chunks[3];
      return *this;
    }

  simdutf_really_inline simd8<T> reduce_or() const {
    return (this->chunks[0] | this->chunks[1]) |
           (this->chunks[2] | this->chunks[3]);
  }


  simdutf_really_inline bool is_ascii() const {
    return input.reduce_or().is_ascii();
  }

  simdutf_really_inline uint64_t to_bitmask() const {
    uint64_t r0 = uint32_t(this->chunks[0].to_bitmask());
    uint64_t r1 = this->chunks[1].to_bitmask();
    uint64_t r2 = this->chunks[2].to_bitmask();
    uint64_t r3 = this->chunks[3].to_bitmask();
    return r0 | (r1 << 16) | (r2 << 32) | (r3 << 48);
  }

  simdutf_really_inline uint64_t eq(const T m) const {
    const simd8<T> mask = simd8<T>::splat(m);
    return simd8x64<bool>(this->chunks[0] == mask, this->chunks[1] == mask,
                          this->chunks[2] == mask, this->chunks[3] == mask)
        .to_bitmask();
  }

  simdutf_really_inline uint64_t eq(const simd8x64<uint8_t> &other) const {
    return simd8x64<bool>(this->chunks[0] == other.chunks[0],
                          this->chunks[1] == other.chunks[1],
                          this->chunks[2] == other.chunks[2],
                          this->chunks[3] == other.chunks[3])
        .to_bitmask();
  }

  simdutf_really_inline uint64_t lteq(const T m) const {
    const simd8<T> mask = simd8<T>::splat(m);
    return simd8x64<bool>(this->chunks[0] <= mask, this->chunks[1] <= mask,
                          this->chunks[2] <= mask, this->chunks[3] <= mask)
        .to_bitmask();
  }

  simdutf_really_inline uint64_t in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);

      return  simd8x64<bool>(
        (this->chunks[0] <= mask_high) & (this->chunks[0] >= mask_low),
        (this->chunks[1] <= mask_high) & (this->chunks[1] >= mask_low),
        (this->chunks[2] <= mask_high) & (this->chunks[2] >= mask_low),
        (this->chunks[3] <= mask_high) & (this->chunks[3] >= mask_low)
      ).to_bitmask();
  }
  simdutf_really_inline uint64_t not_in_range(const T low, const T high) const {
      const simd8<T> mask_low = simd8<T>::splat(low);
      const simd8<T> mask_high = simd8<T>::splat(high);
      return  simd8x64<bool>(
        (this->chunks[0] > mask_high) | (this->chunks[0] < mask_low),
        (this->chunks[1] > mask_high) | (this->chunks[1] < mask_low),
        (this->chunks[2] > mask_high) | (this->chunks[2] < mask_low),
        (this->chunks[3] > mask_high) | (this->chunks[3] < mask_low)
      ).to_bitmask();
  }
  simdutf_really_inline uint64_t lt(const T m) const {
    const simd8<T> mask = simd8<T>::splat(m);
    return simd8x64<bool>(this->chunks[0] < mask, this->chunks[1] < mask,
                          this->chunks[2] < mask, this->chunks[3] < mask)
        .to_bitmask();
  }

  simdutf_really_inline uint64_t gt(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] > mask,
        this->chunks[1] > mask,
        this->chunks[2] > mask,
        this->chunks[3] > mask
      ).to_bitmask();
  }
  simdutf_really_inline uint64_t gteq(const T m) const {
      const simd8<T> mask = simd8<T>::splat(m);
      return  simd8x64<bool>(
        this->chunks[0] >= mask,
        this->chunks[1] >= mask,
        this->chunks[2] >= mask,
        this->chunks[3] >= mask
      ).to_bitmask();
  }
  simdutf_really_inline uint64_t gteq_unsigned(const uint8_t m) const {
      const simd8<uint8_t> mask = simd8<uint8_t>::splat(m);
      return  simd8x64<bool>(
        simd8<uint8_t>(this->chunks[0]) >= mask,
        simd8<uint8_t>(this->chunks[1]) >= mask,
        simd8<uint8_t>(this->chunks[2]) >= mask,
        simd8<uint8_t>(this->chunks[3]) >= mask
      ).to_bitmask();
  }
}; // struct simd8x64<T>

} // namespace simd
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf

#endif // SIMDUTF_PPC64_SIMD_INPUT_H
/* end file src/simdutf/ppc64/simd.h */

/* begin file src/simdutf/ppc64/end.h */
/* end file src/simdutf/ppc64/end.h */

#endif // SIMDUTF_IMPLEMENTATION_PPC64

#endif // SIMDUTF_PPC64_H
/* end file src/simdutf/ppc64.h */
/* begin file src/simdutf/fallback.h */
#ifndef SIMDUTF_FALLBACK_H
#define SIMDUTF_FALLBACK_H


#ifndef SIMDUTF_IMPLEMENTATION_FALLBACK
#define SIMDUTF_IMPLEMENTATION_FALLBACK 1 // (!SIMDUTF_CAN_ALWAYS_RUN_ARM64 && !SIMDUTF_CAN_ALWAYS_RUN_HASWELL && !SIMDUTF_CAN_ALWAYS_RUN_WESTMERE && !SIMDUTF_CAN_ALWAYS_RUN_PPC64)
#endif
#define SIMDUTF_CAN_ALWAYS_RUN_FALLBACK SIMDUTF_IMPLEMENTATION_FALLBACK

#if SIMDUTF_IMPLEMENTATION_FALLBACK

namespace simdutf {
/**
 * Fallback implementation (runs on any machine).
 */
namespace fallback {
} // namespace fallback
} // namespace simdutf

/* begin file src/simdutf/fallback/implementation.h */
#ifndef SIMDUTF_FALLBACK_IMPLEMENTATION_H
#define SIMDUTF_FALLBACK_IMPLEMENTATION_H


namespace simdutf {
namespace fallback {

namespace {
using namespace simdutf;
}

class implementation final : public simdutf::implementation {
public:
  simdutf_really_inline implementation() : simdutf::implementation(
      "fallback",
      "Generic fallback implementation",
      0
  ) {}
  simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16le(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf16be(const char16_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused bool validate_utf32(const char32_t *buf, size_t len) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) const noexcept final;
  void change_endianness_utf16(const char16_t * buf, size_t length, char16_t * output) const noexcept final;
  simdutf_warn_unused size_t count_utf16le(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf16be(const char16_t * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t count_utf8(const char * buf, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept;
  simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) const noexcept;
};

} // namespace fallback
} // namespace simdutf

#endif // SIMDUTF_FALLBACK_IMPLEMENTATION_H
/* end file src/simdutf/fallback/implementation.h */

/* begin file src/simdutf/fallback/begin.h */
/* end file src/simdutf/fallback/begin.h */

/* begin file src/simdutf/fallback/bitmanipulation.h */
#ifndef SIMDUTF_FALLBACK_BITMANIPULATION_H
#define SIMDUTF_FALLBACK_BITMANIPULATION_H

#include <limits>

namespace simdutf {
namespace fallback {
namespace {

#if defined(_MSC_VER) && !defined(_M_ARM64) && !defined(_M_X64)
static inline unsigned char _BitScanForward64(unsigned long* ret, uint64_t x) {
  unsigned long x0 = (unsigned long)x, top, bottom;
  _BitScanForward(&top, (unsigned long)(x >> 32));
  _BitScanForward(&bottom, x0);
  *ret = x0 ? bottom : 32 + top;
  return x != 0;
}
static unsigned char _BitScanReverse64(unsigned long* ret, uint64_t x) {
  unsigned long x1 = (unsigned long)(x >> 32), top, bottom;
  _BitScanReverse(&top, x1);
  _BitScanReverse(&bottom, (unsigned long)x);
  *ret = x1 ? top + 32 : bottom;
  return x != 0;
}
#endif

/* result might be undefined when input_num is zero */
simdutf_really_inline int leading_zeroes(uint64_t input_num) {
#ifdef _MSC_VER
  unsigned long leading_zero = 0;
  if (_BitScanReverse64(&leading_zero, input_num))
    return (int)(63 - leading_zero);
  else
    return 64;
#else
  return __builtin_clzll(input_num);
#endif// _MSC_VER
}

} // unnamed namespace
} // namespace fallback
} // namespace simdutf

#endif // SIMDUTF_FALLBACK_BITMANIPULATION_H
/* end file src/simdutf/fallback/bitmanipulation.h */

/* begin file src/simdutf/fallback/end.h */
/* end file src/simdutf/fallback/end.h */

#endif // SIMDUTF_IMPLEMENTATION_FALLBACK
#endif // SIMDUTF_FALLBACK_H
/* end file src/simdutf/fallback.h */


namespace simdutf {
bool implementation::supported_by_runtime_system() const {
  uint32_t required_instruction_sets = this->required_instruction_sets();
  uint32_t supported_instruction_sets = internal::detect_supported_architectures();
  return ((supported_instruction_sets & required_instruction_sets) == required_instruction_sets);
}

simdutf_warn_unused encoding_type implementation::autodetect_encoding(const char * input, size_t length) const noexcept {
    auto bom_encoding = simdutf::BOM::check_bom(input, length);
    if(bom_encoding != encoding_type::unspecified) { return bom_encoding; }
    if(validate_utf8(input, length)) { return encoding_type::UTF8; }
    if((length % 2) == 0) {
      if(validate_utf16le(reinterpret_cast<const char16_t*>(input), length/2)) { return encoding_type::UTF16_LE; }
    }
    if((length % 4) == 0) {
      if(validate_utf32(reinterpret_cast<const char32_t*>(input), length/4)) { return encoding_type::UTF32_LE; }
    }
    return encoding_type::unspecified;
}

namespace internal {


#if SIMDUTF_IMPLEMENTATION_HASWELL
const haswell::implementation haswell_singleton{};
#endif
#if SIMDUTF_IMPLEMENTATION_WESTMERE
const westmere::implementation westmere_singleton{};
#endif // SIMDUTF_IMPLEMENTATION_WESTMERE
#if SIMDUTF_IMPLEMENTATION_ARM64
const arm64::implementation arm64_singleton{};
#endif // SIMDUTF_IMPLEMENTATION_ARM64
#if SIMDUTF_IMPLEMENTATION_PPC64
const ppc64::implementation ppc64_singleton{};
#endif // SIMDUTF_IMPLEMENTATION_PPC64
#if SIMDUTF_IMPLEMENTATION_FALLBACK
const fallback::implementation fallback_singleton{};
#endif // SIMDUTF_IMPLEMENTATION_FALLBACK

/**
 * @private Detects best supported implementation on first use, and sets it
 */
class detect_best_supported_implementation_on_first_use final : public implementation {
public:
  const std::string &name() const noexcept final { return set_best()->name(); }
  const std::string &description() const noexcept final { return set_best()->description(); }
  uint32_t required_instruction_sets() const noexcept final { return set_best()->required_instruction_sets(); }

  simdutf_warn_unused bool validate_utf8(const char * buf, size_t len) const noexcept final override {
    return set_best()->validate_utf8(buf, len);
  }

  simdutf_warn_unused bool validate_ascii(const char * buf, size_t len) const noexcept final override {
    return set_best()->validate_ascii(buf, len);
  }

  simdutf_warn_unused bool validate_utf16le(const char16_t * buf, size_t len) const noexcept final override {
    return set_best()->validate_utf16le(buf, len);
  }

  simdutf_warn_unused bool validate_utf16be(const char16_t * buf, size_t len) const noexcept final override {
    return set_best()->validate_utf16be(buf, len);
  }

  simdutf_warn_unused bool validate_utf32(const char32_t * buf, size_t len) const noexcept final override {
    return set_best()->validate_utf32(buf, len);
  }

  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_utf8_to_utf16le(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_utf8_to_utf16be(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_valid_utf8_to_utf16le(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_valid_utf8_to_utf16be(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final override {
    return set_best()->convert_utf8_to_utf32(buf, len, utf32_output);
  }

  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * buf, size_t len, char32_t* utf32_output) const noexcept final override {
    return set_best()->convert_valid_utf8_to_utf32(buf, len, utf32_output);
  }

  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_output) const noexcept final override {
    return set_best()->convert_utf16le_to_utf8(buf, len, utf8_output);
  }

  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_output) const noexcept final override {
    return set_best()->convert_utf16be_to_utf8(buf, len, utf8_output);
  }

  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_output) const noexcept final override {
    return set_best()->convert_valid_utf16le_to_utf8(buf, len, utf8_output);
  }

  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_output) const noexcept final override {
    return set_best()->convert_valid_utf16be_to_utf8(buf, len, utf8_output);
  }

  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_output) const noexcept final override {
    return set_best()->convert_utf32_to_utf8(buf, len, utf8_output);
  }

  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_output) const noexcept final override {
    return set_best()->convert_valid_utf32_to_utf8(buf, len, utf8_output);
  }

  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_utf32_to_utf16le(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_utf32_to_utf16be(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_valid_utf32_to_utf16le(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_output) const noexcept final override {
    return set_best()->convert_valid_utf32_to_utf16be(buf, len, utf16_output);
  }

  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_output) const noexcept final override {
    return set_best()->convert_utf16le_to_utf32(buf, len, utf32_output);
  }

  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_output) const noexcept final override {
    return set_best()->convert_utf16be_to_utf32(buf, len, utf32_output);
  }

  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_output) const noexcept final override {
    return set_best()->convert_valid_utf16le_to_utf32(buf, len, utf32_output);
  }

  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_output) const noexcept final override {
    return set_best()->convert_valid_utf16be_to_utf32(buf, len, utf32_output);
  }

  void change_endianness_utf16(const char16_t * buf, size_t len, char16_t * output) const noexcept final override {
    set_best()->change_endianness_utf16(buf, len, output);
  }

  simdutf_warn_unused size_t count_utf16le(const char16_t * buf, size_t len) const noexcept final override {
    return set_best()->count_utf16le(buf, len);
  }

  simdutf_warn_unused size_t count_utf16be(const char16_t * buf, size_t len) const noexcept final override {
    return set_best()->count_utf16be(buf, len);
  }

  simdutf_warn_unused size_t count_utf8(const char * buf, size_t len) const noexcept final override {
    return set_best()->count_utf8(buf, len);
  }

  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * buf, size_t len) const noexcept override {
    return set_best()->utf8_length_from_utf16le(buf, len);
  }

  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * buf, size_t len) const noexcept override {
    return set_best()->utf8_length_from_utf16be(buf, len);
  }

  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * buf, size_t len) const noexcept override {
    return set_best()->utf32_length_from_utf16le(buf, len);
  }

  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * buf, size_t len) const noexcept override {
    return set_best()->utf32_length_from_utf16be(buf, len);
  }

  simdutf_warn_unused size_t utf16_length_from_utf8(const char * buf, size_t len) const noexcept override {
    return set_best()->utf16_length_from_utf8(buf, len);
  }

  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * buf, size_t len) const noexcept override {
    return set_best()->utf8_length_from_utf32(buf, len);
  }

  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * buf, size_t len) const noexcept override {
    return set_best()->utf16_length_from_utf32(buf, len);
  }

  simdutf_warn_unused size_t utf32_length_from_utf8(const char * buf, size_t len) const noexcept override {
    return set_best()->utf32_length_from_utf8(buf, len);
  }

  simdutf_really_inline detect_best_supported_implementation_on_first_use() noexcept : implementation("best_supported_detector", "Detects the best supported implementation and sets it", 0) {}

private:
  const implementation *set_best() const noexcept;
};

const detect_best_supported_implementation_on_first_use detect_best_supported_implementation_on_first_use_singleton;

const std::initializer_list<const implementation *> available_implementation_pointers {
#if SIMDUTF_IMPLEMENTATION_HASWELL
  &haswell_singleton,
#endif
#if SIMDUTF_IMPLEMENTATION_WESTMERE
  &westmere_singleton,
#endif
#if SIMDUTF_IMPLEMENTATION_ARM64
  &arm64_singleton,
#endif
#if SIMDUTF_IMPLEMENTATION_PPC64
  &ppc64_singleton,
#endif
#if SIMDUTF_IMPLEMENTATION_FALLBACK
  &fallback_singleton,
#endif
}; // available_implementation_pointers

class unsupported_implementation final : public implementation {
public:
  simdutf_warn_unused bool validate_utf8(const char *, size_t) const noexcept final override {
    return false; // Just refuse to validate. Given that we have a fallback implementation
  }

  simdutf_warn_unused bool validate_ascii(const char *, size_t) const noexcept final override {
    return false;
  }

  simdutf_warn_unused bool validate_utf16le(const char16_t*, size_t) const noexcept final override {
    return false;
  }

  simdutf_warn_unused bool validate_utf16be(const char16_t*, size_t) const noexcept final override {
    return false;
  }

  simdutf_warn_unused bool validate_utf32(const char32_t*, size_t) const noexcept final override {
    return false;
  }

  simdutf_warn_unused size_t convert_utf8_to_utf16le(const char*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf8_to_utf16be(const char*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf8_to_utf32(const char*, size_t, char32_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char*, size_t, char32_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t*, size_t, char*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t*, size_t, char*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t*, size_t, char*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t*, size_t, char*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t*, size_t, char*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t*, size_t, char*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t*, size_t, char16_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t*, size_t, char32_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t*, size_t, char32_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t*, size_t, char32_t*) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t*, size_t, char32_t*) const noexcept final override {
    return 0;
  }

  void change_endianness_utf16(const char16_t *, size_t, char16_t *) const noexcept final override {

  }

  simdutf_warn_unused size_t count_utf16le(const char16_t *, size_t) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t count_utf16be(const char16_t *, size_t) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t count_utf8(const char *, size_t) const noexcept final override {
    return 0;
  }

  simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf16_length_from_utf8(const char *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t *, size_t) const noexcept override {
    return 0;
  }

  simdutf_warn_unused size_t utf32_length_from_utf8(const char *, size_t) const noexcept override {
    return 0;
  }

  unsupported_implementation() : implementation("unsupported", "Unsupported CPU (no detected SIMD instructions)", 0) {}
};

const unsupported_implementation unsupported_singleton{};

size_t available_implementation_list::size() const noexcept {
  return internal::available_implementation_pointers.size();
}
const implementation * const *available_implementation_list::begin() const noexcept {
  return internal::available_implementation_pointers.begin();
}
const implementation * const *available_implementation_list::end() const noexcept {
  return internal::available_implementation_pointers.end();
}
const implementation *available_implementation_list::detect_best_supported() const noexcept {
  uint32_t supported_instruction_sets = internal::detect_supported_architectures();
  for (const implementation *impl : internal::available_implementation_pointers) {
    uint32_t required_instruction_sets = impl->required_instruction_sets();
    if ((supported_instruction_sets & required_instruction_sets) == required_instruction_sets) { return impl; }
  }
  return &unsupported_singleton; // this should never happen?
}

const implementation *detect_best_supported_implementation_on_first_use::set_best() const noexcept {
  SIMDUTF_PUSH_DISABLE_WARNINGS
  SIMDUTF_DISABLE_DEPRECATED_WARNING // Disable CRT_SECURE warning on MSVC: manually verified this is safe
  char *force_implementation_name = getenv("SIMDUTF_FORCE_IMPLEMENTATION");
  SIMDUTF_POP_DISABLE_WARNINGS

  if (force_implementation_name) {
    auto force_implementation = available_implementations[force_implementation_name];
    if (force_implementation) {
      return active_implementation = force_implementation;
    } else {
      return active_implementation = &unsupported_singleton;
    }
  }
  return active_implementation = available_implementations.detect_best_supported();
}

} // namespace internal

SIMDUTF_DLLIMPORTEXPORT const internal::available_implementation_list available_implementations{};
SIMDUTF_DLLIMPORTEXPORT internal::atomic_ptr<const implementation> active_implementation{&internal::detect_best_supported_implementation_on_first_use_singleton};

simdutf_warn_unused bool validate_utf8(const char *buf, size_t len) noexcept {
  return active_implementation->validate_utf8(buf, len);
}
simdutf_warn_unused bool validate_ascii(const char *buf, size_t len) noexcept {
  return active_implementation->validate_ascii(buf, len);
}
simdutf_warn_unused size_t convert_utf8_to_utf16le(const char * input, size_t length, char16_t* utf16_output) noexcept {
  return active_implementation->convert_utf8_to_utf16le(input, length, utf16_output);
}
simdutf_warn_unused size_t convert_utf8_to_utf16be(const char * input, size_t length, char16_t* utf16_output) noexcept {
  return active_implementation->convert_utf8_to_utf16be(input, length, utf16_output);
}
simdutf_warn_unused size_t convert_utf8_to_utf32(const char * input, size_t length, char32_t* utf32_output) noexcept {
  return active_implementation->convert_utf8_to_utf32(input, length, utf32_output);
}
simdutf_warn_unused bool validate_utf16le(const char16_t * buf, size_t len) noexcept {
  return active_implementation->validate_utf16le(buf, len);
}
simdutf_warn_unused bool validate_utf16be(const char16_t * buf, size_t len) noexcept {
  return active_implementation->validate_utf16be(buf, len);
}
simdutf_warn_unused bool validate_utf32(const char32_t * buf, size_t len) noexcept {
  return active_implementation->validate_utf32(buf, len);
}
simdutf_warn_unused size_t convert_valid_utf8_to_utf16le(const char * input, size_t length, char16_t* utf16_buffer) noexcept {
  return active_implementation->convert_valid_utf8_to_utf16le(input, length, utf16_buffer);
}
simdutf_warn_unused size_t convert_valid_utf8_to_utf16be(const char * input, size_t length, char16_t* utf16_buffer) noexcept {
  return active_implementation->convert_valid_utf8_to_utf16be(input, length, utf16_buffer);
}
simdutf_warn_unused size_t convert_valid_utf8_to_utf32(const char * input, size_t length, char32_t* utf32_buffer) noexcept {
  return active_implementation->convert_valid_utf8_to_utf32(input, length, utf32_buffer);
}
simdutf_warn_unused size_t convert_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) noexcept {
  return active_implementation->convert_utf16le_to_utf8(buf, len, utf8_buffer);
}
simdutf_warn_unused size_t convert_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) noexcept {
  return active_implementation->convert_utf16be_to_utf8(buf, len, utf8_buffer);
}
simdutf_warn_unused size_t convert_valid_utf16le_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) noexcept {
  return active_implementation->convert_valid_utf16le_to_utf8(buf, len, utf8_buffer);
}
simdutf_warn_unused size_t convert_valid_utf16be_to_utf8(const char16_t * buf, size_t len, char* utf8_buffer) noexcept {
  return active_implementation->convert_valid_utf16be_to_utf8(buf, len, utf8_buffer);
}
simdutf_warn_unused size_t convert_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) noexcept {
  return active_implementation->convert_utf32_to_utf8(buf, len, utf8_buffer);
}
simdutf_warn_unused size_t convert_valid_utf32_to_utf8(const char32_t * buf, size_t len, char* utf8_buffer) noexcept {
  return active_implementation->convert_valid_utf32_to_utf8(buf, len, utf8_buffer);
}
simdutf_warn_unused size_t convert_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) noexcept {
  return active_implementation->convert_utf32_to_utf16le(buf, len, utf16_buffer);
}
simdutf_warn_unused size_t convert_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) noexcept {
  return active_implementation->convert_utf32_to_utf16be(buf, len, utf16_buffer);
}
simdutf_warn_unused size_t convert_valid_utf32_to_utf16le(const char32_t * buf, size_t len, char16_t* utf16_buffer) noexcept {
  return active_implementation->convert_valid_utf32_to_utf16le(buf, len, utf16_buffer);
}
simdutf_warn_unused size_t convert_valid_utf32_to_utf16be(const char32_t * buf, size_t len, char16_t* utf16_buffer) noexcept {
  return active_implementation->convert_valid_utf32_to_utf16be(buf, len, utf16_buffer);
}
simdutf_warn_unused size_t convert_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) noexcept {
  return active_implementation->convert_utf16le_to_utf32(buf, len, utf32_buffer);
}
simdutf_warn_unused size_t convert_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) noexcept {
  return active_implementation->convert_utf16be_to_utf32(buf, len, utf32_buffer);
}
simdutf_warn_unused size_t convert_valid_utf16le_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) noexcept {
  return active_implementation->convert_valid_utf16le_to_utf32(buf, len, utf32_buffer);
}
simdutf_warn_unused size_t convert_valid_utf16be_to_utf32(const char16_t * buf, size_t len, char32_t* utf32_buffer) noexcept {
  return active_implementation->convert_valid_utf16be_to_utf32(buf, len, utf32_buffer);
}
void change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) noexcept {
  active_implementation->change_endianness_utf16(input, length, output);
}
simdutf_warn_unused size_t count_utf16le(const char16_t * input, size_t length) noexcept {
  return active_implementation->count_utf16le(input, length);
}
simdutf_warn_unused size_t count_utf16be(const char16_t * input, size_t length) noexcept {
  return active_implementation->count_utf16be(input, length);
}
simdutf_warn_unused size_t count_utf8(const char * input, size_t length) noexcept {
  return active_implementation->count_utf8(input, length);
}
simdutf_warn_unused size_t utf8_length_from_utf16le(const char16_t * input, size_t length) noexcept {
  return active_implementation->utf8_length_from_utf16le(input, length);
}
simdutf_warn_unused size_t utf8_length_from_utf16be(const char16_t * input, size_t length) noexcept {
  return active_implementation->utf8_length_from_utf16be(input, length);
}
simdutf_warn_unused size_t utf32_length_from_utf16le(const char16_t * input, size_t length) noexcept {
  return active_implementation->utf32_length_from_utf16le(input, length);
}
simdutf_warn_unused size_t utf32_length_from_utf16be(const char16_t * input, size_t length) noexcept {
  return active_implementation->utf32_length_from_utf16be(input, length);
}
simdutf_warn_unused size_t utf16_length_from_utf8(const char * input, size_t length) noexcept {
  return active_implementation->utf16_length_from_utf8(input, length);
}
simdutf_warn_unused size_t utf8_length_from_utf32(const char32_t * input, size_t length) noexcept {
  return active_implementation->utf8_length_from_utf32(input, length);
}
simdutf_warn_unused size_t utf16_length_from_utf32(const char32_t * input, size_t length) noexcept {
  return active_implementation->utf16_length_from_utf32(input, length);
}
simdutf_warn_unused size_t utf32_length_from_utf8(const char * input, size_t length) noexcept {
  return active_implementation->utf32_length_from_utf8(input, length);
}
simdutf_warn_unused simdutf::encoding_type autodetect_encoding(const char * buf, size_t length) noexcept {
  return active_implementation->autodetect_encoding(buf, length);
}

const implementation * builtin_implementation() {
  static const implementation * builtin_impl = available_implementations[STRINGIFY(SIMDUTF_BUILTIN_IMPLEMENTATION)];
  return builtin_impl;
}


} // namespace simdutf

/* end file src/implementation.cpp */
/* begin file src/encoding_types.cpp */

namespace simdutf {
std::string to_string(encoding_type bom) {
  switch (bom) {
      case UTF16_LE:     return "UTF16 little-endian";
      case UTF16_BE:     return "UTF16 big-endian";
      case UTF32_LE:     return "UTF32 little-endian";
      case UTF32_BE:     return "UTF32 big-endian";
      case UTF8:         return "UTF8";
      case unspecified:  return "unknown";
      default:           return "error";
  }
}

namespace BOM {
encoding_type check_bom(const uint8_t* byte, size_t length) {
        if (length >= 2 && byte[0] == 0xff and byte[1] == 0xfe) {
            if (length >= 4 && byte[2] == 0x00 and byte[3] == 0x0) {
                return encoding_type::UTF32_LE;
            } else {
                return encoding_type::UTF16_LE;
            }
        } else if (length >= 2 && byte[0] == 0xfe and byte[1] == 0xff) {
            return encoding_type::UTF16_BE;
        } else if (length >= 4 && byte[0] == 0x00 and byte[1] == 0x00 and byte[2] == 0xfe and byte[3] == 0xff) {
            return encoding_type::UTF32_BE;
        } else if (length >= 4 && byte[0] == 0xef and byte[1] == 0xbb and byte[3] == 0xbf) {
            return encoding_type::UTF8;
        }
        return encoding_type::unspecified;
    }

encoding_type check_bom(const char* byte, size_t length) {
      return check_bom(reinterpret_cast<const uint8_t*>(byte), length);
 }

 size_t bom_byte_size(encoding_type bom) {
        switch (bom) {
            case UTF16_LE:     return 2;
            case UTF16_BE:     return 2;
            case UTF32_LE:     return 4;
            case UTF32_BE:     return 4;
            case UTF8:         return 3;
            case unspecified:  return 0;
            default:           return 0;
        }
}

}
}
/* end file src/encoding_types.cpp */
/* begin file src/tables/utf8_to_utf16_tables.h */
#ifndef SIMDUTF_UTF8_TO_UTF16_TABLES_H
#define SIMDUTF_UTF8_TO_UTF16_TABLES_H
#include <cstdint>

namespace simdutf {
namespace {
namespace tables {
namespace utf8_to_utf16 {
/**
 * utf8bigindex uses about 8 kB
 * shufutf8 uses about 3344 B
 *
 * So we use a bit over 11 kB. It would be
 * easy to save about 4 kB by only
 * storing the index in utf8bigindex, and
 * deriving the consumed bytes otherwise.
 * However, this may come at a significant (10% to 20%)
 * performance penalty.
 */

const uint8_t shufutf8[209][16] =
{	{0, 255, 1, 255, 2, 255, 3, 255, 4, 255, 5, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 3, 255, 4, 255, 6, 5, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 3, 255, 5, 4, 6, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 3, 255, 5, 4, 7, 6, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 4, 3, 5, 255, 6, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 4, 3, 5, 255, 7, 6, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 4, 3, 6, 5, 7, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 2, 255, 4, 3, 6, 5, 8, 7, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 4, 255, 5, 255, 6, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 4, 255, 5, 255, 7, 6, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 4, 255, 6, 5, 7, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 4, 255, 6, 5, 8, 7, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 5, 4, 6, 255, 7, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 5, 4, 6, 255, 8, 7, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 5, 4, 7, 6, 8, 255, 0, 0, 0, 0},
 	{0, 255, 1, 255, 3, 2, 5, 4, 7, 6, 9, 8, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 4, 255, 5, 255, 6, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 4, 255, 5, 255, 7, 6, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 4, 255, 6, 5, 7, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 4, 255, 6, 5, 8, 7, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 5, 4, 6, 255, 7, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 5, 4, 6, 255, 8, 7, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 5, 4, 7, 6, 8, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 3, 255, 5, 4, 7, 6, 9, 8, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 5, 255, 6, 255, 7, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 5, 255, 6, 255, 8, 7, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 5, 255, 7, 6, 8, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 5, 255, 7, 6, 9, 8, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 6, 5, 7, 255, 8, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 6, 5, 7, 255, 9, 8, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 6, 5, 8, 7, 9, 255, 0, 0, 0, 0},
 	{0, 255, 2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 4, 255, 5, 255, 6, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 4, 255, 5, 255, 7, 6, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 4, 255, 6, 5, 7, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 4, 255, 6, 5, 8, 7, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 5, 4, 6, 255, 7, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 5, 4, 6, 255, 8, 7, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 5, 4, 7, 6, 8, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 3, 255, 5, 4, 7, 6, 9, 8, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 5, 255, 6, 255, 7, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 5, 255, 6, 255, 8, 7, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 5, 255, 7, 6, 8, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 5, 255, 7, 6, 9, 8, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 6, 5, 7, 255, 8, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 6, 5, 7, 255, 9, 8, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 6, 5, 8, 7, 9, 255, 0, 0, 0, 0},
 	{1, 0, 2, 255, 4, 3, 6, 5, 8, 7, 10, 9, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 5, 255, 6, 255, 7, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 5, 255, 6, 255, 8, 7, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 5, 255, 7, 6, 8, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 5, 255, 7, 6, 9, 8, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 6, 5, 7, 255, 8, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 6, 5, 7, 255, 9, 8, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 6, 5, 8, 7, 9, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 4, 255, 6, 5, 8, 7, 10, 9, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 6, 255, 7, 255, 8, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 6, 255, 7, 255, 9, 8, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 6, 255, 8, 7, 9, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 6, 255, 8, 7, 10, 9, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 7, 6, 8, 255, 9, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 7, 6, 8, 255, 10, 9, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 10, 255, 0, 0, 0, 0},
 	{1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 0, 0, 0, 0},
 	{0, 255, 255, 255, 1, 255, 255, 255, 2, 255, 255, 255, 3, 255, 255, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 2, 255, 255, 255, 4, 3, 255, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 2, 255, 255, 255, 5, 4, 3, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 3, 2, 255, 255, 4, 255, 255, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 3, 2, 255, 255, 5, 4, 255, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 3, 2, 255, 255, 6, 5, 4, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 4, 3, 2, 255, 5, 255, 255, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 4, 3, 2, 255, 6, 5, 255, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 4, 3, 2, 255, 7, 6, 5, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 3, 255, 255, 255, 4, 255, 255, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 3, 255, 255, 255, 5, 4, 255, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 3, 255, 255, 255, 6, 5, 4, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 4, 3, 255, 255, 5, 255, 255, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 4, 3, 255, 255, 6, 5, 255, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 4, 3, 255, 255, 7, 6, 5, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 5, 4, 3, 255, 6, 255, 255, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 5, 4, 3, 255, 7, 6, 255, 255},
 	{0, 255, 255, 255, 2, 1, 255, 255, 5, 4, 3, 255, 8, 7, 6, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 4, 255, 255, 255, 5, 255, 255, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 4, 255, 255, 255, 6, 5, 255, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 4, 255, 255, 255, 7, 6, 5, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 5, 4, 255, 255, 6, 255, 255, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 5, 4, 255, 255, 7, 6, 255, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 5, 4, 255, 255, 8, 7, 6, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 6, 5, 4, 255, 7, 255, 255, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 6, 5, 4, 255, 8, 7, 255, 255},
 	{0, 255, 255, 255, 3, 2, 1, 255, 6, 5, 4, 255, 9, 8, 7, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 3, 255, 255, 255, 4, 255, 255, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 3, 255, 255, 255, 5, 4, 255, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 3, 255, 255, 255, 6, 5, 4, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 4, 3, 255, 255, 5, 255, 255, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 4, 3, 255, 255, 6, 5, 255, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 4, 3, 255, 255, 7, 6, 5, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 5, 4, 3, 255, 6, 255, 255, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 5, 4, 3, 255, 7, 6, 255, 255},
 	{1, 0, 255, 255, 2, 255, 255, 255, 5, 4, 3, 255, 8, 7, 6, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 4, 255, 255, 255, 5, 255, 255, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 4, 255, 255, 255, 6, 5, 255, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 4, 255, 255, 255, 7, 6, 5, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 5, 4, 255, 255, 6, 255, 255, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 5, 4, 255, 255, 7, 6, 255, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 5, 4, 255, 255, 8, 7, 6, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 6, 5, 4, 255, 7, 255, 255, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 6, 5, 4, 255, 8, 7, 255, 255},
 	{1, 0, 255, 255, 3, 2, 255, 255, 6, 5, 4, 255, 9, 8, 7, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 5, 255, 255, 255, 6, 255, 255, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 5, 255, 255, 255, 7, 6, 255, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 5, 255, 255, 255, 8, 7, 6, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 6, 5, 255, 255, 7, 255, 255, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 6, 5, 255, 255, 8, 7, 255, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 6, 5, 255, 255, 9, 8, 7, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 7, 6, 5, 255, 8, 255, 255, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 7, 6, 5, 255, 9, 8, 255, 255},
 	{1, 0, 255, 255, 4, 3, 2, 255, 7, 6, 5, 255, 10, 9, 8, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 4, 255, 255, 255, 5, 255, 255, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 4, 255, 255, 255, 6, 5, 255, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 4, 255, 255, 255, 7, 6, 5, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 5, 4, 255, 255, 6, 255, 255, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 5, 4, 255, 255, 7, 6, 255, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 5, 4, 255, 255, 8, 7, 6, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 6, 5, 4, 255, 7, 255, 255, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 6, 5, 4, 255, 8, 7, 255, 255},
 	{2, 1, 0, 255, 3, 255, 255, 255, 6, 5, 4, 255, 9, 8, 7, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 5, 255, 255, 255, 6, 255, 255, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 5, 255, 255, 255, 7, 6, 255, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 5, 255, 255, 255, 8, 7, 6, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 6, 5, 255, 255, 7, 255, 255, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 6, 5, 255, 255, 8, 7, 255, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 6, 5, 255, 255, 9, 8, 7, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 7, 6, 5, 255, 8, 255, 255, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 7, 6, 5, 255, 9, 8, 255, 255},
 	{2, 1, 0, 255, 4, 3, 255, 255, 7, 6, 5, 255, 10, 9, 8, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 6, 255, 255, 255, 7, 255, 255, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 6, 255, 255, 255, 8, 7, 255, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 6, 255, 255, 255, 9, 8, 7, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 7, 6, 255, 255, 8, 255, 255, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 7, 6, 255, 255, 9, 8, 255, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 7, 6, 255, 255, 10, 9, 8, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 9, 255, 255, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 10, 9, 255, 255},
 	{2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 11, 10, 9, 255},
 	{0, 255, 255, 255, 1, 255, 255, 255, 2, 255, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 1, 255, 255, 255, 3, 2, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 1, 255, 255, 255, 4, 3, 2, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 1, 255, 255, 255, 5, 4, 3, 2, 0, 0, 0, 0},
 	{0, 255, 255, 255, 2, 1, 255, 255, 3, 255, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 2, 1, 255, 255, 4, 3, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 2, 1, 255, 255, 5, 4, 3, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 2, 1, 255, 255, 6, 5, 4, 3, 0, 0, 0, 0},
 	{0, 255, 255, 255, 3, 2, 1, 255, 4, 255, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 3, 2, 1, 255, 5, 4, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 3, 2, 1, 255, 6, 5, 4, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 3, 2, 1, 255, 7, 6, 5, 4, 0, 0, 0, 0},
 	{0, 255, 255, 255, 4, 3, 2, 1, 5, 255, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 4, 3, 2, 1, 6, 5, 255, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 4, 3, 2, 1, 7, 6, 5, 255, 0, 0, 0, 0},
 	{0, 255, 255, 255, 4, 3, 2, 1, 8, 7, 6, 5, 0, 0, 0, 0},
 	{1, 0, 255, 255, 2, 255, 255, 255, 3, 255, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 2, 255, 255, 255, 4, 3, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 2, 255, 255, 255, 5, 4, 3, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 2, 255, 255, 255, 6, 5, 4, 3, 0, 0, 0, 0},
 	{1, 0, 255, 255, 3, 2, 255, 255, 4, 255, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 3, 2, 255, 255, 5, 4, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 3, 2, 255, 255, 6, 5, 4, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 3, 2, 255, 255, 7, 6, 5, 4, 0, 0, 0, 0},
 	{1, 0, 255, 255, 4, 3, 2, 255, 5, 255, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 4, 3, 2, 255, 6, 5, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 4, 3, 2, 255, 7, 6, 5, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 4, 3, 2, 255, 8, 7, 6, 5, 0, 0, 0, 0},
 	{1, 0, 255, 255, 5, 4, 3, 2, 6, 255, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 5, 4, 3, 2, 7, 6, 255, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 5, 4, 3, 2, 8, 7, 6, 255, 0, 0, 0, 0},
 	{1, 0, 255, 255, 5, 4, 3, 2, 9, 8, 7, 6, 0, 0, 0, 0},
 	{2, 1, 0, 255, 3, 255, 255, 255, 4, 255, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 3, 255, 255, 255, 5, 4, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 3, 255, 255, 255, 6, 5, 4, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 3, 255, 255, 255, 7, 6, 5, 4, 0, 0, 0, 0},
 	{2, 1, 0, 255, 4, 3, 255, 255, 5, 255, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 4, 3, 255, 255, 6, 5, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 4, 3, 255, 255, 7, 6, 5, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 4, 3, 255, 255, 8, 7, 6, 5, 0, 0, 0, 0},
 	{2, 1, 0, 255, 5, 4, 3, 255, 6, 255, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 5, 4, 3, 255, 7, 6, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 5, 4, 3, 255, 9, 8, 7, 6, 0, 0, 0, 0},
 	{2, 1, 0, 255, 6, 5, 4, 3, 7, 255, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 6, 5, 4, 3, 8, 7, 255, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 6, 5, 4, 3, 9, 8, 7, 255, 0, 0, 0, 0},
 	{2, 1, 0, 255, 6, 5, 4, 3, 10, 9, 8, 7, 0, 0, 0, 0},
 	{3, 2, 1, 0, 4, 255, 255, 255, 5, 255, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 4, 255, 255, 255, 6, 5, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 4, 255, 255, 255, 7, 6, 5, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 4, 255, 255, 255, 8, 7, 6, 5, 0, 0, 0, 0},
 	{3, 2, 1, 0, 5, 4, 255, 255, 6, 255, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 5, 4, 255, 255, 7, 6, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 5, 4, 255, 255, 8, 7, 6, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 5, 4, 255, 255, 9, 8, 7, 6, 0, 0, 0, 0},
 	{3, 2, 1, 0, 6, 5, 4, 255, 7, 255, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 6, 5, 4, 255, 8, 7, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 6, 5, 4, 255, 9, 8, 7, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 6, 5, 4, 255, 10, 9, 8, 7, 0, 0, 0, 0},
 	{3, 2, 1, 0, 7, 6, 5, 4, 8, 255, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 7, 6, 5, 4, 9, 8, 255, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 7, 6, 5, 4, 10, 9, 8, 255, 0, 0, 0, 0},
 	{3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 0, 0, 0, 0}};
/* number of two bytes : 64 */
/* number of two + three bytes : 145 */
/* number of two + three + four bytes : 209 */
const uint8_t utf8bigindex[4096][2] =
{	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{148, 6},
 	{0, 12},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{0, 12},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{0, 12},
 	{155, 7},
 	{167, 7},
 	{69, 7},
 	{179, 7},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{170, 7},
 	{71, 7},
 	{182, 7},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{185, 7},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{171, 8},
 	{72, 8},
 	{183, 8},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{186, 8},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{68, 6},
 	{122, 8},
 	{74, 6},
 	{92, 6},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{76, 6},
 	{94, 6},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{77, 7},
 	{95, 7},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{187, 9},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{77, 7},
 	{95, 7},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{176, 10},
 	{148, 6},
 	{188, 10},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{200, 10},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{191, 10},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{203, 10},
 	{90, 10},
 	{108, 10},
 	{69, 7},
 	{126, 10},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{114, 10},
 	{71, 7},
 	{132, 10},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{138, 10},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{206, 10},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{116, 10},
 	{72, 8},
 	{134, 10},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{140, 10},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{15, 10},
 	{122, 8},
 	{23, 10},
 	{39, 10},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{27, 10},
 	{43, 10},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{51, 10},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{29, 10},
 	{45, 10},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{53, 10},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{57, 10},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{142, 10},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{30, 10},
 	{46, 10},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{54, 10},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{58, 10},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{60, 10},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{148, 6},
 	{0, 12},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{0, 12},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{192, 11},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{204, 11},
 	{155, 7},
 	{167, 7},
 	{69, 7},
 	{179, 7},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{170, 7},
 	{71, 7},
 	{182, 7},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{185, 7},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{207, 11},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{117, 11},
 	{72, 8},
 	{135, 11},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{141, 11},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{68, 6},
 	{122, 8},
 	{74, 6},
 	{92, 6},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{76, 6},
 	{94, 6},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{77, 7},
 	{95, 7},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{143, 11},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{31, 11},
 	{47, 11},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{55, 11},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{59, 11},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{61, 11},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{176, 10},
 	{148, 6},
 	{188, 10},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{200, 10},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{191, 10},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{203, 10},
 	{90, 10},
 	{108, 10},
 	{69, 7},
 	{126, 10},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{114, 10},
 	{71, 7},
 	{132, 10},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{138, 10},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{206, 10},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{116, 10},
 	{72, 8},
 	{134, 10},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{140, 10},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{62, 11},
 	{15, 10},
 	{122, 8},
 	{23, 10},
 	{39, 10},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{27, 10},
 	{43, 10},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{51, 10},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{29, 10},
 	{45, 10},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{53, 10},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{57, 10},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{142, 10},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{30, 10},
 	{46, 10},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{54, 10},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{58, 10},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{60, 10},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{148, 6},
 	{0, 12},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{0, 12},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{0, 12},
 	{155, 7},
 	{167, 7},
 	{69, 7},
 	{179, 7},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{170, 7},
 	{71, 7},
 	{182, 7},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{185, 7},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{208, 12},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{171, 8},
 	{72, 8},
 	{183, 8},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{186, 8},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{68, 6},
 	{122, 8},
 	{74, 6},
 	{92, 6},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{76, 6},
 	{94, 6},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{77, 7},
 	{95, 7},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{144, 12},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{77, 7},
 	{95, 7},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{176, 10},
 	{148, 6},
 	{188, 10},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{200, 10},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{191, 10},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{203, 10},
 	{90, 10},
 	{108, 10},
 	{69, 7},
 	{126, 10},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{114, 10},
 	{71, 7},
 	{132, 10},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{138, 10},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{206, 10},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{116, 10},
 	{72, 8},
 	{134, 10},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{140, 10},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{63, 12},
 	{15, 10},
 	{122, 8},
 	{23, 10},
 	{39, 10},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{27, 10},
 	{43, 10},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{51, 10},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{29, 10},
 	{45, 10},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{53, 10},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{57, 10},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{142, 10},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{30, 10},
 	{46, 10},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{54, 10},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{58, 10},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{60, 10},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{148, 6},
 	{0, 12},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{0, 12},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{192, 11},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{204, 11},
 	{155, 7},
 	{167, 7},
 	{69, 7},
 	{179, 7},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{170, 7},
 	{71, 7},
 	{182, 7},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{185, 7},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{207, 11},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{117, 11},
 	{72, 8},
 	{135, 11},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{141, 11},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{104, 8},
 	{68, 6},
 	{122, 8},
 	{74, 6},
 	{92, 6},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{76, 6},
 	{94, 6},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{77, 7},
 	{95, 7},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{143, 11},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{31, 11},
 	{47, 11},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{55, 11},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{59, 11},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{61, 11},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{147, 5},
 	{0, 12},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{0, 12},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{176, 10},
 	{148, 6},
 	{188, 10},
 	{151, 6},
 	{163, 6},
 	{66, 6},
 	{200, 10},
 	{154, 6},
 	{166, 6},
 	{68, 6},
 	{178, 6},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{169, 6},
 	{70, 6},
 	{181, 6},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{191, 10},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{203, 10},
 	{90, 10},
 	{108, 10},
 	{69, 7},
 	{126, 10},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{114, 10},
 	{71, 7},
 	{132, 10},
 	{77, 7},
 	{95, 7},
 	{65, 5},
 	{194, 7},
 	{83, 7},
 	{101, 7},
 	{67, 5},
 	{119, 7},
 	{73, 5},
 	{91, 5},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{138, 10},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{103, 7},
 	{68, 6},
 	{121, 7},
 	{74, 6},
 	{92, 6},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{76, 6},
 	{94, 6},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{206, 10},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{116, 10},
 	{72, 8},
 	{134, 10},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{140, 10},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{62, 11},
 	{15, 10},
 	{122, 8},
 	{23, 10},
 	{39, 10},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{27, 10},
 	{43, 10},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{51, 10},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{29, 10},
 	{45, 10},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{53, 10},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{57, 10},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{146, 4},
 	{0, 12},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{160, 9},
 	{172, 9},
 	{147, 5},
 	{184, 9},
 	{150, 5},
 	{162, 5},
 	{65, 5},
 	{196, 9},
 	{153, 5},
 	{165, 5},
 	{67, 5},
 	{177, 5},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{175, 9},
 	{148, 6},
 	{142, 10},
 	{81, 9},
 	{99, 9},
 	{66, 6},
 	{199, 9},
 	{87, 9},
 	{105, 9},
 	{68, 6},
 	{123, 9},
 	{74, 6},
 	{92, 6},
 	{64, 4},
 	{0, 12},
 	{157, 6},
 	{111, 9},
 	{70, 6},
 	{129, 9},
 	{76, 6},
 	{94, 6},
 	{65, 5},
 	{193, 6},
 	{82, 6},
 	{100, 6},
 	{67, 5},
 	{118, 6},
 	{73, 5},
 	{91, 5},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{190, 9},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{202, 9},
 	{89, 9},
 	{107, 9},
 	{69, 7},
 	{125, 9},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{113, 9},
 	{71, 7},
 	{131, 9},
 	{30, 10},
 	{46, 10},
 	{7, 9},
 	{194, 7},
 	{83, 7},
 	{54, 10},
 	{11, 9},
 	{119, 7},
 	{19, 9},
 	{35, 9},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{137, 9},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{58, 10},
 	{13, 9},
 	{121, 7},
 	{21, 9},
 	{37, 9},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{25, 9},
 	{41, 9},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{49, 9},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{145, 3},
 	{205, 9},
 	{156, 8},
 	{168, 8},
 	{146, 4},
 	{180, 8},
 	{149, 4},
 	{161, 4},
 	{64, 4},
 	{0, 12},
 	{159, 8},
 	{115, 9},
 	{72, 8},
 	{133, 9},
 	{78, 8},
 	{96, 8},
 	{65, 5},
 	{195, 8},
 	{84, 8},
 	{102, 8},
 	{67, 5},
 	{120, 8},
 	{73, 5},
 	{91, 5},
 	{64, 4},
 	{0, 12},
 	{0, 12},
 	{174, 8},
 	{148, 6},
 	{139, 9},
 	{80, 8},
 	{98, 8},
 	{66, 6},
 	{198, 8},
 	{86, 8},
 	{60, 10},
 	{14, 9},
 	{122, 8},
 	{22, 9},
 	{38, 9},
 	{3, 8},
 	{0, 12},
 	{157, 6},
 	{110, 8},
 	{70, 6},
 	{128, 8},
 	{26, 9},
 	{42, 9},
 	{5, 8},
 	{193, 6},
 	{82, 6},
 	{50, 9},
 	{9, 8},
 	{118, 6},
 	{17, 8},
 	{33, 8},
 	{0, 6},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{0, 12},
 	{189, 8},
 	{152, 7},
 	{164, 7},
 	{145, 3},
 	{201, 8},
 	{88, 8},
 	{106, 8},
 	{69, 7},
 	{124, 8},
 	{75, 7},
 	{93, 7},
 	{64, 4},
 	{0, 12},
 	{158, 7},
 	{112, 8},
 	{71, 7},
 	{130, 8},
 	{28, 9},
 	{44, 9},
 	{6, 8},
 	{194, 7},
 	{83, 7},
 	{52, 9},
 	{10, 8},
 	{119, 7},
 	{18, 8},
 	{34, 8},
 	{1, 7},
 	{0, 12},
 	{0, 12},
 	{173, 7},
 	{148, 6},
 	{136, 8},
 	{79, 7},
 	{97, 7},
 	{66, 6},
 	{197, 7},
 	{85, 7},
 	{56, 9},
 	{12, 8},
 	{121, 7},
 	{20, 8},
 	{36, 8},
 	{2, 7},
 	{0, 12},
 	{157, 6},
 	{109, 7},
 	{70, 6},
 	{127, 7},
 	{24, 8},
 	{40, 8},
 	{4, 7},
 	{193, 6},
 	{82, 6},
 	{48, 8},
 	{8, 7},
 	{118, 6},
 	{16, 7},
 	{32, 7},
 	{0, 6}};
} // utf8_to_utf16 namespace
} // tables namespace
} // unnamed namespace
} // namespace simdutf

#endif // SIMDUTF_UTF8_TO_UTF16_TABLES_H
/* end file src/tables/utf8_to_utf16_tables.h */
/* begin file src/tables/utf16_to_utf8_tables.h */
#ifndef SIMDUTF_UTF16_TO_UTF8_TABLES_H
#define SIMDUTF_UTF16_TO_UTF8_TABLES_H

namespace simdutf {
namespace {
namespace tables {
namespace utf16_to_utf8 {

  const uint8_t pack_1_2_utf8_bytes[256][17] = {
    {16,1,0,3,2,5,4,7,6,9,8,11,10,13,12,15,14},
    {15,0,3,2,5,4,7,6,9,8,11,10,13,12,15,14,0x80},
    {15,1,0,3,2,5,4,7,6,8,11,10,13,12,15,14,0x80},
    {14,0,3,2,5,4,7,6,8,11,10,13,12,15,14,0x80,0x80},
    {15,1,0,2,5,4,7,6,9,8,11,10,13,12,15,14,0x80},
    {14,0,2,5,4,7,6,9,8,11,10,13,12,15,14,0x80,0x80},
    {14,1,0,2,5,4,7,6,8,11,10,13,12,15,14,0x80,0x80},
    {13,0,2,5,4,7,6,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {15,1,0,3,2,5,4,7,6,9,8,10,13,12,15,14,0x80},
    {14,0,3,2,5,4,7,6,9,8,10,13,12,15,14,0x80,0x80},
    {14,1,0,3,2,5,4,7,6,8,10,13,12,15,14,0x80,0x80},
    {13,0,3,2,5,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80},
    {14,1,0,2,5,4,7,6,9,8,10,13,12,15,14,0x80,0x80},
    {13,0,2,5,4,7,6,9,8,10,13,12,15,14,0x80,0x80,0x80},
    {13,1,0,2,5,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,2,5,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {15,1,0,3,2,4,7,6,9,8,11,10,13,12,15,14,0x80},
    {14,0,3,2,4,7,6,9,8,11,10,13,12,15,14,0x80,0x80},
    {14,1,0,3,2,4,7,6,8,11,10,13,12,15,14,0x80,0x80},
    {13,0,3,2,4,7,6,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {14,1,0,2,4,7,6,9,8,11,10,13,12,15,14,0x80,0x80},
    {13,0,2,4,7,6,9,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {13,1,0,2,4,7,6,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,2,4,7,6,8,11,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,4,7,6,9,8,10,13,12,15,14,0x80,0x80},
    {13,0,3,2,4,7,6,9,8,10,13,12,15,14,0x80,0x80,0x80},
    {13,1,0,3,2,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,4,7,6,9,8,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,2,4,7,6,9,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,7,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {15,1,0,3,2,5,4,7,6,9,8,11,10,12,15,14,0x80},
    {14,0,3,2,5,4,7,6,9,8,11,10,12,15,14,0x80,0x80},
    {14,1,0,3,2,5,4,7,6,8,11,10,12,15,14,0x80,0x80},
    {13,0,3,2,5,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80},
    {14,1,0,2,5,4,7,6,9,8,11,10,12,15,14,0x80,0x80},
    {13,0,2,5,4,7,6,9,8,11,10,12,15,14,0x80,0x80,0x80},
    {13,1,0,2,5,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80},
    {12,0,2,5,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,5,4,7,6,9,8,10,12,15,14,0x80,0x80},
    {13,0,3,2,5,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,7,6,8,10,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,5,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80},
    {12,0,2,5,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,4,7,6,9,8,11,10,12,15,14,0x80,0x80},
    {13,0,3,2,4,7,6,9,8,11,10,12,15,14,0x80,0x80,0x80},
    {13,1,0,3,2,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,4,7,6,9,8,11,10,12,15,14,0x80,0x80,0x80},
    {12,0,2,4,7,6,9,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,7,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,7,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,7,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {15,1,0,3,2,5,4,6,9,8,11,10,13,12,15,14,0x80},
    {14,0,3,2,5,4,6,9,8,11,10,13,12,15,14,0x80,0x80},
    {14,1,0,3,2,5,4,6,8,11,10,13,12,15,14,0x80,0x80},
    {13,0,3,2,5,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {14,1,0,2,5,4,6,9,8,11,10,13,12,15,14,0x80,0x80},
    {13,0,2,5,4,6,9,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {13,1,0,2,5,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,2,5,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,5,4,6,9,8,10,13,12,15,14,0x80,0x80},
    {13,0,3,2,5,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,6,8,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,5,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,2,5,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,4,6,9,8,11,10,13,12,15,14,0x80,0x80},
    {13,0,3,2,4,6,9,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {13,1,0,3,2,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,4,6,9,8,11,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,2,4,6,9,8,11,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,6,8,11,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,6,9,8,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,6,8,10,13,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,5,4,6,9,8,11,10,12,15,14,0x80,0x80},
    {13,0,3,2,5,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,6,8,11,10,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,5,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80},
    {12,0,2,5,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,6,9,8,10,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,5,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,5,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,5,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,5,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80},
    {12,0,3,2,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,6,9,8,11,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,6,8,11,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,3,2,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,3,2,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,6,9,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,2,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,2,4,6,8,10,12,15,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {15,1,0,3,2,5,4,7,6,9,8,11,10,13,12,14,0x80},
    {14,0,3,2,5,4,7,6,9,8,11,10,13,12,14,0x80,0x80},
    {14,1,0,3,2,5,4,7,6,8,11,10,13,12,14,0x80,0x80},
    {13,0,3,2,5,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80},
    {14,1,0,2,5,4,7,6,9,8,11,10,13,12,14,0x80,0x80},
    {13,0,2,5,4,7,6,9,8,11,10,13,12,14,0x80,0x80,0x80},
    {13,1,0,2,5,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80},
    {12,0,2,5,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,5,4,7,6,9,8,10,13,12,14,0x80,0x80},
    {13,0,3,2,5,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,7,6,8,10,13,12,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,5,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80},
    {12,0,2,5,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,4,7,6,9,8,11,10,13,12,14,0x80,0x80},
    {13,0,3,2,4,7,6,9,8,11,10,13,12,14,0x80,0x80,0x80},
    {13,1,0,3,2,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80},
    {12,0,3,2,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,4,7,6,9,8,11,10,13,12,14,0x80,0x80,0x80},
    {12,0,2,4,7,6,9,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,7,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80},
    {12,0,3,2,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,7,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,7,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,5,4,7,6,9,8,11,10,12,14,0x80,0x80},
    {13,0,3,2,5,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,7,6,8,11,10,12,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,5,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80},
    {12,0,2,5,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,7,6,9,8,10,12,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,5,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,5,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,5,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,5,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80},
    {12,0,3,2,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,7,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,7,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,3,2,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,3,2,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,7,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,2,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,2,4,7,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {14,1,0,3,2,5,4,6,9,8,11,10,13,12,14,0x80,0x80},
    {13,0,3,2,5,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,6,8,11,10,13,12,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {13,1,0,2,5,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80},
    {12,0,2,5,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,6,9,8,10,13,12,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,5,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,5,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,5,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,5,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80},
    {12,0,3,2,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,4,6,9,8,11,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,6,8,11,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,3,2,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,3,2,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,6,9,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,2,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,2,4,6,8,10,13,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {13,1,0,3,2,5,4,6,9,8,11,10,12,14,0x80,0x80,0x80},
    {12,0,3,2,5,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,5,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,5,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,2,5,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,2,5,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,5,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,5,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,5,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,5,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,3,2,5,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,3,2,5,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,5,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,5,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,2,5,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,2,5,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {12,1,0,3,2,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80},
    {11,0,3,2,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,3,2,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,3,2,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,2,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,2,4,6,9,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,2,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,2,4,6,8,11,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,1,0,3,2,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80},
    {10,0,3,2,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,3,2,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,3,2,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,1,0,2,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,2,4,6,9,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,1,0,2,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,2,4,6,8,10,12,14,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80}
  };

  const uint8_t pack_1_2_3_utf8_bytes[256][17] = {
    {12,2,3,1,6,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80},
    {9,6,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,3,1,6,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80},
    {10,0,6,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,2,3,1,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80},
    {8,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,3,1,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,7,5,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,2,3,1,4,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,4,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,3,1,4,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,4,10,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,6,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,6,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,6,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,6,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,7,5,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,4,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,4,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,4,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,4,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,2,3,1,6,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80},
    {8,6,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,3,1,6,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,6,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,2,3,1,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,3,1,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,7,5,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,4,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,4,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,4,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,4,11,9,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,2,3,1,6,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,6,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,3,1,6,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,6,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,7,5,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,4,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,4,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,4,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,4,8,14,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,6,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,6,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,6,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,6,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,7,5,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,4,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,4,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,4,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,4,10,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,6,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,6,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,6,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,6,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,2,3,1,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,3,1,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {1,0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,2,3,1,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,3,1,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,0,7,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,2,3,1,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {1,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,3,1,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,0,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,6,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,6,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,6,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,6,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,2,3,1,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,3,1,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,0,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,7,5,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,4,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,4,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,4,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,4,11,9,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,6,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,6,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,6,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,6,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,2,3,1,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {1,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,3,1,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,0,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,7,5,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,2,3,1,4,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,4,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,3,1,4,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,0,4,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {11,2,3,1,6,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80},
    {8,6,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,3,1,6,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,0,6,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,2,3,1,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,3,1,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,7,5,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,4,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,4,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,4,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,4,10,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,6,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,6,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,6,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,6,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,2,3,1,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,3,1,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,0,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,7,5,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,4,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,4,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,4,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,4,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,2,3,1,6,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,6,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,3,1,6,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,6,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,7,5,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,4,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,4,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,4,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,4,11,9,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,6,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,6,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,6,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,6,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,7,5,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,4,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,4,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,4,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,4,8,15,13,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {10,2,3,1,6,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,6,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,3,1,6,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,0,6,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,7,5,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,4,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,4,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,4,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,4,10,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,6,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,6,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,6,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,6,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,2,3,1,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {1,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,3,1,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,0,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,7,5,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,2,3,1,4,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,4,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,3,1,4,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,0,4,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {9,2,3,1,6,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,6,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,3,1,6,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,0,6,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,7,5,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,4,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,4,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,4,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,4,11,9,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {8,2,3,1,6,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,6,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,3,1,6,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,0,6,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,2,3,1,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {2,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,3,1,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,0,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {7,2,3,1,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,3,1,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,0,7,5,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {6,2,3,1,4,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {3,4,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {5,3,1,4,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {4,0,4,8,12,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80}
  };

} // utf16_to_utf8 namespace
} // tables namespace
} // unnamed namespace
} // namespace simdutf

#endif // SIMDUTF_UTF16_TO_UTF8_TABLES_H
/* end file src/tables/utf16_to_utf8_tables.h */

/* begin file src/scalar/ascii.h */
#ifndef SIMDUTF_ASCII_H
#define SIMDUTF_ASCII_H

namespace simdutf {
namespace scalar {
namespace {
namespace ascii {

    inline simdutf_warn_unused bool validate(const char *buf, size_t len) noexcept {
    const uint8_t *data = reinterpret_cast<const uint8_t *>(buf);
    uint64_t pos = 0;
    for (;pos + 16 < len; pos += 16) {
        uint64_t v1;
        std::memcpy(&v1, data + pos, sizeof(uint64_t));
        uint64_t v2;
        std::memcpy(&v2, data + pos + sizeof(uint64_t), sizeof(uint64_t));
        uint64_t v{v1 | v2};
        if ((v & 0x8080808080808080) != 0) { return false; }
    }
    for (;pos < len; pos ++) {
        if (data[pos] >= 0b10000000) { return false; }
    }
    return true;
    }

} // ascii namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/ascii.h */
/* begin file src/scalar/utf8.h */
#ifndef SIMDUTF_UTF8_H
#define SIMDUTF_UTF8_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf8 {
inline simdutf_warn_unused bool validate(const char *buf, size_t len) noexcept {
  const uint8_t *data = reinterpret_cast<const uint8_t *>(buf);
  uint64_t pos = 0;
  uint32_t code_point = 0;
  while (pos < len) {
    uint64_t next_pos = pos + 16;
    if (next_pos <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v1;
      std::memcpy(&v1, data + pos, sizeof(uint64_t));
      uint64_t v2;
      std::memcpy(&v2, data + pos + sizeof(uint64_t), sizeof(uint64_t));
      uint64_t v{v1 | v2};
      if ((v & 0x8080808080808080) == 0) {
        pos = next_pos;
        continue;
      }
    }
    unsigned char byte = data[pos];

    while (byte < 0b10000000) {
      if (++pos == len) { return true; }
      byte = data[pos];
    }

    if ((byte & 0b11100000) == 0b11000000) {
      next_pos = pos + 2;
      if (next_pos > len) { return false; }
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return false; }
      code_point = (byte & 0b00011111) << 6 | (data[pos + 1] & 0b00111111);
      if ((code_point < 0x80) || (0x7ff < code_point)) { return false; }
    } else if ((byte & 0b11110000) == 0b11100000) {
      next_pos = pos + 3;
      if (next_pos > len) { return false; }
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return false; }
      if ((data[pos + 2] & 0b11000000) != 0b10000000) { return false; }
      code_point = (byte & 0b00001111) << 12 |
                   (data[pos + 1] & 0b00111111) << 6 |
                   (data[pos + 2] & 0b00111111);
      if ((code_point < 0x800) || (0xffff < code_point) ||
          (0xd7ff < code_point && code_point < 0xe000)) {
        return false;
      }
    } else if ((byte & 0b11111000) == 0b11110000) { // 0b11110000
      next_pos = pos + 4;
      if (next_pos > len) { return false; }
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return false; }
      if ((data[pos + 2] & 0b11000000) != 0b10000000) { return false; }
      if ((data[pos + 3] & 0b11000000) != 0b10000000) { return false; }
      code_point =
          (byte & 0b00000111) << 18 | (data[pos + 1] & 0b00111111) << 12 |
          (data[pos + 2] & 0b00111111) << 6 | (data[pos + 3] & 0b00111111);
      if (code_point <= 0xffff || 0x10ffff < code_point) { return false; }
    } else {
      return false;
    }
    pos = next_pos;
  }
  return true;
}

inline size_t count_code_points(const char* buf, size_t len) {
    const int8_t * p = reinterpret_cast<const int8_t *>(buf);
    size_t counter{0};
    for(size_t i = 0; i < len; i++) {
        if(p[i] > -65) { counter++; }
    }
    return counter;
}

inline size_t utf16_length_from_utf8(const char* buf, size_t len) {
    const int8_t * p = reinterpret_cast<const int8_t *>(buf);
    size_t counter{0};
    for(size_t i = 0; i < len; i++) {
        if(p[i] > -65) { counter++; }
        if(uint8_t(p[i]) >= 240) { counter++; }
    }
    return counter;
}

inline size_t utf32_length_from_utf8(const char* buf, size_t len) {
    const int8_t * p = reinterpret_cast<const int8_t *>(buf);
    size_t counter{0};
    for(size_t i = 0; i < len; i++) {
        if(p[i] > -65) { counter++; }
    }
    return counter;
}

} // utf8 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf8.h */
/* begin file src/scalar/utf16.h */
#ifndef SIMDUTF_UTF16_H
#define SIMDUTF_UTF16_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf16 {

inline simdutf_warn_unused uint16_t swap_bytes(const uint16_t word) {
  return uint16_t((word >> 8) | (word << 8));
}

template <endianness big_endian>
inline simdutf_warn_unused bool validate(const char16_t *buf, size_t len) noexcept {
  const uint16_t *data = reinterpret_cast<const uint16_t *>(buf);
  uint64_t pos = 0;
  while (pos < len) {
    uint16_t word = big_endian ? swap_bytes(data[pos]) : data[pos];
    if((word &0xF800) == 0xD800) {
        if(pos + 1 >= len) { return false; }
        uint16_t diff = uint16_t(word - 0xD800);
        if(diff > 0x3FF) { return false; }
        uint16_t next_word = big_endian ? uint16_t((data[pos + 1] >> 8) | (data[pos + 1] << 8)) : data[pos + 1];
        uint16_t diff2 = uint16_t(next_word - 0xDC00);
        if(diff2 > 0x3FF) { return false; }
        pos += 2;
    } else {
        pos++;
    }
  }
  return true;
}

template <endianness big_endian>
inline size_t count_code_points(const char16_t* buf, size_t len) {
  const uint16_t * p = reinterpret_cast<const uint16_t *>(buf);
  size_t counter{0};
  for(size_t i = 0; i < len; i++) {
    uint16_t word = big_endian ? swap_bytes(p[i]) : p[i];
    counter += ((word & 0xFC00) != 0xDC00);
  }
  return counter;
}

template <endianness big_endian>
inline size_t utf8_length_from_utf16(const char16_t* buf, size_t len) {
  const uint16_t * p = reinterpret_cast<const uint16_t *>(buf);
  size_t counter{0};
  for(size_t i = 0; i < len; i++) {
    uint16_t word = big_endian ? swap_bytes(p[i]) : p[i];
    /** ASCII **/
    if(word <= 0x7F) { counter++; }
    /** two-byte **/
    else if (word <= 0x7FF) { counter += 2; }
    /** three-byte **/
    else if((word <= 0xD7FF) || (word >= 0xE000)) { counter += 3; }
    /** surrogates -- 4 bytes **/
    else { counter += 2; }
  }
  return counter;
}

template <endianness big_endian>
inline size_t utf32_length_from_utf16(const char16_t* buf, size_t len) {
  const uint16_t * p = reinterpret_cast<const uint16_t *>(buf);
  size_t counter{0};
  for(size_t i = 0; i < len; i++) {
    uint16_t word = big_endian ? swap_bytes(p[i]) : p[i];
    counter += ((word & 0xFC00) != 0xDC00);
  }
  return counter;
}

simdutf_really_inline void change_endianness_utf16(const char16_t* in, size_t size, char16_t* out) {
  const uint16_t * input = reinterpret_cast<const uint16_t *>(in);
  uint16_t * output = reinterpret_cast<uint16_t *>(out);
  for (size_t i = 0; i < size; i++) {
    *output++ = uint16_t(input[i] >> 8 | input[i] << 8);
  }
}

} // utf16 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf16.h */
/* begin file src/scalar/utf32.h */
#ifndef SIMDUTF_UTF32_H
#define SIMDUTF_UTF32_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf32 {

inline simdutf_warn_unused bool validate(const char32_t *buf, size_t len) noexcept {
  const uint32_t *data = reinterpret_cast<const uint32_t *>(buf);
  uint64_t pos = 0;
  for(;pos < len; pos++) {
    uint32_t word = data[pos];
    if(word > 0x10FFFF || (word >= 0xD800 && word <= 0xDFFF)) {
        return false;
    }
  }
  return true;
}

inline size_t utf8_length_from_utf32(const char32_t* buf, size_t len) {
  const uint32_t * p = reinterpret_cast<const uint32_t *>(buf);
  size_t counter{0};
  for(size_t i = 0; i < len; i++) {
    /** ASCII **/
    if(p[i] <= 0x7F) { counter++; }
    /** two-byte **/
    else if(p[i] <= 0x7FF) { counter += 2; }
    /** three-byte **/
    else if(p[i] <= 0xFFFF) { counter += 3; }
    /** four-bytes **/
    else { counter += 4; }
  }
  return counter;
}

inline size_t utf16_length_from_utf32(const char32_t* buf, size_t len) {
  const uint32_t * p = reinterpret_cast<const uint32_t *>(buf);
  size_t counter{0};
  for(size_t i = 0; i < len; i++) {
    /** non-surrogate word **/
    if(p[i] <= 0xFFFF) { counter++; }
    /** surrogate pair **/
    else { counter += 2; }
  }
  return counter;
}

} // utf32 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf32.h */

/* begin file src/scalar/utf32_to_utf8/valid_utf32_to_utf8.h */
#ifndef SIMDUTF_VALID_UTF32_TO_UTF8_H
#define SIMDUTF_VALID_UTF32_TO_UTF8_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf32_to_utf8 {

inline size_t convert_valid(const char32_t* buf, size_t len, char* utf8_output) {
	const uint32_t *data = reinterpret_cast<const uint32_t *>(buf);
  size_t pos = 0;
  char* start{utf8_output};
  while (pos < len) {
    if (pos + 2 <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v;
      ::memcpy(&v, data + pos, sizeof(uint64_t));
      if ((v & 0xFFFFFF80FFFFFF80) == 0) {
        *utf8_output++ = char(buf[pos]);
				*utf8_output++ = char(buf[pos+1]);
        pos += 2;
        continue;
      }
    }
    uint32_t word = data[pos];
    if((word & 0xFFFFFF80)==0) {
      *utf8_output++ = char(word);
      pos++;
    } else if((word & 0xFFFFF800)==0) {
      *utf8_output++ = char((word>>6) | 0b11000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else if((word & 0xFFFF0000)==0) {
      *utf8_output++ = char((word>>12) | 0b11100000);
      *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else {
      *utf8_output++ = char((word>>18) | 0b11110000);
      *utf8_output++ = char(((word>>12) & 0b111111) | 0b10000000);
      *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos ++;
    }
  }
  return utf8_output - start;
}

} // utf32_to_utf8 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf32_to_utf8/valid_utf32_to_utf8.h */
/* begin file src/scalar/utf32_to_utf8/utf32_to_utf8.h */
#ifndef SIMDUTF_UTF32_TO_UTF8_H
#define SIMDUTF_UTF32_TO_UTF8_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf32_to_utf8 {

inline size_t convert(const char32_t* buf, size_t len, char* utf8_output) {
  const uint32_t *data = reinterpret_cast<const uint32_t *>(buf);
  size_t pos = 0;
  char* start{utf8_output};
  while (pos < len) {
    if (pos + 2 <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v;
      ::memcpy(&v, data + pos, sizeof(uint64_t));
      if ((v & 0xFFFFFF80FFFFFF80) == 0) {
        *utf8_output++ = char(buf[pos]);
				*utf8_output++ = char(buf[pos+1]);
        pos += 2;
        continue;
      }
    }
    uint32_t word = data[pos];
    if((word & 0xFFFFFF80)==0) {
      *utf8_output++ = char(word);
      pos++;
    } else if((word & 0xFFFFF800)==0) {
      *utf8_output++ = char((word>>6) | 0b11000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else if((word & 0xFFFF0000)==0) {
			if (word >= 0xD800 && word <= 0xDFFF) { return 0; }
      *utf8_output++ = char((word>>12) | 0b11100000);
      *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else {
			if (word > 0x10FFFF) { return 0; }
      *utf8_output++ = char((word>>18) | 0b11110000);
      *utf8_output++ = char(((word>>12) & 0b111111) | 0b10000000);
      *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos ++;
    }
  }
  return utf8_output - start;
}

} // utf32_to_utf8 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf32_to_utf8/utf32_to_utf8.h */

/* begin file src/scalar/utf32_to_utf16/valid_utf32_to_utf16.h */
#ifndef SIMDUTF_VALID_UTF32_TO_UTF16_H
#define SIMDUTF_VALID_UTF32_TO_UTF16_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf32_to_utf16 {

template <endianness big_endian>
inline size_t convert_valid(const char32_t* buf, size_t len, char16_t* utf16_output) {
  const uint32_t *data = reinterpret_cast<const uint32_t *>(buf);
  size_t pos = 0;
  char16_t* start{utf16_output};
  while (pos < len) {
    uint32_t word = data[pos];
    if((word & 0xFFFF0000)==0) {
      *utf16_output++ = big_endian ? char16_t(utf16::swap_bytes(uint16_t(word))) : char16_t(word);
      pos++;
    } else {
      word -= 0x10000;
      uint16_t high_surrogate = uint16_t(0xD800 + (word >> 10));
      uint16_t low_surrogate = uint16_t(0xDC00 + (word & 0x3FF));
      if (big_endian) {
        high_surrogate = utf16::swap_bytes(high_surrogate);
        low_surrogate = utf16::swap_bytes(low_surrogate);
      }
      *utf16_output++ = char16_t(high_surrogate);
      *utf16_output++ = char16_t(low_surrogate);
      pos++;
    }
  }
  return utf16_output - start;
}

} // utf32_to_utf16 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf32_to_utf16/valid_utf32_to_utf16.h */
/* begin file src/scalar/utf32_to_utf16/utf32_to_utf16.h */
#ifndef SIMDUTF_UTF32_TO_UTF16_H
#define SIMDUTF_UTF32_TO_UTF16_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf32_to_utf16 {

template <endianness big_endian>
inline size_t convert(const char32_t* buf, size_t len, char16_t* utf16_output) {
  const uint32_t *data = reinterpret_cast<const uint32_t *>(buf);
  size_t pos = 0;
  char16_t* start{utf16_output};
  while (pos < len) {
    uint32_t word = data[pos];
    if((word & 0xFFFF0000)==0) {
      if (word >= 0xD800 && word <= 0xDFFF) { return 0; }
      *utf16_output++ = big_endian ? char16_t(utf16::swap_bytes(uint16_t(word))) : char16_t(word);
    } else {
      if (word > 0x10FFFF) { return 0; }
      word -= 0x10000;
      uint16_t high_surrogate = uint16_t(0xD800 + (word >> 10));
      uint16_t low_surrogate = uint16_t(0xDC00 + (word & 0x3FF));
      if (big_endian) {
        high_surrogate = utf16::swap_bytes(high_surrogate);
        low_surrogate = utf16::swap_bytes(low_surrogate);
      }
      *utf16_output++ = char16_t(high_surrogate);
      *utf16_output++ = char16_t(low_surrogate);
    }
    pos++;
  }
  return utf16_output - start;
}

} // utf32_to_utf16 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf32_to_utf16/utf32_to_utf16.h */

/* begin file src/scalar/utf16_to_utf8/valid_utf16_to_utf8.h */
#ifndef SIMDUTF_VALID_UTF16_TO_UTF8_H
#define SIMDUTF_VALID_UTF16_TO_UTF8_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf16_to_utf8 {

template <endianness big_endian>
inline size_t convert_valid(const char16_t* buf, size_t len, char* utf8_output) {
 const uint16_t *data = reinterpret_cast<const uint16_t *>(buf);
  size_t pos = 0;
  char* start{utf8_output};
  while (pos < len) {
    if (pos + 4 <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v;
      ::memcpy(&v, data + pos, sizeof(uint64_t));
      if (big_endian) v = (v >> 8) | (v << (64 - 8));
      if ((v & 0xFF80FF80FF80FF80) == 0) {
        size_t final_pos = pos + 4;
        while(pos < final_pos) {
          *utf8_output++ = big_endian ? char(utf16::swap_bytes(buf[pos])) : char(buf[pos]);
          pos++;
        }
        continue;
      }
    }
    uint16_t word = big_endian ? utf16::swap_bytes(data[pos]) : data[pos];
    if((word & 0xFF80)==0) {
      *utf8_output++ = char(word);
      pos++;
    } else if((word & 0xF800)==0) {
      *utf8_output++ = char((word>>6) | 0b11000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else if((word &0xF800 ) != 0xD800) {
      *utf8_output++ = char((word>>12) | 0b11100000);
      *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else {
      uint16_t diff = uint16_t(word - 0xD800);
      if(pos + 1 >= len) { return 0; } // minimal bound checking
      uint16_t next_word = big_endian ? utf16::swap_bytes(data[pos + 1]) : data[pos + 1];
      uint16_t diff2 = uint16_t(next_word - 0xDC00);
      uint32_t value = (diff << 10) + diff2 + 0x10000;
      *utf8_output++ = char((value>>18) | 0b11110000);
      *utf8_output++ = char(((value>>12) & 0b111111) | 0b10000000);
      *utf8_output++ = char(((value>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((value & 0b111111) | 0b10000000);
      pos += 2;
    }
  }
  return utf8_output - start;
}

} // utf16_to_utf8 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf16_to_utf8/valid_utf16_to_utf8.h */
/* begin file src/scalar/utf16_to_utf8/utf16_to_utf8.h */
#ifndef SIMDUTF_UTF16_TO_UTF8_H
#define SIMDUTF_UTF16_TO_UTF8_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf16_to_utf8 {

template <endianness big_endian>
inline size_t convert(const char16_t* buf, size_t len, char* utf8_output) {
 const uint16_t *data = reinterpret_cast<const uint16_t *>(buf);
  size_t pos = 0;
  char* start{utf8_output};
  while (pos < len) {
    if (pos + 4 <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v;
      ::memcpy(&v, data + pos, sizeof(uint64_t));
      if (big_endian) v = (v >> 8) | (v << (64 - 8));
      if ((v & 0xFF80FF80FF80FF80) == 0) {
        size_t final_pos = pos + 4;
        while(pos < final_pos) {
          *utf8_output++ = big_endian ? char(utf16::swap_bytes(buf[pos])) : char(buf[pos]);
          pos++;
        }
        continue;
      }
    }
    uint16_t word = big_endian ? utf16::swap_bytes(data[pos]) : data[pos];
    if((word & 0xFF80)==0) {
      *utf8_output++ = char(word);
      pos++;
    } else if((word & 0xF800)==0) {
      *utf8_output++ = char((word>>6) | 0b11000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else if((word &0xF800 ) != 0xD800) {
      *utf8_output++ = char((word>>12) | 0b11100000);
      *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((word & 0b111111) | 0b10000000);
      pos++;
    } else {
      if(pos + 1 >= len) { return 0; }
      uint16_t diff = uint16_t(word - 0xD800);
      if(diff > 0x3FF) { return 0; }
      uint16_t next_word = big_endian ? utf16::swap_bytes(data[pos + 1]) : data[pos + 1];
      uint16_t diff2 = uint16_t(next_word - 0xDC00);
      if(diff2 > 0x3FF) { return 0; }
      uint32_t value = (diff << 10) + diff2 + 0x10000;
      *utf8_output++ = char((value>>18) | 0b11110000);
      *utf8_output++ = char(((value>>12) & 0b111111) | 0b10000000);
      *utf8_output++ = char(((value>>6) & 0b111111) | 0b10000000);
      *utf8_output++ = char((value & 0b111111) | 0b10000000);
      pos += 2;
    }
  }
  return utf8_output - start;
}

} // utf16_to_utf8 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf16_to_utf8/utf16_to_utf8.h */

/* begin file src/scalar/utf16_to_utf32/valid_utf16_to_utf32.h */
#ifndef SIMDUTF_VALID_UTF16_TO_UTF32_H
#define SIMDUTF_VALID_UTF16_TO_UTF32_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf16_to_utf32 {

template <endianness big_endian>
inline size_t convert_valid(const char16_t* buf, size_t len, char32_t* utf32_output) {
 const uint16_t *data = reinterpret_cast<const uint16_t *>(buf);
  size_t pos = 0;
  char32_t* start{utf32_output};
  while (pos < len) {
    uint16_t word = big_endian ? utf16::swap_bytes(data[pos]) : data[pos];
    if((word &0xF800 ) != 0xD800) {
      *utf32_output++ = char32_t(word);
      pos++;
    } else {
      uint16_t diff = uint16_t(word - 0xD800);
      if(pos + 1 >= len) { return 0; } // minimal bound checking
      uint16_t next_word = big_endian ? utf16::swap_bytes(data[pos + 1]) : data[pos + 1];
      uint16_t diff2 = uint16_t(next_word - 0xDC00);
      uint32_t value = (diff << 10) + diff2 + 0x10000;
      *utf32_output++ = char32_t(value);
      pos += 2;
    }
  }
  return utf32_output - start;
}

} // utf16_to_utf32 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf16_to_utf32/valid_utf16_to_utf32.h */
/* begin file src/scalar/utf16_to_utf32/utf16_to_utf32.h */
#ifndef SIMDUTF_UTF16_TO_UTF32_H
#define SIMDUTF_UTF16_TO_UTF32_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf16_to_utf32 {

template <endianness big_endian>
inline size_t convert(const char16_t* buf, size_t len, char32_t* utf32_output) {
 const uint16_t *data = reinterpret_cast<const uint16_t *>(buf);
  size_t pos = 0;
  char32_t* start{utf32_output};
  while (pos < len) {
    uint16_t word = big_endian ? utf16::swap_bytes(data[pos]) : data[pos];
    if((word &0xF800 ) != 0xD800) {
      *utf32_output++ = char32_t(word);
      pos++;
    } else {
      uint16_t diff = uint16_t(word - 0xD800);
      if(diff > 0x3FF) { return 0; }
      if(pos + 1 >= len) { return 0; } // minimal bound checking
      uint16_t next_word = big_endian ? utf16::swap_bytes(data[pos + 1]) : data[pos + 1];
      uint16_t diff2 = uint16_t(next_word - 0xDC00);
      if(diff2 > 0x3FF) { return 0; }
      uint32_t value = (diff << 10) + diff2 + 0x10000;
      *utf32_output++ = char32_t(value);
      pos += 2;
    }
  }
  return utf32_output - start;
}

} // utf16_to_utf32 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf16_to_utf32/utf16_to_utf32.h */

/* begin file src/scalar/utf8_to_utf16/valid_utf8_to_utf16.h */
#ifndef SIMDUTF_VALID_UTF8_TO_UTF16_H
#define SIMDUTF_VALID_UTF8_TO_UTF16_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf8_to_utf16 {

template <endianness big_endian>
inline size_t convert_valid(const char* buf, size_t len, char16_t* utf16_output) {
 const uint8_t *data = reinterpret_cast<const uint8_t *>(buf);
  size_t pos = 0;
  char16_t* start{utf16_output};
  while (pos < len) {
    if (pos + 8 <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v;
      ::memcpy(&v, data + pos, sizeof(uint64_t));
      if ((v & 0x8080808080808080) == 0) {
        size_t final_pos = pos + 8;
        while(pos < final_pos) {
          *utf16_output++ = big_endian ? char16_t(utf16::swap_bytes(buf[pos])) : char16_t(buf[pos]);
          pos++;
        }
        continue;
      }
    }
    uint8_t leading_byte = data[pos]; // leading byte
    if (leading_byte < 0b10000000) {
      *utf16_output++ = big_endian ? char16_t(utf16::swap_bytes(leading_byte)) : char16_t(leading_byte);
      pos++;
    } else if ((leading_byte & 0b11100000) == 0b11000000) {
      if(pos + 1 >= len) { break; } // minimal bound checking
      uint16_t code_point = uint16_t(((leading_byte &0b00011111) << 6) | (data[pos + 1] &0b00111111));
      if (big_endian) {
        code_point = utf16::swap_bytes(uint16_t(code_point));
      }
      *utf16_output++ = char16_t(code_point);
      pos += 2;
    } else if ((leading_byte & 0b11110000) == 0b11100000) {
      if(pos + 2 >= len) { break; } // minimal bound checking
      uint16_t code_point = uint16_t(((leading_byte &0b00001111) << 12) | ((data[pos + 1] &0b00111111) << 6) | (data[pos + 2] &0b00111111));
      if (big_endian) {
        code_point = utf16::swap_bytes(uint16_t(code_point));
      }
      *utf16_output++ = char16_t(code_point);
      pos += 3;
    } else if ((leading_byte & 0b11111000) == 0b11110000) { // 0b11110000
      if(pos + 3 >= len) { break; } // minimal bound checking
      uint32_t code_point = ((leading_byte & 0b00000111) << 18 )| ((data[pos + 1] &0b00111111) << 12)
                           | ((data[pos + 2] &0b00111111) << 6) | (data[pos + 3] &0b00111111);
      code_point -= 0x10000;
      uint16_t high_surrogate = uint16_t(0xD800 + (code_point >> 10));
      uint16_t low_surrogate = uint16_t(0xDC00 + (code_point & 0x3FF));
      if (big_endian) {
        high_surrogate = utf16::swap_bytes(high_surrogate);
        low_surrogate = utf16::swap_bytes(low_surrogate);
      }
      *utf16_output++ = char16_t(high_surrogate);
      *utf16_output++ = char16_t(low_surrogate);
      pos += 4;
    } else {
      return 0;
    }
  }
  return utf16_output - start;
}


} // namespace utf8_to_utf16
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf8_to_utf16/valid_utf8_to_utf16.h */
/* begin file src/scalar/utf8_to_utf16/utf8_to_utf16.h */
#ifndef SIMDUTF_UTF8_TO_UTF16_H
#define SIMDUTF_UTF8_TO_UTF16_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf8_to_utf16 {

template <endianness big_endian>
inline size_t convert(const char* buf, size_t len, char16_t* utf16_output) {
 const uint8_t *data = reinterpret_cast<const uint8_t *>(buf);
  size_t pos = 0;
  char16_t* start{utf16_output};
  while (pos < len) {
    if (pos + 16 <= len) { // if it is safe to read 16 more bytes, check that they are ascii
      uint64_t v1;
      ::memcpy(&v1, data + pos, sizeof(uint64_t));
      uint64_t v2;
      ::memcpy(&v2, data + pos + sizeof(uint64_t), sizeof(uint64_t));
      uint64_t v{v1 | v2};
      if ((v & 0x8080808080808080) == 0) {
        size_t final_pos = pos + 16;
        while(pos < final_pos) {
          *utf16_output++ = big_endian ? char16_t(utf16::swap_bytes(buf[pos])) : char16_t(buf[pos]);
          pos++;
        }
        continue;
      }
    }
    uint8_t leading_byte = data[pos]; // leading byte
    if (leading_byte < 0b10000000) {
      *utf16_output++ = big_endian ? char16_t(utf16::swap_bytes(leading_byte)): char16_t(leading_byte);
      pos++;
    } else if ((leading_byte & 0b11100000) == 0b11000000) {
      if(pos + 1 >= len) { return 0; } // minimal bound checking
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return 0; }
      uint32_t code_point = (leading_byte & 0b00011111) << 6 | (data[pos + 1] & 0b00111111);
      if (code_point < 0x80 || 0x7ff < code_point) { return 0; }
      if (big_endian) {
        code_point = uint32_t(utf16::swap_bytes(uint16_t(code_point)));
      }
      *utf16_output++ = char16_t(code_point);
      pos += 2;
    } else if ((leading_byte & 0b11110000) == 0b11100000) {
      if(pos + 2 >= len) { return 0; } // minimal bound checking

      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return 0; }
      if ((data[pos + 2] & 0b11000000) != 0b10000000) { return 0; }
      uint32_t code_point = (leading_byte & 0b00001111) << 12 |
                   (data[pos + 1] & 0b00111111) << 6 |
                   (data[pos + 2] & 0b00111111);
      if (code_point < 0x800 || 0xffff < code_point ||
          (0xd7ff < code_point && code_point < 0xe000)) {
        return 0;
      }
      if (big_endian) {
        code_point = uint32_t(utf16::swap_bytes(uint16_t(code_point)));
      }
      *utf16_output++ = char16_t(code_point);
      pos += 3;
    } else if ((leading_byte & 0b11111000) == 0b11110000) { // 0b11110000
      if(pos + 3 >= len) { return 0; } // minimal bound checking
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return 0; }
      if ((data[pos + 2] & 0b11000000) != 0b10000000) { return 0; }
      if ((data[pos + 3] & 0b11000000) != 0b10000000) { return 0; }

      uint32_t code_point =
          (leading_byte & 0b00000111) << 18 | (data[pos + 1] & 0b00111111) << 12 |
          (data[pos + 2] & 0b00111111) << 6 | (data[pos + 3] & 0b00111111);
      if (code_point <= 0xffff || 0x10ffff < code_point) { return 0; }
      code_point -= 0x10000;
      uint16_t high_surrogate = uint16_t(0xD800 + (code_point >> 10));
      uint16_t low_surrogate = uint16_t(0xDC00 + (code_point & 0x3FF));
      if (big_endian) {
        high_surrogate = utf16::swap_bytes(high_surrogate);
        low_surrogate = utf16::swap_bytes(low_surrogate);
      }
      *utf16_output++ = char16_t(high_surrogate);
      *utf16_output++ = char16_t(low_surrogate);
      pos += 4;
    } else {
      return 0;
    }
  }
  return utf16_output - start;
}

} // utf8_to_utf16 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf8_to_utf16/utf8_to_utf16.h */

/* begin file src/scalar/utf8_to_utf32/valid_utf8_to_utf32.h */
#ifndef SIMDUTF_VALID_UTF8_TO_UTF32_H
#define SIMDUTF_VALID_UTF8_TO_UTF32_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf8_to_utf32 {

inline size_t convert_valid(const char* buf, size_t len, char32_t* utf32_output) {
 const uint8_t *data = reinterpret_cast<const uint8_t *>(buf);
  size_t pos = 0;
  char32_t* start{utf32_output};
  while (pos < len) {
    if (pos + 8 <= len) { // if it is safe to read 8 more bytes, check that they are ascii
      uint64_t v;
      ::memcpy(&v, data + pos, sizeof(uint64_t));
      if ((v & 0x8080808080808080) == 0) {
        size_t final_pos = pos + 8;
        while(pos < final_pos) {
          *utf32_output++ = char32_t(buf[pos]);
          pos++;
        }
        continue;
      }
    }
    uint8_t leading_byte = data[pos]; // leading byte
    if (leading_byte < 0b10000000) {
      *utf32_output++ = char32_t(leading_byte);
      pos++;
    } else if ((leading_byte & 0b11100000) == 0b11000000) {
      if(pos + 1 >= len) { break; } // minimal bound checking
      *utf32_output++ = char32_t(((leading_byte &0b00011111) << 6) | (data[pos + 1] &0b00111111));
      pos += 2;
    } else if ((leading_byte & 0b11110000) == 0b11100000) {
      if(pos + 2 >= len) { break; } // minimal bound checking
      *utf32_output++ = char32_t(((leading_byte &0b00001111) << 12) | ((data[pos + 1] &0b00111111) << 6) | (data[pos + 2] &0b00111111));
      pos += 3;
    } else if ((leading_byte & 0b11111000) == 0b11110000) { // 0b11110000
      if(pos + 3 >= len) { break; } // minimal bound checking
      uint32_t code_word = ((leading_byte & 0b00000111) << 18 )| ((data[pos + 1] &0b00111111) << 12)
                           | ((data[pos + 2] &0b00111111) << 6) | (data[pos + 3] &0b00111111);
      *utf32_output++ = char32_t(code_word);
      pos += 4;
    } else {
      return 0;
    }
  }
  return utf32_output - start;
}


} // namespace utf8_to_utf32
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf8_to_utf32/valid_utf8_to_utf32.h */
/* begin file src/scalar/utf8_to_utf32/utf8_to_utf32.h */
#ifndef SIMDUTF_UTF8_TO_UTF32_H
#define SIMDUTF_UTF8_TO_UTF32_H

namespace simdutf {
namespace scalar {
namespace {
namespace utf8_to_utf32 {

inline size_t convert(const char* buf, size_t len, char32_t* utf32_output) {
 const uint8_t *data = reinterpret_cast<const uint8_t *>(buf);
  size_t pos = 0;
  char32_t* start{utf32_output};
  while (pos < len) {
    if (pos + 16 <= len) { // if it is safe to read 16 more bytes, check that they are ascii
      uint64_t v1;
      ::memcpy(&v1, data + pos, sizeof(uint64_t));
      uint64_t v2;
      ::memcpy(&v2, data + pos + sizeof(uint64_t), sizeof(uint64_t));
      uint64_t v{v1 | v2};
      if ((v & 0x8080808080808080) == 0) {
        size_t final_pos = pos + 16;
        while(pos < final_pos) {
          *utf32_output++ = char32_t(buf[pos]);
          pos++;
        }
        continue;
      }
    }
    uint8_t leading_byte = data[pos]; // leading byte
    if (leading_byte < 0b10000000) {
      *utf32_output++ = char32_t(leading_byte);
      pos++;
    } else if ((leading_byte & 0b11100000) == 0b11000000) {
      if(pos + 1 >= len) { return 0; } // minimal bound checking
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return 0; }
      uint32_t code_point = (leading_byte & 0b00011111) << 6 | (data[pos + 1] & 0b00111111);
      if (code_point < 0x80 || 0x7ff < code_point) { return 0; }
      *utf32_output++ = char32_t(code_point);
      pos += 2;
    } else if ((leading_byte & 0b11110000) == 0b11100000) {
      if(pos + 2 >= len) { return 0; } // minimal bound checking

      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return 0; }
      if ((data[pos + 2] & 0b11000000) != 0b10000000) { return 0; }
      uint32_t code_point = (leading_byte & 0b00001111) << 12 |
                   (data[pos + 1] & 0b00111111) << 6 |
                   (data[pos + 2] & 0b00111111);
      if (code_point < 0x800 || 0xffff < code_point ||
          (0xd7ff < code_point && code_point < 0xe000)) {
        return 0;
      }
      *utf32_output++ = char32_t(code_point);
      pos += 3;
    } else if ((leading_byte & 0b11111000) == 0b11110000) { // 0b11110000
      if(pos + 3 >= len) { return 0; } // minimal bound checking
      if ((data[pos + 1] & 0b11000000) != 0b10000000) { return 0; }
      if ((data[pos + 2] & 0b11000000) != 0b10000000) { return 0; }
      if ((data[pos + 3] & 0b11000000) != 0b10000000) { return 0; }

      uint32_t code_point =
          (leading_byte & 0b00000111) << 18 | (data[pos + 1] & 0b00111111) << 12 |
          (data[pos + 2] & 0b00111111) << 6 | (data[pos + 3] & 0b00111111);
      if (code_point <= 0xffff || 0x10ffff < code_point) { return 0; }
      *utf32_output++ = char32_t(code_point);
      pos += 4;
    } else {
      return 0;
    }
  }
  return utf32_output - start;
}

} // utf8_to_utf32 namespace
} // unnamed namespace
} // namespace scalar
} // namespace simdutf

#endif
/* end file src/scalar/utf8_to_utf32/utf8_to_utf32.h */


SIMDUTF_PUSH_DISABLE_WARNINGS
SIMDUTF_DISABLE_UNDESIRED_WARNINGS


#if SIMDUTF_IMPLEMENTATION_ARM64
/* begin file src/arm64/implementation.cpp */
/* begin file src/simdutf/arm64/begin.h */
/* end file src/simdutf/arm64/begin.h */
namespace simdutf {
namespace arm64 {
namespace {
#ifndef SIMDUTF_ARM64_H
#error "arm64.h must be included"
#endif
using namespace simd;

simdutf_really_inline bool is_ascii(const simd8x64<uint8_t>& input) {
    simd8<uint8_t> bits = input.reduce_or();
    return bits.max_val() < 0b10000000u;
}

simdutf_unused simdutf_really_inline simd8<bool> must_be_continuation(const simd8<uint8_t> prev1, const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
    simd8<bool> is_second_byte = prev1 >= uint8_t(0b11000000u);
    simd8<bool> is_third_byte  = prev2 >= uint8_t(0b11100000u);
    simd8<bool> is_fourth_byte = prev3 >= uint8_t(0b11110000u);
    return is_second_byte ^ is_third_byte ^ is_fourth_byte;
}

simdutf_really_inline simd8<bool> must_be_2_3_continuation(const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
    simd8<bool> is_third_byte  = prev2 >= uint8_t(0b11100000u);
    simd8<bool> is_fourth_byte = prev3 >= uint8_t(0b11110000u);
    return is_third_byte ^ is_fourth_byte;
}

/* begin file src/arm64/arm_validate_utf16.cpp */
template <endianness big_endian>
const char16_t* arm_validate_utf16(const char16_t* input, size_t size) {
    const char16_t* end = input + size;
    const auto v_d8 = simd8<uint8_t>::splat(0xd8);
    const auto v_f8 = simd8<uint8_t>::splat(0xf8);
    const auto v_fc = simd8<uint8_t>::splat(0xfc);
    const auto v_dc = simd8<uint8_t>::splat(0xdc);
    while (input + 16 < end) {
        auto in0 = simd16<uint16_t>(input);
        auto in1 = simd16<uint16_t>(input + simd16<uint16_t>::SIZE / sizeof(char16_t));
        if (big_endian) {
            #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
            const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
            #else
            const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
            #endif
            in0 = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(in0), swap));
            in1 = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(in1), swap));
        }
        const auto t0 = in0.shr<8>();
        const auto t1 = in1.shr<8>();
        const simd8<uint8_t> in = simd16<uint16_t>::pack(t0, t1);
        const uint64_t surrogates_wordmask = ((in & v_f8) == v_d8).to_bitmask64();
        if(surrogates_wordmask == 0) {
            input += 16;
        } else {

            const uint64_t V = ~surrogates_wordmask;

            const auto vH = ((in & v_fc) ==  v_dc);
            const uint64_t H = vH.to_bitmask64();

            const uint64_t L = ~H & surrogates_wordmask;

            const uint64_t a = L & (H >> 4); // A low surrogate must be followed by high one.
            const uint64_t b = a << 4; // Just mark that the opposite fact is hold,
            const uint64_t c = V | a | b;      // Combine all the masks into the final one.
            if (c == ~0ull) {
                input += 16;
            } else if (c == 0xfffffffffffffffull) {
                input += 15;
            } else {
                return nullptr;
            }
        }
    }
    return input;
}
/* end file src/arm64/arm_validate_utf16.cpp */
/* begin file src/arm64/arm_validate_utf32le.cpp */

const char32_t* arm_validate_utf32le(const char32_t* input, size_t size) {
    const char32_t* end = input + size;

    const uint32x4_t standardmax = vmovq_n_u32(0x10ffff);
    const uint32x4_t offset = vmovq_n_u32(0xffff2000);
    const uint32x4_t standardoffsetmax = vmovq_n_u32(0xfffff7ff);
    uint32x4_t currentmax = vmovq_n_u32(0x0);
    uint32x4_t currentoffsetmax = vmovq_n_u32(0x0);

    while (input + 4 < end) {
        const uint32x4_t in = vld1q_u32(reinterpret_cast<const uint32_t*>(input));
        currentmax = vmaxq_u32(in,currentmax);
        currentoffsetmax = vmaxq_u32(vaddq_u32(in, offset), currentoffsetmax);
        input += 4;
    }

    uint32x4_t is_zero = veorq_u32(vmaxq_u32(currentmax, standardmax), standardmax);
    if(vmaxvq_u32(is_zero) != 0) {
        return nullptr;
    }

    is_zero = veorq_u32(vmaxq_u32(currentoffsetmax, standardoffsetmax), standardoffsetmax);
    if(vmaxvq_u32(is_zero) != 0) {
        return nullptr;
    }

    return input;
}
/* end file src/arm64/arm_validate_utf32le.cpp */

/* begin file src/arm64/arm_convert_utf8_to_utf16.cpp */
template <endianness big_endian>
size_t convert_masked_utf8_to_utf16(const char *input,
                           uint64_t utf8_end_of_code_point_mask,
                           char16_t *&utf16_output) {
  #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
  const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
  #else
  const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
  #endif
  uint8x16_t in = vld1q_u8(reinterpret_cast<const uint8_t*>(input));
  const uint16_t input_utf8_end_of_code_point_mask =
      utf8_end_of_code_point_mask & 0xfff;
  if((utf8_end_of_code_point_mask & 0xffff) == 0xffff) {
    uint16x8_t ascii_first = vmovl_u8(vget_low_u8 (in));
    uint16x8_t ascii_second = vmovl_high_u8(in);
    if (big_endian) {
      ascii_first = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(ascii_first), swap));
      ascii_second = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(ascii_second), swap));
    }
    vst1q_u16(reinterpret_cast<uint16_t*>(utf16_output), ascii_first);
    vst1q_u16(reinterpret_cast<uint16_t*>(utf16_output) + 8, ascii_second);
    utf16_output += 16; // We wrote 16 16-bit characters.
    return 16; // We consumed 16 bytes.
  }
  if((utf8_end_of_code_point_mask & 0xffff) == 0xaaaa) {
    uint8x16_t perm = vqtbl1q_u8(in, swap);
    uint8x16_t ascii = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x7f)));
    uint8x16_t highbyte = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x1f00)));
    uint8x16_t composed = vorrq_u8(ascii, vreinterpretq_u8_u16(vshrq_n_u16(vreinterpretq_u16_u8(highbyte), 2)));
    if (big_endian) composed = vqtbl1q_u8(composed, swap);
    vst1q_u8(reinterpret_cast<uint8_t*>(utf16_output), composed);
    utf16_output += 8; // We wrote 16 bytes, 8 code points.
    return 16;
  }
  if(input_utf8_end_of_code_point_mask == 0x924) {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
    const uint8x16_t sh = make_uint8x16_t(2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 11, 10, 9, 255);
#else
    const uint8x16_t sh = {2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 11, 10, 9, 255};
#endif
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x7f))); // 7 or 6 bits
    uint8x16_t middlebyte =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f00))); // 5 or 6 bits
    uint8x16_t middlebyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlebyte), 2));
    uint32x4_t highbyte =
        vreinterpretq_u32_u8(vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x0f0000)))); // 4 bits
    uint32x4_t highbyte_shifted = vshrq_n_u32(highbyte, 4);
    uint32x4_t composed =
        vorrq_u32(vorrq_u32(vreinterpretq_u32_u8(ascii), vreinterpretq_u32_u8(middlebyte_shifted)), highbyte_shifted);
    uint16x8_t composed_repacked = vmovn_high_u32(vmovn_u32(composed), composed);
    if (big_endian) composed_repacked = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(composed_repacked), swap));
    vst1q_u16(reinterpret_cast<uint16_t*>(utf16_output), composed_repacked);
    utf16_output += 4;
    return 12;
  }

  const uint8_t idx =
      simdutf::tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][0];
  const uint8_t consumed =
      simdutf::tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][1];


  if (idx < 64) {
    uint8x16_t sh = vld1q_u8(reinterpret_cast<const uint8_t*>(simdutf::tables::utf8_to_utf16::shufutf8[idx]));
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x7f)));
    uint8x16_t highbyte = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x1f00)));
    uint8x16_t composed = vorrq_u8(ascii, vreinterpretq_u8_u16(vshrq_n_u16(vreinterpretq_u16_u8(highbyte), 2)));
    if (big_endian) composed = vqtbl1q_u8(composed, swap);
    vst1q_u8(reinterpret_cast<uint8_t*>(utf16_output), composed);
    utf16_output += 6; // We wrote 12 bytes, 6 code points.
  } else if (idx < 145) {
    uint8x16_t sh = vld1q_u8(reinterpret_cast<const uint8_t*>(simdutf::tables::utf8_to_utf16::shufutf8[idx]));
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x7f))); // 7 or 6 bits
    uint8x16_t middlebyte =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f00))); // 5 or 6 bits
    uint8x16_t middlebyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlebyte), 2));
    uint32x4_t highbyte =
        vreinterpretq_u32_u8(vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x0f0000)))); // 4 bits
    uint32x4_t highbyte_shifted = vshrq_n_u32(highbyte, 4);
    uint32x4_t composed =
        vorrq_u32(vorrq_u32(vreinterpretq_u32_u8(ascii), vreinterpretq_u32_u8(middlebyte_shifted)), highbyte_shifted);
    uint16x8_t composed_repacked = vmovn_high_u32(vmovn_u32(composed), composed);
    if (big_endian) composed_repacked = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(composed_repacked), swap));
    vst1q_u16(reinterpret_cast<uint16_t*>(utf16_output), composed_repacked);
    utf16_output += 4;
  } else if (idx < 209) {
    uint8x16_t sh = vld1q_u8(reinterpret_cast<const uint8_t*>(simdutf::tables::utf8_to_utf16::shufutf8[idx]));
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x7f)));
    uint8x16_t middlebyte = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f00)));
    uint8x16_t middlebyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlebyte), 2));
    uint8x16_t middlehighbyte = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f0000)));
    uint8x16_t correct =
        vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x400000)))), 1));
    middlehighbyte = veorq_u8(correct, middlehighbyte);
    uint8x16_t middlehighbyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlehighbyte), 4));
    uint8x16_t highbyte = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x07000000)));
    uint8x16_t highbyte_shifted =vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(highbyte), 6));
    uint8x16_t composed =
        vorrq_u8(vorrq_u8(ascii, middlebyte_shifted),
                     vorrq_u8(highbyte_shifted, middlehighbyte_shifted));
    uint32x4_t composedminus =
        vsubq_u32(vreinterpretq_u32_u8(composed), vmovq_n_u32(0x10000));
    uint32x4_t lowtenbits =
        vandq_u32(composedminus, vmovq_n_u32(0x3ff));
    uint32x4_t hightenbits = vshrq_n_u32(composedminus, 10);
    uint32x4_t lowtenbitsadd =
        vaddq_u32(lowtenbits, vmovq_n_u32(0xDC00));
    uint32x4_t hightenbitsadd =
        vaddq_u32(hightenbits, vmovq_n_u32(0xD800));
    uint32x4_t lowtenbitsaddshifted = vshlq_n_u32(lowtenbitsadd, 16);
    uint32x4_t surrogates =
        vorrq_u32(hightenbitsadd, lowtenbitsaddshifted);
    uint32_t basic_buffer[4];
    uint32_t basic_buffer_swap[4];
    if (big_endian) {
      vst1q_u32(basic_buffer_swap, vreinterpretq_u32_u8(vqtbl1q_u8(composed, swap)));
      surrogates = vreinterpretq_u32_u8(vqtbl1q_u8(vreinterpretq_u8_u32(surrogates), swap));
    }
    vst1q_u32(basic_buffer, vreinterpretq_u32_u8(composed));
    uint32_t surrogate_buffer[4];
    vst1q_u32(surrogate_buffer, surrogates);
    for (size_t i = 0; i < 3; i++) {
      if (basic_buffer[i] < 65536) {
        utf16_output[0] = big_endian ? uint16_t(basic_buffer_swap[i]) : uint16_t(basic_buffer[i]);
        utf16_output++;
      } else {
        utf16_output[0] = uint16_t(surrogate_buffer[i] & 0xffff);
        utf16_output[1] = uint16_t(surrogate_buffer[i] >> 16);
        utf16_output += 2;
      }
    }
  } else {
  }
  return consumed;
}
/* end file src/arm64/arm_convert_utf8_to_utf16.cpp */
/* begin file src/arm64/arm_convert_utf8_to_utf32.cpp */
size_t convert_masked_utf8_to_utf32(const char *input,
                           uint64_t utf8_end_of_code_point_mask,
                           char32_t *&utf32_out) {
  uint32_t*& utf32_output = reinterpret_cast<uint32_t*&>(utf32_out);
  uint8x16_t in = vld1q_u8(reinterpret_cast<const uint8_t*>(input));
  const uint16_t input_utf8_end_of_code_point_mask =
      utf8_end_of_code_point_mask & 0xFFF;
  if((utf8_end_of_code_point_mask & 0xffff) == 0xffff) {
    vst1q_u32(utf32_output, vmovl_u16(vget_low_u16(vmovl_u8(vget_low_u8 (in)))));
    vst1q_u32(utf32_output + 4, vmovl_high_u16(vmovl_u8(vget_low_u8 (in))));
    vst1q_u32(utf32_output + 8, vmovl_u16(vget_low_u16(vmovl_high_u8(in))));
    vst1q_u32(utf32_output + 12, vmovl_high_u16(vmovl_high_u8(in)));
    utf32_output += 16; // We wrote 16 16-bit characters.
    return 16; // We consumed 16 bytes.
  }
  if((utf8_end_of_code_point_mask & 0xffff) == 0xaaaa) {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
    const uint8x16_t sh = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
#else
    const uint8x16_t sh = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
#endif
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x7f)));
    uint8x16_t highbyte = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x1f00)));
    uint8x16_t composed = vorrq_u8(ascii, vreinterpretq_u8_u16(vshrq_n_u16(vreinterpretq_u16_u8(highbyte), 2)));
    vst1q_u32(utf32_output,  vmovl_u16(vget_low_u16(vreinterpretq_u16_u8(composed))));
    vst1q_u32(utf32_output+4,  vmovl_high_u16(vreinterpretq_u16_u8(composed)));
    utf32_output += 8; // We wrote 32 bytes, 8 code points.
    return 16;
  }
  if(input_utf8_end_of_code_point_mask == 0x924) {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
    const uint8x16_t sh = make_uint8x16_t(2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 11, 10, 9, 255);
#else
    const uint8x16_t sh = {2, 1, 0, 255, 5, 4, 3, 255, 8, 7, 6, 255, 11, 10, 9, 255};
#endif
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x7f))); // 7 or 6 bits
    uint8x16_t middlebyte =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f00))); // 5 or 6 bits
    uint8x16_t middlebyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlebyte), 2));
    uint32x4_t highbyte =
        vreinterpretq_u32_u8(vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x0f0000)))); // 4 bits
    uint32x4_t highbyte_shifted = vshrq_n_u32(highbyte, 4);
    uint32x4_t composed =
        vorrq_u32(vorrq_u32(vreinterpretq_u32_u8(ascii), vreinterpretq_u32_u8(middlebyte_shifted)), highbyte_shifted);
    vst1q_u32(utf32_output, composed);
    utf32_output += 4;
    return 12;
  }

  const uint8_t idx =
      simdutf::tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][0];
  const uint8_t consumed =
      simdutf::tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][1];


  if (idx < 64) {
    uint8x16_t sh = vld1q_u8(reinterpret_cast<const uint8_t*>(simdutf::tables::utf8_to_utf16::shufutf8[idx]));
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x7f)));
    uint8x16_t highbyte = vandq_u8(perm, vreinterpretq_u8_u16(vmovq_n_u16(0x1f00)));
    uint8x16_t composed = vorrq_u8(ascii, vreinterpretq_u8_u16(vshrq_n_u16(vreinterpretq_u16_u8(highbyte), 2)));
    vst1q_u32(utf32_output,  vmovl_u16(vget_low_u16(vreinterpretq_u16_u8(composed))));
    vst1q_u32(utf32_output+4,  vmovl_high_u16(vreinterpretq_u16_u8(composed)));
    utf32_output += 6; // We wrote 12 bytes, 6 code points.
  } else if (idx < 145) {
    uint8x16_t sh = vld1q_u8(reinterpret_cast<const uint8_t*>(simdutf::tables::utf8_to_utf16::shufutf8[idx]));
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x7f))); // 7 or 6 bits
    uint8x16_t middlebyte =
        vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f00))); // 5 or 6 bits
    uint8x16_t middlebyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlebyte), 2));
    uint32x4_t highbyte =
        vreinterpretq_u32_u8(vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x0f0000)))); // 4 bits
    uint32x4_t highbyte_shifted = vshrq_n_u32(highbyte, 4);
    uint32x4_t composed =
        vorrq_u32(vorrq_u32(vreinterpretq_u32_u8(ascii), vreinterpretq_u32_u8(middlebyte_shifted)), highbyte_shifted);
    vst1q_u32(utf32_output, composed);
    utf32_output += 4;
  } else if (idx < 209) {
    uint8x16_t sh = vld1q_u8(reinterpret_cast<const uint8_t*>(simdutf::tables::utf8_to_utf16::shufutf8[idx]));
    uint8x16_t perm = vqtbl1q_u8(in, sh);
    uint8x16_t ascii = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x7f)));
    uint8x16_t middlebyte = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f00)));
    uint8x16_t middlebyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlebyte), 2));
    uint8x16_t middlehighbyte = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x3f0000)));
    uint8x16_t correct =
        vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x400000)))), 1));
    middlehighbyte = veorq_u8(correct, middlehighbyte);
    uint8x16_t middlehighbyte_shifted = vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(middlehighbyte), 4));
    uint8x16_t highbyte = vandq_u8(perm, vreinterpretq_u8_u32(vmovq_n_u32(0x07000000)));
    uint8x16_t highbyte_shifted =vreinterpretq_u8_u32(vshrq_n_u32(vreinterpretq_u32_u8(highbyte), 6));
    uint8x16_t composed =
        vorrq_u8(vorrq_u8(ascii, middlebyte_shifted),
                     vorrq_u8(highbyte_shifted, middlehighbyte_shifted));
    vst1q_u32(utf32_output, vreinterpretq_u32_u8(composed));
    utf32_output += 3;
  } else {
  }
  return consumed;
}
/* end file src/arm64/arm_convert_utf8_to_utf32.cpp */

/* begin file src/arm64/arm_convert_utf16_to_utf8.cpp */
/*
    The vectorized algorithm works on single SSE register i.e., it
    loads eight 16-bit words.

    We consider three cases:
    1. an input register contains no surrogates and each value
       is in range 0x0000 .. 0x07ff.
    2. an input register contains no surrogates and values are
       is in range 0x0000 .. 0xffff.
    3. an input register contains surrogates --- i.e. codepoints
       can have 16 or 32 bits.

    Ad 1.

    When values are less than 0x0800, it means that a 16-bit words
    can be converted into: 1) single UTF8 byte (when it's an ASCII
    char) or 2) two UTF8 bytes.

    For this case we do only some shuffle to obtain these 2-byte
    codes and finally compress the whole SSE register with a single
    shuffle.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.

    Ad 2.

    When values fit in 16-bit words, but are above 0x07ff, then
    a single word may produce one, two or three UTF8 bytes.

    We prepare data for all these three cases in two registers.
    The first register contains lower two UTF8 bytes (used in all
    cases), while the second one contains just the third byte for
    the three-UTF8-bytes case.

    Finally these two registers are interleaved forming eight-element
    array of 32-bit values. The array spans two SSE registers.
    The bytes from the registers are compressed using two shuffles.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.


    To summarize:
    - We need two 256-entry tables that have 8704 bytes in total.
*/
/*
  Returns a pair: the first unprocessed byte from buf and utf8_output
  A scalar routing should carry on the conversion of the tail.
*/
template <endianness big_endian>
std::pair<const char16_t*, char*> arm_convert_utf16_to_utf8(const char16_t* buf, size_t len, char* utf8_out) {
  uint8_t * utf8_output = reinterpret_cast<uint8_t*>(utf8_out);
  const char16_t* end = buf + len;

  const uint16x8_t v_f800 = vmovq_n_u16((uint16_t)0xf800);
  const uint16x8_t v_d800 = vmovq_n_u16((uint16_t)0xd800);
  const uint16x8_t v_c080 = vmovq_n_u16((uint16_t)0xc080);

  while (buf + 16 <= end) {
    uint16x8_t in = vld1q_u16(reinterpret_cast<const uint16_t *>(buf));
    if (big_endian) {
      #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
      const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
      #else
      const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
      #endif
      in = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(in), swap));
    }
    if(vmaxvq_u16(in) <= 0x7F) { // ASCII fast path!!!!
        uint16x8_t nextin = vld1q_u16(reinterpret_cast<const uint16_t *>(buf) + 8);
        if(vmaxvq_u16(nextin) > 0x7F) {
          uint8x8_t utf8_packed = vmovn_u16(in);
          vst1_u8(utf8_output, utf8_packed);
          buf += 8;
          utf8_output += 8;
          if (big_endian) {
            #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
            const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
            #else
            const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
            #endif
            nextin = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(nextin), swap));
          }
          in = nextin;
        } else {
          uint8x16_t utf8_packed = vmovn_high_u16(vmovn_u16(in), nextin);
          vst1q_u8(utf8_output, utf8_packed);
          buf += 16;
          utf8_output += 16;
          continue; // we are done for this round!
        }
    }

    if (vmaxvq_u16(in) <= 0x7FF) {
          const uint16x8_t v_1f00 = vmovq_n_u16((int16_t)0x1f00);
          const uint16x8_t v_003f = vmovq_n_u16((int16_t)0x003f);

          const uint16x8_t t0 = vshlq_n_u16(in, 2);
          const uint16x8_t t1 = vandq_u16(t0, v_1f00);
          const uint16x8_t t2 = vandq_u16(in, v_003f);
          const uint16x8_t t3 = vorrq_u16(t1, t2);
          const uint16x8_t t4 = vorrq_u16(t3, v_c080);
          const uint16x8_t v_007f = vmovq_n_u16((uint16_t)0x007F);
          const uint16x8_t one_byte_bytemask = vcleq_u16(in, v_007f);
          const uint8x16_t utf8_unpacked = vreinterpretq_u8_u16(vbslq_u16(one_byte_bytemask, in, t4));
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
          const uint16x8_t mask = make_uint16x8_t(0x0001, 0x0004,
                                    0x0010, 0x0040,
                                    0x0002, 0x0008,
                                    0x0020, 0x0080);
#else
          const uint16x8_t mask = { 0x0001, 0x0004,
                                    0x0010, 0x0040,
                                    0x0002, 0x0008,
                                    0x0020, 0x0080 };
#endif
          uint16_t m2 = vaddvq_u16(vandq_u16(one_byte_bytemask, mask));
          const uint8_t* row = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[m2][0];
          const uint8x16_t shuffle = vld1q_u8(row + 1);
          const uint8x16_t utf8_packed = vqtbl1q_u8(utf8_unpacked, shuffle);

          vst1q_u8(utf8_output, utf8_packed);

          buf += 8;
          utf8_output += row[0];
          continue;

    }
    const uint16x8_t surrogates_bytemask = vceqq_u16(vandq_u16(in, v_f800), v_d800);
      if (vmaxvq_u16(surrogates_bytemask) == 0) {
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
        const uint16x8_t dup_even = make_uint16x8_t(0x0000, 0x0202, 0x0404, 0x0606,
                                     0x0808, 0x0a0a, 0x0c0c, 0x0e0e);
#else
        const uint16x8_t dup_even = {0x0000, 0x0202, 0x0404, 0x0606,
                                     0x0808, 0x0a0a, 0x0c0c, 0x0e0e};
#endif
        /* In this branch we handle three cases:
           1. [0000|0000|0ccc|cccc] => [0ccc|cccc]                           - single UFT-8 byte
           2. [0000|0bbb|bbcc|cccc] => [110b|bbbb], [10cc|cccc]              - two UTF-8 bytes
           3. [aaaa|bbbb|bbcc|cccc] => [1110|aaaa], [10bb|bbbb], [10cc|cccc] - three UTF-8 bytes

          We expand the input word (16-bit) into two words (32-bit), thus
          we have room for four bytes. However, we need five distinct bit
          layouts. Note that the last byte in cases #2 and #3 is the same.

          We precompute byte 1 for case #1 and the common byte for cases #2 & #3
          in register t2.

          We precompute byte 1 for case #3 and -- **conditionally** -- precompute
          either byte 1 for case #2 or byte 2 for case #3. Note that they
          differ by exactly one bit.

          Finally from these two words we build proper UTF-8 sequence, taking
          into account the case (i.e, the number of bytes to write).
        */
        /**
         * Given [aaaa|bbbb|bbcc|cccc] our goal is to produce:
         * t2 => [0ccc|cccc] [10cc|cccc]
         * s4 => [1110|aaaa] ([110b|bbbb] OR [10bb|bbbb])
         */
#define vec(x) vmovq_n_u16(static_cast<uint16_t>(x))
        const uint16x8_t t0 = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(in), vreinterpretq_u8_u16(dup_even)));
        const uint16x8_t t1 = vandq_u16(t0, vec(0b0011111101111111));
        const uint16x8_t t2 = vorrq_u16 (t1, vec(0b1000000000000000));

        const uint16x8_t s0 = vshrq_n_u16(in, 12);
        const uint16x8_t s1 = vandq_u16(in, vec(0b0000111111000000));
        const uint16x8_t s1s = vshlq_n_u16(s1, 2);
        const uint16x8_t s2 = vorrq_u16(s0, s1s);
        const uint16x8_t s3 = vorrq_u16(s2, vec(0b1100000011100000));
        const uint16x8_t v_07ff = vmovq_n_u16((uint16_t)0x07FF);
        const uint16x8_t one_or_two_bytes_bytemask = vcleq_u16(in, v_07ff);
        const uint16x8_t m0 = vbicq_u16(vec(0b0100000000000000), one_or_two_bytes_bytemask);
        const uint16x8_t s4 = veorq_u16(s3, m0);
#undef vec

        const uint8x16_t out0 = vreinterpretq_u8_u16(vzip1q_u16(t2, s4));
        const uint8x16_t out1 = vreinterpretq_u8_u16(vzip2q_u16(t2, s4));

        const uint16x8_t v_007f = vmovq_n_u16((uint16_t)0x007F);
        const uint16x8_t one_byte_bytemask = vcleq_u16(in, v_007f);
#ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
        const uint16x8_t onemask = make_uint16x8_t(0x0001, 0x0004,
                                    0x0010, 0x0040,
                                    0x0100, 0x0400,
                                    0x1000, 0x4000 );
        const uint16x8_t twomask = make_uint16x8_t(0x0002, 0x0008,
                                    0x0020, 0x0080,
                                    0x0200, 0x0800,
                                    0x2000, 0x8000 );
#else
        const uint16x8_t onemask = { 0x0001, 0x0004,
                                    0x0010, 0x0040,
                                    0x0100, 0x0400,
                                    0x1000, 0x4000 };
        const uint16x8_t twomask = { 0x0002, 0x0008,
                                    0x0020, 0x0080,
                                    0x0200, 0x0800,
                                    0x2000, 0x8000 };
#endif
        const uint16x8_t combined = vorrq_u16(vandq_u16(one_byte_bytemask, onemask), vandq_u16(one_or_two_bytes_bytemask, twomask));
        const uint16_t mask = vaddvq_u16(combined);
        /*if(mask == 0) {
          const uint8x16_t shuffle = {2,3,1,6,7,5,10,11,9,14,15,13,0,0,0,0};
          const uint8x16_t utf8_0 = vqtbl1q_u8(out0, shuffle);
          const uint8x16_t utf8_1 = vqtbl1q_u8(out1, shuffle);
          vst1q_u8(utf8_output, utf8_0);
          utf8_output += 12;
          vst1q_u8(utf8_output, utf8_1);
          utf8_output += 12;
          buf += 8;
          continue;
        }*/
        const uint8_t mask0 = uint8_t(mask);

        const uint8_t* row0 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask0][0];
        const uint8x16_t shuffle0 = vld1q_u8(row0 + 1);
        const uint8x16_t utf8_0 = vqtbl1q_u8(out0, shuffle0);

        const uint8_t mask1 = static_cast<uint8_t>(mask >> 8);
        const uint8_t* row1 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask1][0];
        const uint8x16_t shuffle1 = vld1q_u8(row1 + 1);
        const uint8x16_t utf8_1 = vqtbl1q_u8(out1, shuffle1);

        vst1q_u8(utf8_output, utf8_0);
        utf8_output += row0[0];
        vst1q_u8(utf8_output, utf8_1);
        utf8_output += row1[0];

        buf += 8;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint16_t word = big_endian ? scalar::utf16::swap_bytes(buf[k]) : buf[k];
        if((word & 0xFF80)==0) {
          *utf8_output++ = char(word);
        } else if((word & 0xF800)==0) {
          *utf8_output++ = char((word>>6) | 0b11000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else if((word &0xF800 ) != 0xD800) {
          *utf8_output++ = char((word>>12) | 0b11100000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else {
          uint16_t diff = uint16_t(word - 0xD800);
          uint16_t next_word = big_endian ? scalar::utf16::swap_bytes(buf[k + 1]) : buf[k + 1];
          k++;
          uint16_t diff2 = uint16_t(next_word - 0xDC00);
          if((diff | diff2) > 0x3FF)  { return std::make_pair(nullptr, reinterpret_cast<char*>(utf8_output)); }
          uint32_t value = (diff << 10) + diff2 + 0x10000;
          *utf8_output++ = char((value>>18) | 0b11110000);
          *utf8_output++ = char(((value>>12) & 0b111111) | 0b10000000);
          *utf8_output++ = char(((value>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((value & 0b111111) | 0b10000000);
        }
      }
      buf += k;
    }
  } // while

  return std::make_pair(buf, reinterpret_cast<char*>(utf8_output));
}
/* end file src/arm64/arm_convert_utf16_to_utf8.cpp */
/* begin file src/arm64/arm_convert_utf16_to_utf32.cpp */
/*
    The vectorized algorithm works on single SSE register i.e., it
    loads eight 16-bit words.

    We consider three cases:
    1. an input register contains no surrogates and each value
       is in range 0x0000 .. 0x07ff.
    2. an input register contains no surrogates and values are
       is in range 0x0000 .. 0xffff.
    3. an input register contains surrogates --- i.e. codepoints
       can have 16 or 32 bits.

    Ad 1.

    When values are less than 0x0800, it means that a 16-bit words
    can be converted into: 1) single UTF8 byte (when it's an ASCII
    char) or 2) two UTF8 bytes.

    For this case we do only some shuffle to obtain these 2-byte
    codes and finally compress the whole SSE register with a single
    shuffle.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.

    Ad 2.

    When values fit in 16-bit words, but are above 0x07ff, then
    a single word may produce one, two or three UTF8 bytes.

    We prepare data for all these three cases in two registers.
    The first register contains lower two UTF8 bytes (used in all
    cases), while the second one contains just the third byte for
    the three-UTF8-bytes case.

    Finally these two registers are interleaved forming eight-element
    array of 32-bit values. The array spans two SSE registers.
    The bytes from the registers are compressed using two shuffles.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.


    To summarize:
    - We need two 256-entry tables that have 8704 bytes in total.
*/
/*
  Returns a pair: the first unprocessed byte from buf and utf8_output
  A scalar routing should carry on the conversion of the tail.
*/
template <endianness big_endian>
std::pair<const char16_t*, char32_t*> arm_convert_utf16_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_out) {
  uint32_t * utf32_output = reinterpret_cast<uint32_t*>(utf32_out);
  const char16_t* end = buf + len;

  const uint16x8_t v_f800 = vmovq_n_u16((uint16_t)0xf800);
  const uint16x8_t v_d800 = vmovq_n_u16((uint16_t)0xd800);

  while (buf + 16 <= end) {
    uint16x8_t in = vld1q_u16(reinterpret_cast<const uint16_t *>(buf));
    if (big_endian) {
      #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
      const uint8x16_t swap = make_uint8x16_t(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
      #else
      const uint8x16_t swap = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14};
      #endif
      in = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(in), swap));
    }

    const uint16x8_t surrogates_bytemask = vceqq_u16(vandq_u16(in, v_f800), v_d800);
      if (vmaxvq_u16(surrogates_bytemask) == 0) {
      vst1q_u32(utf32_output,  vmovl_u16(vget_low_u16(in)));
      vst1q_u32(utf32_output+4,  vmovl_high_u16(in));
      utf32_output += 8;
      buf += 8;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint16_t word = big_endian ? scalar::utf16::swap_bytes(buf[k]) : buf[k];
        if((word &0xF800 ) != 0xD800) {
          *utf32_output++ = char32_t(word);
        } else {
          uint16_t diff = uint16_t(word - 0xD800);
          uint16_t next_word = big_endian ? scalar::utf16::swap_bytes(buf[k + 1]) : buf[k + 1];
          k++;
          uint16_t diff2 = uint16_t(next_word - 0xDC00);
          if((diff | diff2) > 0x3FF)  { return std::make_pair(nullptr, reinterpret_cast<char32_t*>(utf32_output)); }
          uint32_t value = (diff << 10) + diff2 + 0x10000;
          *utf32_output++ = char32_t(value);
        }
      }
      buf += k;
    }
  } // while
  return std::make_pair(buf, reinterpret_cast<char32_t*>(utf32_output));
}
/* end file src/arm64/arm_convert_utf16_to_utf32.cpp */

/* begin file src/arm64/arm_convert_utf32_to_utf8.cpp */
std::pair<const char32_t*, char*> arm_convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_out) {
  uint8_t * utf8_output = reinterpret_cast<uint8_t*>(utf8_out);
  const char32_t* end = buf + len;

  const uint16x8_t v_c080 = vmovq_n_u16((uint16_t)0xc080);

  uint16x8_t forbidden_bytemask = vmovq_n_u16(0x0);

  while (buf + 16 <= end) {
    uint32x4_t in = vld1q_u32(reinterpret_cast<const uint32_t *>(buf));
    uint32x4_t nextin = vld1q_u32(reinterpret_cast<const uint32_t *>(buf+4));

    if(vmaxvq_u32(vorrq_u32(in, nextin)) <= 0xFFFF) {
      uint16x8_t utf16_packed = vcombine_u16(vmovn_u32(in), vmovn_u32(nextin));
      if(vmaxvq_u16(utf16_packed) <= 0x7F) { // ASCII fast path!!!!
          uint8x8_t utf8_packed = vmovn_u16(utf16_packed);
          vst1_u8(utf8_output, utf8_packed);
          buf += 8;
          utf8_output += 8;
          continue; // we are done for this round!
      }

      if (vmaxvq_u16(utf16_packed) <= 0x7FF) {
            const uint16x8_t v_1f00 = vmovq_n_u16((int16_t)0x1f00);
            const uint16x8_t v_003f = vmovq_n_u16((int16_t)0x003f);

            const uint16x8_t t0 = vshlq_n_u16(utf16_packed, 2);
            const uint16x8_t t1 = vandq_u16(t0, v_1f00);
            const uint16x8_t t2 = vandq_u16(utf16_packed, v_003f);
            const uint16x8_t t3 = vorrq_u16(t1, t2);
            const uint16x8_t t4 = vorrq_u16(t3, v_c080);
            const uint16x8_t v_007f = vmovq_n_u16((uint16_t)0x007F);
            const uint16x8_t one_byte_bytemask = vcleq_u16(utf16_packed, v_007f);
            const uint8x16_t utf8_unpacked = vreinterpretq_u8_u16(vbslq_u16(one_byte_bytemask, utf16_packed, t4));
  #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
            const uint16x8_t mask = make_uint16x8_t(0x0001, 0x0004,
                                      0x0010, 0x0040,
                                      0x0002, 0x0008,
                                      0x0020, 0x0080);
  #else
            const uint16x8_t mask = { 0x0001, 0x0004,
                                      0x0010, 0x0040,
                                      0x0002, 0x0008,
                                      0x0020, 0x0080 };
  #endif
            uint16_t m2 = vaddvq_u16(vandq_u16(one_byte_bytemask, mask));
            const uint8_t* row = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[m2][0];
            const uint8x16_t shuffle = vld1q_u8(row + 1);
            const uint8x16_t utf8_packed = vqtbl1q_u8(utf8_unpacked, shuffle);

            vst1q_u8(utf8_output, utf8_packed);

            buf += 8;
            utf8_output += row[0];
            continue;

      } else {
        const uint16x8_t v_d800 = vmovq_n_u16((uint16_t)0xd800);
        const uint16x8_t v_dfff = vmovq_n_u16((uint16_t)0xdfff);
        forbidden_bytemask = vorrq_u16(vandq_u16(vcleq_u16(utf16_packed, v_dfff), vcgeq_u16(utf16_packed, v_d800)), forbidden_bytemask);

  #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
          const uint16x8_t dup_even = make_uint16x8_t(0x0000, 0x0202, 0x0404, 0x0606,
                                      0x0808, 0x0a0a, 0x0c0c, 0x0e0e);
  #else
          const uint16x8_t dup_even = {0x0000, 0x0202, 0x0404, 0x0606,
                                      0x0808, 0x0a0a, 0x0c0c, 0x0e0e};
  #endif
          /* In this branch we handle three cases:
            1. [0000|0000|0ccc|cccc] => [0ccc|cccc]                           - single UFT-8 byte
            2. [0000|0bbb|bbcc|cccc] => [110b|bbbb], [10cc|cccc]              - two UTF-8 bytes
            3. [aaaa|bbbb|bbcc|cccc] => [1110|aaaa], [10bb|bbbb], [10cc|cccc] - three UTF-8 bytes

            We expand the input word (16-bit) into two words (32-bit), thus
            we have room for four bytes. However, we need five distinct bit
            layouts. Note that the last byte in cases #2 and #3 is the same.

            We precompute byte 1 for case #1 and the common byte for cases #2 & #3
            in register t2.

            We precompute byte 1 for case #3 and -- **conditionally** -- precompute
            either byte 1 for case #2 or byte 2 for case #3. Note that they
            differ by exactly one bit.

            Finally from these two words we build proper UTF-8 sequence, taking
            into account the case (i.e, the number of bytes to write).
          */
          /**
           * Given [aaaa|bbbb|bbcc|cccc] our goal is to produce:
           * t2 => [0ccc|cccc] [10cc|cccc]
           * s4 => [1110|aaaa] ([110b|bbbb] OR [10bb|bbbb])
           */
  #define vec(x) vmovq_n_u16(static_cast<uint16_t>(x))
          const uint16x8_t t0 = vreinterpretq_u16_u8(vqtbl1q_u8(vreinterpretq_u8_u16(utf16_packed), vreinterpretq_u8_u16(dup_even)));
          const uint16x8_t t1 = vandq_u16(t0, vec(0b0011111101111111));
          const uint16x8_t t2 = vorrq_u16 (t1, vec(0b1000000000000000));

          const uint16x8_t s0 = vshrq_n_u16(utf16_packed, 12);
          const uint16x8_t s1 = vandq_u16(utf16_packed, vec(0b0000111111000000));
          const uint16x8_t s1s = vshlq_n_u16(s1, 2);
          const uint16x8_t s2 = vorrq_u16(s0, s1s);
          const uint16x8_t s3 = vorrq_u16(s2, vec(0b1100000011100000));
          const uint16x8_t v_07ff = vmovq_n_u16((uint16_t)0x07FF);
          const uint16x8_t one_or_two_bytes_bytemask = vcleq_u16(utf16_packed, v_07ff);
          const uint16x8_t m0 = vbicq_u16(vec(0b0100000000000000), one_or_two_bytes_bytemask);
          const uint16x8_t s4 = veorq_u16(s3, m0);
  #undef vec

          const uint8x16_t out0 = vreinterpretq_u8_u16(vzip1q_u16(t2, s4));
          const uint8x16_t out1 = vreinterpretq_u8_u16(vzip2q_u16(t2, s4));

          const uint16x8_t v_007f = vmovq_n_u16((uint16_t)0x007F);
          const uint16x8_t one_byte_bytemask = vcleq_u16(utf16_packed, v_007f);
  #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
          const uint16x8_t onemask = make_uint16x8_t(0x0001, 0x0004,
                                      0x0010, 0x0040,
                                      0x0100, 0x0400,
                                      0x1000, 0x4000 );
          const uint16x8_t twomask = make_uint16x8_t(0x0002, 0x0008,
                                      0x0020, 0x0080,
                                      0x0200, 0x0800,
                                      0x2000, 0x8000 );
  #else
          const uint16x8_t onemask = { 0x0001, 0x0004,
                                      0x0010, 0x0040,
                                      0x0100, 0x0400,
                                      0x1000, 0x4000 };
          const uint16x8_t twomask = { 0x0002, 0x0008,
                                      0x0020, 0x0080,
                                      0x0200, 0x0800,
                                      0x2000, 0x8000 };
  #endif
          const uint16x8_t combined = vorrq_u16(vandq_u16(one_byte_bytemask, onemask), vandq_u16(one_or_two_bytes_bytemask, twomask));
          const uint16_t mask = vaddvq_u16(combined);
          /*if(mask == 0) {
            const uint8x16_t shuffle = {2,3,1,6,7,5,10,11,9,14,15,13,0,0,0,0};
            const uint8x16_t utf8_0 = vqtbl1q_u8(out0, shuffle);
            const uint8x16_t utf8_1 = vqtbl1q_u8(out1, shuffle);
            vst1q_u8(utf8_output, utf8_0);
            utf8_output += 12;
            vst1q_u8(utf8_output, utf8_1);
            utf8_output += 12;
            buf += 8;
            continue;
          }*/
          const uint8_t mask0 = uint8_t(mask);

          const uint8_t* row0 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask0][0];
          const uint8x16_t shuffle0 = vld1q_u8(row0 + 1);
          const uint8x16_t utf8_0 = vqtbl1q_u8(out0, shuffle0);

          const uint8_t mask1 = static_cast<uint8_t>(mask >> 8);
          const uint8_t* row1 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask1][0];
          const uint8x16_t shuffle1 = vld1q_u8(row1 + 1);
          const uint8x16_t utf8_1 = vqtbl1q_u8(out1, shuffle1);

          vst1q_u8(utf8_output, utf8_0);
          utf8_output += row0[0];
          vst1q_u8(utf8_output, utf8_1);
          utf8_output += row1[0];

          buf += 8;
      }
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint32_t word = buf[k];
        if((word & 0xFFFFFF80)==0) {
          *utf8_output++ = char(word);
        } else if((word & 0xFFFFF800)==0) {
          *utf8_output++ = char((word>>6) | 0b11000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else if((word & 0xFFFF0000)==0) {
          if (word >= 0xD800 && word <= 0xDFFF) { return std::make_pair(nullptr, reinterpret_cast<char*>(utf8_output)); }
          *utf8_output++ = char((word>>12) | 0b11100000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else {
          if (word > 0x10FFFF) { return std::make_pair(nullptr, reinterpret_cast<char*>(utf8_output)); }
          *utf8_output++ = char((word>>18) | 0b11110000);
          *utf8_output++ = char(((word>>12) & 0b111111) | 0b10000000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        }
      }
      buf += k;
    }
  } // while

  if (vmaxvq_u16(forbidden_bytemask) != 0) {
    return std::make_pair(nullptr, reinterpret_cast<char*>(utf8_output));
  }
  return std::make_pair(buf, reinterpret_cast<char*>(utf8_output));
}
/* end file src/arm64/arm_convert_utf32_to_utf8.cpp */
/* begin file src/arm64/arm_convert_utf32_to_utf16.cpp */
template <endianness big_endian>
std::pair<const char32_t*, char16_t*> arm_convert_utf32_to_utf16(const char32_t* buf, size_t len, char16_t* utf16_out) {
  uint16_t * utf16_output = reinterpret_cast<uint16_t*>(utf16_out);
  const char32_t* end = buf + len;

  uint16x4_t forbidden_bytemask = vmov_n_u16(0x0);

  while(buf + 4 <= end) {
    uint32x4_t in = vld1q_u32(reinterpret_cast<const uint32_t *>(buf));

    if(vmaxvq_u32(in) <= 0xFFFF) {
      uint16x4_t utf16_packed = vmovn_u32(in);

      const uint16x4_t v_d800 = vmov_n_u16((uint16_t)0xd800);
      const uint16x4_t v_dfff = vmov_n_u16((uint16_t)0xdfff);
      forbidden_bytemask = vorr_u16(vand_u16(vcle_u16(utf16_packed, v_dfff), vcge_u16(utf16_packed, v_d800)), forbidden_bytemask);

      if (big_endian) {
        #ifdef SIMDUTF_REGULAR_VISUAL_STUDIO
        const uint8x8_t swap = make_uint8x8_t(1, 0, 3, 2, 5, 4, 7, 6);
        #else
        const uint8x8_t swap = {1, 0, 3, 2, 5, 4, 7, 6};
        #endif
        utf16_packed = vreinterpret_u16_u8(vtbl1_u8(vreinterpret_u8_u16(utf16_packed), swap));
      }
      vst1_u16(utf16_output, utf16_packed);
      utf16_output += 4;
      buf += 4;
    } else {
      size_t forward = 3;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint32_t word = buf[k];
        if((word & 0xFFFF0000)==0) {
          if (word >= 0xD800 && word <= 0xDFFF) { return std::make_pair(nullptr, reinterpret_cast<char16_t*>(utf16_output)); }
          *utf16_output++ = big_endian ? char16_t(word >> 8 | word << 8) : char16_t(word);
        } else {
          if (word > 0x10FFFF) { return std::make_pair(nullptr, reinterpret_cast<char16_t*>(utf16_output)); }
          word -= 0x10000;
          uint16_t high_surrogate = uint16_t(0xD800 + (word >> 10));
          uint16_t low_surrogate = uint16_t(0xDC00 + (word & 0x3FF));
          if (big_endian) {
            high_surrogate = uint16_t(high_surrogate >> 8 | high_surrogate << 8);
            low_surrogate = uint16_t(low_surrogate << 8 | low_surrogate >> 8);
          }
          *utf16_output++ = char16_t(high_surrogate);
          *utf16_output++ = char16_t(low_surrogate);
        }
      }
      buf += k;
    }
  }

  if (vmaxv_u16(forbidden_bytemask) != 0) {
    return std::make_pair(nullptr, reinterpret_cast<char16_t*>(utf16_output));
  }

  return std::make_pair(buf, reinterpret_cast<char16_t*>(utf16_output));
}
/* end file src/arm64/arm_convert_utf32_to_utf16.cpp */
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* begin file src/generic/buf_block_reader.h */
namespace simdutf {
namespace arm64 {
namespace {

template<size_t STEP_SIZE>
struct buf_block_reader {
public:
  simdutf_really_inline buf_block_reader(const uint8_t *_buf, size_t _len);
  simdutf_really_inline size_t block_index();
  simdutf_really_inline bool has_full_block() const;
  simdutf_really_inline const uint8_t *full_block() const;
  /**
   * Get the last block, padded with spaces.
   *
   * There will always be a last block, with at least 1 byte, unless len == 0 (in which case this
   * function fills the buffer with spaces and returns 0. In particular, if len == STEP_SIZE there
   * will be 0 full_blocks and 1 remainder block with STEP_SIZE bytes and no spaces for padding.
   *
   * @return the number of effective characters in the last block.
   */
  simdutf_really_inline size_t get_remainder(uint8_t *dst) const;
  simdutf_really_inline void advance();
private:
  const uint8_t *buf;
  const size_t len;
  const size_t lenminusstep;
  size_t idx;
};

simdutf_unused static char * format_input_text_64(const uint8_t *text) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    buf[i] = int8_t(text[i]) < ' ' ? '_' : int8_t(text[i]);
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_input_text(const simd8x64<uint8_t>& in) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  in.store(reinterpret_cast<uint8_t*>(buf));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    if (buf[i] < ' ') { buf[i] = '_'; }
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_mask(uint64_t mask) {
  static char *buf = reinterpret_cast<char*>(malloc(64 + 1));
  for (size_t i=0; i<64; i++) {
    buf[i] = (mask & (size_t(1) << i)) ? 'X' : ' ';
  }
  buf[64] = '\0';
  return buf;
}

template<size_t STEP_SIZE>
simdutf_really_inline buf_block_reader<STEP_SIZE>::buf_block_reader(const uint8_t *_buf, size_t _len) : buf{_buf}, len{_len}, lenminusstep{len < STEP_SIZE ? 0 : len - STEP_SIZE}, idx{0} {}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::block_index() { return idx; }

template<size_t STEP_SIZE>
simdutf_really_inline bool buf_block_reader<STEP_SIZE>::has_full_block() const {
  return idx < lenminusstep;
}

template<size_t STEP_SIZE>
simdutf_really_inline const uint8_t *buf_block_reader<STEP_SIZE>::full_block() const {
  return &buf[idx];
}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::get_remainder(uint8_t *dst) const {
  if(len == idx) { return 0; } // memcpy(dst, null, 0) will trigger an error with some sanitizers
  std::memset(dst, 0x20, STEP_SIZE); // std::memset STEP_SIZE because it's more efficient to write out 8 or 16 bytes at once.
  std::memcpy(dst, buf + idx, len - idx);
  return len - idx;
}

template<size_t STEP_SIZE>
simdutf_really_inline void buf_block_reader<STEP_SIZE>::advance() {
  idx += STEP_SIZE;
}

} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/buf_block_reader.h */
/* begin file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
namespace simdutf {
namespace arm64 {
namespace {
namespace utf8_validation {

using namespace simd;

  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }

  simdutf_really_inline simd8<uint8_t> is_incomplete(const simd8<uint8_t> input) {
    static const uint8_t max_array[32] = {
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 0b11110000u-1, 0b11100000u-1, 0b11000000u-1
    };
    const simd8<uint8_t> max_value(&max_array[sizeof(max_array)-sizeof(simd8<uint8_t>)]);
    return input.gt_bits(max_value);
  }

  struct utf8_checker {
    simd8<uint8_t> error;
    simd8<uint8_t> prev_input_block;
    simd8<uint8_t> prev_incomplete;

    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }

    simdutf_really_inline void check_eof() {
      this->error |= this->prev_incomplete;
    }

    simdutf_really_inline void check_next_input(const simd8x64<uint8_t>& input) {
      if(simdutf_likely(is_ascii(input))) {
        this->error |= this->prev_incomplete;
      } else {
        static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
            "We support either two or four chunks per 64-byte block.");
        if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
        } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
          this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
        }
        this->prev_incomplete = is_incomplete(input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1]);
        this->prev_input_block = input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1];

      }
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // namespace utf8_validation

using utf8_validation::utf8_checker;

} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
/* begin file src/generic/utf8_validation/utf8_validator.h */
namespace simdutf {
namespace arm64 {
namespace {
namespace utf8_validation {

/**
 * Validates that the string is actual UTF-8.
 */
template<class checker>
bool generic_validate_utf8(const uint8_t * input, size_t length) {
    checker c{};
    buf_block_reader<64> reader(input, length);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      c.check_next_input(in);
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    c.check_next_input(in);
    reader.advance();
    c.check_eof();
    return !c.errors();
}

bool generic_validate_utf8(const char * input, size_t length) {
    return generic_validate_utf8<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

template<class checker>
bool generic_validate_ascii(const uint8_t * input, size_t length) {
    buf_block_reader<64> reader(input, length);
    uint8_t blocks[64]{};
    simd::simd8x64<uint8_t> running_or(blocks);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      running_or |= in;
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    running_or |= in;
    reader.advance();
    return running_or.is_ascii();
}

bool generic_validate_ascii(const char * input, size_t length) {
    return generic_validate_ascii<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

} // namespace utf8_validation
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_validator.h */
/* begin file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */


namespace simdutf {
namespace arm64 {
namespace {
namespace utf8_to_utf16 {

using namespace simd;

template <endianness endian>
simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char16_t* utf16_output) noexcept {
  size_t pos = 0;
  char16_t* start{utf16_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf16<endian>(utf16_output);
      utf16_output += 64;
      pos += 64;
    } else {
      uint64_t utf8_continuation_mask = in.lt(-65 + 1);
      uint64_t utf8_leading_mask = ~utf8_continuation_mask;
      uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
      size_t max_starting_point = (pos + 64) - 12;
      while(pos < max_starting_point) {
        size_t consumed = convert_masked_utf8_to_utf16<endian>(input + pos,
                            utf8_end_of_code_point_mask, utf16_output);
        pos += consumed;
        utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf16_output += scalar::utf8_to_utf16::convert_valid<endian>(input + pos, size - pos, utf16_output);
  return utf16_output - start;
}

} // namespace utf8_to_utf16
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf16/utf8_to_utf16.h */


namespace simdutf {
namespace arm64 {
namespace {
namespace utf8_to_utf16 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }


    template <endianness endian>
    simdutf_really_inline size_t convert(const char* in, size_t size, char16_t* utf16_output) {
      size_t pos = 0;
      char16_t* start{utf16_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf16<endian>(utf16_output);
          utf16_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf16<endian>(in + pos,
                            utf8_end_of_code_point_mask, utf16_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf16::convert<endian>(in + pos, size - pos, utf16_output);
        if(howmany == 0) { return 0; }
        utf16_output += howmany;
      }
      return utf16_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf16 namespace
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */

namespace simdutf {
namespace arm64 {
namespace {
namespace utf8_to_utf32 {

using namespace simd;


simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char32_t* utf32_output) noexcept {
  size_t pos = 0;
  char32_t* start{utf32_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf32(utf32_output);
      utf32_output += 64;
      pos += 64;
    } else {
    uint64_t utf8_continuation_mask = in.lt(-65 + 1);
    uint64_t utf8_leading_mask = ~utf8_continuation_mask;
    uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
    size_t max_starting_point = (pos + 64) - 12;
    while(pos < max_starting_point) {
      size_t consumed = convert_masked_utf8_to_utf32(input + pos,
                          utf8_end_of_code_point_mask, utf32_output);
      pos += consumed;
      utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf32_output += scalar::utf8_to_utf32::convert_valid(input + pos, size - pos, utf32_output);
  return utf32_output - start;
}


} // namespace utf8_to_utf32
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */
/* begin file src/generic/utf8_to_utf32/utf8_to_utf32.h */


namespace simdutf {
namespace arm64 {
namespace {
namespace utf8_to_utf32 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }



    simdutf_really_inline size_t convert(const char* in, size_t size, char32_t* utf32_output) {
      size_t pos = 0;
      char32_t* start{utf32_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf32(utf32_output);
          utf32_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf32(in + pos,
                            utf8_end_of_code_point_mask, utf32_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf32::convert(in + pos, size - pos, utf32_output);
        if(howmany == 0) { return 0; }
        utf32_output += howmany;
      }
      return utf32_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf32 namespace
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/utf8_to_utf32.h */
/* begin file src/generic/utf8.h */

namespace simdutf {
namespace arm64 {
namespace {
namespace utf8 {

using namespace simd;

simdutf_really_inline size_t count_code_points(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::count_code_points(in + pos, size - pos);
}


simdutf_really_inline size_t utf16_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
      int64_t utf8_4byte = input.gteq_unsigned(240);
      count += count_ones(utf8_4byte);
    }
    return count + scalar::utf8::utf16_length_from_utf8(in + pos, size - pos);
}


simdutf_really_inline size_t utf32_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::utf32_length_from_utf8(in + pos, size - pos);
}
} // utf8 namespace
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf8.h */
/* begin file src/generic/utf16.h */
#include <iostream>
namespace simdutf {
namespace arm64 {
namespace {
namespace utf16 {

template <endianness big_endian>
simdutf_really_inline size_t count_code_points(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::count_code_points<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf8_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t ascii_mask = input.lteq(0x7F);
      uint64_t twobyte_mask = input.lteq(0x7FF);
      uint64_t not_pair_mask = input.not_in_range(0xD800, 0xDFFF);

      size_t ascii_count = count_ones(ascii_mask) / 2;
      size_t twobyte_count = count_ones(twobyte_mask & ~ ascii_mask) / 2;
      size_t threebyte_count = count_ones(not_pair_mask & ~ twobyte_mask) / 2;
      size_t fourbyte_count = 32 - count_ones(not_pair_mask) / 2;
      count += 2 * fourbyte_count + 3 * threebyte_count + 2 * twobyte_count + ascii_count;
    }
    return count + scalar::utf16::utf8_length_from_utf16<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf32_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::utf32_length_from_utf16<big_endian>(in + pos, size - pos);
}

simdutf_really_inline void change_endianness_utf16(const char16_t* in, size_t size, char16_t* output) {
  size_t pos = 0;

  while (pos + 32 <= size) {
    simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
    input.swap_bytes();
    input.store(reinterpret_cast<uint16_t *>(output));
    pos += 32;
    output += 32;
  }

  scalar::utf16::change_endianness_utf16(in + pos, size - pos, output);
}

} // utf16
} // unnamed namespace
} // namespace arm64
} // namespace simdutf
/* end file src/generic/utf16.h */
namespace simdutf {
namespace arm64 {

simdutf_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept {
  return arm64::utf8_validation::generic_validate_utf8(buf,len);
}

simdutf_warn_unused bool implementation::validate_ascii(const char *buf, size_t len) const noexcept {
  return arm64::utf8_validation::generic_validate_ascii(buf,len);
}

simdutf_warn_unused bool implementation::validate_utf16le(const char16_t *buf, size_t len) const noexcept {
  const char16_t* tail = arm_validate_utf16<endianness::LITTLE>(buf, len);
  if (tail) {
    return scalar::utf16::validate<endianness::LITTLE>(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused bool implementation::validate_utf16be(const char16_t *buf, size_t len) const noexcept {
  const char16_t* tail = arm_validate_utf16<endianness::BIG>(buf, len);
  if (tail) {
    return scalar::utf16::validate<endianness::BIG>(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused bool implementation::validate_utf32(const char32_t *buf, size_t len) const noexcept {
  const char32_t* tail = arm_validate_utf32le(buf, len);
  if (tail) {
    return scalar::utf32::validate(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16le(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
  utf8_to_utf16::validating_transcoder converter;
  return converter.convert<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16be(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
  utf8_to_utf16::validating_transcoder converter;
  return converter.convert<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16le(const char* input, size_t size,
    char16_t* utf16_output) const noexcept {
  return utf8_to_utf16::convert_valid<endianness::LITTLE>(input, size,  utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16be(const char* input, size_t size,
    char16_t* utf16_output) const noexcept {
  return utf8_to_utf16::convert_valid<endianness::BIG>(input, size,  utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf32(const char* buf, size_t len, char32_t* utf32_output) const noexcept {
  utf8_to_utf32::validating_transcoder converter;
  return converter.convert(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf32(const char* input, size_t size,
    char32_t* utf32_output) const noexcept {
  return utf8_to_utf32::convert_valid(input, size,  utf32_output);
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char16_t*, char*> ret = arm_convert_utf16_to_utf8<endianness::LITTLE>(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf8::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char16_t*, char*> ret = arm_convert_utf16_to_utf8<endianness::BIG>(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf8::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf16le_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf16be_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char32_t*, char*> ret = arm_convert_utf32_to_utf8(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf8::convert(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  std::pair<const char16_t*, char32_t*> ret = arm_convert_utf16_to_utf32<endianness::LITTLE>(buf, len, utf32_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf32_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf32::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  std::pair<const char16_t*, char32_t*> ret = arm_convert_utf16_to_utf32<endianness::BIG>(buf, len, utf32_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf32_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf32::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf32_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  std::pair<const char32_t*, char16_t*> ret = arm_convert_utf32_to_utf16<endianness::LITTLE>(buf, len, utf16_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf16_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf16::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  std::pair<const char32_t*, char16_t*> ret = arm_convert_utf32_to_utf16<endianness::BIG>(buf, len, utf16_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf16_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf16::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return convert_utf32_to_utf16le(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return convert_utf32_to_utf16be(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return convert_utf16le_to_utf32(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return convert_utf16be_to_utf32(buf, len, utf32_output);
}

void implementation::change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) const noexcept {
  utf16::change_endianness_utf16(input, length, output);
}

simdutf_warn_unused size_t implementation::count_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::count_code_points<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::count_code_points<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf8(const char * input, size_t length) const noexcept {
  return utf8::count_code_points(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::utf8_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::utf8_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::utf32_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::utf32_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf8(const char * input, size_t length) const noexcept {
  return utf8::utf16_length_from_utf8(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  const uint32x4_t v_7f = vmovq_n_u32((uint32_t)0x7f);
  const uint32x4_t v_7ff = vmovq_n_u32((uint32_t)0x7ff);
  const uint32x4_t v_ffff = vmovq_n_u32((uint32_t)0xffff);
  const uint32x4_t v_1 = vmovq_n_u32((uint32_t)0x1);
  size_t pos = 0;
  size_t count = 0;
  for(;pos + 4 <= length; pos += 4) {
    uint32x4_t in = vld1q_u32(reinterpret_cast<const uint32_t *>(input + pos));
    const uint32x4_t ascii_bytes_bytemask = vcleq_u32(in, v_7f);
    const uint32x4_t one_two_bytes_bytemask = vcleq_u32(in, v_7ff);
    const uint32x4_t two_bytes_bytemask = veorq_u32(one_two_bytes_bytemask, ascii_bytes_bytemask);
    const uint32x4_t three_bytes_bytemask = veorq_u32(vcleq_u32(in, v_ffff), one_two_bytes_bytemask);

    const uint16x8_t reduced_ascii_bytes_bytemask = vreinterpretq_u16_u32(vandq_u32(ascii_bytes_bytemask, v_1));
    const uint16x8_t reduced_two_bytes_bytemask = vreinterpretq_u16_u32(vandq_u32(two_bytes_bytemask, v_1));
    const uint16x8_t reduced_three_bytes_bytemask = vreinterpretq_u16_u32(vandq_u32(three_bytes_bytemask, v_1));

    const uint16x8_t compressed_bytemask0 = vpaddq_u16(reduced_ascii_bytes_bytemask, reduced_two_bytes_bytemask);
    const uint16x8_t compressed_bytemask1 = vpaddq_u16(reduced_three_bytes_bytemask, reduced_three_bytes_bytemask);

    size_t ascii_count = count_ones(vgetq_lane_u64(vreinterpretq_u64_u16(compressed_bytemask0), 0));
    size_t two_bytes_count = count_ones(vgetq_lane_u64(vreinterpretq_u64_u16(compressed_bytemask0), 1));
    size_t three_bytes_count = count_ones(vgetq_lane_u64(vreinterpretq_u64_u16(compressed_bytemask1), 0));

    count += 16 - 3*ascii_count - 2*two_bytes_count - three_bytes_count;
  }
  return count + scalar::utf32::utf8_length_from_utf32(input + pos, length - pos);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  const uint32x4_t v_ffff = vmovq_n_u32((uint32_t)0xffff);
  const uint32x4_t v_1 = vmovq_n_u32((uint32_t)0x1);
  size_t pos = 0;
  size_t count = 0;
  for(;pos + 4 <= length; pos += 4) {
    uint32x4_t in = vld1q_u32(reinterpret_cast<const uint32_t *>(input + pos));
    const uint32x4_t surrogate_bytemask = vcgtq_u32(in, v_ffff);
    const uint16x8_t reduced_bytemask = vreinterpretq_u16_u32(vandq_u32(surrogate_bytemask, v_1));
    const uint16x8_t compressed_bytemask = vpaddq_u16(reduced_bytemask, reduced_bytemask);
    size_t surrogate_count = count_ones(vgetq_lane_u64(vreinterpretq_u64_u16(compressed_bytemask), 0));
    count += 4 + surrogate_count;
  }
  return count + scalar::utf32::utf16_length_from_utf32(input + pos, length - pos);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf8(const char * input, size_t length) const noexcept {
  return utf8::utf32_length_from_utf8(input, length);
}

} // namespace arm64
} // namespace simdutf

/* begin file src/simdutf/arm64/end.h */
/* end file src/simdutf/arm64/end.h */
/* end file src/arm64/implementation.cpp */
#endif
#if SIMDUTF_IMPLEMENTATION_FALLBACK
/* begin file src/fallback/implementation.cpp */
/* begin file src/simdutf/fallback/begin.h */
/* end file src/simdutf/fallback/begin.h */








namespace simdutf {
namespace fallback {

simdutf_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept {
    return scalar::utf8::validate(buf, len);
}

simdutf_warn_unused bool implementation::validate_ascii(const char *buf, size_t len) const noexcept {
    return scalar::ascii::validate(buf, len);
}

simdutf_warn_unused bool implementation::validate_utf16le(const char16_t *buf, size_t len) const noexcept {
    return scalar::utf16::validate<endianness::LITTLE>(buf, len);
}

simdutf_warn_unused bool implementation::validate_utf16be(const char16_t *buf, size_t len) const noexcept {
    return scalar::utf16::validate<endianness::BIG>(buf, len);
}

simdutf_warn_unused bool implementation::validate_utf32(const char32_t *buf, size_t len) const noexcept {
    return scalar::utf32::validate(buf, len);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16le(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
   return scalar::utf8_to_utf16::convert<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16be(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
   return scalar::utf8_to_utf16::convert<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16le(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
   return scalar::utf8_to_utf16::convert_valid<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16be(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
   return scalar::utf8_to_utf16::convert_valid<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf32(const char* buf, size_t len, char32_t* utf32_output) const noexcept {
   return scalar::utf8_to_utf32::convert(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf32(const char* input, size_t size,
    char32_t* utf32_output) const noexcept {
  return scalar::utf8_to_utf32::convert_valid(input, size,  utf32_output);
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert<endianness::LITTLE>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert<endianness::BIG>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert_valid<endianness::LITTLE>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert_valid<endianness::BIG>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf32_to_utf8::convert(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf32_to_utf8::convert_valid(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert_valid<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert_valid<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert<endianness::LITTLE>(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert<endianness::BIG>(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert_valid<endianness::LITTLE>(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert_valid<endianness::BIG>(buf, len, utf32_output);
}

void implementation::change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) const noexcept {
  scalar::utf16::change_endianness_utf16(input, length, output);
}

simdutf_warn_unused size_t implementation::count_utf16le(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::count_code_points<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf16be(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::count_code_points<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf8(const char * input, size_t length) const noexcept {
  return scalar::utf8::count_code_points(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf8_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf8_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf32_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf32_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf8(const char * input, size_t length) const noexcept {
  return scalar::utf8::utf16_length_from_utf8(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  return scalar::utf32::utf8_length_from_utf32(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  return scalar::utf32::utf16_length_from_utf32(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf8(const char * input, size_t length) const noexcept {
  return scalar::utf8::utf32_length_from_utf8(input, length);
}

} // namespace fallback
} // namespace simdutf

/* begin file src/simdutf/fallback/end.h */
/* end file src/simdutf/fallback/end.h */
/* end file src/fallback/implementation.cpp */
#endif
#if SIMDUTF_IMPLEMENTATION_HASWELL
/* begin file src/haswell/implementation.cpp */

/* begin file src/simdutf/haswell/begin.h */
SIMDUTF_TARGET_HASWELL
/* end file src/simdutf/haswell/begin.h */
namespace simdutf {
namespace haswell {
namespace {
#ifndef SIMDUTF_HASWELL_H
#error "haswell.h must be included"
#endif
using namespace simd;


simdutf_really_inline bool is_ascii(const simd8x64<uint8_t>& input) {
  return input.reduce_or().is_ascii();
}

simdutf_unused simdutf_really_inline simd8<bool> must_be_continuation(const simd8<uint8_t> prev1, const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
  simd8<uint8_t> is_second_byte = prev1.saturating_sub(0b11000000u-1); // Only 11______ will be > 0
  simd8<uint8_t> is_third_byte  = prev2.saturating_sub(0b11100000u-1); // Only 111_____ will be > 0
  simd8<uint8_t> is_fourth_byte = prev3.saturating_sub(0b11110000u-1); // Only 1111____ will be > 0
  return simd8<int8_t>(is_second_byte | is_third_byte | is_fourth_byte) > int8_t(0);
}

simdutf_really_inline simd8<bool> must_be_2_3_continuation(const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
  simd8<uint8_t> is_third_byte  = prev2.saturating_sub(0b11100000u-1); // Only 111_____ will be > 0
  simd8<uint8_t> is_fourth_byte = prev3.saturating_sub(0b11110000u-1); // Only 1111____ will be > 0
  return simd8<int8_t>(is_third_byte | is_fourth_byte) > int8_t(0);
}

/* begin file src/haswell/avx2_validate_utf16.cpp */
/*
    In UTF-16 words in range 0xD800 to 0xDFFF have special meaning.

    In a vectorized algorithm we want to examine the most significant
    nibble in order to select a fast path. If none of highest nibbles
    are 0xD (13), than we are sure that UTF-16 chunk in a vector
    register is valid.

    Let us analyze what we need to check if the nibble is 0xD. The
    value of the preceding nibble determines what we have:

    0xd000 .. 0xd7ff - a valid word
    0xd800 .. 0xdbff - low surrogate
    0xdc00 .. 0xdfff - high surrogate

    Other constraints we have to consider:
    - there must not be two consecutive low surrogates (0xd800 .. 0xdbff)
    - there must not be two consecutive high surrogates (0xdc00 .. 0xdfff)
    - there must not be sole low surrogate nor high surrogate

    We're going to build three bitmasks based on the 3rd nibble:
    - V = valid word,
    - L = low surrogate (0xd800 .. 0xdbff)
    - H = high surrogate (0xdc00 .. 0xdfff)

      0   1   2   3   4   5   6   7    <--- word index
    [ V | L | H | L | H | V | V | L ]
      1   0   0   0   0   1   1   0     - V = valid masks
      0   1   0   1   0   0   0   1     - L = low surrogate
      0   0   1   0   1   0   0   0     - H high surrogate


      1   0   0   0   0   1   1   0   V = valid masks
      0   1   0   1   0   0   0   0   a = L & (H >> 1)
      0   0   1   0   1   0   0   0   b = a << 1
      1   1   1   1   1   1   1   0   c = V | a | b
                                  ^
                                  the last bit can be zero, we just consume 7 words
                                  and recheck this word in the next iteration
*/

/* Returns:
   - pointer to the last unprocessed character (a scalar fallback should check the rest);
   - nullptr if an error was detected.
*/
template <endianness big_endian>
const char16_t* avx2_validate_utf16(const char16_t* input, size_t size) {
    const char16_t* end = input + size;

    const auto v_d8 = simd8<uint8_t>::splat(0xd8);
    const auto v_f8 = simd8<uint8_t>::splat(0xf8);
    const auto v_fc = simd8<uint8_t>::splat(0xfc);
    const auto v_dc = simd8<uint8_t>::splat(0xdc);

    while (input + simd16<uint16_t>::ELEMENTS * 2 < end) {
        auto in0 = simd16<uint16_t>(input);
        auto in1 = simd16<uint16_t>(input + simd16<uint16_t>::ELEMENTS);

        if (big_endian) {
            in0 = in0.swap_bytes();
            in1 = in1.swap_bytes();
        }

        const auto t0 = in0.shr<8>();
        const auto t1 = in1.shr<8>();

        const auto in = simd16<uint16_t>::pack(t0, t1);

        const auto surrogates_wordmask = (in & v_f8) == v_d8;
        const uint32_t surrogates_bitmask = surrogates_wordmask.to_bitmask();
        if (surrogates_bitmask == 0x0) {
            input += simd16<uint16_t>::ELEMENTS * 2;
        } else {

            const uint32_t V = ~surrogates_bitmask;

            const auto    vH = (in & v_fc) == v_dc;
            const uint32_t H = vH.to_bitmask();

            const uint32_t L = ~H & surrogates_bitmask;

            const uint32_t a = L & (H >> 1);  // A low surrogate must be followed by high one.
            const uint32_t b = a << 1;        // Just mark that the opposite fact is hold,
            const uint32_t c = V | a | b;     // Combine all the masks into the final one.

            if (c == 0xffffffff) {
                input += simd16<uint16_t>::ELEMENTS * 2;
            } else if (c == 0x7fffffff) {
                input += simd16<uint16_t>::ELEMENTS * 2 - 1;
            } else {
                return nullptr;
            }
        }
    }

    return input;
}
/* end file src/haswell/avx2_validate_utf16.cpp */
/* begin file src/haswell/avx2_validate_utf32le.cpp */
/* Returns:
   - pointer to the last unprocessed character (a scalar fallback should check the rest);
   - nullptr if an error was detected.
*/
const char32_t* avx2_validate_utf32le(const char32_t* input, size_t size) {
    const char32_t* end = input + size;

    const __m256i standardmax = _mm256_set1_epi32(0x10ffff);
    const __m256i offset = _mm256_set1_epi32(0xffff2000);
    const __m256i standardoffsetmax = _mm256_set1_epi32(0xfffff7ff);
    __m256i currentmax = _mm256_setzero_si256();
    __m256i currentoffsetmax = _mm256_setzero_si256();

    while (input + 8 < end) {
        const __m256i in = _mm256_loadu_si256((__m256i *)input);
        currentmax = _mm256_max_epu32(in,currentmax);
        currentoffsetmax = _mm256_max_epu32(_mm256_add_epi32(in, offset), currentoffsetmax);
        input += 8;
    }
    __m256i is_zero = _mm256_xor_si256(_mm256_max_epu32(currentmax, standardmax), standardmax);
    if(_mm256_testz_si256(is_zero, is_zero) == 0) {
        return nullptr;
    }

    is_zero = _mm256_xor_si256(_mm256_max_epu32(currentoffsetmax, standardoffsetmax), standardoffsetmax);
    if(_mm256_testz_si256(is_zero, is_zero) == 0) {
        return nullptr;
    }

    return input;
}
/* end file src/haswell/avx2_validate_utf32le.cpp */

/* begin file src/haswell/avx2_convert_utf8_to_utf16.cpp */


template <endianness big_endian>
size_t convert_masked_utf8_to_utf16(const char *input,
                           uint64_t utf8_end_of_code_point_mask,
                           char16_t *&utf16_output) {
  const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
  const __m128i in = _mm_loadu_si128((__m128i *)input);
  const uint16_t input_utf8_end_of_code_point_mask =
      utf8_end_of_code_point_mask & 0xfff;
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xffff)) {
    __m256i ascii = _mm256_cvtepu8_epi16(in);
    if (big_endian) {
      const __m256i swap256 = _mm256_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14,
                                  17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30);
      ascii = _mm256_shuffle_epi8(ascii, swap256);
    }
    _mm256_storeu_si256(reinterpret_cast<__m256i *>(utf16_output), ascii);
    utf16_output += 16; // We wrote 16 16-bit characters.
    return 16; // We consumed 16 bytes.
  }
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xaaaa)) {
    const __m128i sh = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    if (big_endian) composed = _mm_shuffle_epi8(composed, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed);
    utf16_output += 8; // We wrote 16 bytes, 8 code points.
    return 16;
  }
  if(input_utf8_end_of_code_point_mask == 0x924) {
    const __m128i sh = _mm_setr_epi8(2, 1, 0, -1, 5, 4, 3, -1, 8, 7, 6, -1, 11, 10, 9, -1);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    __m128i composed_repacked = _mm_packus_epi32(composed, composed);
    if (big_endian) composed_repacked = _mm_shuffle_epi8(composed_repacked, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed_repacked);
    utf16_output += 4;
    return 12;
  }

  const uint8_t idx =
      simdutf::tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][0];
  const uint8_t consumed =
      simdutf::tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][1];
  if (idx < 64) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)simdutf::tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    if (big_endian) composed = _mm_shuffle_epi8(composed, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed);
    utf16_output += 6; // We wrote 12 bytes, 6 code points.
  } else if (idx < 145) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)simdutf::tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    __m128i composed_repacked = _mm_packus_epi32(composed, composed);
    if (big_endian) composed_repacked = _mm_shuffle_epi8(composed_repacked, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed_repacked);
    utf16_output += 4;
  } else if (idx < 209) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)simdutf::tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi32(0x7f));
    const __m128i middlebyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f00));
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    __m128i middlehighbyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f0000));
    const __m128i correct =
        _mm_srli_epi32(_mm_and_si128(perm, _mm_set1_epi32(0x400000)), 1);
    middlehighbyte = _mm_xor_si128(correct, middlehighbyte);
    const __m128i middlehighbyte_shifted = _mm_srli_epi32(middlehighbyte, 4);
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi32(0x07000000));
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 6);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted),
                     _mm_or_si128(highbyte_shifted, middlehighbyte_shifted));
    const __m128i composedminus =
        _mm_sub_epi32(composed, _mm_set1_epi32(0x10000));
    const __m128i lowtenbits =
        _mm_and_si128(composedminus, _mm_set1_epi32(0x3ff));
    const __m128i hightenbits = _mm_srli_epi32(composedminus, 10);
    const __m128i lowtenbitsadd =
        _mm_add_epi32(lowtenbits, _mm_set1_epi32(0xDC00));
    const __m128i hightenbitsadd =
        _mm_add_epi32(hightenbits, _mm_set1_epi32(0xD800));
    const __m128i lowtenbitsaddshifted = _mm_slli_epi32(lowtenbitsadd, 16);
    __m128i surrogates =
        _mm_or_si128(hightenbitsadd, lowtenbitsaddshifted);
    uint32_t basic_buffer[4];
    uint32_t basic_buffer_swap[4];
    if (big_endian) {
      _mm_storeu_si128((__m128i *)basic_buffer_swap, _mm_shuffle_epi8(composed, swap));
      surrogates = _mm_shuffle_epi8(surrogates, swap);
    }
    _mm_storeu_si128((__m128i *)basic_buffer, composed);
    uint32_t surrogate_buffer[4];
    _mm_storeu_si128((__m128i *)surrogate_buffer, surrogates);
    for (size_t i = 0; i < 3; i++) {
      if (basic_buffer[i] < 65536) {
        utf16_output[0] = big_endian ? uint16_t(basic_buffer_swap[i]) : uint16_t(basic_buffer[i]);
        utf16_output++;
      } else {
        utf16_output[0] = uint16_t(surrogate_buffer[i] & 0xffff);
        utf16_output[1] = uint16_t(surrogate_buffer[i] >> 16);
        utf16_output += 2;
      }
    }
  } else {
  }
  return consumed;
}
/* end file src/haswell/avx2_convert_utf8_to_utf16.cpp */
/* begin file src/haswell/avx2_convert_utf8_to_utf32.cpp */


size_t convert_masked_utf8_to_utf32(const char *input,
                           uint64_t utf8_end_of_code_point_mask,
                           char32_t *&utf32_output) {
  const __m128i in = _mm_loadu_si128((__m128i *)input);
  const uint16_t input_utf8_end_of_code_point_mask =
      utf8_end_of_code_point_mask & 0xfff;
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xffff)) {
    _mm256_storeu_si256(reinterpret_cast<__m256i *>(utf32_output), _mm256_cvtepu8_epi32(in));
    _mm256_storeu_si256(reinterpret_cast<__m256i *>(utf32_output+8), _mm256_cvtepu8_epi32(_mm_srli_si128(in,8)));
    utf32_output += 16; // We wrote 16 32-bit characters.
    return 16; // We consumed 16 bytes.
  }
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xaaaa)) {
    const __m128i sh = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    const __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    _mm256_storeu_si256((__m256i *)utf32_output, _mm256_cvtepu16_epi32(composed));
    utf32_output += 8; // We wrote 16 bytes, 8 code points.
    return 16;
  }
  if(input_utf8_end_of_code_point_mask == 0x924) {
    const __m128i sh = _mm_setr_epi8(2, 1, 0, -1, 5, 4, 3, -1, 8, 7, 6, -1, 11, 10, 9, -1);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    _mm_storeu_si128((__m128i *)utf32_output, composed);
    utf32_output += 4;
    return 12;
  }

  const uint8_t idx =
      tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][0];
  const uint8_t consumed =
      tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][1];
  if (idx < 64) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    const __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    _mm256_storeu_si256((__m256i *)utf32_output, _mm256_cvtepu16_epi32(composed));
    utf32_output += 6; // We wrote 12 bytes, 6 code points.
  } else if (idx < 145) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    _mm_storeu_si128((__m128i *)utf32_output, composed);
    utf32_output += 4;
  } else if (idx < 209) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi32(0x7f));
    const __m128i middlebyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f00));
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    __m128i middlehighbyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f0000));
    const __m128i correct =
        _mm_srli_epi32(_mm_and_si128(perm, _mm_set1_epi32(0x400000)), 1);
    middlehighbyte = _mm_xor_si128(correct, middlehighbyte);
    const __m128i middlehighbyte_shifted = _mm_srli_epi32(middlehighbyte, 4);
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi32(0x07000000));
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 6);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted),
                     _mm_or_si128(highbyte_shifted, middlehighbyte_shifted));
    _mm_storeu_si128((__m128i *)utf32_output, composed);
    utf32_output += 3;
  } else {
  }
  return consumed;
}
/* end file src/haswell/avx2_convert_utf8_to_utf32.cpp */

/* begin file src/haswell/avx2_convert_utf16_to_utf8.cpp */
/*
    The vectorized algorithm works on single SSE register i.e., it
    loads eight 16-bit words.

    We consider three cases:
    1. an input register contains no surrogates and each value
       is in range 0x0000 .. 0x07ff.
    2. an input register contains no surrogates and values are
       is in range 0x0000 .. 0xffff.
    3. an input register contains surrogates --- i.e. codepoints
       can have 16 or 32 bits.

    Ad 1.

    When values are less than 0x0800, it means that a 16-bit words
    can be converted into: 1) single UTF8 byte (when it's an ASCII
    char) or 2) two UTF8 bytes.

    For this case we do only some shuffle to obtain these 2-byte
    codes and finally compress the whole SSE register with a single
    shuffle.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.

    Ad 2.

    When values fit in 16-bit words, but are above 0x07ff, then
    a single word may produce one, two or three UTF8 bytes.

    We prepare data for all these three cases in two registers.
    The first register contains lower two UTF8 bytes (used in all
    cases), while the second one contains just the third byte for
    the three-UTF8-bytes case.

    Finally these two registers are interleaved forming eight-element
    array of 32-bit values. The array spans two SSE registers.
    The bytes from the registers are compressed using two shuffles.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.


    To summarize:
    - We need two 256-entry tables that have 8704 bytes in total.
*/


/*
  Returns a pair: the first unprocessed byte from buf and utf8_output
  A scalar routing should carry on the conversion of the tail.
*/
template <endianness big_endian>
std::pair<const char16_t*, char*> avx2_convert_utf16_to_utf8(const char16_t* buf, size_t len, char* utf8_output) {
  const char16_t* end = buf + len;
  const __m256i v_0000 = _mm256_setzero_si256();
  const __m256i v_f800 = _mm256_set1_epi16((int16_t)0xf800);
  const __m256i v_d800 = _mm256_set1_epi16((int16_t)0xd800);
  const __m256i v_c080 = _mm256_set1_epi16((int16_t)0xc080);
  const size_t safety_margin = 11; // to avoid overruns, see issue https://github.com/simdutf/simdutf/issues/92

  while (buf + 16 + safety_margin <= end) {
    __m256i in = _mm256_loadu_si256((__m256i*)buf);
    if (big_endian) {
      const __m256i swap = _mm256_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14,
                                  17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30);
      in = _mm256_shuffle_epi8(in, swap);
    }
    const __m256i v_ff80 = _mm256_set1_epi16((int16_t)0xff80);
    if(_mm256_testz_si256(in, v_ff80)) { // ASCII fast path!!!!
        const __m128i utf8_packed = _mm_packus_epi16(_mm256_castsi256_si128(in),_mm256_extractf128_si256(in,1));
        _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);
        buf += 16;
        utf8_output += 16;
        continue; // we are done for this round!
    }
    const __m256i one_byte_bytemask = _mm256_cmpeq_epi16(_mm256_and_si256(in, v_ff80), v_0000);
    const uint32_t one_byte_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(one_byte_bytemask));

    const __m256i one_or_two_bytes_bytemask = _mm256_cmpeq_epi16(_mm256_and_si256(in, v_f800), v_0000);
    const uint32_t one_or_two_bytes_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(one_or_two_bytes_bytemask));
    if (one_or_two_bytes_bitmask == 0xffffffff) {

          const __m256i v_1f00 = _mm256_set1_epi16((int16_t)0x1f00);
          const __m256i v_003f = _mm256_set1_epi16((int16_t)0x003f);

          const __m256i t0 = _mm256_slli_epi16(in, 2);
          const __m256i t1 = _mm256_and_si256(t0, v_1f00);
          const __m256i t2 = _mm256_and_si256(in, v_003f);
          const __m256i t3 = _mm256_or_si256(t1, t2);
          const __m256i t4 = _mm256_or_si256(t3, v_c080);

          const __m256i utf8_unpacked = _mm256_blendv_epi8(t4, in, one_byte_bytemask);

          const uint32_t M0 = one_byte_bitmask & 0x55555555;
          const uint32_t M1 = M0 >> 7;
          const uint32_t M2 = (M1 | M0)  & 0x00ff00ff;

          const uint8_t* row = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[uint8_t(M2)][0];
          const uint8_t* row_2 = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[uint8_t(M2>>16)][0];

          const __m128i shuffle = _mm_loadu_si128((__m128i*)(row + 1));
          const __m128i shuffle_2 = _mm_loadu_si128((__m128i*)(row_2 + 1));

          const __m256i utf8_packed = _mm256_shuffle_epi8(utf8_unpacked, _mm256_setr_m128i(shuffle,shuffle_2));
          _mm_storeu_si128((__m128i*)utf8_output, _mm256_castsi256_si128(utf8_packed));
          utf8_output += row[0];
          _mm_storeu_si128((__m128i*)utf8_output, _mm256_extractf128_si256(utf8_packed,1));
          utf8_output += row_2[0];

          buf += 16;
          continue;
    }
    const __m256i surrogates_bytemask = _mm256_cmpeq_epi16(_mm256_and_si256(in, v_f800), v_d800);

    const uint32_t surrogates_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(surrogates_bytemask));
    if (surrogates_bitmask == 0x00000000) {
        const __m256i dup_even = _mm256_setr_epi16(0x0000, 0x0202, 0x0404, 0x0606,
                                                0x0808, 0x0a0a, 0x0c0c, 0x0e0e,
                                                0x0000, 0x0202, 0x0404, 0x0606,
                                                0x0808, 0x0a0a, 0x0c0c, 0x0e0e);

        /* In this branch we handle three cases:
           1. [0000|0000|0ccc|cccc] => [0ccc|cccc]                           - single UFT-8 byte
           2. [0000|0bbb|bbcc|cccc] => [110b|bbbb], [10cc|cccc]              - two UTF-8 bytes
           3. [aaaa|bbbb|bbcc|cccc] => [1110|aaaa], [10bb|bbbb], [10cc|cccc] - three UTF-8 bytes

          We expand the input word (16-bit) into two words (32-bit), thus
          we have room for four bytes. However, we need five distinct bit
          layouts. Note that the last byte in cases #2 and #3 is the same.

          We precompute byte 1 for case #1 and the common byte for cases #2 & #3
          in register t2.

          We precompute byte 1 for case #3 and -- **conditionally** -- precompute
          either byte 1 for case #2 or byte 2 for case #3. Note that they
          differ by exactly one bit.

          Finally from these two words we build proper UTF-8 sequence, taking
          into account the case (i.e, the number of bytes to write).
        */
        /**
         * Given [aaaa|bbbb|bbcc|cccc] our goal is to produce:
         * t2 => [0ccc|cccc] [10cc|cccc]
         * s4 => [1110|aaaa] ([110b|bbbb] OR [10bb|bbbb])
         */
#define vec(x) _mm256_set1_epi16(static_cast<uint16_t>(x))
        const __m256i t0 = _mm256_shuffle_epi8(in, dup_even);
        const __m256i t1 = _mm256_and_si256(t0, vec(0b0011111101111111));
        const __m256i t2 = _mm256_or_si256 (t1, vec(0b1000000000000000));

        const __m256i s0 = _mm256_srli_epi16(in, 4);
        const __m256i s1 = _mm256_and_si256(s0, vec(0b0000111111111100));
        const __m256i s2 = _mm256_maddubs_epi16(s1, vec(0x0140));
        const __m256i s3 = _mm256_or_si256(s2, vec(0b1100000011100000));
        const __m256i m0 = _mm256_andnot_si256(one_or_two_bytes_bytemask, vec(0b0100000000000000));
        const __m256i s4 = _mm256_xor_si256(s3, m0);
#undef vec

        const __m256i out0 = _mm256_unpacklo_epi16(t2, s4);
        const __m256i out1 = _mm256_unpackhi_epi16(t2, s4);

        const uint32_t mask = (one_byte_bitmask & 0x55555555) |
                              (one_or_two_bytes_bitmask & 0xaaaaaaaa);
        /*if(mask == 0) {
          const __m256i shuffle = _mm256_setr_epi8(2,3,1,6,7,5,10,11,9,14,15,13,-1,-1,-1,-1, 2,3,1,6,7,5,10,11,9,14,15,13,-1,-1,-1,-1);
          const __m256i utf8_0 = _mm256_shuffle_epi8(out0, shuffle);
          const __m256i utf8_1 = _mm256_shuffle_epi8(out1, shuffle);
          _mm_storeu_si128((__m128i*)utf8_output, _mm256_castsi256_si128(utf8_0));
          utf8_output += 12;
          _mm_storeu_si128((__m128i*)utf8_output, _mm256_castsi256_si128(utf8_1));
          utf8_output += 12;
          _mm_storeu_si128((__m128i*)utf8_output, _mm256_extractf128_si256(utf8_0,1));
          utf8_output += 12;
          _mm_storeu_si128((__m128i*)utf8_output, _mm256_extractf128_si256(utf8_1,1));
          utf8_output += 12;
          buf += 16;
          continue;
        }*/
        const uint8_t mask0 = uint8_t(mask);
        const uint8_t* row0 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask0][0];
        const __m128i shuffle0 = _mm_loadu_si128((__m128i*)(row0 + 1));
        const __m128i utf8_0 = _mm_shuffle_epi8(_mm256_castsi256_si128(out0), shuffle0);

        const uint8_t mask1 = static_cast<uint8_t>(mask >> 8);
        const uint8_t* row1 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask1][0];
        const __m128i shuffle1 = _mm_loadu_si128((__m128i*)(row1 + 1));
        const __m128i utf8_1 = _mm_shuffle_epi8(_mm256_castsi256_si128(out1), shuffle1);

        const uint8_t mask2 = static_cast<uint8_t>(mask >> 16);
        const uint8_t* row2 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask2][0];
        const __m128i shuffle2 = _mm_loadu_si128((__m128i*)(row2 + 1));
        const __m128i utf8_2 = _mm_shuffle_epi8(_mm256_extractf128_si256(out0,1), shuffle2);


        const uint8_t mask3 = static_cast<uint8_t>(mask >> 24);
        const uint8_t* row3 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask3][0];
        const __m128i shuffle3 = _mm_loadu_si128((__m128i*)(row3 + 1));
        const __m128i utf8_3 = _mm_shuffle_epi8(_mm256_extractf128_si256(out1,1), shuffle3);

        _mm_storeu_si128((__m128i*)utf8_output, utf8_0);
        utf8_output += row0[0];
        _mm_storeu_si128((__m128i*)utf8_output, utf8_1);
        utf8_output += row1[0];
        _mm_storeu_si128((__m128i*)utf8_output, utf8_2);
        utf8_output += row2[0];
        _mm_storeu_si128((__m128i*)utf8_output, utf8_3);
        utf8_output += row3[0];
        buf += 16;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint16_t word = big_endian ? scalar::utf16::swap_bytes(buf[k]) : buf[k];
        if((word & 0xFF80)==0) {
          *utf8_output++ = char(word);
        } else if((word & 0xF800)==0) {
          *utf8_output++ = char((word>>6) | 0b11000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else if((word &0xF800 ) != 0xD800) {
          *utf8_output++ = char((word>>12) | 0b11100000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else {
          uint16_t diff = uint16_t(word - 0xD800);
          uint16_t next_word = big_endian ? scalar::utf16::swap_bytes(buf[k+1]) : buf[k+1];
          k++;
          uint16_t diff2 = uint16_t(next_word - 0xDC00);
          if((diff | diff2) > 0x3FF)  { return std::make_pair(nullptr, utf8_output); }
          uint32_t value = (diff << 10) + diff2 + 0x10000;
          *utf8_output++ = char((value>>18) | 0b11110000);
          *utf8_output++ = char(((value>>12) & 0b111111) | 0b10000000);
          *utf8_output++ = char(((value>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((value & 0b111111) | 0b10000000);
        }
      }
      buf += k;
    }
  } // while
  return std::make_pair(buf, utf8_output);
}
/* end file src/haswell/avx2_convert_utf16_to_utf8.cpp */
/* begin file src/haswell/avx2_convert_utf16_to_utf32.cpp */
/*
    The vectorized algorithm works on single SSE register i.e., it
    loads eight 16-bit words.

    We consider three cases:
    1. an input register contains no surrogates and each value
       is in range 0x0000 .. 0x07ff.
    2. an input register contains no surrogates and values are
       is in range 0x0000 .. 0xffff.
    3. an input register contains surrogates --- i.e. codepoints
       can have 16 or 32 bits.

    Ad 1.

    When values are less than 0x0800, it means that a 16-bit words
    can be converted into: 1) single UTF8 byte (when it's an ASCII
    char) or 2) two UTF8 bytes.

    For this case we do only some shuffle to obtain these 2-byte
    codes and finally compress the whole SSE register with a single
    shuffle.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.

    Ad 2.

    When values fit in 16-bit words, but are above 0x07ff, then
    a single word may produce one, two or three UTF8 bytes.

    We prepare data for all these three cases in two registers.
    The first register contains lower two UTF8 bytes (used in all
    cases), while the second one contains just the third byte for
    the three-UTF8-bytes case.

    Finally these two registers are interleaved forming eight-element
    array of 32-bit values. The array spans two SSE registers.
    The bytes from the registers are compressed using two shuffles.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.


    To summarize:
    - We need two 256-entry tables that have 8704 bytes in total.
*/


/*
  Returns a pair: the first unprocessed byte from buf and utf32_output
  A scalar routing should carry on the conversion of the tail.
*/
template <endianness big_endian>
std::pair<const char16_t*, char32_t*> avx2_convert_utf16_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) {
  const char16_t* end = buf + len;
  const __m256i v_f800 = _mm256_set1_epi16((int16_t)0xf800);
  const __m256i v_d800 = _mm256_set1_epi16((int16_t)0xd800);

  while (buf + 16 <= end) {
    __m256i in = _mm256_loadu_si256((__m256i*)buf);
    if (big_endian) {
      const __m256i swap = _mm256_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14,
                                  17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30);
      in = _mm256_shuffle_epi8(in, swap);
    }

    const __m256i surrogates_bytemask = _mm256_cmpeq_epi16(_mm256_and_si256(in, v_f800), v_d800);

    const uint32_t surrogates_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(surrogates_bytemask));
    if (surrogates_bitmask == 0x00000000) {
        _mm256_storeu_si256(reinterpret_cast<__m256i *>(utf32_output), _mm256_cvtepu16_epi32(_mm256_castsi256_si128(in)));
        _mm256_storeu_si256(reinterpret_cast<__m256i *>(utf32_output + 8), _mm256_cvtepu16_epi32(_mm256_extractf128_si256(in,1)));
        utf32_output += 16;
        buf += 16;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint16_t word = big_endian ? scalar::utf16::swap_bytes(buf[k]) : buf[k];
        if((word &0xF800 ) != 0xD800) {
          *utf32_output++ = char32_t(word);
        } else {
          uint16_t diff = uint16_t(word - 0xD800);
          uint16_t next_word = big_endian ? scalar::utf16::swap_bytes(buf[k+1]) : buf[k+1];
          k++;
          uint16_t diff2 = uint16_t(next_word - 0xDC00);
          if((diff | diff2) > 0x3FF)  { return std::make_pair(nullptr, utf32_output); }
          uint32_t value = (diff << 10) + diff2 + 0x10000;
          *utf32_output++ = char32_t(value);
        }
      }
      buf += k;
    }
  } // while
  return std::make_pair(buf, utf32_output);
}
/* end file src/haswell/avx2_convert_utf16_to_utf32.cpp */

/* begin file src/haswell/avx2_convert_utf32_to_utf8.cpp */
std::pair<const char32_t*, char*> avx2_convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) {
  const char32_t* end = buf + len;
  const __m256i v_0000 = _mm256_setzero_si256();
  const __m256i v_ffff0000 = _mm256_set1_epi32((uint32_t)0xffff0000);
  const __m256i v_ff80 = _mm256_set1_epi16((uint16_t)0xff80);
  const __m256i v_f800 = _mm256_set1_epi16((uint16_t)0xf800);
  const __m256i v_c080 = _mm256_set1_epi16((uint16_t)0xc080);
  const __m256i v_7fffffff = _mm256_set1_epi32((uint32_t)0x7fffffff);
  __m256i running_max = _mm256_setzero_si256();
  __m256i forbidden_bytemask = _mm256_setzero_si256();

  const size_t safety_margin = 11; // to avoid overruns, see issue https://github.com/simdutf/simdutf/issues/92

  while (buf + 16 + safety_margin <= end) {
    __m256i in = _mm256_loadu_si256((__m256i*)buf);
    __m256i nextin = _mm256_loadu_si256((__m256i*)buf+1);
    running_max = _mm256_max_epu32(_mm256_max_epu32(in, running_max), nextin);

    __m256i in_16 = _mm256_packus_epi32(_mm256_and_si256(in, v_7fffffff), _mm256_and_si256(nextin, v_7fffffff));
    in_16 = _mm256_permute4x64_epi64(in_16, 0b11011000);


    if(_mm256_testz_si256(in_16, v_ff80)) { // ASCII fast path!!!!
      const __m128i utf8_packed = _mm_packus_epi16(_mm256_castsi256_si128(in_16),_mm256_extractf128_si256(in_16,1));
      _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);
      buf += 16;
      utf8_output += 16;
      continue; // we are done for this round!
    }
    const __m256i one_byte_bytemask = _mm256_cmpeq_epi16(_mm256_and_si256(in_16, v_ff80), v_0000);
    const uint32_t one_byte_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(one_byte_bytemask));

    const __m256i one_or_two_bytes_bytemask = _mm256_cmpeq_epi16(_mm256_and_si256(in_16, v_f800), v_0000);
    const uint32_t one_or_two_bytes_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(one_or_two_bytes_bytemask));
    if (one_or_two_bytes_bitmask == 0xffffffff) {
      const __m256i v_1f00 = _mm256_set1_epi16((int16_t)0x1f00);
      const __m256i v_003f = _mm256_set1_epi16((int16_t)0x003f);

      const __m256i t0 = _mm256_slli_epi16(in_16, 2);
      const __m256i t1 = _mm256_and_si256(t0, v_1f00);
      const __m256i t2 = _mm256_and_si256(in_16, v_003f);
      const __m256i t3 = _mm256_or_si256(t1, t2);
      const __m256i t4 = _mm256_or_si256(t3, v_c080);

      const __m256i utf8_unpacked = _mm256_blendv_epi8(t4, in_16, one_byte_bytemask);

      const uint32_t M0 = one_byte_bitmask & 0x55555555;
      const uint32_t M1 = M0 >> 7;
      const uint32_t M2 = (M1 | M0)  & 0x00ff00ff;

      const uint8_t* row = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[uint8_t(M2)][0];
      const uint8_t* row_2 = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[uint8_t(M2>>16)][0];

      const __m128i shuffle = _mm_loadu_si128((__m128i*)(row + 1));
      const __m128i shuffle_2 = _mm_loadu_si128((__m128i*)(row_2 + 1));

      const __m256i utf8_packed = _mm256_shuffle_epi8(utf8_unpacked, _mm256_setr_m128i(shuffle,shuffle_2));
      _mm_storeu_si128((__m128i*)utf8_output, _mm256_castsi256_si128(utf8_packed));
      utf8_output += row[0];
      _mm_storeu_si128((__m128i*)utf8_output, _mm256_extractf128_si256(utf8_packed,1));
      utf8_output += row_2[0];

      buf += 16;
      continue;
    }
    const __m256i saturation_bytemask = _mm256_cmpeq_epi32(_mm256_and_si256(_mm256_or_si256(in, nextin), v_ffff0000), v_0000);
    const uint32_t saturation_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(saturation_bytemask));
    if (saturation_bitmask == 0xffffffff) {
      const __m256i v_d800 = _mm256_set1_epi16((uint16_t)0xd800);
      forbidden_bytemask = _mm256_or_si256(forbidden_bytemask, _mm256_cmpeq_epi16(_mm256_and_si256(in_16, v_f800), v_d800));

      const __m256i dup_even = _mm256_setr_epi16(0x0000, 0x0202, 0x0404, 0x0606,
                                              0x0808, 0x0a0a, 0x0c0c, 0x0e0e,
                                              0x0000, 0x0202, 0x0404, 0x0606,
                                              0x0808, 0x0a0a, 0x0c0c, 0x0e0e);

      /* In this branch we handle three cases:
        1. [0000|0000|0ccc|cccc] => [0ccc|cccc]                           - single UFT-8 byte
        2. [0000|0bbb|bbcc|cccc] => [110b|bbbb], [10cc|cccc]              - two UTF-8 bytes
        3. [aaaa|bbbb|bbcc|cccc] => [1110|aaaa], [10bb|bbbb], [10cc|cccc] - three UTF-8 bytes

        We expand the input word (16-bit) into two words (32-bit), thus
        we have room for four bytes. However, we need five distinct bit
        layouts. Note that the last byte in cases #2 and #3 is the same.

        We precompute byte 1 for case #1 and the common byte for cases #2 & #3
        in register t2.

        We precompute byte 1 for case #3 and -- **conditionally** -- precompute
        either byte 1 for case #2 or byte 2 for case #3. Note that they
        differ by exactly one bit.

        Finally from these two words we build proper UTF-8 sequence, taking
        into account the case (i.e, the number of bytes to write).
      */
      /**
       * Given [aaaa|bbbb|bbcc|cccc] our goal is to produce:
       * t2 => [0ccc|cccc] [10cc|cccc]
       * s4 => [1110|aaaa] ([110b|bbbb] OR [10bb|bbbb])
       */
#define vec(x) _mm256_set1_epi16(static_cast<uint16_t>(x))
      const __m256i t0 = _mm256_shuffle_epi8(in_16, dup_even);
      const __m256i t1 = _mm256_and_si256(t0, vec(0b0011111101111111));
      const __m256i t2 = _mm256_or_si256 (t1, vec(0b1000000000000000));

      const __m256i s0 = _mm256_srli_epi16(in_16, 4);
      const __m256i s1 = _mm256_and_si256(s0, vec(0b0000111111111100));
      const __m256i s2 = _mm256_maddubs_epi16(s1, vec(0x0140));
      const __m256i s3 = _mm256_or_si256(s2, vec(0b1100000011100000));
      const __m256i m0 = _mm256_andnot_si256(one_or_two_bytes_bytemask, vec(0b0100000000000000));
      const __m256i s4 = _mm256_xor_si256(s3, m0);
#undef vec

      const __m256i out0 = _mm256_unpacklo_epi16(t2, s4);
      const __m256i out1 = _mm256_unpackhi_epi16(t2, s4);

      const uint32_t mask = (one_byte_bitmask & 0x55555555) |
                            (one_or_two_bytes_bitmask & 0xaaaaaaaa);
      /*if(mask == 0) {
        const __m256i shuffle = _mm256_setr_epi8(2,3,1,6,7,5,10,11,9,14,15,13,-1,-1,-1,-1, 2,3,1,6,7,5,10,11,9,14,15,13,-1,-1,-1,-1);
        const __m256i utf8_0 = _mm256_shuffle_epi8(out0, shuffle);
        const __m256i utf8_1 = _mm256_shuffle_epi8(out1, shuffle);
        _mm_storeu_si128((__m128i*)utf8_output, _mm256_castsi256_si128(utf8_0));
        utf8_output += 12;
        _mm_storeu_si128((__m128i*)utf8_output, _mm256_castsi256_si128(utf8_1));
        utf8_output += 12;
        _mm_storeu_si128((__m128i*)utf8_output, _mm256_extractf128_si256(utf8_0,1));
        utf8_output += 12;
        _mm_storeu_si128((__m128i*)utf8_output, _mm256_extractf128_si256(utf8_1,1));
        utf8_output += 12;
        buf += 16;
        continue;
      }*/
      const uint8_t mask0 = uint8_t(mask);
      const uint8_t* row0 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask0][0];
      const __m128i shuffle0 = _mm_loadu_si128((__m128i*)(row0 + 1));
      const __m128i utf8_0 = _mm_shuffle_epi8(_mm256_castsi256_si128(out0), shuffle0);

      const uint8_t mask1 = static_cast<uint8_t>(mask >> 8);
      const uint8_t* row1 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask1][0];
      const __m128i shuffle1 = _mm_loadu_si128((__m128i*)(row1 + 1));
      const __m128i utf8_1 = _mm_shuffle_epi8(_mm256_castsi256_si128(out1), shuffle1);

      const uint8_t mask2 = static_cast<uint8_t>(mask >> 16);
      const uint8_t* row2 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask2][0];
      const __m128i shuffle2 = _mm_loadu_si128((__m128i*)(row2 + 1));
      const __m128i utf8_2 = _mm_shuffle_epi8(_mm256_extractf128_si256(out0,1), shuffle2);


      const uint8_t mask3 = static_cast<uint8_t>(mask >> 24);
      const uint8_t* row3 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask3][0];
      const __m128i shuffle3 = _mm_loadu_si128((__m128i*)(row3 + 1));
      const __m128i utf8_3 = _mm_shuffle_epi8(_mm256_extractf128_si256(out1,1), shuffle3);

      _mm_storeu_si128((__m128i*)utf8_output, utf8_0);
      utf8_output += row0[0];
      _mm_storeu_si128((__m128i*)utf8_output, utf8_1);
      utf8_output += row1[0];
      _mm_storeu_si128((__m128i*)utf8_output, utf8_2);
      utf8_output += row2[0];
      _mm_storeu_si128((__m128i*)utf8_output, utf8_3);
      utf8_output += row3[0];
      buf += 16;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint32_t word = buf[k];
        if((word & 0xFFFFFF80)==0) {  // 1-byte (ASCII)
          *utf8_output++ = char(word);
        } else if((word & 0xFFFFF800)==0) { // 2-byte
          *utf8_output++ = char((word>>6) | 0b11000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else if((word & 0xFFFF0000 )==0) {  // 3-byte
          if (word >= 0xD800 && word <= 0xDFFF) { return std::make_pair(nullptr, utf8_output); }
          *utf8_output++ = char((word>>12) | 0b11100000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else {  // 4-byte
          if (word > 0x10FFFF) { return std::make_pair(nullptr, utf8_output); }
          *utf8_output++ = char((word>>18) | 0b11110000);
          *utf8_output++ = char(((word>>12) & 0b111111) | 0b10000000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        }
      }
      buf += k;
    }
  } // while

  const __m256i v_10ffff = _mm256_set1_epi32((uint32_t)0x10ffff);
  if(static_cast<uint32_t>(_mm256_movemask_epi8(_mm256_cmpeq_epi32(_mm256_max_epu32(running_max, v_10ffff), v_10ffff))) != 0xffffffff) {
    return std::make_pair(nullptr, utf8_output);
  }

  if (static_cast<uint32_t>(_mm256_movemask_epi8(forbidden_bytemask)) != 0) { return std::make_pair(nullptr, utf8_output); }

  return std::make_pair(buf, utf8_output);
}
/* end file src/haswell/avx2_convert_utf32_to_utf8.cpp */
/* begin file src/haswell/avx2_convert_utf32_to_utf16.cpp */
template <endianness big_endian>
std::pair<const char32_t*, char16_t*> avx2_convert_utf32_to_utf16(const char32_t* buf, size_t len, char16_t* utf16_output) {
  const char32_t* end = buf + len;

  const size_t safety_margin = 11; // to avoid overruns, see issue https://github.com/simdutf/simdutf/issues/92
  __m256i forbidden_bytemask = _mm256_setzero_si256();


  while (buf + 8 + safety_margin <= end) {
    __m256i in = _mm256_loadu_si256((__m256i*)buf);

    const __m256i v_00000000 = _mm256_setzero_si256();
    const __m256i v_ffff0000 = _mm256_set1_epi32((int32_t)0xffff0000);

    const __m256i saturation_bytemask = _mm256_cmpeq_epi32(_mm256_and_si256(in, v_ffff0000), v_00000000);
    const uint32_t saturation_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(saturation_bytemask));

    if (saturation_bitmask == 0xffffffff) {
      const __m256i v_f800 = _mm256_set1_epi32((uint32_t)0xf800);
      const __m256i v_d800 = _mm256_set1_epi32((uint32_t)0xd800);
      forbidden_bytemask = _mm256_or_si256(forbidden_bytemask, _mm256_cmpeq_epi32(_mm256_and_si256(in, v_f800), v_d800));

      __m128i utf16_packed = _mm_packus_epi32(_mm256_castsi256_si128(in),_mm256_extractf128_si256(in,1));
      if (big_endian) {
        const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
        utf16_packed = _mm_shuffle_epi8(utf16_packed, swap);
      }
      _mm_storeu_si128((__m128i*)utf16_output, utf16_packed);
      utf16_output += 8;
      buf += 8;
    } else {
      size_t forward = 7;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint32_t word = buf[k];
        if((word & 0xFFFF0000)==0) {
          if (word >= 0xD800 && word <= 0xDFFF) { return std::make_pair(nullptr, utf16_output); }
          *utf16_output++ = big_endian ? char16_t((uint16_t(word) >> 8) | (uint16_t(word) << 8)) : char16_t(word);
        } else {
          if (word > 0x10FFFF) { return std::make_pair(nullptr, utf16_output); }
          word -= 0x10000;
          uint16_t high_surrogate = uint16_t(0xD800 + (word >> 10));
          uint16_t low_surrogate = uint16_t(0xDC00 + (word & 0x3FF));
          if (big_endian) {
            high_surrogate = uint16_t((high_surrogate >> 8) | (high_surrogate << 8));
            low_surrogate = uint16_t((low_surrogate >> 8) | (low_surrogate << 8));
          }
          *utf16_output++ = char16_t(high_surrogate);
          *utf16_output++ = char16_t(low_surrogate);
        }
      }
      buf += k;
    }
  }

  if (static_cast<uint32_t>(_mm256_movemask_epi8(forbidden_bytemask)) != 0) { return std::make_pair(nullptr, utf16_output); }

  return std::make_pair(buf, utf16_output);
}
/* end file src/haswell/avx2_convert_utf32_to_utf16.cpp */
} // unnamed namespace
} // namespace haswell
} // namespace simdutf

/* begin file src/generic/buf_block_reader.h */
namespace simdutf {
namespace haswell {
namespace {

template<size_t STEP_SIZE>
struct buf_block_reader {
public:
  simdutf_really_inline buf_block_reader(const uint8_t *_buf, size_t _len);
  simdutf_really_inline size_t block_index();
  simdutf_really_inline bool has_full_block() const;
  simdutf_really_inline const uint8_t *full_block() const;
  /**
   * Get the last block, padded with spaces.
   *
   * There will always be a last block, with at least 1 byte, unless len == 0 (in which case this
   * function fills the buffer with spaces and returns 0. In particular, if len == STEP_SIZE there
   * will be 0 full_blocks and 1 remainder block with STEP_SIZE bytes and no spaces for padding.
   *
   * @return the number of effective characters in the last block.
   */
  simdutf_really_inline size_t get_remainder(uint8_t *dst) const;
  simdutf_really_inline void advance();
private:
  const uint8_t *buf;
  const size_t len;
  const size_t lenminusstep;
  size_t idx;
};

simdutf_unused static char * format_input_text_64(const uint8_t *text) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    buf[i] = int8_t(text[i]) < ' ' ? '_' : int8_t(text[i]);
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_input_text(const simd8x64<uint8_t>& in) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  in.store(reinterpret_cast<uint8_t*>(buf));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    if (buf[i] < ' ') { buf[i] = '_'; }
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_mask(uint64_t mask) {
  static char *buf = reinterpret_cast<char*>(malloc(64 + 1));
  for (size_t i=0; i<64; i++) {
    buf[i] = (mask & (size_t(1) << i)) ? 'X' : ' ';
  }
  buf[64] = '\0';
  return buf;
}

template<size_t STEP_SIZE>
simdutf_really_inline buf_block_reader<STEP_SIZE>::buf_block_reader(const uint8_t *_buf, size_t _len) : buf{_buf}, len{_len}, lenminusstep{len < STEP_SIZE ? 0 : len - STEP_SIZE}, idx{0} {}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::block_index() { return idx; }

template<size_t STEP_SIZE>
simdutf_really_inline bool buf_block_reader<STEP_SIZE>::has_full_block() const {
  return idx < lenminusstep;
}

template<size_t STEP_SIZE>
simdutf_really_inline const uint8_t *buf_block_reader<STEP_SIZE>::full_block() const {
  return &buf[idx];
}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::get_remainder(uint8_t *dst) const {
  if(len == idx) { return 0; } // memcpy(dst, null, 0) will trigger an error with some sanitizers
  std::memset(dst, 0x20, STEP_SIZE); // std::memset STEP_SIZE because it's more efficient to write out 8 or 16 bytes at once.
  std::memcpy(dst, buf + idx, len - idx);
  return len - idx;
}

template<size_t STEP_SIZE>
simdutf_really_inline void buf_block_reader<STEP_SIZE>::advance() {
  idx += STEP_SIZE;
}

} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/buf_block_reader.h */
/* begin file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
namespace simdutf {
namespace haswell {
namespace {
namespace utf8_validation {

using namespace simd;

  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }

  simdutf_really_inline simd8<uint8_t> is_incomplete(const simd8<uint8_t> input) {
    static const uint8_t max_array[32] = {
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 0b11110000u-1, 0b11100000u-1, 0b11000000u-1
    };
    const simd8<uint8_t> max_value(&max_array[sizeof(max_array)-sizeof(simd8<uint8_t>)]);
    return input.gt_bits(max_value);
  }

  struct utf8_checker {
    simd8<uint8_t> error;
    simd8<uint8_t> prev_input_block;
    simd8<uint8_t> prev_incomplete;

    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }

    simdutf_really_inline void check_eof() {
      this->error |= this->prev_incomplete;
    }

    simdutf_really_inline void check_next_input(const simd8x64<uint8_t>& input) {
      if(simdutf_likely(is_ascii(input))) {
        this->error |= this->prev_incomplete;
      } else {
        static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
            "We support either two or four chunks per 64-byte block.");
        if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
        } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
          this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
        }
        this->prev_incomplete = is_incomplete(input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1]);
        this->prev_input_block = input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1];

      }
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // namespace utf8_validation

using utf8_validation::utf8_checker;

} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
/* begin file src/generic/utf8_validation/utf8_validator.h */
namespace simdutf {
namespace haswell {
namespace {
namespace utf8_validation {

/**
 * Validates that the string is actual UTF-8.
 */
template<class checker>
bool generic_validate_utf8(const uint8_t * input, size_t length) {
    checker c{};
    buf_block_reader<64> reader(input, length);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      c.check_next_input(in);
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    c.check_next_input(in);
    reader.advance();
    c.check_eof();
    return !c.errors();
}

bool generic_validate_utf8(const char * input, size_t length) {
    return generic_validate_utf8<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

template<class checker>
bool generic_validate_ascii(const uint8_t * input, size_t length) {
    buf_block_reader<64> reader(input, length);
    uint8_t blocks[64]{};
    simd::simd8x64<uint8_t> running_or(blocks);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      running_or |= in;
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    running_or |= in;
    reader.advance();
    return running_or.is_ascii();
}

bool generic_validate_ascii(const char * input, size_t length) {
    return generic_validate_ascii<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

} // namespace utf8_validation
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_validator.h */
/* begin file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */


namespace simdutf {
namespace haswell {
namespace {
namespace utf8_to_utf16 {

using namespace simd;

template <endianness endian>
simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char16_t* utf16_output) noexcept {
  size_t pos = 0;
  char16_t* start{utf16_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf16<endian>(utf16_output);
      utf16_output += 64;
      pos += 64;
    } else {
      uint64_t utf8_continuation_mask = in.lt(-65 + 1);
      uint64_t utf8_leading_mask = ~utf8_continuation_mask;
      uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
      size_t max_starting_point = (pos + 64) - 12;
      while(pos < max_starting_point) {
        size_t consumed = convert_masked_utf8_to_utf16<endian>(input + pos,
                            utf8_end_of_code_point_mask, utf16_output);
        pos += consumed;
        utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf16_output += scalar::utf8_to_utf16::convert_valid<endian>(input + pos, size - pos, utf16_output);
  return utf16_output - start;
}

} // namespace utf8_to_utf16
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf16/utf8_to_utf16.h */


namespace simdutf {
namespace haswell {
namespace {
namespace utf8_to_utf16 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }


    template <endianness endian>
    simdutf_really_inline size_t convert(const char* in, size_t size, char16_t* utf16_output) {
      size_t pos = 0;
      char16_t* start{utf16_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf16<endian>(utf16_output);
          utf16_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf16<endian>(in + pos,
                            utf8_end_of_code_point_mask, utf16_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf16::convert<endian>(in + pos, size - pos, utf16_output);
        if(howmany == 0) { return 0; }
        utf16_output += howmany;
      }
      return utf16_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf16 namespace
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */

namespace simdutf {
namespace haswell {
namespace {
namespace utf8_to_utf32 {

using namespace simd;


simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char32_t* utf32_output) noexcept {
  size_t pos = 0;
  char32_t* start{utf32_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf32(utf32_output);
      utf32_output += 64;
      pos += 64;
    } else {
    uint64_t utf8_continuation_mask = in.lt(-65 + 1);
    uint64_t utf8_leading_mask = ~utf8_continuation_mask;
    uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
    size_t max_starting_point = (pos + 64) - 12;
    while(pos < max_starting_point) {
      size_t consumed = convert_masked_utf8_to_utf32(input + pos,
                          utf8_end_of_code_point_mask, utf32_output);
      pos += consumed;
      utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf32_output += scalar::utf8_to_utf32::convert_valid(input + pos, size - pos, utf32_output);
  return utf32_output - start;
}


} // namespace utf8_to_utf32
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */
/* begin file src/generic/utf8_to_utf32/utf8_to_utf32.h */


namespace simdutf {
namespace haswell {
namespace {
namespace utf8_to_utf32 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }



    simdutf_really_inline size_t convert(const char* in, size_t size, char32_t* utf32_output) {
      size_t pos = 0;
      char32_t* start{utf32_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf32(utf32_output);
          utf32_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf32(in + pos,
                            utf8_end_of_code_point_mask, utf32_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf32::convert(in + pos, size - pos, utf32_output);
        if(howmany == 0) { return 0; }
        utf32_output += howmany;
      }
      return utf32_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf32 namespace
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/utf8_to_utf32.h */
/* begin file src/generic/utf8.h */

namespace simdutf {
namespace haswell {
namespace {
namespace utf8 {

using namespace simd;

simdutf_really_inline size_t count_code_points(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::count_code_points(in + pos, size - pos);
}


simdutf_really_inline size_t utf16_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
      int64_t utf8_4byte = input.gteq_unsigned(240);
      count += count_ones(utf8_4byte);
    }
    return count + scalar::utf8::utf16_length_from_utf8(in + pos, size - pos);
}


simdutf_really_inline size_t utf32_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::utf32_length_from_utf8(in + pos, size - pos);
}
} // utf8 namespace
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf8.h */
/* begin file src/generic/utf16.h */
#include <iostream>
namespace simdutf {
namespace haswell {
namespace {
namespace utf16 {

template <endianness big_endian>
simdutf_really_inline size_t count_code_points(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::count_code_points<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf8_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t ascii_mask = input.lteq(0x7F);
      uint64_t twobyte_mask = input.lteq(0x7FF);
      uint64_t not_pair_mask = input.not_in_range(0xD800, 0xDFFF);

      size_t ascii_count = count_ones(ascii_mask) / 2;
      size_t twobyte_count = count_ones(twobyte_mask & ~ ascii_mask) / 2;
      size_t threebyte_count = count_ones(not_pair_mask & ~ twobyte_mask) / 2;
      size_t fourbyte_count = 32 - count_ones(not_pair_mask) / 2;
      count += 2 * fourbyte_count + 3 * threebyte_count + 2 * twobyte_count + ascii_count;
    }
    return count + scalar::utf16::utf8_length_from_utf16<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf32_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::utf32_length_from_utf16<big_endian>(in + pos, size - pos);
}

simdutf_really_inline void change_endianness_utf16(const char16_t* in, size_t size, char16_t* output) {
  size_t pos = 0;

  while (pos + 32 <= size) {
    simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
    input.swap_bytes();
    input.store(reinterpret_cast<uint16_t *>(output));
    pos += 32;
    output += 32;
  }

  scalar::utf16::change_endianness_utf16(in + pos, size - pos, output);
}

} // utf16
} // unnamed namespace
} // namespace haswell
} // namespace simdutf
/* end file src/generic/utf16.h */

namespace simdutf {
namespace haswell {


simdutf_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept {
  return haswell::utf8_validation::generic_validate_utf8(buf,len);
}

simdutf_warn_unused bool implementation::validate_ascii(const char *buf, size_t len) const noexcept {
  return haswell::utf8_validation::generic_validate_ascii(buf,len);
}

simdutf_warn_unused bool implementation::validate_utf16le(const char16_t *buf, size_t len) const noexcept {
  const char16_t* tail = avx2_validate_utf16<endianness::LITTLE>(buf, len);
  if (tail) {
    return scalar::utf16::validate<endianness::LITTLE>(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused bool implementation::validate_utf16be(const char16_t *buf, size_t len) const noexcept {
  const char16_t* tail = avx2_validate_utf16<endianness::BIG>(buf, len);
  if (tail) {
    return scalar::utf16::validate<endianness::BIG>(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused bool implementation::validate_utf32(const char32_t *buf, size_t len) const noexcept {
  const char32_t* tail = avx2_validate_utf32le(buf, len);
  if (tail) {
    return scalar::utf32::validate(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16le(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
  utf8_to_utf16::validating_transcoder converter;
  return converter.convert<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16be(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
  utf8_to_utf16::validating_transcoder converter;
  return converter.convert<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16le(const char* input, size_t size,
    char16_t* utf16_output) const noexcept {
   return utf8_to_utf16::convert_valid<endianness::LITTLE>(input, size,  utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16be(const char* input, size_t size,
    char16_t* utf16_output) const noexcept {
   return utf8_to_utf16::convert_valid<endianness::BIG>(input, size,  utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf32(const char* buf, size_t len, char32_t* utf32_output) const noexcept {
  utf8_to_utf32::validating_transcoder converter;
  return converter.convert(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf32(const char* input, size_t size,
    char32_t* utf32_output) const noexcept {
  return utf8_to_utf32::convert_valid(input, size,  utf32_output);
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char16_t*, char*> ret = haswell::avx2_convert_utf16_to_utf8<endianness::LITTLE>(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf8::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char16_t*, char*> ret = haswell::avx2_convert_utf16_to_utf8<endianness::BIG>(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf8::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf16le_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf16be_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char32_t*, char*> ret = avx2_convert_utf32_to_utf8(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf8::convert(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  std::pair<const char16_t*, char32_t*> ret = haswell::avx2_convert_utf16_to_utf32<endianness::LITTLE>(buf, len, utf32_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf32_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf32::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  std::pair<const char16_t*, char32_t*> ret = haswell::avx2_convert_utf16_to_utf32<endianness::BIG>(buf, len, utf32_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf32_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf32::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf32_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  std::pair<const char32_t*, char16_t*> ret = avx2_convert_utf32_to_utf16<endianness::LITTLE>(buf, len, utf16_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf16_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf16::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  std::pair<const char32_t*, char16_t*> ret = avx2_convert_utf32_to_utf16<endianness::BIG>(buf, len, utf16_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf16_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf16::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return convert_utf32_to_utf16le(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return convert_utf32_to_utf16be(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return convert_utf16le_to_utf32(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return convert_utf16be_to_utf32(buf, len, utf32_output);
}

void implementation::change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) const noexcept {
  utf16::change_endianness_utf16(input, length, output);
}

simdutf_warn_unused size_t implementation::count_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::count_code_points<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::count_code_points<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf8(const char * input, size_t length) const noexcept {
  return utf8::count_code_points(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::utf8_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::utf8_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::utf32_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::utf32_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf8(const char * input, size_t length) const noexcept {
  return utf8::utf16_length_from_utf8(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  const __m256i v_00000000 = _mm256_setzero_si256();
  const __m256i v_ffffff80 = _mm256_set1_epi32((uint32_t)0xffffff80);
  const __m256i v_fffff800 = _mm256_set1_epi32((uint32_t)0xfffff800);
  const __m256i v_ffff0000 = _mm256_set1_epi32((uint32_t)0xffff0000);
  size_t pos = 0;
  size_t count = 0;
  for(;pos + 8 <= length; pos += 8) {
    __m256i in = _mm256_loadu_si256((__m256i*)(input + pos));
    const __m256i ascii_bytes_bytemask = _mm256_cmpeq_epi32(_mm256_and_si256(in, v_ffffff80), v_00000000);
    const __m256i one_two_bytes_bytemask = _mm256_cmpeq_epi32(_mm256_and_si256(in, v_fffff800), v_00000000);
    const __m256i two_bytes_bytemask = _mm256_xor_si256(one_two_bytes_bytemask, ascii_bytes_bytemask);
    const __m256i one_two_three_bytes_bytemask = _mm256_cmpeq_epi32(_mm256_and_si256(in, v_ffff0000), v_00000000);
    const __m256i three_bytes_bytemask = _mm256_xor_si256(one_two_three_bytes_bytemask, one_two_bytes_bytemask);
    const uint32_t ascii_bytes_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(ascii_bytes_bytemask));
    const uint32_t two_bytes_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(two_bytes_bytemask));
    const uint32_t three_bytes_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(three_bytes_bytemask));

    size_t ascii_count = count_ones(ascii_bytes_bitmask) / 4;
    size_t two_bytes_count = count_ones(two_bytes_bitmask) / 4;
    size_t three_bytes_count = count_ones(three_bytes_bitmask) / 4;
    count += 32 - 3*ascii_count - 2*two_bytes_count - three_bytes_count;
  }
  return count + scalar::utf32::utf8_length_from_utf32(input + pos, length - pos);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  const __m256i v_00000000 = _mm256_setzero_si256();
  const __m256i v_ffff0000 = _mm256_set1_epi32((uint32_t)0xffff0000);
  size_t pos = 0;
  size_t count = 0;
  for(;pos + 8 <= length; pos += 8) {
    __m256i in = _mm256_loadu_si256((__m256i*)(input + pos));
    const __m256i surrogate_bytemask = _mm256_cmpeq_epi32(_mm256_and_si256(in, v_ffff0000), v_00000000);
    const uint32_t surrogate_bitmask = static_cast<uint32_t>(_mm256_movemask_epi8(surrogate_bytemask));
    size_t surrogate_count = (32-count_ones(surrogate_bitmask))/4;
    count += 8 + surrogate_count;
  }
  return count + scalar::utf32::utf16_length_from_utf32(input + pos, length - pos);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf8(const char * input, size_t length) const noexcept {
  return utf8::utf32_length_from_utf8(input, length);
}

} // namespace haswell
} // namespace simdutf

/* begin file src/simdutf/haswell/end.h */
SIMDUTF_UNTARGET_REGION
/* end file src/simdutf/haswell/end.h */
/* end file src/haswell/implementation.cpp */
#endif
#if SIMDUTF_IMPLEMENTATION_PPC64
/* begin file src/ppc64/implementation.cpp */





/* begin file src/simdutf/ppc64/begin.h */
/* end file src/simdutf/ppc64/begin.h */
namespace simdutf {
namespace ppc64 {
namespace {
#ifndef SIMDUTF_PPC64_H
#error "ppc64.h must be included"
#endif
using namespace simd;


simdutf_really_inline bool is_ascii(const simd8x64<uint8_t>& input) {
  return input.reduce_or().saturating_sub(0b01111111u).bits_not_set_anywhere();
}

simdutf_unused simdutf_really_inline simd8<bool> must_be_continuation(const simd8<uint8_t> prev1, const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
  simd8<uint8_t> is_second_byte = prev1.saturating_sub(0b11000000u-1); // Only 11______ will be > 0
  simd8<uint8_t> is_third_byte  = prev2.saturating_sub(0b11100000u-1); // Only 111_____ will be > 0
  simd8<uint8_t> is_fourth_byte = prev3.saturating_sub(0b11110000u-1); // Only 1111____ will be > 0
  return simd8<int8_t>(is_second_byte | is_third_byte | is_fourth_byte) > int8_t(0);
}

simdutf_really_inline simd8<bool> must_be_2_3_continuation(const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
  simd8<uint8_t> is_third_byte  = prev2.saturating_sub(0b11100000u-1); // Only 111_____ will be > 0
  simd8<uint8_t> is_fourth_byte = prev3.saturating_sub(0b11110000u-1); // Only 1111____ will be > 0
  return simd8<int8_t>(is_third_byte | is_fourth_byte) > int8_t(0);
}

} // unnamed namespace
} // namespace ppc64
} // namespace simdutf

/* begin file src/generic/buf_block_reader.h */
namespace simdutf {
namespace ppc64 {
namespace {

template<size_t STEP_SIZE>
struct buf_block_reader {
public:
  simdutf_really_inline buf_block_reader(const uint8_t *_buf, size_t _len);
  simdutf_really_inline size_t block_index();
  simdutf_really_inline bool has_full_block() const;
  simdutf_really_inline const uint8_t *full_block() const;
  /**
   * Get the last block, padded with spaces.
   *
   * There will always be a last block, with at least 1 byte, unless len == 0 (in which case this
   * function fills the buffer with spaces and returns 0. In particular, if len == STEP_SIZE there
   * will be 0 full_blocks and 1 remainder block with STEP_SIZE bytes and no spaces for padding.
   *
   * @return the number of effective characters in the last block.
   */
  simdutf_really_inline size_t get_remainder(uint8_t *dst) const;
  simdutf_really_inline void advance();
private:
  const uint8_t *buf;
  const size_t len;
  const size_t lenminusstep;
  size_t idx;
};

simdutf_unused static char * format_input_text_64(const uint8_t *text) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    buf[i] = int8_t(text[i]) < ' ' ? '_' : int8_t(text[i]);
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_input_text(const simd8x64<uint8_t>& in) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  in.store(reinterpret_cast<uint8_t*>(buf));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    if (buf[i] < ' ') { buf[i] = '_'; }
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_mask(uint64_t mask) {
  static char *buf = reinterpret_cast<char*>(malloc(64 + 1));
  for (size_t i=0; i<64; i++) {
    buf[i] = (mask & (size_t(1) << i)) ? 'X' : ' ';
  }
  buf[64] = '\0';
  return buf;
}

template<size_t STEP_SIZE>
simdutf_really_inline buf_block_reader<STEP_SIZE>::buf_block_reader(const uint8_t *_buf, size_t _len) : buf{_buf}, len{_len}, lenminusstep{len < STEP_SIZE ? 0 : len - STEP_SIZE}, idx{0} {}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::block_index() { return idx; }

template<size_t STEP_SIZE>
simdutf_really_inline bool buf_block_reader<STEP_SIZE>::has_full_block() const {
  return idx < lenminusstep;
}

template<size_t STEP_SIZE>
simdutf_really_inline const uint8_t *buf_block_reader<STEP_SIZE>::full_block() const {
  return &buf[idx];
}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::get_remainder(uint8_t *dst) const {
  if(len == idx) { return 0; } // memcpy(dst, null, 0) will trigger an error with some sanitizers
  std::memset(dst, 0x20, STEP_SIZE); // std::memset STEP_SIZE because it's more efficient to write out 8 or 16 bytes at once.
  std::memcpy(dst, buf + idx, len - idx);
  return len - idx;
}

template<size_t STEP_SIZE>
simdutf_really_inline void buf_block_reader<STEP_SIZE>::advance() {
  idx += STEP_SIZE;
}

} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/buf_block_reader.h */
/* begin file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8_validation {

using namespace simd;

  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }

  simdutf_really_inline simd8<uint8_t> is_incomplete(const simd8<uint8_t> input) {
    static const uint8_t max_array[32] = {
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 0b11110000u-1, 0b11100000u-1, 0b11000000u-1
    };
    const simd8<uint8_t> max_value(&max_array[sizeof(max_array)-sizeof(simd8<uint8_t>)]);
    return input.gt_bits(max_value);
  }

  struct utf8_checker {
    simd8<uint8_t> error;
    simd8<uint8_t> prev_input_block;
    simd8<uint8_t> prev_incomplete;

    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }

    simdutf_really_inline void check_eof() {
      this->error |= this->prev_incomplete;
    }

    simdutf_really_inline void check_next_input(const simd8x64<uint8_t>& input) {
      if(simdutf_likely(is_ascii(input))) {
        this->error |= this->prev_incomplete;
      } else {
        static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
            "We support either two or four chunks per 64-byte block.");
        if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
        } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
          this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
        }
        this->prev_incomplete = is_incomplete(input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1]);
        this->prev_input_block = input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1];

      }
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // namespace utf8_validation

using utf8_validation::utf8_checker;

} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
/* begin file src/generic/utf8_validation/utf8_validator.h */
namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8_validation {

/**
 * Validates that the string is actual UTF-8.
 */
template<class checker>
bool generic_validate_utf8(const uint8_t * input, size_t length) {
    checker c{};
    buf_block_reader<64> reader(input, length);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      c.check_next_input(in);
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    c.check_next_input(in);
    reader.advance();
    c.check_eof();
    return !c.errors();
}

bool generic_validate_utf8(const char * input, size_t length) {
    return generic_validate_utf8<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

template<class checker>
bool generic_validate_ascii(const uint8_t * input, size_t length) {
    buf_block_reader<64> reader(input, length);
    uint8_t blocks[64]{};
    simd::simd8x64<uint8_t> running_or(blocks);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      running_or |= in;
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    running_or |= in;
    reader.advance();
    return running_or.is_ascii();
}

bool generic_validate_ascii(const char * input, size_t length) {
    return generic_validate_ascii<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

} // namespace utf8_validation
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_validator.h */
/* begin file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */


namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8_to_utf16 {

using namespace simd;

template <endianness endian>
simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char16_t* utf16_output) noexcept {
  size_t pos = 0;
  char16_t* start{utf16_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf16<endian>(utf16_output);
      utf16_output += 64;
      pos += 64;
    } else {
      uint64_t utf8_continuation_mask = in.lt(-65 + 1);
      uint64_t utf8_leading_mask = ~utf8_continuation_mask;
      uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
      size_t max_starting_point = (pos + 64) - 12;
      while(pos < max_starting_point) {
        size_t consumed = convert_masked_utf8_to_utf16<endian>(input + pos,
                            utf8_end_of_code_point_mask, utf16_output);
        pos += consumed;
        utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf16_output += scalar::utf8_to_utf16::convert_valid<endian>(input + pos, size - pos, utf16_output);
  return utf16_output - start;
}

} // namespace utf8_to_utf16
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf16/utf8_to_utf16.h */


namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8_to_utf16 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }


    template <endianness endian>
    simdutf_really_inline size_t convert(const char* in, size_t size, char16_t* utf16_output) {
      size_t pos = 0;
      char16_t* start{utf16_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf16<endian>(utf16_output);
          utf16_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf16<endian>(in + pos,
                            utf8_end_of_code_point_mask, utf16_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf16::convert<endian>(in + pos, size - pos, utf16_output);
        if(howmany == 0) { return 0; }
        utf16_output += howmany;
      }
      return utf16_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf16 namespace
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */

namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8_to_utf32 {

using namespace simd;


simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char32_t* utf32_output) noexcept {
  size_t pos = 0;
  char32_t* start{utf32_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf32(utf32_output);
      utf32_output += 64;
      pos += 64;
    } else {
    uint64_t utf8_continuation_mask = in.lt(-65 + 1);
    uint64_t utf8_leading_mask = ~utf8_continuation_mask;
    uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
    size_t max_starting_point = (pos + 64) - 12;
    while(pos < max_starting_point) {
      size_t consumed = convert_masked_utf8_to_utf32(input + pos,
                          utf8_end_of_code_point_mask, utf32_output);
      pos += consumed;
      utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf32_output += scalar::utf8_to_utf32::convert_valid(input + pos, size - pos, utf32_output);
  return utf32_output - start;
}


} // namespace utf8_to_utf32
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */
/* begin file src/generic/utf8_to_utf32/utf8_to_utf32.h */


namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8_to_utf32 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }



    simdutf_really_inline size_t convert(const char* in, size_t size, char32_t* utf32_output) {
      size_t pos = 0;
      char32_t* start{utf32_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf32(utf32_output);
          utf32_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf32(in + pos,
                            utf8_end_of_code_point_mask, utf32_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf32::convert(in + pos, size - pos, utf32_output);
        if(howmany == 0) { return 0; }
        utf32_output += howmany;
      }
      return utf32_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf32 namespace
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/utf8_to_utf32.h */
/* begin file src/generic/utf8.h */

namespace simdutf {
namespace ppc64 {
namespace {
namespace utf8 {

using namespace simd;

simdutf_really_inline size_t count_code_points(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::count_code_points(in + pos, size - pos);
}


simdutf_really_inline size_t utf16_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
      int64_t utf8_4byte = input.gteq_unsigned(240);
      count += count_ones(utf8_4byte);
    }
    return count + scalar::utf8::utf16_length_from_utf8(in + pos, size - pos);
}


simdutf_really_inline size_t utf32_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::utf32_length_from_utf8(in + pos, size - pos);
}
} // utf8 namespace
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf8.h */
/* begin file src/generic/utf16.h */
#include <iostream>
namespace simdutf {
namespace ppc64 {
namespace {
namespace utf16 {

template <endianness big_endian>
simdutf_really_inline size_t count_code_points(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::count_code_points<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf8_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t ascii_mask = input.lteq(0x7F);
      uint64_t twobyte_mask = input.lteq(0x7FF);
      uint64_t not_pair_mask = input.not_in_range(0xD800, 0xDFFF);

      size_t ascii_count = count_ones(ascii_mask) / 2;
      size_t twobyte_count = count_ones(twobyte_mask & ~ ascii_mask) / 2;
      size_t threebyte_count = count_ones(not_pair_mask & ~ twobyte_mask) / 2;
      size_t fourbyte_count = 32 - count_ones(not_pair_mask) / 2;
      count += 2 * fourbyte_count + 3 * threebyte_count + 2 * twobyte_count + ascii_count;
    }
    return count + scalar::utf16::utf8_length_from_utf16<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf32_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::utf32_length_from_utf16<big_endian>(in + pos, size - pos);
}

simdutf_really_inline void change_endianness_utf16(const char16_t* in, size_t size, char16_t* output) {
  size_t pos = 0;

  while (pos + 32 <= size) {
    simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
    input.swap_bytes();
    input.store(reinterpret_cast<uint16_t *>(output));
    pos += 32;
    output += 32;
  }

  scalar::utf16::change_endianness_utf16(in + pos, size - pos, output);
}

} // utf16
} // unnamed namespace
} // namespace ppc64
} // namespace simdutf
/* end file src/generic/utf16.h */

namespace simdutf {
namespace ppc64 {

simdutf_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept {
  return ppc64::utf8_validation::generic_validate_utf8(buf,len);
}

simdutf_warn_unused bool implementation::validate_ascii(const char *buf, size_t len) const noexcept {
  return ppc64::utf8_validation::generic_validate_ascii(buf,len);
}

simdutf_warn_unused bool implementation::validate_utf16le(const char16_t *buf, size_t len) const noexcept {
  return scalar::utf16::validate<endianness::LITTLE>(buf, len);
}

simdutf_warn_unused bool implementation::validate_utf16be(const char16_t *buf, size_t len) const noexcept {
  return scalar::utf16::validate<endianness::BIG>(buf, len);
}

simdutf_warn_unused bool implementation::validate_utf32(const char16_t *buf, size_t len) const noexcept {
  return scalar::utf32::validate(buf, len);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16le(const char* /*buf*/, size_t /*len*/, char16_t* /*utf16_output*/) const noexcept {
  return 0; // stub
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16be(const char* /*buf*/, size_t /*len*/, char16_t* /*utf16_output*/) const noexcept {
  return 0; // stub
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16le(const char* /*buf*/, size_t /*len*/, char16_t* /*utf16_output*/) const noexcept {
  return 0; // stub
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16be(const char* /*buf*/, size_t /*len*/, char16_t* /*utf16_output*/) const noexcept {
  return 0; // stub
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf32(const char* /*buf*/, size_t /*len*/, char16_t* /*utf16_output*/) const noexcept {
  return 0; // stub
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf32(const char* /*buf*/, size_t /*len*/, char32_t* /*utf16_output*/) const noexcept {
  return 0; // stub
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert<endianness::LITTLE>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert<endianness::BIG>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert_valid<endianness::LITTLE>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf16_to_utf8::convert_valid<endianness::BIG>(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf32_to_utf8::convert(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return scalar::utf32_to_utf8::convert_valid(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert_valid<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return scalar::utf32_to_utf16::convert_valid<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert<endianness::LITTLE>(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert<endianness::BIG>(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert_valid<endianness::LITTLE>(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return scalar::utf16_to_utf32::convert_valid<endianness::BIG>(buf, len, utf32_output);
}

void implementation::change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) const noexcept {
  scalar::utf16::change_endianness_utf16(input, length, output);
}

simdutf_warn_unused size_t implementation::count_utf16le(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::count_code_points<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf16be(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::count_code_points<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf8(const char * input, size_t length) const noexcept {
  return utf8::count_code_points(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf8_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf8_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf32_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return scalar::utf16::utf32_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf8(const char * input, size_t length) const noexcept {
  return scalar::utf8::utf16_length_from_utf8(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  return scalar::utf32::utf8_length_from_utf32(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  return scalar::utf32::utf16_length_from_utf32(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf8(const char * input, size_t length) const noexcept {
  return scalar::utf8::utf32_length_from_utf8(input, length);
}

} // namespace ppc64
} // namespace simdutf

/* begin file src/simdutf/ppc64/end.h */
/* end file src/simdutf/ppc64/end.h */
/* end file src/ppc64/implementation.cpp */
#endif
#if SIMDUTF_IMPLEMENTATION_WESTMERE
/* begin file src/westmere/implementation.cpp */
#include <utility>

/* begin file src/simdutf/westmere/begin.h */
SIMDUTF_TARGET_WESTMERE
/* end file src/simdutf/westmere/begin.h */
namespace simdutf {
namespace westmere {
namespace {
#ifndef SIMDUTF_WESTMERE_H
#error "westmere.h must be included"
#endif
using namespace simd;

simdutf_really_inline bool is_ascii(const simd8x64<uint8_t>& input) {
  return input.reduce_or().is_ascii();
}

simdutf_unused simdutf_really_inline simd8<bool> must_be_continuation(const simd8<uint8_t> prev1, const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
  simd8<uint8_t> is_second_byte = prev1.saturating_sub(0b11000000u-1); // Only 11______ will be > 0
  simd8<uint8_t> is_third_byte  = prev2.saturating_sub(0b11100000u-1); // Only 111_____ will be > 0
  simd8<uint8_t> is_fourth_byte = prev3.saturating_sub(0b11110000u-1); // Only 1111____ will be > 0
  return simd8<int8_t>(is_second_byte | is_third_byte | is_fourth_byte) > int8_t(0);
}

simdutf_really_inline simd8<bool> must_be_2_3_continuation(const simd8<uint8_t> prev2, const simd8<uint8_t> prev3) {
  simd8<uint8_t> is_third_byte  = prev2.saturating_sub(0b11100000u-1); // Only 111_____ will be > 0
  simd8<uint8_t> is_fourth_byte = prev3.saturating_sub(0b11110000u-1); // Only 1111____ will be > 0
  return simd8<int8_t>(is_third_byte | is_fourth_byte) > int8_t(0);
}

/* begin file src/westmere/sse_validate_utf16.cpp */
/*
    In UTF-16 words in range 0xD800 to 0xDFFF have special meaning.

    In a vectorized algorithm we want to examine the most significant
    nibble in order to select a fast path. If none of highest nibbles
    are 0xD (13), than we are sure that UTF-16 chunk in a vector
    register is valid.

    Let us analyze what we need to check if the nibble is 0xD. The
    value of the preceding nibble determines what we have:

    0xd000 .. 0xd7ff - a valid word
    0xd800 .. 0xdbff - low surrogate
    0xdc00 .. 0xdfff - high surrogate

    Other constraints we have to consider:
    - there must not be two consecutive low surrogates (0xd800 .. 0xdbff)
    - there must not be two consecutive high surrogates (0xdc00 .. 0xdfff)
    - there must not be sole low surrogate nor high surrogate

    We're going to build three bitmasks based on the 3rd nibble:
    - V = valid word,
    - L = low surrogate (0xd800 .. 0xdbff)
    - H = high surrogate (0xdc00 .. 0xdfff)

      0   1   2   3   4   5   6   7    <--- word index
    [ V | L | H | L | H | V | V | L ]
      1   0   0   0   0   1   1   0     - V = valid masks
      0   1   0   1   0   0   0   1     - L = low surrogate
      0   0   1   0   1   0   0   0     - H high surrogate


      1   0   0   0   0   1   1   0   V = valid masks
      0   1   0   1   0   0   0   0   a = L & (H >> 1)
      0   0   1   0   1   0   0   0   b = a << 1
      1   1   1   1   1   1   1   0   c = V | a | b
                                  ^
                                  the last bit can be zero, we just consume 7 words
                                  and recheck this word in the next iteration
*/

/* Returns:
   - pointer to the last unprocessed character (a scalar fallback should check the rest);
   - nullptr if an error was detected.
*/
template <endianness big_endian>
const char16_t* sse_validate_utf16(const char16_t* input, size_t size) {
    const char16_t* end = input + size;

    const auto v_d8 = simd8<uint8_t>::splat(0xd8);
    const auto v_f8 = simd8<uint8_t>::splat(0xf8);
    const auto v_fc = simd8<uint8_t>::splat(0xfc);
    const auto v_dc = simd8<uint8_t>::splat(0xdc);

    while (input + simd16<uint16_t>::SIZE * 2 < end) {
        auto in0 = simd16<uint16_t>(input);
        auto in1 = simd16<uint16_t>(input + simd16<uint16_t>::SIZE / sizeof(char16_t));
        if (big_endian) {
            in0 = in0.swap_bytes();
            in1 = in1.swap_bytes();
        }

        const auto t0 = in0.shr<8>();
        const auto t1 = in1.shr<8>();

        const auto in = simd16<uint16_t>::pack(t0, t1);

        const auto surrogates_wordmask = (in & v_f8) == v_d8;
        const uint16_t surrogates_bitmask = static_cast<uint16_t>(surrogates_wordmask.to_bitmask());
        if (surrogates_bitmask == 0x0000) {
            input += 16;
        } else {

            const uint16_t V = static_cast<uint16_t>(~surrogates_bitmask);

            const auto    vH = (in & v_fc) == v_dc;
            const uint16_t H = static_cast<uint16_t>(vH.to_bitmask());

            const uint16_t L = static_cast<uint16_t>(~H & surrogates_bitmask);

            const uint16_t a = static_cast<uint16_t>(L & (H >> 1));  // A low surrogate must be followed by high one.
            const uint16_t b = static_cast<uint16_t>(a << 1);        // Just mark that the opposite fact is hold,
            const uint16_t c = static_cast<uint16_t>(V | a | b);     // Combine all the masks into the final one.

            if (c == 0xffff) {
                input += 16;
            } else if (c == 0x7fff) {
                input += 15;
            } else {
                return nullptr;
            }
        }
    }

    return input;
}
/* end file src/westmere/sse_validate_utf16.cpp */
/* begin file src/westmere/sse_validate_utf32le.cpp */
/* Returns:
   - pointer to the last unprocessed character (a scalar fallback should check the rest);
   - nullptr if an error was detected.
*/
const char32_t* sse_validate_utf32le(const char32_t* input, size_t size) {
    const char32_t* end = input + size;

    const __m128i standardmax = _mm_set1_epi32(0x10ffff);
    const __m128i offset = _mm_set1_epi32(0xffff2000);
    const __m128i standardoffsetmax = _mm_set1_epi32(0xfffff7ff);
    __m128i currentmax = _mm_setzero_si128();
    __m128i currentoffsetmax = _mm_setzero_si128();

    while (input + 4 < end) {
        const __m128i in = _mm_loadu_si128((__m128i *)input);
        currentmax = _mm_max_epu32(in,currentmax);
        currentoffsetmax = _mm_max_epu32(_mm_add_epi32(in, offset), currentoffsetmax);
        input += 4;
    }
    __m128i is_zero = _mm_xor_si128(_mm_max_epu32(currentmax, standardmax), standardmax);
    if(_mm_test_all_zeros(is_zero, is_zero) == 0) {
        return nullptr;
    }

    is_zero = _mm_xor_si128(_mm_max_epu32(currentoffsetmax, standardoffsetmax), standardoffsetmax);
    if(_mm_test_all_zeros(is_zero, is_zero) == 0) {
        return nullptr;
    }

    return input;
}
/* end file src/westmere/sse_validate_utf32le.cpp */

/* begin file src/westmere/sse_convert_utf8_to_utf16.cpp */


template <endianness big_endian>
size_t convert_masked_utf8_to_utf16(const char *input,
                           uint64_t utf8_end_of_code_point_mask,
                           char16_t *&utf16_output) {
  const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
  const __m128i in = _mm_loadu_si128((__m128i *)input);
  const uint16_t input_utf8_end_of_code_point_mask =
      utf8_end_of_code_point_mask & 0xfff;
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xffff)) {
    __m128i ascii_first = _mm_cvtepu8_epi16(in);
    __m128i ascii_second = _mm_cvtepu8_epi16(_mm_srli_si128(in,8));
    if (big_endian) {
      ascii_first = _mm_shuffle_epi8(ascii_first, swap);
      ascii_second = _mm_shuffle_epi8(ascii_second, swap);
    }
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf16_output), ascii_first);
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf16_output + 8), ascii_second);
    utf16_output += 16; // We wrote 16 16-bit characters.
    return 16; // We consumed 16 bytes.
  }
  if(((utf8_end_of_code_point_mask & 0xFFFF) == 0xaaaa)) {
    const __m128i sh = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    if (big_endian) composed = _mm_shuffle_epi8(composed, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed);
    utf16_output += 8; // We wrote 16 bytes, 8 code points.
    return 16;
  }
  if(input_utf8_end_of_code_point_mask == 0x924) {
    const __m128i sh = _mm_setr_epi8(2, 1, 0, -1, 5, 4, 3, -1, 8, 7, 6, -1, 11, 10, 9, -1);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    __m128i composed_repacked = _mm_packus_epi32(composed, composed);
    if (big_endian) composed_repacked = _mm_shuffle_epi8(composed_repacked, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed_repacked);
    utf16_output += 4;
    return 12;
  }

  const uint8_t idx =
      tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][0];
  const uint8_t consumed =
      tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][1];
  if (idx < 64) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    if (big_endian) composed = _mm_shuffle_epi8(composed, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed);
    utf16_output += 6; // We wrote 12 bytes, 6 code points.
  } else if (idx < 145) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
     __m128i composed_repacked = _mm_packus_epi32(composed, composed);
    if (big_endian) composed_repacked = _mm_shuffle_epi8(composed_repacked, swap);
    _mm_storeu_si128((__m128i *)utf16_output, composed_repacked);
    utf16_output += 4;
  } else if (idx < 209) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi32(0x7f));
    const __m128i middlebyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f00));
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    __m128i middlehighbyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f0000));
    const __m128i correct =
        _mm_srli_epi32(_mm_and_si128(perm, _mm_set1_epi32(0x400000)), 1);
    middlehighbyte = _mm_xor_si128(correct, middlehighbyte);
    const __m128i middlehighbyte_shifted = _mm_srli_epi32(middlehighbyte, 4);
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi32(0x07000000));
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 6);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted),
                     _mm_or_si128(highbyte_shifted, middlehighbyte_shifted));
    const __m128i composedminus =
        _mm_sub_epi32(composed, _mm_set1_epi32(0x10000));
    const __m128i lowtenbits =
        _mm_and_si128(composedminus, _mm_set1_epi32(0x3ff));
    const __m128i hightenbits = _mm_srli_epi32(composedminus, 10);
    const __m128i lowtenbitsadd =
        _mm_add_epi32(lowtenbits, _mm_set1_epi32(0xDC00));
    const __m128i hightenbitsadd =
        _mm_add_epi32(hightenbits, _mm_set1_epi32(0xD800));
    const __m128i lowtenbitsaddshifted = _mm_slli_epi32(lowtenbitsadd, 16);
    __m128i surrogates =
        _mm_or_si128(hightenbitsadd, lowtenbitsaddshifted);
    uint32_t basic_buffer[4];
    uint32_t basic_buffer_swap[4];
    if (big_endian) {
      _mm_storeu_si128((__m128i *)basic_buffer_swap, _mm_shuffle_epi8(composed, swap));
      surrogates = _mm_shuffle_epi8(surrogates, swap);
    }
    _mm_storeu_si128((__m128i *)basic_buffer, composed);
    uint32_t surrogate_buffer[4];
    _mm_storeu_si128((__m128i *)surrogate_buffer, surrogates);
    for (size_t i = 0; i < 3; i++) {
      if (basic_buffer[i] < 65536) {
        utf16_output[0] = big_endian ? uint16_t(basic_buffer_swap[i]) : uint16_t(basic_buffer[i]);
        utf16_output++;
      } else {
        utf16_output[0] = uint16_t(surrogate_buffer[i] & 0xffff);
        utf16_output[1] = uint16_t(surrogate_buffer[i] >> 16);
        utf16_output += 2;
      }
    }
  } else {
  }
  return consumed;
}
/* end file src/westmere/sse_convert_utf8_to_utf16.cpp */
/* begin file src/westmere/sse_convert_utf8_to_utf32.cpp */


size_t convert_masked_utf8_to_utf32(const char *input,
                           uint64_t utf8_end_of_code_point_mask,
                           char32_t *&utf32_output) {
  const __m128i in = _mm_loadu_si128((__m128i *)input);
  const uint16_t input_utf8_end_of_code_point_mask =
      utf8_end_of_code_point_mask & 0xfff;
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xffff)) {
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output), _mm_cvtepu8_epi32(in));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output+4), _mm_cvtepu8_epi32(_mm_srli_si128(in,4)));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output+8), _mm_cvtepu8_epi32(_mm_srli_si128(in,8)));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output+12), _mm_cvtepu8_epi32(_mm_srli_si128(in,12)));
    utf32_output += 16; // We wrote 16 32-bit characters.
    return 16; // We consumed 16 bytes.
  }
  if(((utf8_end_of_code_point_mask & 0xffff) == 0xaaaa)) {
    const __m128i sh = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    const __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output), _mm_cvtepu16_epi32(composed));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output+4), _mm_cvtepu16_epi32(_mm_srli_si128(composed,8)));
    utf32_output += 8; // We wrote 32 bytes, 8 code points.
    return 16;
  }
  if(input_utf8_end_of_code_point_mask == 0x924) {
    const __m128i sh = _mm_setr_epi8(2, 1, 0, -1, 5, 4, 3, -1, 8, 7, 6, -1, 11, 10, 9, -1);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    _mm_storeu_si128((__m128i *)utf32_output, composed);
    utf32_output += 4;
    return 12;
  }

  const uint8_t idx =
      tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][0];
  const uint8_t consumed =
      tables::utf8_to_utf16::utf8bigindex[input_utf8_end_of_code_point_mask][1];
  if (idx < 64) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi16(0x7f));
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi16(0x1f00));
    const __m128i composed = _mm_or_si128(ascii, _mm_srli_epi16(highbyte, 2));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output), _mm_cvtepu16_epi32(composed));
    _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output+4), _mm_cvtepu16_epi32(_mm_srli_si128(composed,8)));
    utf32_output += 6; // We wrote 12 bytes, 6 code points.
  } else if (idx < 145) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii =
        _mm_and_si128(perm, _mm_set1_epi32(0x7f)); // 7 or 6 bits
    const __m128i middlebyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x3f00)); // 5 or 6 bits
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    const __m128i highbyte =
        _mm_and_si128(perm, _mm_set1_epi32(0x0f0000)); // 4 bits
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 4);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted), highbyte_shifted);
    _mm_storeu_si128((__m128i *)utf32_output, composed);
    utf32_output += 4;
  } else if (idx < 209) {
    const __m128i sh =
        _mm_loadu_si128((const __m128i *)tables::utf8_to_utf16::shufutf8[idx]);
    const __m128i perm = _mm_shuffle_epi8(in, sh);
    const __m128i ascii = _mm_and_si128(perm, _mm_set1_epi32(0x7f));
    const __m128i middlebyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f00));
    const __m128i middlebyte_shifted = _mm_srli_epi32(middlebyte, 2);
    __m128i middlehighbyte = _mm_and_si128(perm, _mm_set1_epi32(0x3f0000));
    const __m128i correct =
        _mm_srli_epi32(_mm_and_si128(perm, _mm_set1_epi32(0x400000)), 1);
    middlehighbyte = _mm_xor_si128(correct, middlehighbyte);
    const __m128i middlehighbyte_shifted = _mm_srli_epi32(middlehighbyte, 4);
    const __m128i highbyte = _mm_and_si128(perm, _mm_set1_epi32(0x07000000));
    const __m128i highbyte_shifted = _mm_srli_epi32(highbyte, 6);
    const __m128i composed =
        _mm_or_si128(_mm_or_si128(ascii, middlebyte_shifted),
                     _mm_or_si128(highbyte_shifted, middlehighbyte_shifted));
    _mm_storeu_si128((__m128i *)utf32_output, composed);
    utf32_output += 3;
  } else {
  }
  return consumed;
}
/* end file src/westmere/sse_convert_utf8_to_utf32.cpp */

/* begin file src/westmere/sse_convert_utf16_to_utf8.cpp */
/*
    The vectorized algorithm works on single SSE register i.e., it
    loads eight 16-bit words.

    We consider three cases:
    1. an input register contains no surrogates and each value
       is in range 0x0000 .. 0x07ff.
    2. an input register contains no surrogates and values are
       is in range 0x0000 .. 0xffff.
    3. an input register contains surrogates --- i.e. codepoints
       can have 16 or 32 bits.

    Ad 1.

    When values are less than 0x0800, it means that a 16-bit words
    can be converted into: 1) single UTF8 byte (when it's an ASCII
    char) or 2) two UTF8 bytes.

    For this case we do only some shuffle to obtain these 2-byte
    codes and finally compress the whole SSE register with a single
    shuffle.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.

    Ad 2.

    When values fit in 16-bit words, but are above 0x07ff, then
    a single word may produce one, two or three UTF8 bytes.

    We prepare data for all these three cases in two registers.
    The first register contains lower two UTF8 bytes (used in all
    cases), while the second one contains just the third byte for
    the three-UTF8-bytes case.

    Finally these two registers are interleaved forming eight-element
    array of 32-bit values. The array spans two SSE registers.
    The bytes from the registers are compressed using two shuffles.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.


    To summarize:
    - We need two 256-entry tables that have 8704 bytes in total.
*/

/*
  Returns a pair: the first unprocessed byte from buf and utf8_output
  A scalar routing should carry on the conversion of the tail.
*/
template <endianness big_endian>
std::pair<const char16_t*, char*> sse_convert_utf16_to_utf8(const char16_t* buf, size_t len, char* utf8_output) {

  const char16_t* end = buf + len;

  const __m128i v_0000 = _mm_setzero_si128();
  const __m128i v_f800 = _mm_set1_epi16((int16_t)0xf800);
  const __m128i v_d800 = _mm_set1_epi16((int16_t)0xd800);
  const __m128i v_c080 = _mm_set1_epi16((int16_t)0xc080);
  while (buf + 16 <= end) {
    __m128i in = _mm_loadu_si128((__m128i*)buf);
    if (big_endian) {
      const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
      in = _mm_shuffle_epi8(in, swap);
    }
    const __m128i v_ff80 = _mm_set1_epi16((int16_t)0xff80);
    if(_mm_testz_si128(in, v_ff80)) { // ASCII fast path!!!!
        __m128i nextin = _mm_loadu_si128((__m128i*)buf+1);
        if (big_endian) {
          const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
          nextin = _mm_shuffle_epi8(nextin, swap);
        }
        if(!_mm_testz_si128(nextin, v_ff80)) {
          const __m128i utf8_packed = _mm_packus_epi16(in,in);
          _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);
          buf += 8;
          utf8_output += 8;
          in = nextin;
        } else {
          const __m128i utf8_packed = _mm_packus_epi16(in,nextin);
          _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);
          buf += 16;
          utf8_output += 16;
          continue; // we are done for this round!
        }
    }

    const __m128i one_byte_bytemask = _mm_cmpeq_epi16(_mm_and_si128(in, v_ff80), v_0000);
    const uint16_t one_byte_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(one_byte_bytemask));

    const __m128i one_or_two_bytes_bytemask = _mm_cmpeq_epi16(_mm_and_si128(in, v_f800), v_0000);
    const uint16_t one_or_two_bytes_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(one_or_two_bytes_bytemask));

    if (one_or_two_bytes_bitmask == 0xffff) {
          const __m128i v_1f00 = _mm_set1_epi16((int16_t)0x1f00);
          const __m128i v_003f = _mm_set1_epi16((int16_t)0x003f);

          const __m128i t0 = _mm_slli_epi16(in, 2);
          const __m128i t1 = _mm_and_si128(t0, v_1f00);
          const __m128i t2 = _mm_and_si128(in, v_003f);
          const __m128i t3 = _mm_or_si128(t1, t2);
          const __m128i t4 = _mm_or_si128(t3, v_c080);

          const __m128i utf8_unpacked = _mm_blendv_epi8(t4, in, one_byte_bytemask);

          const uint16_t m0 = one_byte_bitmask & 0x5555;  // m0 = 0h0g0f0e0d0c0b0a
          const uint16_t m1 = static_cast<uint16_t>(m0 >> 7);                    // m1 = 00000000h0g0f0e0
          const uint8_t  m2 = static_cast<uint8_t>((m0 | m1) & 0xff);           // m2 =         hdgcfbea
          const uint8_t* row = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[m2][0];
          const __m128i shuffle = _mm_loadu_si128((__m128i*)(row + 1));
          const __m128i utf8_packed = _mm_shuffle_epi8(utf8_unpacked, shuffle);

          _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);

          buf += 8;
          utf8_output += row[0];
          continue;

    }

    const __m128i surrogates_bytemask = _mm_cmpeq_epi16(_mm_and_si128(in, v_f800), v_d800);

    const uint16_t surrogates_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(surrogates_bytemask));
    if (surrogates_bitmask == 0x0000) {
        const __m128i dup_even = _mm_setr_epi16(0x0000, 0x0202, 0x0404, 0x0606,
                                                0x0808, 0x0a0a, 0x0c0c, 0x0e0e);

        /* In this branch we handle three cases:
           1. [0000|0000|0ccc|cccc] => [0ccc|cccc]                           - single UFT-8 byte
           2. [0000|0bbb|bbcc|cccc] => [110b|bbbb], [10cc|cccc]              - two UTF-8 bytes
           3. [aaaa|bbbb|bbcc|cccc] => [1110|aaaa], [10bb|bbbb], [10cc|cccc] - three UTF-8 bytes

          We expand the input word (16-bit) into two words (32-bit), thus
          we have room for four bytes. However, we need five distinct bit
          layouts. Note that the last byte in cases #2 and #3 is the same.

          We precompute byte 1 for case #1 and the common byte for cases #2 & #3
          in register t2.

          We precompute byte 1 for case #3 and -- **conditionally** -- precompute
          either byte 1 for case #2 or byte 2 for case #3. Note that they
          differ by exactly one bit.

          Finally from these two words we build proper UTF-8 sequence, taking
          into account the case (i.e, the number of bytes to write).
        */
        /**
         * Given [aaaa|bbbb|bbcc|cccc] our goal is to produce:
         * t2 => [0ccc|cccc] [10cc|cccc]
         * s4 => [1110|aaaa] ([110b|bbbb] OR [10bb|bbbb])
         */
#define vec(x) _mm_set1_epi16(static_cast<uint16_t>(x))
        const __m128i t0 = _mm_shuffle_epi8(in, dup_even);
        const __m128i t1 = _mm_and_si128(t0, vec(0b0011111101111111));
        const __m128i t2 = _mm_or_si128 (t1, vec(0b1000000000000000));

        const __m128i s0 = _mm_srli_epi16(in, 4);
        const __m128i s1 = _mm_and_si128(s0, vec(0b0000111111111100));
        const __m128i s2 = _mm_maddubs_epi16(s1, vec(0x0140));
        const __m128i s3 = _mm_or_si128(s2, vec(0b1100000011100000));
        const __m128i m0 = _mm_andnot_si128(one_or_two_bytes_bytemask, vec(0b0100000000000000));
        const __m128i s4 = _mm_xor_si128(s3, m0);
#undef vec

        const __m128i out0 = _mm_unpacklo_epi16(t2, s4);
        const __m128i out1 = _mm_unpackhi_epi16(t2, s4);

        const uint16_t mask = (one_byte_bitmask & 0x5555) |
                              (one_or_two_bytes_bitmask & 0xaaaa);
        if(mask == 0) {
          const __m128i shuffle = _mm_setr_epi8(2,3,1,6,7,5,10,11,9,14,15,13,-1,-1,-1,-1);
          const __m128i utf8_0 = _mm_shuffle_epi8(out0, shuffle);
          const __m128i utf8_1 = _mm_shuffle_epi8(out1, shuffle);
          _mm_storeu_si128((__m128i*)utf8_output, utf8_0);
          utf8_output += 12;
          _mm_storeu_si128((__m128i*)utf8_output, utf8_1);
          utf8_output += 12;
          buf += 8;
          continue;
        }
        const uint8_t mask0 = uint8_t(mask);

        const uint8_t* row0 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask0][0];
        const __m128i shuffle0 = _mm_loadu_si128((__m128i*)(row0 + 1));
        const __m128i utf8_0 = _mm_shuffle_epi8(out0, shuffle0);

        const uint8_t mask1 = static_cast<uint8_t>(mask >> 8);

        const uint8_t* row1 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask1][0];
        const __m128i shuffle1 = _mm_loadu_si128((__m128i*)(row1 + 1));
        const __m128i utf8_1 = _mm_shuffle_epi8(out1, shuffle1);

        _mm_storeu_si128((__m128i*)utf8_output, utf8_0);
        utf8_output += row0[0];
        _mm_storeu_si128((__m128i*)utf8_output, utf8_1);
        utf8_output += row1[0];

        buf += 8;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint16_t word = big_endian ? scalar::utf16::swap_bytes(buf[k]) : buf[k];
        if((word & 0xFF80)==0) {
          *utf8_output++ = char(word);
        } else if((word & 0xF800)==0) {
          *utf8_output++ = char((word>>6) | 0b11000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else if((word &0xF800 ) != 0xD800) {
          *utf8_output++ = char((word>>12) | 0b11100000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else {
          uint16_t diff = uint16_t(word - 0xD800);
          uint16_t next_word = big_endian ? scalar::utf16::swap_bytes(buf[k+1]) : buf[k+1];
          k++;
          uint16_t diff2 = uint16_t(next_word - 0xDC00);
          if((diff | diff2) > 0x3FF)  { return std::make_pair(nullptr, utf8_output); }
          uint32_t value = (diff << 10) + diff2 + 0x10000;
          *utf8_output++ = char((value>>18) | 0b11110000);
          *utf8_output++ = char(((value>>12) & 0b111111) | 0b10000000);
          *utf8_output++ = char(((value>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((value & 0b111111) | 0b10000000);
        }
      }
      buf += k;
    }
  } // while

  return std::make_pair(buf, utf8_output);
}
/* end file src/westmere/sse_convert_utf16_to_utf8.cpp */
/* begin file src/westmere/sse_convert_utf16_to_utf32.cpp */
/*
    The vectorized algorithm works on single SSE register i.e., it
    loads eight 16-bit words.

    We consider three cases:
    1. an input register contains no surrogates and each value
       is in range 0x0000 .. 0x07ff.
    2. an input register contains no surrogates and values are
       is in range 0x0000 .. 0xffff.
    3. an input register contains surrogates --- i.e. codepoints
       can have 16 or 32 bits.

    Ad 1.

    When values are less than 0x0800, it means that a 16-bit words
    can be converted into: 1) single UTF8 byte (when it's an ASCII
    char) or 2) two UTF8 bytes.

    For this case we do only some shuffle to obtain these 2-byte
    codes and finally compress the whole SSE register with a single
    shuffle.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.

    Ad 2.

    When values fit in 16-bit words, but are above 0x07ff, then
    a single word may produce one, two or three UTF8 bytes.

    We prepare data for all these three cases in two registers.
    The first register contains lower two UTF8 bytes (used in all
    cases), while the second one contains just the third byte for
    the three-UTF8-bytes case.

    Finally these two registers are interleaved forming eight-element
    array of 32-bit values. The array spans two SSE registers.
    The bytes from the registers are compressed using two shuffles.

    We need 256-entry lookup table to get a compression pattern
    and the number of output bytes in the compressed vector register.
    Each entry occupies 17 bytes.


    To summarize:
    - We need two 256-entry tables that have 8704 bytes in total.
*/

/*
  Returns a pair: the first unprocessed byte from buf and utf8_output
  A scalar routing should carry on the conversion of the tail.
*/
template <endianness big_endian>
std::pair<const char16_t*, char32_t*> sse_convert_utf16_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) {
  const char16_t* end = buf + len;

  const __m128i v_f800 = _mm_set1_epi16((int16_t)0xf800);
  const __m128i v_d800 = _mm_set1_epi16((int16_t)0xd800);

  while (buf + 16 <= end) {
    __m128i in = _mm_loadu_si128((__m128i*)buf);

    if (big_endian) {
      const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
      in = _mm_shuffle_epi8(in, swap);
    }

    const __m128i surrogates_bytemask = _mm_cmpeq_epi16(_mm_and_si128(in, v_f800), v_d800);

    const uint16_t surrogates_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(surrogates_bytemask));
    if (surrogates_bitmask == 0x0000) {
        _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output), _mm_cvtepu16_epi32(in));
        _mm_storeu_si128(reinterpret_cast<__m128i *>(utf32_output+4), _mm_cvtepu16_epi32(_mm_srli_si128(in,8)));
        utf32_output += 8;
        buf += 8;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint16_t word = big_endian ? scalar::utf16::swap_bytes(buf[k]) : buf[k];
        if((word &0xF800 ) != 0xD800) {
          *utf32_output++ = char32_t(word);
        } else {
          uint16_t diff = uint16_t(word - 0xD800);
          uint16_t next_word = big_endian ? scalar::utf16::swap_bytes(buf[k+1]) : buf[k+1];
          k++;
          uint16_t diff2 = uint16_t(next_word - 0xDC00);
          if((diff | diff2) > 0x3FF)  { return std::make_pair(nullptr, utf32_output); }
          uint32_t value = (diff << 10) + diff2 + 0x10000;
          *utf32_output++ = char32_t(value);
        }
      }
      buf += k;
    }
  } // while
  return std::make_pair(buf, utf32_output);
}
/* end file src/westmere/sse_convert_utf16_to_utf32.cpp */

/* begin file src/westmere/sse_convert_utf32_to_utf8.cpp */
std::pair<const char32_t*, char*> sse_convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) {

  const char32_t* end = buf + len;

  const __m128i v_0000 = _mm_setzero_si128();
  const __m128i v_f800 = _mm_set1_epi16((uint16_t)0xf800);
  const __m128i v_c080 = _mm_set1_epi16((uint16_t)0xc080);
  const __m128i v_ff80 = _mm_set1_epi16((uint16_t)0xff80);
  const __m128i v_ffff0000 = _mm_set1_epi32((uint32_t)0xffff0000);
  const __m128i v_7fffffff = _mm_set1_epi32((uint32_t)0x7fffffff);
  __m128i running_max = _mm_setzero_si128();
  __m128i forbidden_bytemask = _mm_setzero_si128();
  const size_t safety_margin = 11; // to avoid overruns, see issue https://github.com/simdutf/simdutf/issues/92

  while (buf + 16 + safety_margin <= end) {
    __m128i in = _mm_loadu_si128((__m128i*)buf);
    __m128i nextin = _mm_loadu_si128((__m128i*)buf+1);
    running_max = _mm_max_epu32(_mm_max_epu32(in, running_max), nextin);

    __m128i in_16 = _mm_packus_epi32(_mm_and_si128(in, v_7fffffff), _mm_and_si128(nextin, v_7fffffff));


    if(_mm_testz_si128(in_16, v_ff80)) { // ASCII fast path!!!!
      __m128i thirdin = _mm_loadu_si128((__m128i*)buf+2);
      __m128i fourthin = _mm_loadu_si128((__m128i*)buf+3);
      running_max = _mm_max_epu32(_mm_max_epu32(thirdin, running_max), fourthin);
      __m128i nextin_16 = _mm_packus_epi32(_mm_and_si128(thirdin, v_7fffffff), _mm_and_si128(fourthin, v_7fffffff));
      if(!_mm_testz_si128(nextin_16, v_ff80)) {
        const __m128i utf8_packed = _mm_packus_epi16(in_16,in_16);
        _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);
        buf += 8;
        utf8_output += 8;
        in_16 = nextin_16;
      } else {
        const __m128i utf8_packed = _mm_packus_epi16(in_16, nextin_16);
        _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);
        buf += 16;
        utf8_output += 16;
        continue; // we are done for this round!
      }
    }

    const __m128i one_byte_bytemask = _mm_cmpeq_epi16(_mm_and_si128(in_16, v_ff80), v_0000);
    const uint16_t one_byte_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(one_byte_bytemask));

    const __m128i one_or_two_bytes_bytemask = _mm_cmpeq_epi16(_mm_and_si128(in_16, v_f800), v_0000);
    const uint16_t one_or_two_bytes_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(one_or_two_bytes_bytemask));

    if (one_or_two_bytes_bitmask == 0xffff) {
      const __m128i v_1f00 = _mm_set1_epi16((int16_t)0x1f00);
      const __m128i v_003f = _mm_set1_epi16((int16_t)0x003f);

      const __m128i t0 = _mm_slli_epi16(in_16, 2);
      const __m128i t1 = _mm_and_si128(t0, v_1f00);
      const __m128i t2 = _mm_and_si128(in_16, v_003f);
      const __m128i t3 = _mm_or_si128(t1, t2);
      const __m128i t4 = _mm_or_si128(t3, v_c080);

      const __m128i utf8_unpacked = _mm_blendv_epi8(t4, in_16, one_byte_bytemask);

      const uint16_t m0 = one_byte_bitmask & 0x5555;  // m0 = 0h0g0f0e0d0c0b0a
      const uint16_t m1 = static_cast<uint16_t>(m0 >> 7);                    // m1 = 00000000h0g0f0e0
      const uint8_t  m2 = static_cast<uint8_t>((m0 | m1) & 0xff);           // m2 =         hdgcfbea
      const uint8_t* row = &simdutf::tables::utf16_to_utf8::pack_1_2_utf8_bytes[m2][0];
      const __m128i shuffle = _mm_loadu_si128((__m128i*)(row + 1));
      const __m128i utf8_packed = _mm_shuffle_epi8(utf8_unpacked, shuffle);

      _mm_storeu_si128((__m128i*)utf8_output, utf8_packed);

      buf += 8;
      utf8_output += row[0];
      continue;
    }


    const __m128i saturation_bytemask = _mm_cmpeq_epi32(_mm_and_si128(_mm_or_si128(in, nextin), v_ffff0000), v_0000);
    const uint32_t saturation_bitmask = static_cast<uint32_t>(_mm_movemask_epi8(saturation_bytemask));

    if (saturation_bitmask == 0xffff) {
      const __m128i v_d800 = _mm_set1_epi16((uint16_t)0xd800);
      forbidden_bytemask = _mm_or_si128(forbidden_bytemask, _mm_cmpeq_epi16(_mm_and_si128(in_16, v_f800), v_d800));

      const __m128i dup_even = _mm_setr_epi16(0x0000, 0x0202, 0x0404, 0x0606,
                                              0x0808, 0x0a0a, 0x0c0c, 0x0e0e);

      /* In this branch we handle three cases:
          1. [0000|0000|0ccc|cccc] => [0ccc|cccc]                           - single UFT-8 byte
          2. [0000|0bbb|bbcc|cccc] => [110b|bbbb], [10cc|cccc]              - two UTF-8 bytes
          3. [aaaa|bbbb|bbcc|cccc] => [1110|aaaa], [10bb|bbbb], [10cc|cccc] - three UTF-8 bytes

        We expand the input word (16-bit) into two words (32-bit), thus
        we have room for four bytes. However, we need five distinct bit
        layouts. Note that the last byte in cases #2 and #3 is the same.

        We precompute byte 1 for case #1 and the common byte for cases #2 & #3
        in register t2.

        We precompute byte 1 for case #3 and -- **conditionally** -- precompute
        either byte 1 for case #2 or byte 2 for case #3. Note that they
        differ by exactly one bit.

        Finally from these two words we build proper UTF-8 sequence, taking
        into account the case (i.e, the number of bytes to write).
      */
      /**
       * Given [aaaa|bbbb|bbcc|cccc] our goal is to produce:
       * t2 => [0ccc|cccc] [10cc|cccc]
       * s4 => [1110|aaaa] ([110b|bbbb] OR [10bb|bbbb])
       */
#define vec(x) _mm_set1_epi16(static_cast<uint16_t>(x))
      const __m128i t0 = _mm_shuffle_epi8(in_16, dup_even);
      const __m128i t1 = _mm_and_si128(t0, vec(0b0011111101111111));
      const __m128i t2 = _mm_or_si128 (t1, vec(0b1000000000000000));

      const __m128i s0 = _mm_srli_epi16(in_16, 4);
      const __m128i s1 = _mm_and_si128(s0, vec(0b0000111111111100));
      const __m128i s2 = _mm_maddubs_epi16(s1, vec(0x0140));
      const __m128i s3 = _mm_or_si128(s2, vec(0b1100000011100000));
      const __m128i m0 = _mm_andnot_si128(one_or_two_bytes_bytemask, vec(0b0100000000000000));
      const __m128i s4 = _mm_xor_si128(s3, m0);
#undef vec

      const __m128i out0 = _mm_unpacklo_epi16(t2, s4);
      const __m128i out1 = _mm_unpackhi_epi16(t2, s4);

      const uint16_t mask = (one_byte_bitmask & 0x5555) |
                            (one_or_two_bytes_bitmask & 0xaaaa);
      if(mask == 0) {
        const __m128i shuffle = _mm_setr_epi8(2,3,1,6,7,5,10,11,9,14,15,13,-1,-1,-1,-1);
        const __m128i utf8_0 = _mm_shuffle_epi8(out0, shuffle);
        const __m128i utf8_1 = _mm_shuffle_epi8(out1, shuffle);
        _mm_storeu_si128((__m128i*)utf8_output, utf8_0);
        utf8_output += 12;
        _mm_storeu_si128((__m128i*)utf8_output, utf8_1);
        utf8_output += 12;
        buf += 8;
        continue;
      }
      const uint8_t mask0 = uint8_t(mask);

      const uint8_t* row0 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask0][0];
      const __m128i shuffle0 = _mm_loadu_si128((__m128i*)(row0 + 1));
      const __m128i utf8_0 = _mm_shuffle_epi8(out0, shuffle0);

      const uint8_t mask1 = static_cast<uint8_t>(mask >> 8);

      const uint8_t* row1 = &simdutf::tables::utf16_to_utf8::pack_1_2_3_utf8_bytes[mask1][0];
      const __m128i shuffle1 = _mm_loadu_si128((__m128i*)(row1 + 1));
      const __m128i utf8_1 = _mm_shuffle_epi8(out1, shuffle1);

      _mm_storeu_si128((__m128i*)utf8_output, utf8_0);
      utf8_output += row0[0];
      _mm_storeu_si128((__m128i*)utf8_output, utf8_1);
      utf8_output += row1[0];

      buf += 8;
    } else {
      size_t forward = 15;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint32_t word = buf[k];
        if((word & 0xFFFFFF80)==0) {
          *utf8_output++ = char(word);
        } else if((word & 0xFFFFF800)==0) {
          *utf8_output++ = char((word>>6) | 0b11000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else if((word &0xFFFF0000 )==0) {
          if (word >= 0xD800 && word <= 0xDFFF) { return std::make_pair(nullptr, utf8_output); }
          *utf8_output++ = char((word>>12) | 0b11100000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        } else {
          if (word > 0x10FFFF) { return std::make_pair(nullptr, utf8_output); }
          *utf8_output++ = char((word>>18) | 0b11110000);
          *utf8_output++ = char(((word>>12) & 0b111111) | 0b10000000);
          *utf8_output++ = char(((word>>6) & 0b111111) | 0b10000000);
          *utf8_output++ = char((word & 0b111111) | 0b10000000);
        }
      }
      buf += k;
    }
  } // while

  const __m128i v_10ffff = _mm_set1_epi32((uint32_t)0x10ffff);
  if(static_cast<uint16_t>(_mm_movemask_epi8(_mm_cmpeq_epi32(_mm_max_epu32(running_max, v_10ffff), v_10ffff))) != 0xffff) {
    return std::make_pair(nullptr, utf8_output);
  }

  if (static_cast<uint32_t>(_mm_movemask_epi8(forbidden_bytemask)) != 0) { return std::make_pair(nullptr, utf8_output); }

  return std::make_pair(buf, utf8_output);
}
/* end file src/westmere/sse_convert_utf32_to_utf8.cpp */
/* begin file src/westmere/sse_convert_utf32_to_utf16.cpp */
template <endianness big_endian>
std::pair<const char32_t*, char16_t*> sse_convert_utf32_to_utf16(const char32_t* buf, size_t len, char16_t* utf16_output) {

  const char32_t* end = buf + len;

  const __m128i v_0000 = _mm_setzero_si128();
  const __m128i v_ffff0000 = _mm_set1_epi32((int32_t)0xffff0000);
  __m128i forbidden_bytemask = _mm_setzero_si128();

  while (buf + 8 <= end) {
    __m128i in = _mm_loadu_si128((__m128i*)buf);
    __m128i nextin = _mm_loadu_si128((__m128i*)buf+1);
    const __m128i saturation_bytemask = _mm_cmpeq_epi32(_mm_and_si128(_mm_or_si128(in, nextin), v_ffff0000), v_0000);
    const uint32_t saturation_bitmask = static_cast<uint32_t>(_mm_movemask_epi8(saturation_bytemask));

    if (saturation_bitmask == 0xffff) {
      __m128i utf16_packed = _mm_packus_epi32(in, nextin);

      const __m128i v_f800 = _mm_set1_epi16((uint16_t)0xf800);
      const __m128i v_d800 = _mm_set1_epi16((uint16_t)0xd800);
      forbidden_bytemask = _mm_or_si128(forbidden_bytemask, _mm_cmpeq_epi16(_mm_and_si128(utf16_packed, v_f800), v_d800));

      if (big_endian) {
        const __m128i swap = _mm_setr_epi8(1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14);
        utf16_packed = _mm_shuffle_epi8(utf16_packed, swap);
      }

      _mm_storeu_si128((__m128i*)utf16_output, utf16_packed);
      utf16_output += 8;
      buf += 8;
    } else {
      size_t forward = 7;
      size_t k = 0;
      if(size_t(end - buf) < forward + 1) { forward = size_t(end - buf - 1);}
      for(; k < forward; k++) {
        uint32_t word = buf[k];
        if((word & 0xFFFF0000)==0) {
          if (word >= 0xD800 && word <= 0xDFFF) { return std::make_pair(nullptr, utf16_output); }
          *utf16_output++ = big_endian ? char16_t((uint16_t(word) >> 8) | (uint16_t(word) << 8)) : char16_t(word);
        } else {
          if (word > 0x10FFFF) { return std::make_pair(nullptr, utf16_output); }
          word -= 0x10000;
          uint16_t high_surrogate = uint16_t(0xD800 + (word >> 10));
          uint16_t low_surrogate = uint16_t(0xDC00 + (word & 0x3FF));
          if (big_endian) {
            high_surrogate = uint16_t((high_surrogate >> 8) | (high_surrogate << 8));
            low_surrogate = uint16_t((low_surrogate >> 8) | (low_surrogate << 8));
          }
          *utf16_output++ = char16_t(high_surrogate);
          *utf16_output++ = char16_t(low_surrogate);
        }
      }
      buf += k;
    }
  }

  if (static_cast<uint32_t>(_mm_movemask_epi8(forbidden_bytemask)) != 0) { return std::make_pair(nullptr, utf16_output); }

  return std::make_pair(buf, utf16_output);
}
/* end file src/westmere/sse_convert_utf32_to_utf16.cpp */

} // unnamed namespace
} // namespace westmere
} // namespace simdutf

/* begin file src/generic/buf_block_reader.h */
namespace simdutf {
namespace westmere {
namespace {

template<size_t STEP_SIZE>
struct buf_block_reader {
public:
  simdutf_really_inline buf_block_reader(const uint8_t *_buf, size_t _len);
  simdutf_really_inline size_t block_index();
  simdutf_really_inline bool has_full_block() const;
  simdutf_really_inline const uint8_t *full_block() const;
  /**
   * Get the last block, padded with spaces.
   *
   * There will always be a last block, with at least 1 byte, unless len == 0 (in which case this
   * function fills the buffer with spaces and returns 0. In particular, if len == STEP_SIZE there
   * will be 0 full_blocks and 1 remainder block with STEP_SIZE bytes and no spaces for padding.
   *
   * @return the number of effective characters in the last block.
   */
  simdutf_really_inline size_t get_remainder(uint8_t *dst) const;
  simdutf_really_inline void advance();
private:
  const uint8_t *buf;
  const size_t len;
  const size_t lenminusstep;
  size_t idx;
};

simdutf_unused static char * format_input_text_64(const uint8_t *text) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    buf[i] = int8_t(text[i]) < ' ' ? '_' : int8_t(text[i]);
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_input_text(const simd8x64<uint8_t>& in) {
  static char *buf = reinterpret_cast<char*>(malloc(sizeof(simd8x64<uint8_t>) + 1));
  in.store(reinterpret_cast<uint8_t*>(buf));
  for (size_t i=0; i<sizeof(simd8x64<uint8_t>); i++) {
    if (buf[i] < ' ') { buf[i] = '_'; }
  }
  buf[sizeof(simd8x64<uint8_t>)] = '\0';
  return buf;
}

simdutf_unused static char * format_mask(uint64_t mask) {
  static char *buf = reinterpret_cast<char*>(malloc(64 + 1));
  for (size_t i=0; i<64; i++) {
    buf[i] = (mask & (size_t(1) << i)) ? 'X' : ' ';
  }
  buf[64] = '\0';
  return buf;
}

template<size_t STEP_SIZE>
simdutf_really_inline buf_block_reader<STEP_SIZE>::buf_block_reader(const uint8_t *_buf, size_t _len) : buf{_buf}, len{_len}, lenminusstep{len < STEP_SIZE ? 0 : len - STEP_SIZE}, idx{0} {}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::block_index() { return idx; }

template<size_t STEP_SIZE>
simdutf_really_inline bool buf_block_reader<STEP_SIZE>::has_full_block() const {
  return idx < lenminusstep;
}

template<size_t STEP_SIZE>
simdutf_really_inline const uint8_t *buf_block_reader<STEP_SIZE>::full_block() const {
  return &buf[idx];
}

template<size_t STEP_SIZE>
simdutf_really_inline size_t buf_block_reader<STEP_SIZE>::get_remainder(uint8_t *dst) const {
  if(len == idx) { return 0; } // memcpy(dst, null, 0) will trigger an error with some sanitizers
  std::memset(dst, 0x20, STEP_SIZE); // std::memset STEP_SIZE because it's more efficient to write out 8 or 16 bytes at once.
  std::memcpy(dst, buf + idx, len - idx);
  return len - idx;
}

template<size_t STEP_SIZE>
simdutf_really_inline void buf_block_reader<STEP_SIZE>::advance() {
  idx += STEP_SIZE;
}

} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/buf_block_reader.h */
/* begin file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
namespace simdutf {
namespace westmere {
namespace {
namespace utf8_validation {

using namespace simd;

  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }

  simdutf_really_inline simd8<uint8_t> is_incomplete(const simd8<uint8_t> input) {
    static const uint8_t max_array[32] = {
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 0b11110000u-1, 0b11100000u-1, 0b11000000u-1
    };
    const simd8<uint8_t> max_value(&max_array[sizeof(max_array)-sizeof(simd8<uint8_t>)]);
    return input.gt_bits(max_value);
  }

  struct utf8_checker {
    simd8<uint8_t> error;
    simd8<uint8_t> prev_input_block;
    simd8<uint8_t> prev_incomplete;

    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }

    simdutf_really_inline void check_eof() {
      this->error |= this->prev_incomplete;
    }

    simdutf_really_inline void check_next_input(const simd8x64<uint8_t>& input) {
      if(simdutf_likely(is_ascii(input))) {
        this->error |= this->prev_incomplete;
      } else {
        static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
            "We support either two or four chunks per 64-byte block.");
        if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
        } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
          this->check_utf8_bytes(input.chunks[0], this->prev_input_block);
          this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
          this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
        }
        this->prev_incomplete = is_incomplete(input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1]);
        this->prev_input_block = input.chunks[simd8x64<uint8_t>::NUM_CHUNKS-1];

      }
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // namespace utf8_validation

using utf8_validation::utf8_checker;

} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_lookup4_algorithm.h */
/* begin file src/generic/utf8_validation/utf8_validator.h */
namespace simdutf {
namespace westmere {
namespace {
namespace utf8_validation {

/**
 * Validates that the string is actual UTF-8.
 */
template<class checker>
bool generic_validate_utf8(const uint8_t * input, size_t length) {
    checker c{};
    buf_block_reader<64> reader(input, length);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      c.check_next_input(in);
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    c.check_next_input(in);
    reader.advance();
    c.check_eof();
    return !c.errors();
}

bool generic_validate_utf8(const char * input, size_t length) {
    return generic_validate_utf8<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

template<class checker>
bool generic_validate_ascii(const uint8_t * input, size_t length) {
    buf_block_reader<64> reader(input, length);
    uint8_t blocks[64]{};
    simd::simd8x64<uint8_t> running_or(blocks);
    while (reader.has_full_block()) {
      simd::simd8x64<uint8_t> in(reader.full_block());
      running_or |= in;
      reader.advance();
    }
    uint8_t block[64]{};
    reader.get_remainder(block);
    simd::simd8x64<uint8_t> in(block);
    running_or |= in;
    reader.advance();
    return running_or.is_ascii();
}

bool generic_validate_ascii(const char * input, size_t length) {
    return generic_validate_ascii<utf8_checker>(reinterpret_cast<const uint8_t *>(input),length);
}

} // namespace utf8_validation
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8_validation/utf8_validator.h */
/* begin file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */


namespace simdutf {
namespace westmere {
namespace {
namespace utf8_to_utf16 {

using namespace simd;

template <endianness endian>
simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char16_t* utf16_output) noexcept {
  size_t pos = 0;
  char16_t* start{utf16_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf16<endian>(utf16_output);
      utf16_output += 64;
      pos += 64;
    } else {
      uint64_t utf8_continuation_mask = in.lt(-65 + 1);
      uint64_t utf8_leading_mask = ~utf8_continuation_mask;
      uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
      size_t max_starting_point = (pos + 64) - 12;
      while(pos < max_starting_point) {
        size_t consumed = convert_masked_utf8_to_utf16<endian>(input + pos,
                            utf8_end_of_code_point_mask, utf16_output);
        pos += consumed;
        utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf16_output += scalar::utf8_to_utf16::convert_valid<endian>(input + pos, size - pos, utf16_output);
  return utf16_output - start;
}

} // namespace utf8_to_utf16
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/valid_utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf16/utf8_to_utf16.h */


namespace simdutf {
namespace westmere {
namespace {
namespace utf8_to_utf16 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }


    template <endianness endian>
    simdutf_really_inline size_t convert(const char* in, size_t size, char16_t* utf16_output) {
      size_t pos = 0;
      char16_t* start{utf16_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf16<endian>(utf16_output);
          utf16_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf16<endian>(in + pos,
                            utf8_end_of_code_point_mask, utf16_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf16::convert<endian>(in + pos, size - pos, utf16_output);
        if(howmany == 0) { return 0; }
        utf16_output += howmany;
      }
      return utf16_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf16 namespace
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8_to_utf16/utf8_to_utf16.h */
/* begin file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */

namespace simdutf {
namespace westmere {
namespace {
namespace utf8_to_utf32 {

using namespace simd;


simdutf_warn_unused size_t convert_valid(const char* input, size_t size,
    char32_t* utf32_output) noexcept {
  size_t pos = 0;
  char32_t* start{utf32_output};
  const size_t safety_margin = 16; // to avoid overruns!
  while(pos + 64 + safety_margin <= size) {
    simd8x64<int8_t> in(reinterpret_cast<const int8_t *>(input + pos));
    if(in.is_ascii()) {
      in.store_ascii_as_utf32(utf32_output);
      utf32_output += 64;
      pos += 64;
    } else {
    uint64_t utf8_continuation_mask = in.lt(-65 + 1);
    uint64_t utf8_leading_mask = ~utf8_continuation_mask;
    uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
    size_t max_starting_point = (pos + 64) - 12;
    while(pos < max_starting_point) {
      size_t consumed = convert_masked_utf8_to_utf32(input + pos,
                          utf8_end_of_code_point_mask, utf32_output);
      pos += consumed;
      utf8_end_of_code_point_mask >>= consumed;
      }
    }
  }
  utf32_output += scalar::utf8_to_utf32::convert_valid(input + pos, size - pos, utf32_output);
  return utf32_output - start;
}


} // namespace utf8_to_utf32
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/valid_utf8_to_utf32.h */
/* begin file src/generic/utf8_to_utf32/utf8_to_utf32.h */


namespace simdutf {
namespace westmere {
namespace {
namespace utf8_to_utf32 {
using namespace simd;


  simdutf_really_inline simd8<uint8_t> check_special_cases(const simd8<uint8_t> input, const simd8<uint8_t> prev1) {
    constexpr const uint8_t TOO_SHORT   = 1<<0; // 11______ 0_______
    constexpr const uint8_t TOO_LONG    = 1<<1; // 0_______ 10______
    constexpr const uint8_t OVERLONG_3  = 1<<2; // 11100000 100_____
    constexpr const uint8_t SURROGATE   = 1<<4; // 11101101 101_____
    constexpr const uint8_t OVERLONG_2  = 1<<5; // 1100000_ 10______
    constexpr const uint8_t TWO_CONTS   = 1<<7; // 10______ 10______
    constexpr const uint8_t TOO_LARGE   = 1<<3; // 11110100 1001____
    constexpr const uint8_t TOO_LARGE_1000 = 1<<6;
    constexpr const uint8_t OVERLONG_4  = 1<<6; // 11110000 1000____

    const simd8<uint8_t> byte_1_high = prev1.shr<4>().lookup_16<uint8_t>(
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TOO_LONG, TOO_LONG, TOO_LONG, TOO_LONG,
      TWO_CONTS, TWO_CONTS, TWO_CONTS, TWO_CONTS,
      TOO_SHORT | OVERLONG_2,
      TOO_SHORT,
      TOO_SHORT | OVERLONG_3 | SURROGATE,
      TOO_SHORT | TOO_LARGE | TOO_LARGE_1000 | OVERLONG_4
    );
    constexpr const uint8_t CARRY = TOO_SHORT | TOO_LONG | TWO_CONTS; // These all have ____ in byte 1 .
    const simd8<uint8_t> byte_1_low = (prev1 & 0x0F).lookup_16<uint8_t>(
      CARRY | OVERLONG_3 | OVERLONG_2 | OVERLONG_4,
      CARRY | OVERLONG_2,
      CARRY,
      CARRY,

      CARRY | TOO_LARGE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,

      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000 | SURROGATE,
      CARRY | TOO_LARGE | TOO_LARGE_1000,
      CARRY | TOO_LARGE | TOO_LARGE_1000
    );
    const simd8<uint8_t> byte_2_high = input.shr<4>().lookup_16<uint8_t>(
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,
      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT,

      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE_1000 | OVERLONG_4,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | OVERLONG_3 | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,
      TOO_LONG | OVERLONG_2 | TWO_CONTS | SURROGATE  | TOO_LARGE,

      TOO_SHORT, TOO_SHORT, TOO_SHORT, TOO_SHORT
    );
    return (byte_1_high & byte_1_low & byte_2_high);
  }
  simdutf_really_inline simd8<uint8_t> check_multibyte_lengths(const simd8<uint8_t> input,
      const simd8<uint8_t> prev_input, const simd8<uint8_t> sc) {
    simd8<uint8_t> prev2 = input.prev<2>(prev_input);
    simd8<uint8_t> prev3 = input.prev<3>(prev_input);
    simd8<uint8_t> must23 = simd8<uint8_t>(must_be_2_3_continuation(prev2, prev3));
    simd8<uint8_t> must23_80 = must23 & uint8_t(0x80);
    return must23_80 ^ sc;
  }


  struct validating_transcoder {
    simd8<uint8_t> error;

    validating_transcoder() : error(uint8_t(0)) {}
    simdutf_really_inline void check_utf8_bytes(const simd8<uint8_t> input, const simd8<uint8_t> prev_input) {
      simd8<uint8_t> prev1 = input.prev<1>(prev_input);
      simd8<uint8_t> sc = check_special_cases(input, prev1);
      this->error |= check_multibyte_lengths(input, prev_input, sc);
    }



    simdutf_really_inline size_t convert(const char* in, size_t size, char32_t* utf32_output) {
      size_t pos = 0;
      char32_t* start{utf32_output};
      const size_t safety_margin = 16; // to avoid overruns!
      while(pos + 64 + safety_margin <= size) {
        simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
        if(input.is_ascii()) {
          input.store_ascii_as_utf32(utf32_output);
          utf32_output += 64;
          pos += 64;
        } else {
          static_assert((simd8x64<uint8_t>::NUM_CHUNKS == 2) || (simd8x64<uint8_t>::NUM_CHUNKS == 4),
              "We support either two or four chunks per 64-byte block.");
          auto zero = simd8<uint8_t>{uint8_t(0)};
          if(simd8x64<uint8_t>::NUM_CHUNKS == 2) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
          } else if(simd8x64<uint8_t>::NUM_CHUNKS == 4) {
            this->check_utf8_bytes(input.chunks[0], zero);
            this->check_utf8_bytes(input.chunks[1], input.chunks[0]);
            this->check_utf8_bytes(input.chunks[2], input.chunks[1]);
            this->check_utf8_bytes(input.chunks[3], input.chunks[2]);
          }
          uint64_t utf8_continuation_mask = input.lt(-65 + 1);
          uint64_t utf8_leading_mask = ~utf8_continuation_mask;
          uint64_t utf8_end_of_code_point_mask = utf8_leading_mask>>1;
          size_t max_starting_point = (pos + 64) - 12;
          while(pos < max_starting_point) {
            size_t consumed = convert_masked_utf8_to_utf32(in + pos,
                            utf8_end_of_code_point_mask, utf32_output);
            pos += consumed;
            utf8_end_of_code_point_mask >>= consumed;
          }
        }
      }
      if(errors()) { return 0; }
      if(pos < size) {
        size_t howmany  = scalar::utf8_to_utf32::convert(in + pos, size - pos, utf32_output);
        if(howmany == 0) { return 0; }
        utf32_output += howmany;
      }
      return utf32_output - start;
    }

    simdutf_really_inline bool errors() const {
      return this->error.any_bits_set_anywhere();
    }

  }; // struct utf8_checker
} // utf8_to_utf32 namespace
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8_to_utf32/utf8_to_utf32.h */
/* begin file src/generic/utf8.h */

namespace simdutf {
namespace westmere {
namespace {
namespace utf8 {

using namespace simd;

simdutf_really_inline size_t count_code_points(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::count_code_points(in + pos, size - pos);
}


simdutf_really_inline size_t utf16_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
      int64_t utf8_4byte = input.gteq_unsigned(240);
      count += count_ones(utf8_4byte);
    }
    return count + scalar::utf8::utf16_length_from_utf8(in + pos, size - pos);
}


simdutf_really_inline size_t utf32_length_from_utf8(const char* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 64 <= size; pos += 64) {
      simd8x64<int8_t> input(reinterpret_cast<const int8_t *>(in + pos));
      uint64_t utf8_continuation_mask = input.lt(-65 + 1);
      count += 64 - count_ones(utf8_continuation_mask);
    }
    return count + scalar::utf8::utf32_length_from_utf8(in + pos, size - pos);
}
} // utf8 namespace
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf8.h */
/* begin file src/generic/utf16.h */
#include <iostream>
namespace simdutf {
namespace westmere {
namespace {
namespace utf16 {

template <endianness big_endian>
simdutf_really_inline size_t count_code_points(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::count_code_points<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf8_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t ascii_mask = input.lteq(0x7F);
      uint64_t twobyte_mask = input.lteq(0x7FF);
      uint64_t not_pair_mask = input.not_in_range(0xD800, 0xDFFF);

      size_t ascii_count = count_ones(ascii_mask) / 2;
      size_t twobyte_count = count_ones(twobyte_mask & ~ ascii_mask) / 2;
      size_t threebyte_count = count_ones(not_pair_mask & ~ twobyte_mask) / 2;
      size_t fourbyte_count = 32 - count_ones(not_pair_mask) / 2;
      count += 2 * fourbyte_count + 3 * threebyte_count + 2 * twobyte_count + ascii_count;
    }
    return count + scalar::utf16::utf8_length_from_utf16<big_endian>(in + pos, size - pos);
}

template <endianness big_endian>
simdutf_really_inline size_t utf32_length_from_utf16(const char16_t* in, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    for(;pos + 32 <= size; pos += 32) {
      simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
      if (big_endian) input.swap_bytes();
      uint64_t not_pair = input.not_in_range(0xDC00, 0xDFFF);
      count += count_ones(not_pair) / 2;
    }
    return count + scalar::utf16::utf32_length_from_utf16<big_endian>(in + pos, size - pos);
}

simdutf_really_inline void change_endianness_utf16(const char16_t* in, size_t size, char16_t* output) {
  size_t pos = 0;

  while (pos + 32 <= size) {
    simd16x32<uint16_t> input(reinterpret_cast<const uint16_t *>(in + pos));
    input.swap_bytes();
    input.store(reinterpret_cast<uint16_t *>(output));
    pos += 32;
    output += 32;
  }

  scalar::utf16::change_endianness_utf16(in + pos, size - pos, output);
}

} // utf16
} // unnamed namespace
} // namespace westmere
} // namespace simdutf
/* end file src/generic/utf16.h */

namespace simdutf {
namespace westmere {

simdutf_warn_unused bool implementation::validate_utf8(const char *buf, size_t len) const noexcept {
  return westmere::utf8_validation::generic_validate_utf8(buf, len);
}

simdutf_warn_unused bool implementation::validate_ascii(const char *buf, size_t len) const noexcept {
  return westmere::utf8_validation::generic_validate_ascii(buf, len);
}

simdutf_warn_unused bool implementation::validate_utf16le(const char16_t *buf, size_t len) const noexcept {
  const char16_t* tail = sse_validate_utf16<endianness::LITTLE>(buf, len);
  if (tail) {
    return scalar::utf16::validate<endianness::LITTLE>(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused bool implementation::validate_utf16be(const char16_t *buf, size_t len) const noexcept {
  const char16_t* tail = sse_validate_utf16<endianness::BIG>(buf, len);
  if (tail) {
    return scalar::utf16::validate<endianness::BIG>(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused bool implementation::validate_utf32(const char32_t *buf, size_t len) const noexcept {
  const char32_t* tail = sse_validate_utf32le(buf, len);
  if (tail) {
    return scalar::utf32::validate(tail, len - (tail - buf));
  } else {
    return false;
  }
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16le(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
  utf8_to_utf16::validating_transcoder converter;
  return converter.convert<endianness::LITTLE>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf16be(const char* buf, size_t len, char16_t* utf16_output) const noexcept {
  utf8_to_utf16::validating_transcoder converter;
  return converter.convert<endianness::BIG>(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16le(const char* input, size_t size,
    char16_t* utf16_output) const noexcept {
  return utf8_to_utf16::convert_valid<endianness::LITTLE>(input, size,  utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf16be(const char* input, size_t size,
    char16_t* utf16_output) const noexcept {
  return utf8_to_utf16::convert_valid<endianness::BIG>(input, size,  utf16_output);
}

simdutf_warn_unused size_t implementation::convert_utf8_to_utf32(const char* buf, size_t len, char32_t* utf32_output) const noexcept {
  utf8_to_utf32::validating_transcoder converter;
  return converter.convert(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf8_to_utf32(const char* input, size_t size,
    char32_t* utf32_output) const noexcept {
  return utf8_to_utf32::convert_valid(input, size,  utf32_output);
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char16_t*, char*> ret = sse_convert_utf16_to_utf8<endianness::LITTLE>(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf8::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char16_t*, char*> ret = sse_convert_utf16_to_utf8<endianness::BIG>(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf8::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf16le_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf8(const char16_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf16be_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  std::pair<const char32_t*, char*> ret = sse_convert_utf32_to_utf8(buf, len, utf8_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf8_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf8::convert(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  std::pair<const char16_t*, char32_t*> ret = sse_convert_utf16_to_utf32<endianness::LITTLE>(buf, len, utf32_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf32_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf32::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  std::pair<const char16_t*, char32_t*> ret = sse_convert_utf16_to_utf32<endianness::BIG>(buf, len, utf32_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf32_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf16_to_utf32::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf8(const char32_t* buf, size_t len, char* utf8_output) const noexcept {
  return convert_utf32_to_utf8(buf, len, utf8_output);
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  std::pair<const char32_t*, char16_t*> ret = sse_convert_utf32_to_utf16<endianness::LITTLE>(buf, len, utf16_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf16_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf16::convert<endianness::LITTLE>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  std::pair<const char32_t*, char16_t*> ret = sse_convert_utf32_to_utf16<endianness::BIG>(buf, len, utf16_output);
  if (ret.first == nullptr) { return 0; }
  size_t saved_bytes = ret.second - utf16_output;
  if (ret.first != buf + len) {
    const size_t scalar_saved_bytes = scalar::utf32_to_utf16::convert<endianness::BIG>(
                                        ret.first, len - (ret.first - buf), ret.second);
    if (scalar_saved_bytes == 0) { return 0; }
    saved_bytes += scalar_saved_bytes;
  }
  return saved_bytes;
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16le(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return convert_utf32_to_utf16le(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf32_to_utf16be(const char32_t* buf, size_t len, char16_t* utf16_output) const noexcept {
  return convert_utf32_to_utf16be(buf, len, utf16_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16le_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return convert_utf16le_to_utf32(buf, len, utf32_output);
}

simdutf_warn_unused size_t implementation::convert_valid_utf16be_to_utf32(const char16_t* buf, size_t len, char32_t* utf32_output) const noexcept {
  return convert_utf16be_to_utf32(buf, len, utf32_output);
}

void implementation::change_endianness_utf16(const char16_t * input, size_t length, char16_t * output) const noexcept {
  utf16::change_endianness_utf16(input, length, output);
}

simdutf_warn_unused size_t implementation::count_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::count_code_points<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::count_code_points<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::count_utf8(const char * input, size_t length) const noexcept {
  return utf8::count_code_points(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::utf8_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::utf8_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16le(const char16_t * input, size_t length) const noexcept {
  return utf16::utf32_length_from_utf16<endianness::LITTLE>(input, length);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf16be(const char16_t * input, size_t length) const noexcept {
  return utf16::utf32_length_from_utf16<endianness::BIG>(input, length);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf8(const char * input, size_t length) const noexcept {
  return utf8::utf16_length_from_utf8(input, length);
}

simdutf_warn_unused size_t implementation::utf8_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  const __m128i v_00000000 = _mm_setzero_si128();
  const __m128i v_ffffff80 = _mm_set1_epi32((uint32_t)0xffffff80);
  const __m128i v_fffff800 = _mm_set1_epi32((uint32_t)0xfffff800);
  const __m128i v_ffff0000 = _mm_set1_epi32((uint32_t)0xffff0000);
  size_t pos = 0;
  size_t count = 0;
  for(;pos + 4 <= length; pos += 4) {
    __m128i in = _mm_loadu_si128((__m128i*)(input + pos));
    const __m128i ascii_bytes_bytemask = _mm_cmpeq_epi32(_mm_and_si128(in, v_ffffff80), v_00000000);
    const __m128i one_two_bytes_bytemask = _mm_cmpeq_epi32(_mm_and_si128(in, v_fffff800), v_00000000);
    const __m128i two_bytes_bytemask = _mm_xor_si128(one_two_bytes_bytemask, ascii_bytes_bytemask);
    const __m128i one_two_three_bytes_bytemask = _mm_cmpeq_epi32(_mm_and_si128(in, v_ffff0000), v_00000000);
    const __m128i three_bytes_bytemask = _mm_xor_si128(one_two_three_bytes_bytemask, one_two_bytes_bytemask);
    const uint16_t ascii_bytes_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(ascii_bytes_bytemask));
    const uint16_t two_bytes_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(two_bytes_bytemask));
    const uint16_t three_bytes_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(three_bytes_bytemask));

    size_t ascii_count = count_ones(ascii_bytes_bitmask) / 4;
    size_t two_bytes_count = count_ones(two_bytes_bitmask) / 4;
    size_t three_bytes_count = count_ones(three_bytes_bitmask) / 4;
    count += 16 - 3*ascii_count - 2*two_bytes_count - three_bytes_count;
  }
  return count + scalar::utf32::utf8_length_from_utf32(input + pos, length - pos);
}

simdutf_warn_unused size_t implementation::utf16_length_from_utf32(const char32_t * input, size_t length) const noexcept {
  const __m128i v_00000000 = _mm_setzero_si128();
  const __m128i v_ffff0000 = _mm_set1_epi32((uint32_t)0xffff0000);
  size_t pos = 0;
  size_t count = 0;
  for(;pos + 4 <= length; pos += 4) {
    __m128i in = _mm_loadu_si128((__m128i*)(input + pos));
    const __m128i surrogate_bytemask = _mm_cmpeq_epi32(_mm_and_si128(in, v_ffff0000), v_00000000);
    const uint16_t surrogate_bitmask = static_cast<uint16_t>(_mm_movemask_epi8(surrogate_bytemask));
    size_t surrogate_count = (16-count_ones(surrogate_bitmask))/4;
    count += 4 + surrogate_count;
  }
  return count + scalar::utf32::utf16_length_from_utf32(input + pos, length - pos);
}

simdutf_warn_unused size_t implementation::utf32_length_from_utf8(const char * input, size_t length) const noexcept {
  return utf8::utf32_length_from_utf8(input, length);
}

} // namespace westmere
} // namespace simdutf

/* begin file src/simdutf/westmere/end.h */
SIMDUTF_UNTARGET_REGION
/* end file src/simdutf/westmere/end.h */
/* end file src/westmere/implementation.cpp */
#endif

SIMDUTF_POP_DISABLE_WARNINGS
/* end file src/simdutf.cpp */
