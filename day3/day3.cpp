//Day 3 - Advent of Code 2019
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class wireHistory{ //The coordinate that represent where the wire has been
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
class Edges {
private:
	int x1, y1, x2, y2 = 0;
	char orientation = ' ';
public:
	void assignX1(int num) { x1 = num; }
	void assignY1(int num) { y1 = num; }
	void assignX2(int num) { x2 = num; }
	void assignY2(int num) { y2 = num; }
	void assignOrientation(char letter) { orientation = letter; }

	int getX1() { return x1; }
	int getY1() { return y1; }
	int getX2() { return x2; }
	int getY2() { return y2; }
	char getOrientation() { return orientation; }
};
void printWireHistory(vector<wireHistory>& history) //Prints the history of the wire in a cartesian format
{
	for (int i = 0; i < history.size(); i++)
		cout << "(" << history[i].getX() << "," << history[i].getY() << ")" << endl;
}
void printEdges(vector<Edges>& edge, char choice) //Prints the edges together 
{
	if (choice == 'A')
	{
		for (int i = 0; i < edge.size(); i++)
		{
			cout << "(" << edge[i].getX1() << "," << edge[i].getY1() << ")"
				<< "(" << edge[i].getX2() << "," << edge[i].getY2() << ")" << endl;
		}
	}
	else if (choice == 'V')
	{
		for (int i = 0; i < edge.size(); i++)
		{
			if (edge[i].getOrientation() == 'v')
			{
				cout << "(" << edge[i].getX1() << "," << edge[i].getY1() << ")"
					<< "(" << edge[i].getX2() << "," << edge[i].getY2() << ")" << endl;
			}
		}
	}
	else if (choice == 'H')
	{
		for (int i = 0; i < edge.size(); i++)
		{
			if (edge[i].getOrientation() == 'h')
			{
				cout << "(" << edge[i].getX1() << "," << edge[i].getY1() << ")"
					<< "(" << edge[i].getX2() << "," << edge[i].getY2() << ")" << endl;
			}
		}
	}
	else
		cout << "OOOOOOOOOF" << endl;

}
void getInput(vector<string>& wire, string fileName) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
}
void traceWirePath(vector<string>& wire, vector<wireHistory>& history) //Traces the path of the wire passed into it
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
void findEdges(vector<string>& wire, vector<Edges> edge, int x, int y)
{
	int move = 0;
	string holder = " ";
	Edges edgeContainer;
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		if (holder[0] == 'U')
		{
			edgeContainer.assignX1(x);
			edgeContainer.assignY1(y);
			holder.erase(0, 1);
			move = stoi(holder);
			y += move;
			edgeContainer.assignX2(x);
			edgeContainer.assignY2(y);
			edgeContainer.assignOrientation('v');
			edge.push_back(edgeContainer);
		}
		else if (holder[0] == 'D')
		{
			edgeContainer.assignX1(x);
			edgeContainer.assignY1(y);
			holder.erase(0, 1);
			move = stoi(holder);
			y -= move;
			edgeContainer.assignX2(x);
			edgeContainer.assignY2(y);
			edgeContainer.assignOrientation('v');
			edge.push_back(edgeContainer);
		}
		else if (holder[0] == 'L')
		{
			edgeContainer.assignX1(x);
			edgeContainer.assignY1(y);
			holder.erase(0, 1);
			move = stoi(holder);
			x -= move;
			edgeContainer.assignX2(x);
			edgeContainer.assignY2(y);
			edgeContainer.assignOrientation('h');
			edge.push_back(edgeContainer);
		}
		else if (holder[0] == 'R')
		{
			edgeContainer.assignX1(x);
			edgeContainer.assignY1(y);
			holder.erase(0, 1);
			move = stoi(holder);
			x += move;
			edgeContainer.assignX2(x);
			edgeContainer.assignY2(y);
			edgeContainer.assignOrientation('h');
			edge.push_back(edgeContainer);
		}
		else
			cout << "I don't know how we got here." << endl;
	}
}

int main()
{
	int x = 0;
	int	y = 0;
	vector<string> redWire, blackWire;
	vector<wireHistory> redHistory, blackHistory;
	vector<Edges> redEdges, blackEdges;
	
	//getInput(redWire, "redWire.txt");
	//getInput(blackWire, "blackWire.txt");

	getInput(redWire, "redDebug1.txt");
	getInput(blackWire, "blackDebug1.txt");

	findEdges(redWire, redEdges, x, y);

	printEdges(redEdges, 'V');




	/*
	traceWirePath(redWire, redHistory);
	traceWirePath(blackWire, blackHistory);

	printWireHistory(redHistory);

	cout << "--------------------------------------------" << endl;

	printWireHistory(blackHistory);
	*/



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