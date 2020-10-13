//New Method to Solve Day 3, Solution Inspired by Niko's
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Point {
public:
	int x = 0;
	int y = 0;
};
class Segment {
private:
	Point point1;
	Point point2;
public:
	void assignPoint1(int x, int y) { point1.x = x; point1.y = y; }
	void assignPoint2(int x, int y) { point2.x = x; point2.y = y; }
};
void printPreCur(Point previous, Point current)
{
	cout << "Current: (" << current.x << "," << current.y << ")" << endl;
	cout << "Previous: (" << previous.x << "," << previous.y << ")" << endl;
}
void getInput(vector<string>& wire, string fileName) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
}
void printPoints(vector<Point>& points)
{
	for (int i = 0; i < points.size(); i++)
		cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
}
void getWireHistory(vector<string>& wire, vector<Point>& pointsVector)
{
	Point current, previous, newEntry;
	string holder = " ";
	int move = 0;
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		if (holder[0] == 'U')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			newEntry.x = previous.x;
			newEntry.y = previous.y;
			current.y = previous.y + move;
			current.x = previous.x;
			printPreCur(previous, current);
			for (int i = 0; i < abs(previous.y - current.y); i++)
			{
				newEntry.x += 0;
				newEntry.y++;
				pointsVector.push_back(newEntry);
			}
			previous.x = newEntry.x;
			previous.y = newEntry.y;
		}
		else if (holder[0] == 'D')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			newEntry.x = previous.x;
			newEntry.y = previous.y;
			current.y = previous.y + move;
			current.x = previous.x;
			printPreCur(previous, current);
			for (int i = 0; i < abs(previous.y - current.y); i++)
			{
				newEntry.x += 0;
				newEntry.y--;
				pointsVector.push_back(newEntry);
			}
			previous.x = newEntry.x;
			previous.y = newEntry.y;
		}
		else if (holder[0] == 'L')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			newEntry.x = previous.x;
			newEntry.y = previous.y;
			current.y = previous.y;
			current.x = previous.x - move;
			printPreCur(previous, current);
			for (int i = 0; i < abs(previous.x - current.x); i++)
			{
				newEntry.x--;
				newEntry.y += 0;
				pointsVector.push_back(newEntry);
			}
			previous.x = newEntry.x;
			previous.y = newEntry.y;
		}
		else if (holder[0] == 'R')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			newEntry.x = previous.x;
			newEntry.y = previous.y;
			current.y = previous.y;
			current.x = previous.x + move;
			printPreCur(previous, current);
			for (int i = 0; i < abs(previous.x - current.x); i++)
			{
				newEntry.x++;
				newEntry.y += 0;
				pointsVector.push_back(newEntry);
			}
			previous.x = newEntry.x;
			previous.y = newEntry.y;
		}
		else
			cout << "oof" << endl;
	}
}

int main()
{
	vector<string> redWire, blackWire;
	vector<Point> redPoints, blackPoints;

	getInput(redWire, "redDebug1.txt");
	getInput(blackWire, "blackDebug1.txt");
	
	getWireHistory(redWire, redPoints);
	getWireHistory(blackWire, blackPoints);

	printPoints(redPoints);
	cout << "------------------------------------" << endl;
	printPoints(blackPoints);

	//printVector(redWire);
	//printVector(blackWire);

	return 0;
}