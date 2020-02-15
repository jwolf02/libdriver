#include <iostream>
#include <Timer.hpp>
#include <chrono>
#include <thread>
#include <test.hpp>
#include <atomic>

void test_expiration() {
    std::chrono::system_clock::time_point begin, end;
    Timer t;
    ASSERT_NO_THROW(Timer([&](){ end = std::chrono::system_clock::now(); }, 2000));
    begin = std::chrono::system_clock::now();

    std::this_thread::sleep_for(std::chrono::microseconds (2000));

    ASSERT(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() < 100);
    ASSERT_NO_THROW(t.stop());
}

void test_interval() {
    int count = 0;
    Timer t;
    ASSERT_NO_THROW(t = Timer([&](){ count += 1; }, 1000, 1000));

    std::this_thread::sleep_for(std::chrono::milliseconds(3500));

    ASSERT_EQUAL(count, 3);
    ASSERT_NO_THROW(t.stop());
}

void test_single_shot() {
    int val = 0;
    ASSERT_NO_THROW(Timer::singleShot([&](){ val = 1; }, 1000000));

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    ASSERT(val == 1);
}

int main() {

    test_expiration();
    test_single_shot();
    test_interval();

    std::cout << "test finished successfully" << std::endl;

    return EXIT_SUCCESS;
}