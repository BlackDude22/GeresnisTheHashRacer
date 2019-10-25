#ifndef JONASSIUKSTERIS_H
#define JONASSIUKSTERIS_H


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

namespace JonasSiuksteris{
string Hash(string input)
{
    ostringstream stream;
    int temp[64]{};
    string hash{};
    char b, c;

    while(input.length() < 64)
    {
        if(input.length() == 0)
        {
            cout << "1234567890abcdeffedc";
            return 0;
        }

        if(input.length() == 1)
        {
            b = input[input.length() - 1];
            c = input[input.length() - 1];
        }
        else
        {
            b = input[input.length() - 1];
            c = input[input.length() - 2];
        }
        input.push_back(char(((b+c) + b * 2 + c * 2)%73));
    }


    for(int i = 0; i < input.length(); i++)
    {
        temp[i % 64] += input[i];
        temp[(i + 1) % 64] += input[i] << 1;
    }

    for(int i = 0; i < 64; i++)
    {
        temp[i] += (temp[i] + (temp[i] << 1) ) % 54;
        temp[i] %= 73;
    }
    for(int k = 0; k < 2; k++)
        for(int i = 0; i < 64; i++){
            for(int j = 0; j < 64; j++)
            {
                if(i != j)
                {
                    temp[i] += temp[j] + (temp[j] << 1);
                }
            }
            temp[i] <<= 1;
            temp[i] %= 73;
        }

    for(int i = 0; i < 64; i++)
    {
        temp[i] %= 16;
    }

    for(int i = 0; i < 64; i++){
        stream << hex << temp[i];
    }
    hash = stream.str();

    return hash;
}
}
#endif