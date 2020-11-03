#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getNumbers(int start, int end, vector<string>& num)
{
	for (int i = start; i <= end; i++)
		num.push_back(to_string(i));
}
void printNumbers(vector<string>& num)
{
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << endl;
}
void checkAdjacent(vector<string>& num, vector<string>& adj)
{
	string holder;
	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < num[i].length() - 1; j++)
		{
			holder = num[i];
			if (holder[j] == holder[j + 1])
			{
				//cout << "True" << holder << endl;
				adj.push_back(holder);
				break;
			}
		}
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

	//getNumbers(111, 222, numbers);
	getNumbers(367479, 893698, numbers);
	//printNumbers(numbers);
	checkAdjacent(numbers, adjacentNumbers);
	checkIncrease(adjacentNumbers, increaseNumbers);
	//printNumbers(increaseNumbers);

	cout << "Size: " << increaseNumbers.size() << endl;
	return 0;
}