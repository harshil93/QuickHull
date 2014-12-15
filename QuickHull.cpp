#include "QuickHull.h"
#include <time.h>
#include <set>
using namespace std;


void QuickHull::run()
{
	boundaryPoints.clear();
	int minIndex = 0;
	int maxIndex = 0;
	double miX = points[0].getX();
	double maX = points[0].getX();
	for (int i = 0; i<points.size(); i++)
	{
		Point temp = points[i];
		if (temp.getX() > maX)
		{
			maxIndex = i;
			maX = temp.getX();
		}
		else if (temp.getX() < miX)
		{
			minIndex = i;
			miX = temp.getX();
		}
	}

	boundaryPoints.push_back(points[maxIndex]);
	boundaryPoints.push_back(points[minIndex]);

	vector<Point> left; // points to the left of edge
	vector<Point> right; // to the right of edge

	edge seg = edge(points[maxIndex], points[minIndex]);
	edge revseg = edge(points[minIndex], points[maxIndex]); // handling the initial case when the line has to be reversed

	for (int i = 0; i<points.size(); i++)
	{
		if (isLeft(seg, points[i]))
			left.push_back(points[i]);
		else
			right.push_back(points[i]);
	}
	generateHull(seg,left);
	generateHull(revseg, right);
}

vector<Point> QuickHull::getPoints()
{
	return points;
}

void QuickHull::setPoints(vector<Point> _points)
{
	points = _points;
}
vector<Point> QuickHull::getBoundaryPoints()
{
	set<Point> s(boundaryPoints.begin(), boundaryPoints.end());
	vector<Point> res;
	for (set<Point>::iterator it = s.begin(); it != s.end(); it++)
	{
		res.push_back(*it);
	}
	return res;
}

// reverse edge and return;
edge revEdge(edge e){
	return edge(e.getPoint(2), e.getPoint(1));
}


// the recursive function generating hull for the given edge and points
void QuickHull::generateHull(edge seg, vector<Point> points)
{
	if (points.size() == 0)
		return;
	vector<Point> left;
	vector<Point> right;

	Point p1 = seg.getMax(points);
	removePoints(seg, p1); // removing points in triangle
	boundaryPoints.push_back(p1);

	edge e1 = edge(p1, seg.getPoint(1));
	for (int i = 0; i<points.size(); i++)
	{
		if (points[i] != e1.getPoint(1) && points[i] != e1.getPoint(2) && !isLeft(e1, points[i]))
			right.push_back(points[i]);
	}
	generateHull(revEdge(e1), right);

	edge e2 = edge(p1, seg.getPoint(2));
	for (int i = 0; i<points.size(); i++)
	{
		if (points[i] != e2.getPoint(1) && points[i] != e2.getPoint(2) && isLeft(e2, points[i]))
			left.push_back(points[i]);
	}
	generateHull(e2, left);
	
}


double QuickHull::sign(Point p1, Point p2, Point p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}


bool QuickHull::isPointInsideTriangle(Point v1, Point v2, Point v3, Point pt)
{
	bool b1, b2, b3;
	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;
	return ((b1 == b2) && (b2 == b3));
}
void QuickHull::removePoints(edge e, Point p)
{
	vector<Point> temp;
	for (int i = 0; i<points.size(); i++)
	{
		if (!isPointInsideTriangle(e.getPoint(1), e.getPoint(2), p, points[i]))
		{
			temp.push_back(points[i]);
		}
	}
	points = temp;
}

bool QuickHull::isLeft(edge e, Point p)
{
	return ((e.getPoint(2).getX() - e.getPoint(1).getX())*(p.getY() - e.getPoint(1).getY())) >
		((e.getPoint(2).getY() - e.getPoint(1).getY())*(p.getX() - e.getPoint(1).getX()));
}