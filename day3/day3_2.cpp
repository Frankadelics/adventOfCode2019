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
	bool operator== (Point oof)
	{
		if (x == oof.x && y == oof.y)
			return true;
		else
			return false;
	}
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
void printPoints(vector<Point>& points)
{
	for (int i = 0; i < points.size(); i++)
		cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
}
void getInput(vector<string>& wire, string fileName) //Get the inputs given to me by Advent of Code 
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
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
			current.y = previous.y + move;
			//printPreCur(previous, current);
			for (int i = 0; i < abs(previous.y - current.y); i++)
			{
				newEntry.y++;
				pointsVector.push_back(newEntry);
			}
			previous = newEntry;
		}
		else if (holder[0] == 'D')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			current.y = previous.y + move;
			//printPreCur(previous, current);
			for (int i = 0; i < abs(previous.y - current.y); i++)
			{
				newEntry.y--;
				pointsVector.push_back(newEntry);
			}
			previous = newEntry;
		}
		else if (holder[0] == 'L')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			current.x = previous.x - move;
			//printPreCur(previous, current);
			for (int i = 0; i < abs(previous.x - current.x); i++)
			{
				newEntry.x--;
				pointsVector.push_back(newEntry);
			}
			previous = newEntry;
		}
		else if (holder[0] == 'R')
		{
			holder.erase(0, 1);
			move = stoi(holder);
			current.x = previous.x + move;
			//printPreCur(previous, current);
			for (int i = 0; i < abs(previous.x - current.x); i++)
			{
				newEntry.x++;
				pointsVector.push_back(newEntry);
			}
			previous = newEntry;
		}
		else
			cout << "oof" << endl;
	}
}
void compareWirePath(vector<Point>& red, vector<Point>& black, vector<Point>& crossedPoints)
{
	for (int i = 0; i < red.size(); i++)
	{
		for (int j = 0; j < black.size(); j++)
		{
			if (red[i] == black[j])
				crossedPoints.push_back(red[i]);
		}
	}
}
void getDistance(vector<Point> points)
{
	int min = points[0].x + points[0].y;
	int distance = 0;
	for (int i = 0; i < points.size(); i++)
	{
		distance = points[i].x + points[i].y;
		if (distance < min)
			min = distance;
	}
	cout << "Max Distance: " << min << endl;
}

int main()
{
	vector<string> redWire, blackWire;
	vector<Point> redPoints, blackPoints, crossedPoints;

	//getInput(redWire, "redDebug1.txt");
	//getInput(blackWire, "blackDebug1.txt");
	//getWireHistory(redWire, redPoints);
	//getWireHistory(blackWire, blackPoints);
	//printPoints(redPoints);
	//cout << "------------------------------------" << endl;
	//printPoints(blackPoints);
	//cout << "------------------------------------" << endl;
	//compareWirePath(redPoints, blackPoints, crossedPoints);
	//printPoints(crossedPoints);
	//getDistance(crossedPoints);

	//Need to optimize the solution!! This takes way too long to finish
	getInput(redWire, "redWire.txt");
	getInput(blackWire, "blackWire.txt");
	getWireHistory(redWire, redPoints);
	getWireHistory(blackWire, blackPoints);
	printPoints(redPoints);
	cout << "Hello again again" << endl;
	compareWirePath(redPoints, blackPoints, crossedPoints);
	cout << "Hello again" << endl;
	getDistance(crossedPoints);
	cout << "Hello" << endl;
	return 0;
}