#include "CurrentSamplingModule.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <vector>

using namespace std;

int g_SampledReadings_arr[100];
const int g_SampledReadings_arr_size = sizeof(g_SampledReadings_arr) / sizeof(g_SampledReadings_arr[0]);
int SampleReadingIndex[g_SampledReadings_arr_size];

unsigned int ConsecutiveRanges(unsigned int Current_Samples[], int Current_Samples_size) {

    unsigned int Step_count = 1;
    int index;

    // check if the current element & previous element step is 1.
    for (index = 0; index < Current_Samples_size; index++) {

        if ((Current_Samples[index + 1] - Current_Samples[index]) == 1) {
            Step_count = Step_count + 1;
        }
    }
    return Step_count;
}


void DetectRangeReadings(unsigned int f_Current_Samples[], int f_Current_Samples_size) {

    memset(g_SampledReadings_arr, 0, sizeof(g_SampledReadings_arr));

    for (int index = 0; index < f_Current_Samples_size; index++)
    {
        g_SampledReadings_arr[f_Current_Samples[index]]++;
    }

    for (int i = 0; i < g_SampledReadings_arr_size; ++i)
    {
        if (g_SampledReadings_arr[i] != 0)
        {
            SampleReadingIndex[i] = i;
        }
    }
}

string GetConsecutiveRange(unsigned int f_Current_Samples[], int f_Current_Samples_size)
{
    string PassDetectedRanges;
    DetectRangeReadings(f_Current_Samples, f_Current_Samples_size);
    vector<string> GetDetectedRanges = CheckconsecutiveRanges(SampleReadingIndex, g_SampledReadings_arr, g_SampledReadings_arr_size);

    for (size_t i = 0; i < GetDetectedRanges.size(); ++i) {
        PassDetectedRanges += GetDetectedRanges[i];
        PassDetectedRanges += " ,";
    }

    PassDetectedRanges.pop_back();
    return PassDetectedRanges;

}


vector<string> CheckconsecutiveRanges(int f_SampleReadingIndex[], int f_SampledReadings[], int f_SampledReadings_arr_size)
{
    int Readings = 0;
    int LastValue = 1;
    vector<string> DetectedRange;

    if (f_SampledReadings_arr_size == 0)
    {
        return DetectedRange;
    }

    for (int i = 1; i <= f_SampledReadings_arr_size; i++)
    {

        if (i == f_SampledReadings_arr_size || f_SampleReadingIndex[i] - f_SampleReadingIndex[i - 1] != 1)
        {
            if (LastValue == 1)
            {
                //DetectedRange.push_back(to_string(a[i - length]));
            }
            else
            {
                for (int j = i - LastValue; j <= i - 1; j++)
                {
                    Readings = Readings + f_SampledReadings[j];
                }
                string temp = to_string(f_SampleReadingIndex[i - LastValue]) +
                    " -> " + to_string(f_SampleReadingIndex[i - 1]) + " , Reading:" + to_string(Readings);

                DetectedRange.push_back(temp);
            }

            LastValue = 1;
            Readings = 0;
        }
        else
        {
            LastValue++;
        }
    }

    return DetectedRange;
}
