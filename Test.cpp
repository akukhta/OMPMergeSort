#ifdef _DEBUG
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <omp.h>
#include <vector>
#include <algorithm>
#include "merge.h"
#include <chrono>

auto _start = std::chrono::high_resolution_clock::now();
auto _stop = std::chrono::high_resolution_clock::now();

void start()
{
    _start = std::chrono::high_resolution_clock::now();
}

void stop()
{
    static size_t testNumber = 1;
    _stop = std::chrono::high_resolution_clock::now();
    auto secs = std::chrono::duration_cast<std::chrono::milliseconds>(_stop - _start).count();
    std::cout << "Test[" << testNumber++ << "]:" << secs << " milliseconds" << std::endl;
}

auto generate(size_t n)
{
    std::vector<int> res;

    for (size_t i = 0; i < n; i++)
    {
        res.push_back(rand());
    }
    return res;
}

BOOST_AUTO_TEST_CASE(test1000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec));
    stop();
    std::sort(tvec.begin(), tvec.end());
  BOOST_TEST(vec == tvec);
}

BOOST_AUTO_TEST_CASE(test10000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec));
    stop();
    std::sort(tvec.begin(), tvec.end());
  BOOST_TEST(vec == tvec);
}

BOOST_AUTO_TEST_CASE(test100000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec));
    stop();
    std::sort(tvec.begin(), tvec.end());
  BOOST_TEST(vec == tvec);
}

BOOST_AUTO_TEST_CASE(test1000000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec));
    stop();
    std::sort(tvec.begin(), tvec.end());
  BOOST_TEST(vec == tvec);
}
BOOST_AUTO_TEST_CASE(gtest1000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec), std::greater<decltype(vec[0])>());
    stop();
    std::sort(tvec.begin(), tvec.end(), std::greater<decltype(vec[0])>());
  BOOST_TEST(vec == tvec);
}

BOOST_AUTO_TEST_CASE(gtest10000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec), std::greater<decltype(vec[0])>());
    stop();
    std::sort(tvec.begin(), tvec.end(), std::greater<decltype(vec[0])>());
  BOOST_TEST(vec == tvec);
}

BOOST_AUTO_TEST_CASE(gtest100000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort(std::move(vec), std::greater<decltype(vec[0])>());
    stop();
    std::sort(tvec.begin(), tvec.end(), std::greater<decltype(vec[0])>());
  BOOST_TEST(vec == tvec);
}

BOOST_AUTO_TEST_CASE(gtest1000000)
{
    auto vec = generate(10000000);
    auto tvec = vec;
    start();
    vec = sort<int>(std::move(vec), std::greater<decltype(vec[0])>());
    stop();
    std::sort(tvec.begin(), tvec.end(), std::greater<decltype(vec[0])>());
  BOOST_TEST(vec == tvec);
}

#endif
