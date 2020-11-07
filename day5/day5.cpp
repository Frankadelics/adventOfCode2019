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
void prependZeros(string& opcode) //Add any missing zeros to the front of the given opcode
{
	int append = 5 - opcode.length();
	for (int i = 0; i < append; i++)
		opcode.insert(i, "0");
}
void getInput(vector<int>& opcode, string file) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(file);
	while (getline(readFromFile, input, ','))
		opcode.push_back(stoi(input));
}
void runProgram(vector<int>& opcode) //day 1 solution that runs through the "program" given to it
{
	int firstPos = 0;
	int secondPos = 0;
	int memoryLocation = 0;
	int input = 0;
	for (int i = 0; i < opcode.size(); i++)
	{
		if (opcode[i] == 1)
		{
			opcode[i + 3] = opcode[i + 1] + opcode[i + 2];
			i += 3;
		}
		else if (opcode[i] == 2)
		{
			opcode[i + 3] = opcode[i + 1] * opcode[i + 2];
			i += 3;
		}
		else if (opcode[i] == 3)
		{
			cout << "Opcode 3 Encountered. Enter Input: ";
			cin >> input;
			memoryLocation = opcode[i + 1];
			opcode[memoryLocation] = input;
			i += 1;
		}
		else if (opcode[i] == 4)
		{
			memoryLocation = opcode[i + 1];
			cout << "Opcode 4 Encountered. Output at " << opcode[i + 1] << " memory location: " << opcode[memoryLocation] << endl;
			i += 1;
		}
		else if (opcode[i] == 99)
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
			runProgram(codes);
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

	//getInput(opcode, "day5DebugInputs.txt");
	//runProgram(opcode);
	//printNormal(opcode);

	string number = "10";
	prependZeros(number);
	cout << "Number: " << number << endl;
													
													
													//getInput(opcode, "day5Input.txt");	     	//Get the inputs I was given
	//getInput(originalOpcode, "day5Input.txt");	//Keep a copy of the original opcodes 

	/*
			The Day 2 - Part 1 Solution. Uncomment to get solution.
			NOTE: Make sure to comment out Day 2 - Part 2 solution first!
	*/
	//runProgramOnce(opcode);
	//cout << "Index 0: " << opcode[0] << endl;

	/*
			Day 2 - Part 2 Solution. Uncomment to get the solution.
			NOTE: Make sure to comment out Day 2 - Part 1 solution first!
	*/
	//findNounAndVerb(opcode, originalOpcode);

	return 0;
}