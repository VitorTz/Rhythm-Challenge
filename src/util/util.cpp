#include "../../include/util/util.hpp"



unsigned int randomInt(int start, int end) {
    std::random_device os_seed;
    const uint_least32_t seed = os_seed();

    std::mt19937 generator( seed );
    std::uniform_int_distribution<uint_least32_t> distribute( start, end);

    return distribute(generator);
}