//Day 5 - Advent of Code 2019
/*
	Rules:
	99 - End the program
	1  - Add two numbers together from two positions that follow
	2  - Multiply two numbers togther from two positions that follow
	3  - Takes single integer as input and saves to position given by only parameter
	4  - Outputs value of onlu parameter

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void printNormal(vector<int>& codes) //Prints opcodes one line each
{
	for (int i = 0; i < codes.size(); i++)
		cout << i << ". " << codes[i] << endl;
}
void getInput(vector<int>& opcode, string file) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(file);
	while (getline(readFromFile, input, ','))
		opcode.push_back(stoi(input));
}
void runProgramV2(vector<int>& opcode)
{
	int a, b, c, d, e;
	int valueC, valueB, locationA, input;
	for (int i = 0; i < opcode.size(); i++)
	{
		a = opcode[i] / 10000;
		b = opcode[i] / 1000 % 10;
		c = opcode[i] / 100 % 10;
		d = opcode[i] / 10 % 10;
		e = opcode[i] / 1 % 10;
		cout << "---------------------- i = " << i << " ------------------------" << endl;
		cout << "Opcode: " << opcode[i] << endl;
		if (e == 1) //Addition
		{
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			valueB = b ? opcode[i + 2] : opcode[opcode[i + 2]];
			opcode[opcode[i + 3]] = valueC + valueB;
			i += 3;
			cout << "valueC: " << valueC << endl;
			cout << "valueB: " << valueB << endl;
			cout << "Storing " << valueC + valueB << " in index: " << opcode[i + 3] << endl;
		}
		else if (e == 2) //Multiplication
		{
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			valueB = b ? opcode[i + 2] : opcode[opcode[i + 2]];
			opcode[opcode[i + 3]] = valueC * valueB;
			i += 3;
			cout << "valueC: " << valueC << endl;
			cout << "valueB: " << valueB << endl;
			cout << "Storing " << valueC * valueB << " in index: " << opcode[i + 3] << endl;
		}
		else if (e == 3) //User Input
		{
			cout << "Opcode 3 Encountered. Input: ";
			cin >> input;
			opcode[opcode[i + 1]] = input;
			i += 1;
		}
		else if (e == 4) //Output from memory location given
		{
			cout << "Opcode 4 Encountered. Output: " << opcode[opcode[i + 1]] << endl;
			i += 1;
		}
		else if (e == 5) //If first param is non-zero, sets i to value of second param
		{
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			if (valueC != 0)
			{
				i = b ? opcode[i + 2] : opcode[opcode[i + 2]];
				i -= 1;
			}
			else
				i += 2;
			cout << "valueC: " << valueC << endl;
			cout << "i: " << i << endl;
		}
		else if (e == 6) //If first param is zero, sets i to value of second param
		{
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			if (valueC == 0)
			{
				i = b ? opcode[i + 2] : opcode[opcode[i + 2]];
				i -= 1;
			}
			else
				i += 2;
			cout << "valueC: " << valueC << endl;
			cout << "i: " << i << endl;
		}
		else if (e == 7) //If first param is less than second param, stores 1 in position of third param
		{
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			valueB = b ? opcode[i + 2] : opcode[opcode[i + 2]];
			opcode[opcode[i + 3]] = valueC < valueB ? 1 : 0;
			i += 3;
			cout << "valueC: " << valueC << endl;
			cout << "valueB: " << valueB << endl;
		}
		else if (e == 8) //If first param is equal to second param, stores 1 in position of third param
		{
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			valueB = b ? opcode[i + 2] : opcode[opcode[i + 2]];
			opcode[opcode[i + 3]] = valueC == valueB ? 1 : 0;
			i += 3;
			cout << "valueC: " << valueC << endl;
			cout << "valueB: " << valueB << endl;
		}
		else if (e == 9)
			break;
		else
			cout << "I don't know how we got here." << endl;
	}
}

int main()
{
	vector<int> opcode;
	vector<int> originalOpcode;

	//getInput(opcode, "day5DebugInputs.txt");
	printNormal(opcode);
	getInput(opcode, "day5Input.txt");
	runProgramV2(opcode);

	return 0;
}