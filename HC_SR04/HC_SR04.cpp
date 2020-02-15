#include <HC_SR04.hpp>
#include <unistd.h>
#include <chrono>
#include <gpio.hpp>

HC_SR04::HC_SR04(int trigger, int echo) {
    gpio::init();
    _trigger = trigger;
    _echo = echo;
    gpio::setup(trigger, gpio::OUTPUT);
    gpio::setup(echo, gpio::OUTPUT);
    gpio::setup(echo, gpio::INPUT);
}

double HC_SR04::distance() {
    if (!gpio::hardware_support()) {
        return -1.0;
    }

    gpio::write(_trigger, gpio::HIGH);
    usleep(10);
    gpio::write(_trigger, gpio::LOW);

    std::chrono::system_clock::time_point begin, end;

    while (gpio::read(_echo) == gpio::LOW) {
        begin = std::chrono::system_clock::now();
    }

    while (gpio::read(_echo) == gpio::HIGH) {
        end = std::chrono::system_clock::now();
    }

    const double time_of_flight = double(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.;
    return time_of_flight * 17250.0;
}
