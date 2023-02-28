#pragma once
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cstdlib>
#include <vector>
using namespace std;

unsigned int ConsecutiveRanges(unsigned int Current_Samples[], int Current_Samples_size);
void DetectRangeReadings(unsigned int Current_Samples[], int Current_Samples_size);
//std::unordered_map<int, unsigned int> Start_Counter(unsigned int vals[]);
//void GetSequenceCount(const std::unordered_map<int, unsigned int>& counts);
vector<string> CheckconsecutiveRanges(int f_SampleReadingIndex[], int f_SampleReadingCount[], int f_SampledReadings_arr_size);

string GetConsecutiveRange(unsigned int f_Current_Samples[], int f_Current_Samples_size);
