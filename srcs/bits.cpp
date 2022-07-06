#include "bits.h"
#include <iostream>

int main()
{
    std::cout << "little-endian: " << static_cast<int>(cppll::endian::little) << std::endl;
    std::cout << "big-endian: " << static_cast<int>(cppll::endian::big) << std::endl;
    std::cout << "native-endian: " << static_cast<int>(cppll::endian::native) << std::endl;
    const auto f64v = 20220706.0;
    std::cout
        << std::fixed << f64v << "f64.to_bits() == 0x"
        << std::hex << cppll::bit_cast<std::uint64_t>(f64v) << "u64\n";
    return 0;
}
