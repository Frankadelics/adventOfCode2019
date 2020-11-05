#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printNumbers(vector<string>& num)
{
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << endl;
}
void getNumbers(int start, int end, vector<string>& num)
{
	for (int i = start; i <= end; i++)
		num.push_back(to_string(i));
}
void checkAdjacent(vector<string>& num, vector<string>& adj)
{
	string holder;
	for (int i = 0; i < num.size(); i++)
	{
		holder = num[i];
		for (int j = 0; j < num[i].length() - 1; j++)
		{
			
			if (holder[j] == holder[j + 1])
			{
				adj.push_back(holder);
				break;
			}
		}
	}
}
void checkRepeatOnceAdjacent(vector<string>& adj, vector<string>& repeatOnce)
{
	string holder;
	for (int i = 0; i < adj.size(); i++)
	{
		holder = adj[i];
		if (holder[0] == holder[1] && holder[0] != holder[2])
			repeatOnce.push_back(holder);
		else if (holder[1] == holder[2] && holder[1] != holder[0] && holder[1] != holder[3])
			repeatOnce.push_back(holder);
		else if (holder[2] == holder[3] && holder[2] != holder[1] && holder[2] != holder[4])
			repeatOnce.push_back(holder);
		else if (holder[3] == holder[4] && holder[3] != holder[2] && holder[3] != holder[5])
			repeatOnce.push_back(holder);
		else if (holder[4] == holder[5] && holder[4] != holder[3])
			repeatOnce.push_back(holder);
	}
}
void checkIncrease(vector<string>& num, vector<string>& inc)
{
	string holder;
	bool check = false;
	for (int i = 0; i < num.size(); i++)
	{
		holder = num[i];
		check = true;
		for (int j = 0; j < num[i].length() - 1; j++)
		{
			if (holder[j] > holder[j + 1])
				check = false;
		}
		if (check)
			inc.push_back(holder);
	}
}

int main()
{
	vector<string> numbers;
	vector<string> adjacentNumbers;
	vector<string> increaseNumbers;
	vector<string> repeatOnceAdjNumbers;

	getNumbers(367479, 893698, numbers);
	checkAdjacent(numbers, adjacentNumbers);
	checkIncrease(adjacentNumbers, increaseNumbers);
	checkRepeatOnceAdjacent(increaseNumbers, repeatOnceAdjNumbers);

	cout << "Day 1: " << increaseNumbers.size() << endl;
	cout << "Day 2: " << repeatOnceAdjNumbers.size() << endl;

	return 0;
}