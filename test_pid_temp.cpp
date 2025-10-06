#include <iostream>
#include "include/PID.hpp"

int main() {
    control::PID<float> pid(1.0, 0.1, 0.05, 100.0, -100.0);
    float output = pid.compute(10.0, 2.0, 0.1);
    std::cout << "PID Output: " << output << std::endl;
    return 0;
}