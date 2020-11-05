#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printNumbers(vector<string>& num) //For debugging purposes
{
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << endl;
}
bool checkAdjacent(string number) //Check if number has any neighbors that are the same
{
	for (int i = 0; i < number.length() - 1; i++)
	{
		if (number[i] == number[i + 1])
		{
			return true;
			break;
		}
	}
	return false;
}
bool checkRepeatOnceAdjacent(string number) //Check if number has one pair of equal numbers only, no triplets, quadruplets, quintuplets 
{
	if (number[0] == number[1] && number[0] != number[2])
		return true;
	else if (number[1] == number[2] && number[1] != number[0] && number[1] != number[3])
		return true;
	else if (number[2] == number[3] && number[2] != number[1] && number[2] != number[4])
		return true;
	else if (number[3] == number[4] && number[3] != number[2] && number[3] != number[5])
		return true;
	else if (number[4] == number[5] && number[4] != number[3])
		return true;
	else
		return false;
}
bool checkIncrease(string number) //Check if the numbers only increase
{
	bool check = true;
	for (int i = 0; i < number.length() - 1; i++)
	{
		if (number[i] > number[i + 1])
			check = false;
	}
	if (check)
		return true;
	else
		return false;
}
void getNumbers(int start, int end, vector<string>& part1, vector<string>& part2)
{
	for (int i = start; i <= end; i++)
	{
		string number = to_string(i);
		if (checkAdjacent(number) && checkIncrease(number))
		{
			part1.push_back(number);
			if (checkRepeatOnceAdjacent(number))
				part2.push_back(number);
		}
	}
}

int main()
{
	vector<string> numbersPart1;
	vector<string> numbersPart2;

	getNumbers(367479, 893698, numbersPart1, numbersPart2);

	cout << "Part 1: " << numbersPart1.size() << endl;
	cout << "Part 2: " << numbersPart2.size() << endl;

	return 0;
}