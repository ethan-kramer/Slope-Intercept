// file: line.cpp
// Final Project
// by: Ethan Kramer
// org: COP 2001, CRN: 10410
// desc: implementation of a line class object
// ---------------------------------------------------------------------------------
#include <iostream>				// console library for debugging
#define _USE_MATH_DEFINES		// enable M_PI
#include <math.h>				// for sqrt, pwr, atan2, M_PI

#include "line.h"


//constructors
// ---------------------------------------------------------------------------------
/**
default constructor
*/
Line::Line() 
{
	firstPoint;
	secondPoint;
	slope;
	yIntercept;
	length;
	angle;
}

/**
properties constructor
*/
Line::Line(Point firstPoint, Point secondPoint, float slope, float yIntercept, float length, float angle) 
{
	this->firstPoint = firstPoint;
	this->secondPoint = secondPoint;
	this->slope = slope;
	this->yIntercept = yIntercept;
	this->length = length;
	this->angle = angle;
}


//accessors
// ---------------------------------------------------------------------------------
//getters
Point Line::getFirstPoint() { return firstPoint; }
Point Line::getSecondPoint() { return secondPoint; }
float Line::getSlope() { return slope; }


//setters
void Line::setFirstPoint(Point value) { firstPoint = value; }
void Line::setSecondPoint(Point value) { secondPoint = value; }
void Line::setSlope(float value) { slope = value; }


//member methods
// ---------------------------------------------------------------------------------
/**
Calculate difference between x coordinates

Parameters:

Returns:
difference between x coordinates
*/
float Line::calcDiffX()
{
	float difference = secondPoint.getXCoordinate() - firstPoint.getXCoordinate();
	return difference;
}


/**
Calculate difference between y coordinates

Parameters:

Returns:
float			difference between y coordinates
*/
float Line::calcDiffY() { return secondPoint.getYCoordinate() - firstPoint.getYCoordinate(); }



/**
Calculate slope of line

Parameters:

Returns:
float			slope of line
*/
float Line::calcSlope() { return calcDiffY() / calcDiffX(); }



/**
 Takes a point and slope parameter and returns the y-intercept as a float

 Parameters:
 Point			point structure (x and y coordinates)
 float			slope of a line

 Returns:
 float			y-intercept of line
*/
float Line::slopeIntercept()
{
	float yIntercept = firstPoint.getYCoordinate() - (slope * firstPoint.getXCoordinate());
	return yIntercept;
}


/**
 Takes a Line and returns the distance between two points as a float

 Parameters:
 Line			line structure (two points)

 Returns:
 float			distance between two points
*/
float Line::lineLength()
{
	float distance;
	distance = sqrt(pow(secondPoint.getXCoordinate() - firstPoint.getXCoordinate(), 2) + pow(secondPoint.getYCoordinate() - firstPoint.getYCoordinate(), 2));
	return distance;
}


/**
 Takes a Line and returns the line's angle from the top of the y axis, or zero degrees

 Parameters:

 Returns:
 float			angle of line structure
*/
float Line::lineAngle()
{
	float lineAngle;
	float radians = std::atan2(secondPoint.getYCoordinate() - firstPoint.getYCoordinate(), secondPoint.getXCoordinate() - firstPoint.getXCoordinate());
	float angle = radians * 180.0 / M_PI;
	float degrees = 90.0 - angle;
	lineAngle = (degrees > 0.0 ? degrees : degrees + 360.0);

	return lineAngle;
}