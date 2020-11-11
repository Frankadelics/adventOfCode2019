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
		cout << "---------------------- i = " << i << " ------------------------" << endl;
		a = opcode[i] / 10000;
		b = opcode[i] / 1000 % 10;
		c = opcode[i] / 100 % 10;
		d = opcode[i] / 10 % 10;
		e = opcode[i] / 1 % 10;
		cout << "Opcode: " << opcode[i] << endl;
		cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << " e: " << e << endl;
		switch (e) {
		case 1: //Addition
			cout << "i1: " << i << endl;
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			cout << "i2: " << i << endl;
			valueB = b ? opcode[i + 2] : opcode[opcode[i + 2]];
			cout << "i3: " << i << endl;
			//locationA = a ? opcode[i + 3] : opcode[opcode[i + 3]];
			//locationA = a ? opcode[i + 3] : opcode[opcode[i + 3]];
			opcode[opcode[i + 3]] = valueC + valueB;
			cout << "Storing " << valueC + valueB << " in index: " << opcode[i + 3] << endl;
			cout << "i4: " << i << endl;
			i += 3;
			cout << "i1: " << i << endl;
			cout << "valueC: " << valueC << endl;
			cout << "valueB: " << valueB << endl;
			cout << "i + 3: " << i + 3 << endl;
			break;
		case 2: //Multiplication
			valueC = c ? opcode[i + 1] : opcode[opcode[i + 1]];
			valueB = b ? opcode[i + 2] : opcode[opcode[i + 2]];
			//locationA = a ? opcode[i + 3] : opcode[opcode[i + 3]];
			opcode[opcode[i + 3]] = valueC * valueB;
			i += 3;
			cout << "valueC: " << valueC << endl;
			cout << "valueB: " << valueB << endl;
			cout << "Storing in index: " << opcode[i + 3] << endl;
			break;
		case 3: //Get input from user
			cout << "Opcode 3 Encountered. Input: ";
			cin >> input;
			opcode[opcode[i + 1]] = input;
			i += 1;
			break;
		case 4: //Output from memory location given
			cout << "Opcode 4 Encountered. Output: " << opcode[opcode[i + 1]] << endl;
			i += 1;
			break;
		default:
			cout << "I don't know how we got here." << endl;
			break;
		}
	}
}
void runProgram(vector<int>& opcode) //day 1 solution that runs through the "program" given to it
{
	int firstPos = 0;
	int secondPos = 0;
	int memoryLocation = 0;
	int input = 0;
	string code = " ";
	for (int i = 0; i < opcode.size(); i++)
	{
		code = to_string(opcode[i]);
	
		if (code[3] == '0' && code[4] == '1')
		{
			opcode[i + 3] = opcode[i + 1] + opcode[i + 2];
			i += 3;
		}
		else if (code[3] == '0' && code[4] == '2')
		{
			opcode[i + 3] = opcode[i + 1] * opcode[i + 2];
			i += 3;
		}
		else if (code[3] == '0' && code[4] == '3')
		{
			cout << "Opcode 3 Encountered. Enter Input: ";
			cin >> input;
			memoryLocation = opcode[i + 1];
			opcode[memoryLocation] = input;
			i += 1;
		}
		else if (code[3] == '0' && code[4] == '4')
		{
			memoryLocation = opcode[i + 1];
			cout << "Opcode 4 Encountered. Output at " << opcode[i + 1] << " memory location: " << opcode[memoryLocation] << endl;
			i += 1;
		}
		else if (code[3] == '9' && code[4] == '9')
			break;
		else
			cout << "I don't know how we managed to get here." << endl;
	}
}
void getParameterMode(string& opcode)
{
	string code = "   ";
	code[0] = opcode[0];
	code[1] = opcode[1];
	code[2] = opcode[2];
	if (code == "000")
		cout << "oof" << endl;
	else if (code == "001")
		cout << "oof" << endl;
	else if (code == "010")
		cout << "oof" << endl;
	else if (code == "011")
		cout << "oof" << endl;
	else if (code == "100")
		cout << "oof" << endl;
	else if (code == "101")
		cout << "oof" << endl;
	else if (code == "110")
		cout << "oof" << endl;
	else if (code == "111")
		cout << "oof" << endl;
	else
		cout << "big oof" << endl;

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

	getInput(opcode, "day5Input.txt");
	printNormal(opcode);
	runProgramV2(opcode);


			
										
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