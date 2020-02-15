#include <iostream>
#include <common.hpp>
#include <test.hpp>

void test_str() {
    ASSERT(strsplit("hello world", " ")[1] == "world");
    ASSERT(strstartswith("hello world", "hello"));
    ASSERT(strendswith("hello world", "world"));
    ASSERT(striequals("Hello", "hello"));
    ASSERT(strcontains("hello world", "world"));
    ASSERT_EQUAL(strto<bool>("True"), true);
    ASSERT_EQUAL_FLOAT(strto<double>("1.0"), 1.0);
    ASSERT(strtrim("   hello   ") == "hello");
    ASSERT(strupper("hello") == "HELLO");
    ASSERT(strlower("HELLO") == "hello");
}

void test_sequence() {
    std::vector<int> v({1, 2, 3, 4, 5, 6, 7, 8});

    ASSERT_EQUAL(argmin(v.begin(), v.end()), 0);
    ASSERT_EQUAL(argmax(v.begin(), v.end()), 7);
    ASSERT_EQUAL(sum(v.begin(), v.end()), 36);
    ASSERT_EQUAL(product(v.begin(), v.end()), (1 * 2 * 3 * 4 * 5 * 6 * 7 * 8));
    ASSERT_EQUAL(::min(v.begin(), v.end()), 1);
    ASSERT_EQUAL(::max(v.begin(), v.end()), 8);
}

void test_misc() {
    ASSERT_EQUAL(bswap<int>(0x01020304), 0x04030201);
    ASSERT_EQUAL(bswap<float>(1.0), 1.0);
}

int main() {

    test_str();
    test_sequence();

    std::cout << "test finished successfully" << std::endl;

    return EXIT_SUCCESS;
}