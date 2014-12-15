#include "QuickHull.h"
#include "BruteForceHull.h"
#include "RandomPoints.h"
#include <iostream>
#include <set>
#include <fstream>
#include <string>
using namespace std;

int main(){
	vector<Point> points;

	cout << "Enter 0 for file input or 1 for random" << endl;
	int flag; cin >> flag;
	if (flag == 0){

		ifstream in;
		cout << "Enter filename" << endl;
		string filename; cin >> filename;

		in.open(filename.c_str());
		
		int n; in >> n;
		for (size_t i = 0; i < n; i++)
		{
			float x, y;
			in >> x >> y;
			points.push_back(Point(x, y));
		}
	}
	else{
		cout << "Bruteforce will take a lot of time for num of points > 100" << endl;
		cout << "Enter no. of points" << endl;
		
		int n;
		cin >> n;
		RandomPoints r;
		points = r.generateRandomPoints(n);
	}

	QuickHull qh;
	BruteForceHull bh;
	
	qh.setPoints(points);
	qh.run();

	// qhboundaryPts contains convex hull for quickhull algorithm
	vector<Point> qhboundaryPts = qh.getBoundaryPoints();

	bh.setPoints(points);
	bh.run();

	// bhboundaryPts contains convex hull for bruteforce algorithm
	vector<Point> bhboundaryPts = bh.getBoundaryPoints();

	cout << "Using quickhull algo" << endl;
	for (size_t i = 0; i < qhboundaryPts.size(); i++)
	{
		cout << qhboundaryPts[i].getX() << " " << qhboundaryPts[i].getY() << endl;
	}
	cout << endl << endl;

	cout << "Using bruteforce algo" << endl;
	for (size_t i = 0; i < bhboundaryPts.size(); i++)
	{
		cout << bhboundaryPts[i].getX() << " " << bhboundaryPts[i].getY() << endl;
	}
	

	return 0;
}