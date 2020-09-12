#include "source.hpp" 

//it is drawing facis of a cube 

int Hexagon::edge = 7; //length of side of LED 

Hexagon::Hexagon(Display * m_display, Window & m_window,
		XEvent & m_event, GC & m_gc,  int xx, int yy, direction dir)
{
//	int edge = 7; //length of side of cube interesting pics	
	axis s_point(xx, yy, 0);	
	//left angle line
	if (vertical == dir){
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x, s_point.m_a_y, 
		  s_point.m_a_x - edge, s_point.m_a_y + edge);	

	//right angle line	
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x, s_point.m_a_y, 
		  s_point.m_a_x + edge, s_point.m_a_y + edge);	
	
	//left horizontal line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x - edge, s_point.m_a_y + edge, 
		  s_point.m_a_x - edge, s_point.m_a_y + 3*edge);	

	//right horizontal line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x + edge, s_point.m_a_y + edge, 
		  s_point.m_a_x + edge, s_point.m_a_y + 3*edge);	

	//right angle line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x + edge, s_point.m_a_y + 3*edge, 
		  s_point.m_a_x , s_point.m_a_y + 4*edge);	
	
	//right angle line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x - edge, s_point.m_a_y + 3*edge, 
		  s_point.m_a_x, s_point.m_a_y + 4*edge);	
	}  else {

		XSetForeground(m_display, m_gc, green_col.pixel);		
		XDrawLine(m_display, m_window, m_gc,
			  s_point.m_a_x, s_point.m_a_y, 
			  s_point.m_a_x + edge, s_point.m_a_y - edge);	

		//right angle line	
		XSetForeground(m_display, m_gc, green_col.pixel);	
		XDrawLine(m_display, m_window, m_gc,
			  s_point.m_a_x + edge, s_point.m_a_y - edge, 
			  s_point.m_a_x + 3*edge, s_point.m_a_y - edge);	
	
		//left horizontal line 
		XSetForeground(m_display, m_gc, green_col.pixel);		
		XDrawLine(m_display, m_window, m_gc,
			  s_point.m_a_x + 3*edge, s_point.m_a_y - edge, 
			  s_point.m_a_x + 4* edge, s_point.m_a_y);	

		//right horizontal line //
		XSetForeground(m_display, m_gc, green_col.pixel);		
		XDrawLine(m_display, m_window, m_gc,
			  s_point.m_a_x + 4 * edge, s_point.m_a_y, 
			  s_point.m_a_x + 3 * edge, s_point.m_a_y + edge);	

		//right angle line
		XSetForeground(m_display, m_gc, green_col.pixel);		
		XDrawLine(m_display, m_window, m_gc,
			  s_point.m_a_x + 3 * edge, s_point.m_a_y + edge, 
			  s_point.m_a_x + edge , s_point.m_a_y + edge);	
	
		//right angle line
		XSetForeground(m_display, m_gc, green_col.pixel);		
		XDrawLine(m_display, m_window, m_gc,
			  s_point.m_a_x + edge, s_point.m_a_y + edge, 
			  s_point.m_a_x, s_point.m_a_y );	
	}
}

SevenSegmentDisplay::SevenSegmentDisplay(Display * disp, Window & wind, 
			    XEvent & event, GC & gc, int x, int y)
{
	Hexagon(disp, wind, event, gc, x, y, horizontal); //A	
	Hexagon(disp, wind, event, gc, x, y, vertical);  // F
	Hexagon(disp, wind, event, gc, x + 4*edge, y, vertical);// B
	Hexagon(disp, wind, event, gc, x, y+ 4 * edge, vertical); // E
	Hexagon(disp, wind, event, gc, x + 4*edge, y+4*edge, vertical); // C
	Hexagon(disp, wind, event, gc, x, y+4*edge, horizontal);//G
	Hexagon(disp, wind, event, gc, x, y+8*edge, horizontal); //D
}



