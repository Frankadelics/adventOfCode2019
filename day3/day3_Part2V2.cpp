//Day 3 - Advent of Code 2019
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Point {
public:
	int x = 0;
	int y = 0;
};
class Segment {
public:
	Point start;	
	Point end;
	int length;
	int color;
};
class Cross {
public:
	Point intersection;
	Segment hSeg;
	Segment vSeg;
};

bool withinRange(int min, int max, int num)
{
	int buffer = 0;
	if (min > max)
	{
		buffer = max;
		max = min;
		min = buffer;
	}
	if (num > min && num < max)
		return true;
	else
		return false;
}
void getInput(vector<string>& wire, string fileName) //Get the inputs from the specified text file
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
}
void getSegments(vector<string>& wire, vector<Segment>& horizontal, vector<Segment>& vertical)
{
	//This function helps both parts of day 3
	int move = 0;
	int length = 0;
	char dir = ' ';
	Segment seg;
	string holder = " ";
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		dir = holder[0];
		holder.erase(0, 1);
		move = stoi(holder);
		length += move;
		if (dir == 'U')
		{
			seg.end.y += move;
			seg.length = length;
			vertical.push_back(seg);
			seg.start.y = seg.end.y; 
		}
		else if (dir == 'D')
		{
			seg.end.y -= move;
			seg.length = length;
			vertical.push_back(seg);
			seg.start.y = seg.end.y; 
		}
		else if (dir == 'L')
		{
			seg.end.x -= move;
			seg.length = length;
			horizontal.push_back(seg);  
			seg.start.x = seg.end.x;
		}
		else if (dir == 'R')
		{
			seg.end.x += move;
			seg.length = length;
			horizontal.push_back(seg);
			seg.start.x = seg.end.x; 
		}
		else
			cout << "I don't know how we got here buddy" << endl;
	}
}
void getIntersections(vector<Segment>& vertical, vector<Segment>& horizontal, vector<Cross>& intersections)
{
	//This function helps with both parts of day 3
	Cross inter;
	int max = 0;
	int min = 0;
	int num = 0;
	for (int i = 0; i < vertical.size(); i++)
	{
		for (int j = 0; j < horizontal.size(); j++)
		{
			num = vertical[i].start.x;
			min = horizontal[j].start.x;
			max = horizontal[j].end.x;
			if (withinRange(min, max, num))
			{
				num = horizontal[j].start.y;
				min = vertical[i].start.y;
				max = vertical[i].end.y;
				if (withinRange(min, max, num))
				{
					inter.intersection.x = vertical[i].start.x;
					inter.intersection.y = horizontal[j].start.y;
					inter.hSeg = horizontal[j];
					inter.vSeg = vertical[i];
					intersections.push_back(inter);
				}
			}
		}
	}
}
int getDistance(vector<Cross> points)
{
	//This is for Day 3 Part 1
	int min = abs(points[0].intersection.x) + abs(points[0].intersection.y);
	int distance = 0;
	for (int i = 0; i < points.size(); i++)
	{
		distance = abs(points[i].intersection.x) + abs(points[i].intersection.y);
		if (distance < min)
			min = distance;
	}
	return min;
}
int getDistanceBetweenTwoPoints(int& x1, int& x2, int& y1, int& y2)
{
	//This is just the distance formula
	int dx = (x1 - x2) * (x1 - x2);
	int dy = (y1 - y2) * (y1 - y2);
	int distance = sqrt(dx + dy);
	return distance;
}
int getDelay(vector<Cross>& cross)
{
	int delay = 0;
	int minDelay = 0;
	int x1, x2, y1, y2;
	for (int i = 0; i < cross.size(); i++)
	{
		delay = cross[i].hSeg.length + cross[i].vSeg.length;

		x1 = cross[i].intersection.x;
		x2 = cross[i].hSeg.end.x;
		y1 = cross[i].intersection.y;
		y2 = cross[i].hSeg.end.y;
		delay -= getDistanceBetweenTwoPoints(x1, x2, y1, y2);

		x1 = cross[i].intersection.x;
		x2 = cross[i].vSeg.end.x;
		y1 = cross[i].intersection.y;
		y2 = cross[i].vSeg.end.y;
		delay -= getDistanceBetweenTwoPoints(x1, x2, y1, y2);

		if (i == 0) { minDelay = delay; }
		if (delay < minDelay) { minDelay = delay; }
	}
	return minDelay;
}
void printPoints(vector<Point>& points)
{
	for (int i = 0; i < points.size(); i++)
		cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
}
void printSegments(vector<Segment>& segments)
{
	for (int i = 0; i < segments.size(); i++)
		cout << "(" << segments[i].start.x << ", " << segments[i].start.y << ") ("
			<< segments[i].end.x << ", " << segments[i].end.y << ")" << "totalLength: " << segments[i].length << endl;
}
void printCross(vector<Cross>& cross)
{
	for (int i = 0; i < cross.size(); i++)
	{
		cout << "(" << cross[i].intersection.x << ", " << cross[i].intersection.y <<
			") hStart: (" << cross[i].hSeg.start.x << ", " << cross[i].hSeg.start.y << ") hEnd: ("
			<< cross[i].hSeg.end.x << ", " << cross[i].hSeg.end.y << ") vStart: ("
			<< cross[i].vSeg.start.x << ", " << cross[i].vSeg.start.y << ") vEnd: ("
			<< cross[i].vSeg.end.x << ", " << cross[i].vSeg.end.y << ") hLength: "
			<< cross[i].hSeg.length << " vLength: " << cross[i].vSeg.length << endl;
	}
}

int main()
{
	vector <string> redWire, blackWire;
	vector <Segment> red_horizontal_segments, red_vertical_segments;
	vector <Segment> black_horizontal_segments, black_vertical_segments;
	vector <Cross> intersections;
	
	//getInput(redWire, "redDebug1.txt");
	//getInput(blackWire, "blackDebug1.txt");
	
	getInput(redWire, "redWire.txt");
	getInput(blackWire, "blackWire.txt");

	getSegments(redWire, red_horizontal_segments, red_vertical_segments);
	getSegments(blackWire, black_horizontal_segments, black_vertical_segments);

	getIntersections(red_vertical_segments, black_horizontal_segments, intersections);
	getIntersections(black_vertical_segments, red_horizontal_segments, intersections);

	cout << "Day 3.1: " << getDistance(intersections) << endl;
	cout << "Day 3.2: " << getDelay(intersections) << endl;
	
	return 0;
}