#ifndef CPPLL_DEPS_BITS_H
#define CPPLL_DEPS_BITS_H

#include <cstring>
#include <type_traits>

namespace cppll
{

    enum class endian
    {
#ifdef _WIN32
        little = 0,
        big = 1,
        native = little
#else
        little = __ORDER_LITTLE_ENDIAN__,
        big = __ORDER_BIG_ENDIAN__,
        native = __BYTE_ORDER__
#endif
    };

    template <class To, class From>
    typename std::enable_if_t<
        sizeof(To) == sizeof(From) &&
            std::is_trivially_copyable_v<From> &&
            std::is_trivially_copyable_v<To>,
        To>
    bit_cast(const From &x) noexcept
    {
        static_assert(std::is_trivially_constructible_v<To>,
                      "This implementation additionally requires destination type to be trivially constructible");

        To result;
        std::memcpy(&result, &x, sizeof(To));
        return result;
    }

} // namespace cppll

#endif
