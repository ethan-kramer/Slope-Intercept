// file: slopeIntercept.h
// Final Project
// by: Ethan Kramer
// org: COP 2001, CRN: 10410
// desc: main header file for Slope Intercept Project
// --------------------------------------------------------

#ifndef SLOPE_INTERCEPT_H
#define SLOPE_INTERCEPT_H

#include <string>				// for window title

//Global Constants
//-----------------------------------------------------------------------------------------
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Slope Intercept Conversion";

// Main Menu enum
enum Mode {
	TWO_POINT = 1,	// so numbers match with outputted menu options
	POINT_SLOPE,
	EXIT
};

#endif // SLOPE_INTERCEPT_H

