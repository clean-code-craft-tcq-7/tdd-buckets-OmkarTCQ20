#include "TestCases.hpp"
#include "test/catch.hpp"
#include <iostream>
#include "CurrentSamplingModule.hpp"
using namespace std;

// As a first step, only considering to detect continuous ranges in the samples
TEST_CASE("PASSING TEST CASE 1") {
    unsigned int Current_Samples[] = { 4, 5 };
    int Current_Samples_size = sizeof(Current_Samples) / sizeof(Current_Samples[0]);
    REQUIRE(SampleRangeReadings(Current_Samples, Current_Samples_size, 2) == true);
}
