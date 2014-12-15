#include <vector>
#include "Point.h"
#include <time.h>
using namespace std;


static class RandomPoints{
public:
	// Generate n random points
	static vector<Point> generateRandomPoints(int n){
		srand(time(NULL));
		vector<Point> res;
		for (int i = 0; i < n; i++)
			res.push_back(Point((rand() % 500), (rand() % 500)));
		return res;
	}

	// a testing function to generate some sample points

	static vector<Point> generateSamplePoints(){
		vector<Point> res;
		
		res.push_back(Point(309,251));
		res.push_back(Point(402,383));
		res.push_back(Point(172,350));
		res.push_back(Point(232,253));
		res.push_back(Point(78,52));
		res.push_back(Point(280,105));
		res.push_back(Point(25,180));
		res.push_back(Point(412,457));
		res.push_back(Point(345,276));
		res.push_back(Point(41,156));



		return res;

	}
};