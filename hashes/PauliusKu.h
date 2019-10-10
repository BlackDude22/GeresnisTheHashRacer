//
// Created by Paulius on 2019-09-14.
//

#ifndef HASH_GENERATOR_HASHFUNCTION_H
#define HASH_GENERATOR_HASHFUNCTION_H

#include <string>
#include <vector>
#include <iostream>
#include "PauliusKu.h"

namespace PauliusKu{

std::string hexToString(unsigned int n);
std::string hashFunc(std::string& pBlock1, std::string& pBlock2);
std::vector<std::string> makeBlocks(const std::string& pInp1);
std::string hashAlgo(const std::string& pInp1);
	
std::string hashAlgo(const std::string& pInp1){
    std::vector<std::string> blocks = makeBlocks(pInp1);
    std::string seed = "FCB469D2";

    for(auto& value: blocks){
        seed = hashFunc(value, seed);
    }
    return seed;
}

std::vector<std::string> makeBlocks(const std::string& pInp1){
    std::vector<std::string> blocks;
    for(unsigned long i = 0; i < pInp1.size(); i++)
        blocks.push_back(pInp1.substr(i, 8));
    return blocks;
}

std::string hashFunc(std::string pBlock){
    unsigned int hash = 0xAAAAAAAA;
    unsigned long i = 0;

    for (i = 0; i < pBlock.size(); ++pBlock[i], ++i){
        if ((i & 1u) == 0)
            hash ^= hash << 7u ^ (pBlock[i]) * (hash >> 3u);
        else hash ^= ~((hash << 11u) + ((pBlock[i] + 0u) ^ (hash >> 5u)));
    }

    return hexToString(hash);
}

std::string hashFunc32(std::string& pBlock1, std::string& pBlock2){
    return hashFunc(pBlock1 + pBlock2);
}

std::string hashFunc96(std::string& pBlock1, std::string& pBlock2){
    std::string pBlockSum = hashFunc(pBlock1 + pBlock2);
    pBlock1 = hashFunc(pBlock1);
    pBlock2 = hashFunc(pBlock2);
    pBlock1 = hashFunc(pBlock1 + pBlock2);
    pBlock2 = hashFunc(pBlock1 + pBlockSum);

    return pBlockSum + pBlock1 + pBlock2;
}

std::string hashFunc(std::string& pBlock1, std::string& pBlock2){
    return hashFunc96(pBlock1, pBlock2);
}

std::string hexToString(unsigned int hex){
    std::string str {"00000000"};
    int itr = 0;

    do{
        str[itr] = "0123456789ABCDEF"[hex % 16];
        hex >>= 4u;
        itr++;
    } while(hex);

    return str;
}
}
#endif //HASH_GENERATOR_HASHFUNCTION_H