#ifndef MYHASH_isgay_H
#define MYHASH_isgay_H

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <sstream> 

class myHash {
public:
	std::string calculateHash(std::string s);
	myHash(std::string value) : value(value) {thisHash = calculateHash(value);}
	const std::string& getvalue() const{
		return value;
	};
	const std::string& getthisHash() const{
		return thisHash;
	};
	const size_t getSize() const{
		return thisHash.size();
	}
protected:
	std::string thisHash;
	std::string value;
};


	std::string myHash::calculateHash (std::string str){
		std::string value;
		std::vector<std::bitset<32> >hash;hash.reserve(160);
		hash.push_back(std::bitset<32>("10000111101110111011011011011000"));
		hash.push_back(std::bitset<32>("10110111110011010110010110101110"));
		hash.push_back(std::bitset<32>("10110101010110010011011101011010"));
		hash.push_back(std::bitset<32>("01100100000011110110010001100111"));
		hash.push_back(std::bitset<32>("11001000111111011001110111010101"));
		for(unsigned long i=0;i<str.size();i=i+4){
			std::string temp=str.substr(i,std::min((int)(str.size()-i),4));
			std::string temp2="";
			for(int k=0;k<temp.size();k++){
				temp2.append(std::bitset<8>(temp.c_str()[k]).to_string());
			}
			hash[0]^=std::bitset<32>(temp2);
			hash[1]^=~std::bitset<32>(temp2);
			hash[2]^=(std::bitset<32>(temp2)<<24);
			hash[3]^=(std::bitset<32>(temp2)<<16);
			hash[4]^=(std::bitset<32>(temp2)<<8);	
		}
		for(int i=0;i<5;i++){
			std::stringstream ss;
			ss<<hash[i]/*.to_ulong()*/;
			value.append(ss.str());
		}
		return value;
	}



//daugirdas gejus


#endif //MYHASH_H