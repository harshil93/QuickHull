#ifndef _POINT_H
#define _POINT_H

#include <math.h>
#include <vector>
#include <cstdlib>
#include <cmath>
class Point
{
private:
	float x;
	float y;
public:
	Point(float x, float y)
	{
		setX(x);
		setY(y);
	}

	

	Point()
	{
		x = 0;
		y = 0;
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void setX(float X)
	{
		x = X;
	}
	void setY(float Y)
	{
		y = Y;
	}
	Point sub(Point p)
	{
		p.setX(x - p.getX());
		p.setY(y - p.getY());
		return p;
	}
	Point add(Point p)
	{
		p.setX(x + p.getX());
		p.setY(y + p.getY());
		return p;
	}
	Point mul(float val)
	{
		Point p;
		p.setX(x*val);
		p.setY(y*val);
		return p;
	}

	friend bool operator< (const Point &cC1,const Point &cC2){
		if (cC1.x == cC2.x){
			return cC1.y < cC2.y;
		}
		return cC1.x < cC2.x;
	}

	friend bool operator != (const Point &a, const Point &b){
		return !(a.x == b.x && a.y == b.y);
	}
};

#endif // !1