#include "BruteForceHull.h"
#include <set>
using namespace std;

void BruteForceHull::run(){
	generateHull();
}

vector<Point> BruteForceHull::getBoundaryPoints(){
	set<Point> s(boundaryPoints.begin(), boundaryPoints.end());
	vector<Point> res;
	for (set<Point>::iterator it = s.begin(); it != s.end(); it++)
	{
		res.push_back(*it);
	}
	return res;

	
}

void BruteForceHull::setPoints(vector<Point> _points){
	points = _points;
}

void BruteForceHull::generateHull(){
	for (size_t i = 0; i < points.size(); i++)
	{
		for (size_t j = i + 1; j < points.size(); j++)
		{
			bool isFirst = true;
			bool flag = true;
			bool sign;
			edge e(points[i], points[j]);
			for (size_t k = 0; k < points.size(); k++)
			{
				if (k != i && k != j){
					if (isFirst){
						sign = isLeft(e, points[k]);
						isFirst = false;
					}
					else{
						if (isLeft(e, points[k]) != sign){
							flag = false;
							break;
						}
					}
				}
			}

			if (flag){
				boundaryPoints.push_back(points[i]);
				boundaryPoints.push_back(points[j]);

			}
		}
	}
}

bool BruteForceHull::isLeft(edge e, Point p){
	return ((e.getPoint(2).getX() - e.getPoint(1).getX())*(p.getY() - e.getPoint(1).getY())) >
		((e.getPoint(2).getY() - e.getPoint(1).getY())*(p.getX() - e.getPoint(1).getX()));
}