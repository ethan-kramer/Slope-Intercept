// file: point.cpp
// Final Project
// by: Ethan Kramer
// org: COP 2001, CRN: 10410
// desc: implementation of a point class object
// --------------------------------------------------------
#include "point.h"


// constructors
// ---------------------------------------------------------------------------------
/**
default constructor
*/
Point::Point() 
{
	xCoordinate = 0;
	yCoordinate = 0;
}


/**
properties construcutor
*/
Point::Point(float x, float y) 
{
	this->xCoordinate = x;
	this->yCoordinate = y;
}

//accessors
// ---------------------------------------------------------------------------------
//getters
float Point::getXCoordinate() { return xCoordinate; }
float Point::getYCoordinate() { return yCoordinate; }

//setters
void Point::setXCoordinate(float value) { xCoordinate = value; }
void Point::setYCoordinate(float value) { yCoordinate = value; }
