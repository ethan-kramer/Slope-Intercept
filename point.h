// file: point.h
// Final Project
// by: Ethan Kramer
// org: COP 2001, CRN: 10410
// desc: declaration of a point class object
// --------------------------------------------------------
#ifndef POINT_H
#define POINT_H


class Point {
public:
	// constructors
	Point();
	Point(float x, float y);

	//accessors
	//getters
	float getXCoordinate();
	float getYCoordinate();

	//setters
	void setXCoordinate(float value);
	void setYCoordinate(float value);


private:
	int xCoordinate;
	int yCoordinate;
};


#endif // POINT_H