#include <iostream>
#include <fstream>

#include "quicksort.h"
using std::cout;
using std::uint64_t;
using std::ofstream;
uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

const int TEST_RANGE_START = 0;
const int TEST_RANGE_END = 10000;
int main()
{
    /*
    ofstream outputfile;
    outputfile.open("data.csv");
    for(int i = TEST_RANGE_START; i < TEST_RANGE_END; ++i) {
        // 4 * 1-100
        int myarr[i];

        for (int j = 0; j < i; ++j)
            myarr[j] = (rand() % 100); // 0-90000

        uint64_t start = rdtsc();
        quicksort<int>().sort(myarr, i);
        uint64_t delta = rdtsc() - start;

        outputfile << i << "," << delta << "\n";
    }
    outputfile.close();
    */

    std::string startString = "google";

    int strlength = startString.length();
    char myarray[strlength];
    startString.copy(myarray,strlength);
    myarray[strlength] = '\0';

    int arrlength = sizeof(myarray)/sizeof(myarray[0]);

    quicksort<char>().sort(myarray, arrlength);

    std::string mystring(myarray);
    std::cout << startString << "\n" << mystring;
    return 0;
}

