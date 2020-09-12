
#ifndef SOURCE_HPP
#define SOURCE_HPP

#include<X11/Xlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include"myLCD.hpp"

enum  direction{horizontal = 0, vertical = 1};

class Hexagon {//: private axis  {
private:
	Colormap colormap;
	XColor green_col;
	const char green_bits[8]= "#00FF00";
public:
	static int edge; //length of side of cube

protected:
	int m_x_begin; //start point for x
	int m_y_begin; //start point for y
	
public:
	Hexagon(){}
	Hexagon(Display * disp, Window & wind,
		XEvent & evend, GC & gc, int x, int y, direction );
	Hexagon(const Hexagon & ){}
	virtual ~Hexagon(){}
};


class SevenSegmentDisplay : private Hexagon{
public:
	SevenSegmentDisplay() {}
	SevenSegmentDisplay(Display * disp, Window & wind, 
			    XEvent & event, GC & gc, int x, int y);
	virtual ~SevenSegmentDisplay(){}
};

class idSevenSegmentDisplay : private SevenSegmentDisplay {
public:
	
};

#endif //SOURCE_HPP
