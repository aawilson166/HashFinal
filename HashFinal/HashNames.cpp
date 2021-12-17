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

#include "HashNames.h"

using namespace std;
using std::istream;
using std::ostream;
using std::string;

//Constructors
HashNames::HashNames()
{
	this->hash("names.txt");
	this->printVect();
}
HashNames::HashNames(string fileToHash)
{
	this->hash(fileToHash);
	this->printVect();
}

//Member functions
int HashNames::djbHash(string data, int tablesize)
{
	int hashVal = 5381;
	for (int i = 0; i < data.length(); i++)
	{
		hashVal *= 33;
		hashVal += static_cast<int>(data[i]);
	}

	hashVal %= tablesize;
	return abs(hashVal);
}

void HashNames::hash(string file)
{
	int count = 0;
	ifstream infile(file);
	if (!infile)
	{
		cout << "Error opening file for reading" << endl;
		exit(-1);
	}
	string input;
	while (getline(infile, input))
	{
		this->namesVect[djbHash(input, 53)].push_back(input);
		count++;
	}
	infile.close();
}

void HashNames::printVect()
{
	for (int i = 0; i < 53; i++) {

		cout << "Hash value of " << i << ": ";

		for (auto name = this->namesVect[i].begin();
			name != this->namesVect[i].end(); name++) {

			cout << *name << ',' << ' ';
		}
		cout << endl;
	}
}