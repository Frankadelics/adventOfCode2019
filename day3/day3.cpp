//Day 3 - Advent of Code 2019
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class wireHistory {
private:
	int x = 0;
	int y = 0;
public:
	void increaseX(int num) { x += num; }
	void decreaseX(int num) { x -= num; }
	void increaseY(int num) { y += num; }
	void decreaseY(int num) { y -= num; }
	int getX() { return x; }
	int getY() { return y; }
};
void printWireHistory(vector<wireHistory>& history) //Prints opcodes one line each
{
	for (int i = 0; i < history.size(); i++)
	{
		cout << "(" << history[i].getX() << "," << history[i].getY() << ")" << endl;
	}
}
void getInput(vector<string>& wire, string fileName) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
}
void traceWirePath(vector<string>& wire, vector<wireHistory>& history)
{
	wireHistory historyContainer;
	string holder = " ";
	int move = 0;
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		if (holder[0] == 'U')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			//cout << "Holder: " << holder << " | Move: " << move << endl;
			historyContainer.increaseY(move);
			historyContainer.increaseX(0);
			history.push_back(historyContainer);
		}
		else if (holder[0] == 'D')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			historyContainer.decreaseY(move);
			historyContainer.decreaseX(0);
			history.push_back(historyContainer);
		}
		else if (holder[0] == 'L')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			historyContainer.decreaseX(move);
			historyContainer.decreaseY(0);
			history.push_back(historyContainer);
		}
		else if (holder[0] == 'R')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			historyContainer.increaseX(move);
			historyContainer.increaseY(0);
			history.push_back(historyContainer);
		}
		else
			cout << "I don't know how we got here" << endl;
	}
}


int main()
{
	int rY, rX, bX, bY = 0;
	vector<string> redWire;
	vector<string> blackWire;
	vector<wireHistory> redHistory;
	vector<wireHistory> blackHistory;
	
	//getInput(redWire, "redWire.txt");
	//getInput(blackWire, "blackWire.txt");

	getInput(redWire, "redDebug1.txt");
	getInput(blackWire, "blackDebug1.txt");


	traceWirePath(redWire, redHistory);
	traceWirePath(blackWire, blackHistory);

	printWireHistory(redHistory);

	cout << "--------------------------------------------" << endl;

	printWireHistory(blackHistory);

	//Debug stuff
	/*int tester = 0;
	string test("D123");
	cout << test << endl;
	test.erase(0, 1);
	cout << test << endl;
	tester = stoi(test);
	cout << tester + 1 << endl;*/

	//moveWire(redWire, rX, rY, redHistory);
	//printNormal(redDir);
	//printNormal(blackDir);

	return 0;
}