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
	int length = 0;
	int rank = 0;
	char wireColor = ' ';
};
class PointAndIntersection {
public:
	Point intersection;
	Segment verticalSeg;
	Segment horizontalSeg;
};

bool withinRange(int min, int max, int num)
{
	/*
		1. Check if "num" is within range from "min" to "max."
		2. If the "min" value passed is larger than the "max" value passed
		   we wil swap them so the if statement which reads "if (num >= min && num <= max)"
		   will make sense.
	*/
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
void getInput(vector<string>& wire, string fileName) //Get the inputs from the specified text file
{
	string input;
	ifstream readFromFile(fileName);
	while (getline(readFromFile, input, ','))
		wire.push_back(input);
}
void getSegments(vector<string>& wire, vector<Segment>& horizontal, vector<Segment>& vertical, char wireColor) //Find all the segments from the given wire
{
	/*
	  while(explanationMakesSense)
	  {
		0. Create variables needed. "move" holds how much to move in the direction of "dir" and "seg" holds the segment
		   we would like to keep track of in our vector of segments. "holder" will hold the string from which we will
		   extract the direction and movement from.
		1. Get the i-th instruction from vector of strings "wire" and save that string to holder.
		2. Save the first character of holder(holder[0]) to dir (stands for "direction").
		3. Erase the first character of holder so we are left with just a string of numbers in holder.
		4. Convert the string of numbers to an integer and save it to move.
		5. Check dir against multiple if statements and choose appropriate one. We will use dir = 'R' as an example.
		6. 'R' means we will go to the right. Our previous value, before the change, is unaltered. In this case, our
		   previous point is seg.start. The current value, the value after the change is the previous
		   value incremented by the value in "move." In this case, current is seg.end.
		7. Since we are moving to the right, the X value is the ONLY thing that changes. Everything else stays the same.
		   Going to the left or right will result in a segment that is horizontal. Vertical segments are the result of
		   going up or down. In this example, we push the changes to the vector of horizontal segments.
		8. Save the current (seg.end) point to the previous (seg.start) so we can update the next run through of
		   the for loop with the correct start and end point. In our example, seg.start.x = seg.end.x because,
		   remember, going to the left OR right, will result in a change to the x-values ONLY.
		9. Repeat steps but with new values found in the vector of strings "wires."
	   }

	   if (!explanationMakesSense)
			cout << "oof" << endl;
	*/


	int move = 0;
	int place = 0;
	char dir = ' ';
	char color = ' ';
	Segment seg;
	string holder = " ";	
	if (wireColor == 'R')
		color = wireColor;
	else
		color = wireColor;
	for (int i = 0; i < wire.size(); i++)
	{
		holder = wire[i];
		dir = holder[0];
		holder.erase(0, 1);
		move = stoi(holder);
		if (dir == 'U')
		{
			seg.end.y += move;
			seg.rank = i;
			seg.wireColor = color;
			vertical.push_back(seg);
			seg.start.y = seg.end.y;
		}
		else if (dir == 'D')
		{
			seg.end.y -= move;
			seg.rank = i;
			seg.wireColor = color;
			vertical.push_back(seg);
			seg.start.y = seg.end.y;
		}
		else if (dir == 'L')
		{
			seg.end.x -= move;
			seg.rank = i;
			seg.wireColor = color;
			horizontal.push_back(seg);
			seg.start.x = seg.end.x;
		}
		else if (dir == 'R')
		{
			seg.end.x += move;
			seg.rank = i;
			seg.wireColor = color;
			horizontal.push_back(seg);
			seg.start.x = seg.end.x;
		}
		else
			cout << "I don't know how we got here buddy" << endl;
	}
}
void getAllSegments(vector<string>& wire, vector<Segment>& segments) //Find all the segments from the given wire
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
			seg.length += move;
			segments.push_back(seg);
			seg.length = 0;
			seg.start.y = seg.end.y;
		}
		else if (dir == 'D')
		{
			seg.end.y -= move;
			seg.length += move;
			segments.push_back(seg);
			seg.length = 0;
			seg.start.y = seg.end.y;
		}
		else if (dir == 'L')
		{
			seg.end.x -= move;
			seg.length += move;
			segments.push_back(seg);
			seg.length = 0;
			seg.start.x = seg.end.x;
		}
		else if (dir == 'R')
		{
			seg.end.x += move;
			seg.length += move;
			segments.push_back(seg);
			seg.length = 0;
			seg.start.x = seg.end.x;
		}
		else
			cout << "I don't know how we got here buddy" << endl;
	}
}
void getIntersections(vector<Segment>& vertical, vector<Segment>& horizontal, vector<Point>& intersections)
{
	/*
		0. Create needed variables. "max" and "min" will hold the minimum and maximum values of the
		   range we want to look at. "num" is the number that we want to know if it lies
		   within "min" and "max." "inter" is a "Point" object that will hold the point at which the
		   horizontal and vertical segments cross, if such a point exists.
		1. Vetical segments will only ever cross horizontal segments.
		2. First, we need to know if the vertical segments x-values are within the range of the x-values of the
		   horizontal segments. Note, vertical segments will ALWAYS have the same x-values in their
		   starting and ending points. Horizontal segments will ALWAYS have the same y-values in their
		   starting and ending points.
		3. If the vertical segments x-values are within the range of the horizontal segments x-values we continue.
		4. Now we check if the horizontal segments y-values are within range of the vertical segments y-values.
		   If this is true, we save the x-values of the vertical segment and save the y-values of the horizontal segment.
		   We have found an intersection!
	*/
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
void getPAI(vector<Segment>& vertical, vector<Segment>& horizontal, vector<PointAndIntersection>& intersections)
{
	/*
		0. Create needed variables. "max" and "min" will hold the minimum and maximum values of the
		   range we want to look at. "num" is the number that we want to know if it lies
		   within "min" and "max." "inter" is a "Point" object that will hold the point at which the
		   horizontal and vertical segments cross, if such a point exists.
		1. Vetical segments will only ever cross horizontal segments.
		2. First, we need to know if the vertical segments x-values are within the range of the x-values of the
		   horizontal segments. Note, vertical segments will ALWAYS have the same x-values in their
		   starting and ending points. Horizontal segments will ALWAYS have the same y-values in their
		   starting and ending points.
		3. If the vertical segments x-values are within the range of the horizontal segments x-values we continue.
		4. Now we check if the horizontal segments y-values are within range of the vertical segments y-values.
		   If this is true, we save the x-values of the vertical segment and save the y-values of the horizontal segment.
		   We have found an intersection!
	*/
	PointAndIntersection inter;
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
					inter.horizontalSeg = horizontal[j];
					inter.verticalSeg = vertical[i];
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
int getSmallestPath(vector<PointAndIntersection>& pai, vector<Segment>& red, vector<Segment> black)
{
	int totalBlackSegmentLength = 0;
	int totalRedSegmentLength = 0;
	int totalSegmentLength = 0;
	int currentRank = 0;
	int answer = 0;
	int subtract = 0;
	for (int i = 0; i < pai.size(); i++)
	{
		totalBlackSegmentLength = 0;
		totalRedSegmentLength = 0;
		totalSegmentLength = 0;
		if (pai[i].horizontalSeg.wireColor == 'B')
		{
			currentRank = pai[i].horizontalSeg.rank;
		//	cout << "CurrentRank1: " << currentRank << endl << "-------------BlackSegLength-------------" << endl;
			for (int j = 0; j < currentRank; j++)
			{
				totalBlackSegmentLength += black[j].length;
		//		cout << "TotalBlackForLoop: " << totalBlackSegmentLength << endl;
			}
			subtract = abs(abs(pai[i].intersection.x) - abs(pai[i].horizontalSeg.start.x));
			//cout << "----------------------------------------" << endl << "Subtract: " << subtract << endl;
			totalBlackSegmentLength += subtract;
		//	cout << "TotalBlack: " << totalBlackSegmentLength << endl;


			currentRank = pai[i].verticalSeg.rank;
			//cout << "CurrentRank2: " << currentRank << endl << "-------------RedSegLength-------------" << endl;
			for (int j = 0; j < currentRank; j++)
			{
				totalRedSegmentLength += red[j].length;
			//	cout << "TotalRedLoop: " << totalRedSegmentLength << endl;
			}
			subtract = abs(abs(pai[i].intersection.y) - abs(pai[i].verticalSeg.start.y));
			//cout << "----------------------------------------" << endl << "Subtract: " << subtract << endl;
			totalRedSegmentLength += subtract;
			//cout << "TotalRed: " << totalRedSegmentLength << endl;

			totalSegmentLength = totalBlackSegmentLength + totalRedSegmentLength;
		}
		else if (pai[i].horizontalSeg.wireColor == 'R')
		{
			currentRank = pai[i].horizontalSeg.rank;
			//cout << "CurrentRank1: " << currentRank << endl << "-------------RedSegLength-------------" << endl;
			for (int j = 0; j < currentRank; j++)
			{
				totalRedSegmentLength += red[j].length;
			//	cout << "TotalRedLoop: " << totalRedSegmentLength << endl;
			}
			subtract = abs(abs(pai[i].intersection.x) - abs(pai[i].horizontalSeg.start.x));
			//cout << "----------------------------------------" << endl << "Subtract: " << subtract << endl;
			totalRedSegmentLength += subtract;
			//cout << "TotalRed: " << totalRedSegmentLength << endl;

			currentRank = pai[i].verticalSeg.rank;
			//cout << "CurrentRank2: " << currentRank << endl << "-------------BlackSegLength-------------" << endl;
			for (int j = 0; j < currentRank; j++)
			{
				totalBlackSegmentLength += black[j].length;
			//	cout << "TotalBlackForLoop: " << totalBlackSegmentLength << endl;
			}
			subtract = abs(abs(pai[i].intersection.y) - abs(pai[i].verticalSeg.start.y));
			//cout << "----------------------------------------" << endl << "Subtract: " << subtract << endl;
			totalBlackSegmentLength += subtract;\
			//cout << "TotalBlack: " << totalBlackSegmentLength << endl;

			totalSegmentLength = totalBlackSegmentLength + totalRedSegmentLength;
		}
		else
			cout << "oof" << endl;
		if (i == 0) { answer = totalSegmentLength; }
		if (answer > totalSegmentLength) { answer = totalSegmentLength; }
	}

	return answer;
}
void printSegments(vector<Segment>& segments) //Used for debugging. Wanted to make sure segments were saved correctly in getSegments().
{
	for (int i = 0; i < segments.size(); i++)
		cout << "(" << segments[i].start.x << ", " << segments[i].start.y << ") ("
		<< segments[i].end.x << ", " << segments[i].end.y << ")" << " Rank: " << segments[i].rank << endl;
}
void printSegmentsPart2(vector<Segment>& segments) //Used for debugging. Wanted to make sure segments were saved correctly in getSegments().
{
	for (int i = 0; i < segments.size(); i++)
		cout << "Start: (" << segments[i].start.x << ", " << segments[i].start.y << ") End: ("
		<< segments[i].end.x << ", " << segments[i].end.y << ")" << " Length: " << segments[i].length
		<< " Rank: " << i << endl;
}
void printPoints(vector<Point>& points) //Used for debugging. Wanted to make sure my intersections were saved correctly from getIntersections().
{
	for (int i = 0; i < points.size(); i++)
		cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
}
void printPAI(vector<PointAndIntersection>& pai)
{
	for (int i = 0; i < pai.size(); i++)
		cout << "Point: (" << pai[i].intersection.x << ", " << pai[i].intersection.y << ")" <<
			" hRank: " << pai[i].horizontalSeg.wireColor << pai[i].horizontalSeg.rank << " vRank: " <<
		pai[i].verticalSeg.wireColor << pai[i].verticalSeg.rank << endl;
}

int main()
{
	/*
		1. I made an assumption that horizontal points from the red line could not cross horizontal points
		   from the black wire (i.e. multiple points being crossed versus just one point.
		2. Assumption turned out to be okay for the first part of day 3.

	*/

	vector <string> redWire, blackWire;
	vector <Segment> red_horizontal_segments, red_vertical_segments;
	vector <Segment> black_horizontal_segments, black_vertical_segments;
	vector <Segment> redSegments, blackSegments;
	vector <PointAndIntersection> pai;
	vector <Point> intersections;

	getInput(redWire, "redDebug1.txt");
	getInput(blackWire, "blackDebug1.txt");

	//getInput(redWire, "redWire.txt");
	//getInput(blackWire, "blackWire.txt");

	getSegments(redWire, red_horizontal_segments, red_vertical_segments, 'R');
	getSegments(blackWire, black_horizontal_segments, black_vertical_segments, 'B');

	getAllSegments(redWire, redSegments);
	getAllSegments(blackWire, blackSegments);

	getPAI(red_vertical_segments, black_horizontal_segments, pai);
    getPAI(black_vertical_segments, red_horizontal_segments, pai);


	//cout << "------------------RED HOR----------------------------" << endl;
	//printSegments(red_vertical_segments);
	//printSegments(red_horizontal_segments);
	//cout << "----------------------BLACK VERT------------------------" << endl;
	//printSegments(black_vertical_segments);
	//printSegments(black_horizontal_segments);

	cout << "Answer: " << getSmallestPath(pai, redSegments, blackSegments) << endl;
	cout << "-----------------------------------------PAI-------------------------------------------------" << endl;
	printPAI(pai);
	cout << "-----------------------------------------ALL RED SEGMENTS------------------------------------" << endl;
	printSegmentsPart2(redSegments);
	cout << "-----------------------------------------ALL BLACK SEGMENTS----------------------------------" << endl;
	printSegmentsPart2(blackSegments);

	//getIntersections(red_vertical_segments, black_horizontal_segments, intersections);
	//getIntersections(black_vertical_segments, red_horizontal_segments, intersections);

	//printPoints(intersections);
	//getDistance(intersections);

	return 0;
}