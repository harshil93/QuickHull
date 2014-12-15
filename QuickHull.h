#ifndef _QUICKHULL_H
#define _QUICKHULL_H

#include "edge.h"
class QuickHull
{
private:
	// all the points
	vector<Point> points;
	//Final boundary Point
	vector<Point> boundaryPoints;
public:
	// runs the algo
	void run();
	vector<Point> getPoints();
	void setPoints(vector<Point>);

	// gives the final convex hull
	vector<Point> getBoundaryPoints();
	void generateHull(edge, vector<Point> points);

	// sign depending on the area of triangle
	double sign(Point p1, Point p2, Point p3);

	// finds out whether the point is in the triangle or not
	bool isPointInsideTriangle(Point v1, Point v2, Point v3, Point pt);

	// remove points which are inside triangle formed by the edge points and given point
	void removePoints(edge e, Point p);

	// finds out whether the point is in left side or not
	bool isLeft(edge e, Point p);

};

#endif // !1