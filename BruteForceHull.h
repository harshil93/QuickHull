#ifndef _BRUTEFORCEHULL_H
#define _BRUTEFORCEHULL_H


#include "edge.h"

class BruteForceHull
{
private:
	//Random points
	vector<Point> points;
	//Final boundary Point
	vector<Point> boundaryPoints;
public:
	void run();
	vector<Point> getBoundaryPoints();
	void setPoints(vector<Point>);
	void generateHull();
	bool isLeft(edge e, Point p);
};

#endif // !1