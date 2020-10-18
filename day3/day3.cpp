//Day 3 - Advent of Code 2019
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Point {
public:
	int x = 0;
	int y = 0;
	bool operator< (const Point& rhs) const
	{
		return x < rhs.x;
	}
};
class Segment {
public:
	Point start;	//Where the point was before it was moved
	Point end;		//Where the  point is after it is moved
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
	if (num >= min && num <= max)
		return true;
	else
		return false;
}
void getInput(vector<string>& wire, string fileName)
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
}
void getSegments(vector<string>& wire, vector<Segment>& horizontal, vector<Segment>& vertical)
{
	int move;
	char dir;
	Segment seg;
	string holder = " ";
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		dir = holder[0];
		holder.erase(0, 1);
		move = stoi(holder);
		if (dir == 'U')
		{
			seg.end.y += move;
			vertical.push_back(seg);  //Previous(start) point should already be in seg so it gets pushed back along with current(end) point
			seg.start.y = seg.end.y; //Assign current(end) to previous(start) so it becomes previous for next direction
		}
		else if (dir == 'D')
		{
			seg.end.y -= move;
			vertical.push_back(seg);  //Previous(start) point should already be in seg so it gets pushed back along with current(end) point
			seg.start.y = seg.end.y; //Assign current(end) to previous(start) so it becomes previous for next direction
		}
		else if (dir == 'L')
		{
			seg.end.x -= move;
			horizontal.push_back(seg);  //Previous(start) point should already be in seg so it gets pushed back along with current(end) point
			seg.start.x = seg.end.x; //Assign current(end) to previous(start) so it becomes previous for next direction
		}
		else if (dir == 'R')
		{
			seg.end.x += move;
			horizontal.push_back(seg);  //Previous(start) point should already be in seg so it gets pushed back along with current(end) point
			seg.start.x = seg.end.x; //Assign current(end) to previous(start) so it becomes previous for next direction
		}
		else
			cout << "I don't know how we got here buddy" << endl;
	}
}
void printSegments(vector<Segment>& segments)
{
	for (int i = 0; i < segments.size(); i++)
		cout << "(" << segments[i].start.x << ", " << segments[i].start.y << ") ("
			<< segments[i].end.x << ", " << segments[i].end.y << ")" << endl;
}
void printPoints(vector<Point> points)
{
	for (int i = 0; i < points.size(); i++)
		cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
}
void getIntersections(vector<Segment>& vertical, vector<Segment>& horizontal, vector<Point>& intersections)
{
	Point inter;
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
					inter.x = vertical[i].start.x;
					inter.y = horizontal[j].start.y;
					intersections.push_back(inter);
				}
			}
		}
	}
}
void getDistance(vector<Point> points)
{
	int min = abs(points[0].x) + abs(points[0].y);
	int distance = 0;
	for (int i = 0; i < points.size(); i++)
	{
		distance = abs(points[i].x) + abs(points[i].y);
		if (distance < min)
			min = distance;
	}
	cout << "Max Distance: " << min << endl;
}
int main()
{
	vector <string> redWire, blackWire;
	vector <Segment> red_horizontal_segments, red_vertical_segments;
	vector <Segment> black_horizontal_segments, black_vertical_segments;
	vector <Point> intersections;

	getInput(redWire, "redWire.txt");
	getInput(blackWire, "blackWire.txt");

	//getInput(redWire, "redDebug1.txt");
	//getInput(blackWire, "blackDebug1.txt");

	getSegments(redWire, red_horizontal_segments, red_vertical_segments);
	getSegments(blackWire, black_horizontal_segments, black_vertical_segments);

	getIntersections(red_vertical_segments, black_horizontal_segments, intersections);
	getIntersections(black_vertical_segments, red_horizontal_segments, intersections);

	
	sort(intersections.begin(), intersections.end());
	printPoints(intersections);
	getDistance(intersections);
	//cout << "---------------------------------------------------" << endl;
	//cout << "Red Vertical Segments:" << endl;
	//printSegments(red_vertical_segments);
	//cout << "---------------------------------------------------" << endl;
	//cout << "Black Horizontal Segments: " << endl;
	//printSegments(black_horizontal_segments);

	return 0;
}