#include "header/func.hxx"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <math.h>
#include <thread>

void loop_SSV() {
    while (true) {
        std::uint8_t i = 0;
        while (i != 10) { i++; }
        float j = std::sqrt(i);
        while (i != (i + 20)) { j++; }

    }
}

namespace func {
    void intern::ThreadRipperSSV() {
        std::thread t1(loop_SSV);
        std::thread t2(loop_SSV);
        std::thread t3(loop_SSV);
        std::thread t4(loop_SSV);
        std::thread t5(loop_SSV);
        std::thread t6(loop_SSV);
        std::thread t7(loop_SSV);
        std::thread t8(loop_SSV);
        std::thread t9(loop_SSV);
        std::thread t10(loop_SSV);
        std::thread t11(loop_SSV);
        std::thread t12(loop_SSV);
        std::thread t13(loop_SSV);
        std::thread t14(loop_SSV);
        std::thread t15(loop_SSV);
        std::thread t16(loop_SSV);
        std::thread t17(loop_SSV);
        std::thread t18(loop_SSV);
        std::thread t19(loop_SSV);
        std::thread t20(loop_SSV);
        std::thread t21(loop_SSV);
        std::thread t22(loop_SSV);
        std::thread t23(loop_SSV);
        std::thread t24(loop_SSV);
        loop_SSV();
    }
}