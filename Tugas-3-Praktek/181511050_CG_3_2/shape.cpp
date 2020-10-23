#include "stroke.h"
#include "shape.h"

void rhombush(int x1, int y1, int adjacent, int opposite, int color, int thick, char stroke){
	
	// Hypotenuse a
	makeLineStrokeThickVertical(x1, y1, x1+opposite, y1+adjacent, color, thick, stroke);
	// Hypotenuse b
	makeLineStrokeThickVertical(x1, y1, x1+opposite, y1-adjacent, color, thick, stroke);
	// Hypotenuse c
	makeLineStrokeThickVertical(x1+(opposite*2), y1, x1+opposite, y1+adjacent, color, thick, stroke);
	// Hypotenuse d
	makeLineStrokeThickVertical(x1+(opposite*2), y1, x1+opposite, y1-adjacent, color, thick, stroke);
}

void angledtriangle(int x1, int y1, int adjacent, int opposite, int color, int thick, char stroke){
	
	// Adjacent
	makeLineStrokeThickVertical(x1, y1, x1, y1+adjacent, color, thick, stroke);
	// Hypotenuse
	makeLineStrokeThickVertical(x1, y1, x1+opposite, y1+adjacent, color, thick, stroke);
	// Oppsite
	makeLineStrokeThickHorizontal(x1, y1+adjacent, x1+opposite, y1+adjacent, color, thick, stroke);
}

void trapezoid(int x1, int y1, int x2, int y2, int width1, int width2, int color, int thick, char stroke){
	
	// left
	makeLineStrokeThickVertical(x1, y1, x2, y2, color, thick, stroke);
	// right
	makeLineStrokeThickVertical(x1+width1, y1, x2+width2, y2, color, thick, stroke);
	// top
	makeLineStrokeThickHorizontal(x1, y1, x1+width1, y1, color, thick, stroke);
	// botton
	makeLineStrokeThickHorizontal(x2, y2, x2+width2, y2, color, thick, stroke);	
}

void parallelogram(int x1, int y1, int b, int height, int width, int color, int thick, char stroke){
	
	// left 
	makeLineStrokeThickVertical(x1, y1, x1+b, y1+width, color, thick, stroke);
	// right
	makeLineStrokeThickVertical(x1+height, y1, x1+height+b, y1+width, color, thick, stroke);
	// top
	makeLineStrokeThickHorizontal(x1, y1, x1+height, y1, color, thick, stroke);
	// botton
	makeLineStrokeThickHorizontal(x1+b, y1+width, x1+height+b, y1+width, color, thick, stroke);
}

void square(int x1, int y1, int length, int color, int thick, char stroke){
	
	// left
	makeLineStrokeThickVertical(x1, y1, x1, y1+length, color, thick, stroke);
	// right
	makeLineStrokeThickVertical(x1+length, y1, x1+length, y1+length, color, thick, stroke);
	// top
	makeLineStrokeThickHorizontal(x1, y1, x1+length, y1, color, thick, stroke);
	// botton
	makeLineStrokeThickHorizontal(x1, y1+length, x1+length, y1+length, color, thick, stroke);
}

void rectangel(int x1, int y1, int length, int width, int color, int thick, char stroke){
	
	// left
	makeLineStrokeThickVertical(x1, y1, x1, y1+width, color, thick, stroke);
	// right
	makeLineStrokeThickVertical(x1+length, y1, x1+length, y1+width, color, thick, stroke);
	// top
	makeLineStrokeThickHorizontal(x1, y1, x1+length, y1, color, thick, stroke);
	// botton
	makeLineStrokeThickHorizontal(x1, y1+width, x1+length, y1+width, color, thick, stroke);
}

