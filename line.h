// file: line.h
// Final Project
// by: Ethan Kramer
// org: COP 2001, CRN: 10410
// desc: declaration of a line class object
// --------------------------------------------------------
#include "point.h"


#ifndef LINE_H
#define LINE_H


class Line {
public:
	//constructors
	Line();
	Line(Point firstPoint, Point secondPoint, float slope, float yIntercept, float length, float angle);

	//accessors
	//getters
	Point getFirstPoint();
	Point getSecondPoint();
	float getSlope();

	//setters
	void setFirstPoint(Point value);
	void setSecondPoint(Point value);
	void setSlope(float value);

	//member methods
	float calcDiffX();
	float calcDiffY();
	float calcSlope();
	float slopeIntercept();
	float lineLength();
	float lineAngle();
	

private:
	Point firstPoint;
	Point secondPoint;
	float slope;
	float yIntercept;
	float length;
	float angle;
};

#endif // LINE_H