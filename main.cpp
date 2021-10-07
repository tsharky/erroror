#include <iostream>
#include <cstdint>

constexpr int32_t OKAY = 0;
constexpr int32_t ERROR = -1;

template <typename T>
struct [[nodiscard]] ErrorOr {
    int32_t r = ERROR;
    T val;
    constexpr bool isOk() noexcept { return r >= 0; }
    constexpr bool isErr() noexcept { return !isOk(); }
};

ErrorOr<double> divide (double x, double y) {
    if (y == 0) {
        return {};
    }
    return {OKAY, x / y};
}

int main() {
    auto res = divide(1.3, 0.0);
    if (res.isOk()) {
        std::cout << res.val << std::endl;
    } else {
        std::cout << "Division not possible. Error code = " << res.r << std::endl;
    }
    return 0;
}
