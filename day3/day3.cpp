//Day 3 - Advent of Code 2019
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class wireHistory {
private:
	int x;
	int y;
public:
	void increaseX(int num) { x += num; }
	void decreaseX(int num) { x -= num; }
	void increaseY(int num) { y += num; }
	void decreaseY(int num) { y -= num; }
	int getX() { return x; }
	int getY() { return y; }
};

void printNormal(vector<wireHistory>& wires) //Prints opcodes one line each
{
	for (int i = 0; i < wires.size(); i++)
	{
		cout << "(" << wires[i].getX() << "," << wires[i].getY() << ")" << endl;
	}
}
void getAOCInput(vector<string>& codes, string fileName) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		codes.push_back(input);
}
void moveWire(vector<string>& wire, vector<wireHistory>& wireHistory)
{
	string holder = " ";
	int move = 0;
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		if (holder[0] == 'U')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			wireHistory[i].increaseY(move);
			wireHistory[i].increaseX(0);
		}
		else if (holder[0] == 'D')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			wireHistory[i].decreaseY(move);
			wireHistory[i].decreaseX(0);
		}
		else if (holder[0] == 'L')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			wireHistory[i].decreaseX(move);
			wireHistory[i].decreaseY(0);
		}
		else if (holder[0] == 'R')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			wireHistory[i].increaseX(move);
			wireHistory[i].increaseY(0);
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
	
	getAOCInput(redWire, "redWire.txt");
	getAOCInput(blackWire, "blackWire.txt");

	moveWire(redWire, redHistory);
	//moveWire(blackWire, blackHistory);

	//printNormal(redHistory);

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