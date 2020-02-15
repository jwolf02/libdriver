#include <iostream>
#include <HC_SR04.hpp>
#include <csignal>
#include <common.hpp>

volatile bool flag = false;

void signal_handler(int signum) {
    if (signum == SIGINT) {
        flag = true;
    }
}

int main(int argc, const char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <trigger pin> <echo pin>" << std::endl;
        return EXIT_SUCCESS;
    }

    signal(SIGINT, signal_handler);

    HC_SR04 sensor(strto<int>(argv[1]), strto<int>(argv[2]));

    std::cout << "Press CTRL+C to quit" << std::endl;

    while (flag) {
        std::cout << '\r' << sensor.distance() << "          " << std::flush;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}