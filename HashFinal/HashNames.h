/*
Aaron Wilson
ID: 0373166
Due: 12/17/2021
Final Project
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;
using std::istream;
using std::ostream;
using std::string;

#ifndef HASHNAMES
#define HASHNAMES

class HashNames
{

	private:
		vector<string> namesVect[53];
		int djbHash(string data, int tablesize);

	public:
		//Member Functions
		void hash(string file);
		void printVect();

		//Constructors
		HashNames();
		HashNames(string fileToHash);
};

#endif
