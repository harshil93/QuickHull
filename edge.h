
#ifndef _EDGE_H
#define _EDGE_H


#include "Point.h"
#include <vector>
using namespace std;

class edge{
private:
	Point p1;
	Point p2;
public:
	edge(Point P1, Point P2)
	{
		p1 = P1;
		p2 = P2;
	}
	edge()
	{
	}
	Point getPoint(int i)
	{
		if (i == 1)
			return p1;
		else
			return p2;
	}
	//return the farthest point from edge
	Point getMax(vector<Point> points)
	{
		double max = distance(points[0]);
		int index = 0;
		for (int i = 1; i<points.size(); i++)
		{
			double temp = distance(points[i]);
			if (temp > max)
			{
				max = temp;
				index = i;
			}
		}
		return points[index];
	}

	//distance of edge and point
	double distance(Point p)
	{
		double a, b, c;
		a = distance(p, p1);
		b = distance(p, p2);
		c = distance(p1, p2);
		double s = (a + b + c) / 2;
		double Area = sqrt(s*(s - a)*(s - b)*(s - c));
		return 2 * Area / c;
	}

	//distance between two points
	double distance(Point x, Point y)
	{
		return sqrt(pow((x.getX() - y.getX()), 2) + pow((x.getY() - y.getY()), 2));
	}
};

#endif // !1