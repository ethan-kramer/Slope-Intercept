// file: SlopeIntercept.cpp
// by: Ethan Kramer
// desc: Converts either two-point or point-slope form into slope intercept form, calculate line's length, angle and degrees, and graph the line
// --------------------------------------------------------
#include <iostream>				// console library for debugging
#define _USE_MATH_DEFINES			// enable M_PI
#include <math.h>				// for sqrt, pwr, atan2, M_PI

#include "slopeIntercept.h"
#include "fgcugl.h"				// fgcu OpenGL library
#include "point.h"				// point object
#include "line.h"				// line object


// function prototypes
Mode getProblem();
Point getPoint();
void get2Point(Line& line);
void getPointSlope(Line& line);
void calcLine(Mode menuChoice, Line& line);
void displayLine(Line line);
void display2Pt(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);


int main()
{
	Line line;
	bool again = false;

	// main converter loop
	while (!again)
	{
		Mode menuChoice = getProblem();

		if (menuChoice == TWO_POINT)
		{
			get2Point(line);
			calcLine(menuChoice, line);
			displayLine(line);
			display2Pt(line);
			displaySlopeIntercept(line);
			drawLine(line);
		}
		else if (menuChoice == POINT_SLOPE)
		{
			getPointSlope(line);
			calcLine(menuChoice, line);
			displayLine(line);
			displayPointSlope(line);
			displaySlopeIntercept(line);
			drawLine(line);

		}
		else if (menuChoice == EXIT)
		{
			again = true;
		}

	}


	std::cout << "See ya..." << std::endl;
	return 0;
}	// end main

/**
 display user menu(modes), prompt for menu choice, and return the mode value entered by user

 Parameters:

 Returns:
 Mode		menu choice selected by user
*/
Mode getProblem()
{
	int menuOption = 0;
	std::cout << "Select the form that you would like to convert to slope-intercept form: \n";
	std::cout << "\t 1) Two-point form (you know the two points of the line)\n"
		<< "\t 2) Point-slope form (you know the line's slope and one point)\n"
		<< "\t 3) Exit  \n";
	std::cin >> menuOption;

	switch (menuOption)
	{
	case 1:
		return TWO_POINT;
		break;
	case 2:
		return POINT_SLOPE;
		break;
	case 3:
		return EXIT;
		break;
	default:
		std::cout << "Please either enter a 1, 2, or 3. \n";
	}
}	// end getProblem


/**
 Prompt user for an X and Y coordinate and return them as a Point Structure

 Parameters:

 Returns:
 Point			x-coordinate and y-coordinate
*/
Point getPoint()
{
	float userX;
	float userY;
	Point point;

	std::cout << "Enter the x-coordinate: ";
	std::cin >> userX;
	point.setXCoordinate(userX);
	std::cout << "\nEnter the y-coordinate: ";
	std::cin >> userY;
	point.setYCoordinate(userY);
	return point;
}


/**
 Take a Line as a parameter and call getPoint two times to
 populate the two point properties of the line

 Parameters:
 Line				line structure inputted by the user

 Return:
 void
*/
void get2Point(Line& line)
{
	std::cout << "Enter your first point: \n\n";
	line.setFirstPoint(getPoint());
	std::cout << "\nEnter your second point: \n\n";
	line.setSecondPoint(getPoint());
}

void getPointSlope(Line& line)
{
	float slope;
	std::cout << "Enter a point for the line\n";
	line.setFirstPoint(getPoint());	// generates one of the point properties
	std::cout << "Enter your slope value: ";
	std::cin >> slope;
	line.setSlope(slope);
}


/**
 Call **INSERT METHODS HERE** to set properties of the line for method chosen by the user

 Parameters:

 Return:

*/
void calcLine(Mode menuChoice, Line& line)
{
	if (menuChoice == TWO_POINT)
	{
		line.setSlope(line.calcSlope());
	}
	else if (menuChoice == POINT_SLOPE)
	{
		line.setSecondPoint({ 0, line.slopeIntercept() });
	}
}


/**
 takes a Line and displays property values on the console

 Parameters:
 Line			line structure (two point structures)

 Returns:
 void
*/
void displayLine(Line line)
{
	std::cout << "Line: \n" << "\tPoint 1: (" << line.getFirstPoint().getXCoordinate() << ", " << line.getFirstPoint().getYCoordinate() << ")\n"
		<< "\tPoint 2: (" << line.getSecondPoint().getXCoordinate() << ", " << line.getSecondPoint().getYCoordinate() << ")\n"
		<< "\tSlope: " << line.getSlope() << "\n" << "\tY-Intercept: " << line.slopeIntercept() << "\n"
		<< "\tLength: " << line.lineLength() << "\n" << "\tAngle: " << line.lineAngle() << std::endl;

}


/**
 Takes a line and displays the two-point form of the line on the console

 Parameters:
 Line			line structure (two point structures)

 Returns:
 void
*/
void display2Pt(Line line)
{
	std::cout << "Two-Point Form: \n" << "\t" << "(" << line.getSecondPoint().getYCoordinate() << " - " << line.getFirstPoint().getYCoordinate() << ")" << "\n\t" <<
		"------------------------------------------\n"
		<< "\t(" << line.getSecondPoint().getXCoordinate() << " - " << line.getFirstPoint().getXCoordinate() << ")" << std::endl;
}


/**
 Takes a Line and displays the point-slope form of the line on the console

 Parameters:
 Line			line strucutre (two point structures)

 Returns:
 void
*/
void displayPointSlope(Line line)
{
	std::cout << "Point-Slope Form: \n" << "\t y - " << line.getFirstPoint().getYCoordinate() << " = " << line.getSlope() << "(x - " << line.getFirstPoint().getXCoordinate() << ")" << std::endl;
}


/**
 Takes a Line and displays the slope-intercept form of the line on the console

 Parameters:
 Line			line structure (two point structures)

 Returns:
 void
*/
void displaySlopeIntercept(Line line)
{
	std::cout << "Slope-Intercept form: \n" << "\t y = " << line.getSlope() << "x + " << line.slopeIntercept() << std::endl;
}


/**
 Takes a line and graphs the line on an OpenGL window with X and Y axis

 Parameters:
 Line			line structure (two point structures)

 Returns:
 void
*/
void drawLine(Line line)
{
	// main graph window
	fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	bool userExit = false;
	while (!userExit)
	{
		// for x-axis
		fgcugl::drawLine(0.0, (WINDOW_HEIGHT / 2), WINDOW_WIDTH, (WINDOW_HEIGHT / 2));

		// for y-axis
		fgcugl::drawLine((WINDOW_WIDTH / 2), 0.0, (WINDOW_WIDTH / 2), WINDOW_HEIGHT);

		// for user inputted line
		fgcugl::drawLine(line.getFirstPoint().getXCoordinate() + (WINDOW_WIDTH / 2), line.getFirstPoint().getYCoordinate() + (WINDOW_HEIGHT / 2), line.getSecondPoint().getXCoordinate() + (WINDOW_WIDTH / 2), line.getSecondPoint().getYCoordinate() + (WINDOW_HEIGHT / 2));

		fgcugl::windowPaint();

		fgcugl::getEvents();

		// closes program if window is closed by user
		userExit = userExit || fgcugl::windowClosing();
	}
	fgcugl::cleanup();
}
