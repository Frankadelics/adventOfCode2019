//Day 2 - Advent of Code 2019
/*
	Rules:
	99 - End the program
	1  - Add two numbers together from two positions that follow
	2  - Multiply two numbers togther from two positions that follow
	
	Example:
	[1, 10, 20, 30]
	1. Will add 10 and 20 and store the result in location 30
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void printFancy(vector<int>& codes) //prints opcodes out in rows of 4
{
	for (int i = 0; i < codes.size(); i++)
	{
		cout << codes[i] << ", ";
		if ((i + 1) % 4 == 0)
			cout << endl << endl;

	}
}
void printNormal(vector<int>& codes) //Prints opcodes one line each
{
	for (int i = 0; i < codes.size(); i++)
		cout << codes[i] << endl;
}
void getAOCInput(vector<int>& codes) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile("inputDay2.txt");
	while (getline(readFromFile, input, ','))
		codes.push_back(stoi(input));
}
void getdebugInputs(vector<int>& codes) //Small "program" given as an example that I used to debug and help wrap my head around problem
{
	codes.push_back(1);
	codes.push_back(9);
	codes.push_back(10);
	codes.push_back(3);
	codes.push_back(2);
	codes.push_back(3);
	codes.push_back(11);
	codes.push_back(0);
	codes.push_back(99);
	codes.push_back(30);
	codes.push_back(40);
	codes.push_back(50);
	//codes.push_back(oof);
}
void runProgramOnce(vector<int>& codes) //day 1 solution that runs through the "program" given to it
{
	int firstPos = 0;
	int secondPos = 0;
	int storeResult = 0;
	int result = 0;
	for (int i = 0; i < codes.size(); i++)
	{
		if (codes[i] == 1)
		{
			firstPos = codes[i + 1];
			secondPos = codes[i + 2];
			storeResult = codes[i + 3];

			result = codes[firstPos] + codes[secondPos];
			codes[storeResult] = result;
			i += 3;
		}
		else if (codes[i] == 2)
		{
			firstPos = codes[i + 1];
			secondPos = codes[i + 2];
			storeResult = codes[i + 3];

			result = codes[firstPos] * codes[secondPos];
			codes[storeResult] = result;
			i += 3;
		}
		else if (codes[i] == 99)
			break;
		else
			cout << "I don't know how we managed to get here." << endl;
	}
}
void resetOpcode(vector<int>& codes, vector<int>& OGcodes) //Reset the opcodes to the original values from the .txt
{
	codes = OGcodes;
}
void findNounAndVerb(vector<int>& codes, vector<int>& OGcodes)
{
	int noun = 0;
	int verb = 0;
	const int NEEDTHISNUM = 19690720;

	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			codes[1] = i;
			codes[2] = j;
			runProgramOnce(codes);
			if (codes[0] == NEEDTHISNUM)
			{
				noun = i;
				verb = j;
				cout << "Noun: " << noun << " | Verb: " << verb << endl;
				resetOpcode(codes, OGcodes);
				break;
			}
			else
				resetOpcode(codes, OGcodes);
		}
		if (codes[0] == NEEDTHISNUM)
			break;
	}
}

int main()
{
	vector<int> opcode;
	vector<int> originalOpcode;

	//getdebugInputs(opcode);		//Get custom inputs I have selected
	getAOCInput(opcode);	     	//Get the inputs I was given
	getAOCInput(originalOpcode);	//Keep a copy of the original opcodes 
	
	/*
			The Day 1 Solution. Uncomment to get solution. 
			NOTE: Make sure to comment out day2 solution first. 
	*/
	//runProgramOnce(opcode);
	//cout << "Index 0: " << opcode[0] << endl;

	/*
			Day 2 Solution. Uncomment to get the solution.
			NOTE: Make sure to comment day 1 solution first!
	*/
	//findNounAndVerb(opcode, originalOpcode);

	return 0;
}