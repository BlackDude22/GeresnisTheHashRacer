#ifndef C___PROGRAMS_HEADER_H
#define C___PROGRAMS_HEADER_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <chrono>

namespace Aspectrus{
std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
std::string myhash;
auto elapsed = (std::chrono::duration<double>(start-end).count());
unsigned char* hash = new unsigned char[32];
// using std::cout, std::endl, std::cin;
using namespace std;
double timer=0;


char decToHexa(int n)
{
    char hexaDeciNum;
    int temp = n % 16;
    if(temp < 10)
    {
        hexaDeciNum = temp + 48;
    }
    else
    {
        hexaDeciNum = temp + 55;
    }
    return hexaDeciNum;
}

int sum_the_decimal_digits_of_a_value(long double &rootvalue, int digitsum, int end) {
    double whole = floor(rootvalue);
    rootvalue = (rootvalue - whole);
    for(int i=0; i<end; i++)
    {
        rootvalue *= 10;
        digitsum += floor(rootvalue);
        rootvalue -= floor(rootvalue);
    }
    return digitsum;
}

int digitsum=0;
std::string inputhashing(std::string input)
{

    // starttimer();
    for(char& character : input)
    {
        int ascii = abs((int) character);
        long double rootvalue = std::pow(ascii, 1.0/319.0);
        int end=7;
        digitsum = sum_the_decimal_digits_of_a_value(rootvalue,digitsum, end);
        for(int i = 0; i < 32; i++)
        {
            
            digitsum%=16;
            hash[i]=decToHexa(digitsum +  int(hash[i]));
            end=1;
            if (i==7 )
            {
                rootvalue = std::pow(ascii, 1.0/947.0);
                end=3;
            }
            else if(i==15 )
            {
                rootvalue = std::pow(ascii, 1.0/727.0);
                end=3;
            }
            else if(i==23 )
            {
                rootvalue = std::pow(ascii, 1.0/683.0);
                end=3;
            }
        }
    }

    // endtimer();
    return reinterpret_cast<char*>(hash);
}

std::string filehashing(std::string file_name)
{
    std::ifstream in (file_name);
    std::string line;
    while(std::getline(in, line))
    {
        myhash = inputhashing(line);
    }
    in.close();
    return myhash;
}
}

#endif //C___PROGRAMS_HEADER_H