#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <bitset>
#include <vector>
#include "timer.hpp"
#include "hashes/picosha2.h"
#include "hashes/tylek8137.hpp"
#include "hashes/RytisMasterClassOnHashingAlgorithms.h"
#include "hashes/agnuss7.h"
#include "hashes/SimonasValkiunas.h"
#include "hashes/PauliusKu.h"
#include "hashes/RaimundV.h"
std::string getHash(std::string input, std::string algorithm){
	std::string result;
	if (algorithm == "BlackDude22"){
		TYLEK8137 h;
		result = h.getHash(input);
	} else if (algorithm == "SHA256"){
		result = picosha2::hash256_hex_string(input);
	} else if (algorithm == "Rytisgit"){
		result = hash(input);
	} else if (algorithm == "agnuss7"){
		result = agnuss7::hash(input);
	} else if (algorithm == "SimonasValkiunas"){
		result = SimonasValkiunas::hashFunction(input, 64);
	} else if (algorithm == "PauliusKu"){
		result = PauliusKu::hashFunc(input);
	} else if (algorithm == "PauliusKu"){
		result = PauliusKu::hashFunc(input);
	} else if (algorithm == "RaimundV"){
		result = RaimundV::stringToAscii(input);
	} 
	return result;
}

void test1(int testCount, std::string algorithm, std::string fileName="konstitucija.txt"){
	std::ifstream ifs;
	ifs.open(fileName);
	std::string line;
	double totalTime = 0;
	std::vector<std::string> fileContents;
	while(std::getline(ifs, line))
		fileContents.push_back(line);
	for (int i = 0; i < testCount; i++){
		for (std::string l : fileContents){
			Timer start;
			std::string hashedLine = getHash(line, algorithm);
			totalTime += start.elapsed();
			start.reset();
		}
	}
	std::cout << "Number of tests performed on file " << fileName << ": " << testCount << std::endl;
	std::cout << "Total hashing time (s): " << totalTime << std::endl;
	std::cout << "Average hashing time (s): " << totalTime/testCount << std::endl;
}

void test2(int testCount, int stringLength, std::string algorithm, bool displayInterval = false){
	std::set<std::string> hashes;
	double totalTime = 0;
	double intervalTime = 0;
	int printInterval = 1e5;
	int duplicate = 0;
	for (int i = 1; i <= testCount; i++){
		std::string currentString = std::to_string(i);
		currentString.resize(stringLength, 'a');
		Timer start;
		std::string res = getHash(currentString, algorithm);
		double currentTime = start.elapsed();
		totalTime += currentTime;
		intervalTime += currentTime;
		start.reset();
		auto p = hashes.insert(res);
		if (!p.second)
			duplicate++;
		if (i%printInterval==0 && displayInterval){
			std::cout << "Hashes: " << i << ", Collisions: " << duplicate << ", Total hashing time: " << totalTime << "s, Hashes per second: " << printInterval/intervalTime << ", Average hashes per second: " << i/totalTime << std::endl;
			intervalTime = 0;
		}
	}
	std::cout << "Number of hashes tested: " << testCount << std::endl;
	std::cout << "Collisions: " << duplicate << std::endl;
	std::cout << "Total hashing time (s): " << totalTime << std::endl;
	std::cout << "Average hashing speed (hash/s): " << testCount/totalTime << std::endl;
}

double compareHashes(std::string hash1, std::string hash2){
	double matches = 0;
	for(int i = 0; i < hash1.length(); i++){
		if (hash1.at(i) == hash2.at(i))
			matches++;
	}
	return matches/hash1.length();
}

void test3(int testCount, std::string algorithm){
	double min = 1, max = 0;
	double total = 0;
	for (int i = 1; i <= testCount; i++){
		std::string hash1 = getHash(std::to_string(i)+"a", algorithm);
		std::string hash2 = getHash(std::to_string(i)+"A", algorithm);
		double cmp = compareHashes(hash1, hash2);
		if (cmp < min)
			min = cmp;
		if (cmp > max)
			max = cmp;
		total += cmp;
	}
	std::cout << "Number of tests performed: " << testCount << std::endl;
	std::cout << "Similarity ratings: " << std::endl;
	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Avg: " << total/testCount << std::endl;
}

void runTests(std::string algorithm){
	std::cout << "--- Testing on " << algorithm << " ---"<< std::endl;
	std::cout << std::endl;
	std::cout << "Starting konstitucija test..." << std::endl;
	test1(1e2, algorithm);
	std::cout << std::endl;
	std::cout << "Starting speed and collision test with short strings..." << std::endl;
	test2(1e6, 8, algorithm, true);
	std::cout << std::endl;
	std::cout << "Starting speed and collision test with long strings..." << std::endl;
	test2(5e5, 1000, algorithm, true);
	std::cout << std::endl;
	std::cout << "Starting character similarity test..." << std::endl;
	test3(1e5, algorithm);
	std::cout << std::endl;
}

void runAllTests(){
	runTests("BlackDude22");
	runTests("Rytisgit");
	runTests("agnuss7");
	runTests("SimonasValkiunas");
	runTests("PauliusKu");
	runTests("RaimundV");
}

int main(int argc, char *argv[]){
	if (std::string(argv[1]) == "all")
		runAllTests();
	else runTests(argv[1]);
}