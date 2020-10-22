#include <windows.h>
#include <graphics.h>
#include <stdio.h>
#include <math.h>

void makeLine(int x1, int y1, int x2, int y2);
void makeLineMargin(int margin, int height, int width);
void valueMarginPoint(int margin, int height, int width);
void makeKartesian(int margin, int height, int width);
void xSqure(int margin, int height, int width, float x1, float x2);
void xSin(int margin, int height, int width, double x1, double x2);
void xCos(int margin, int height, int width, double x1, double x2);
void function1(int margin, int height, int width, double x1, double x2);


int main(){

	// initiate
	int height = 500;
	int width = 500;
	int margin = 1;
	
	// open windows
	initwindow(width, height, "sample");
	
	makeLineMargin(margin, height, width);
	makeKartesian(margin, height, width);
	valueMarginPoint(margin, height, width);
	function1(margin, height, width, -100.0, 100.0);
	xCos(margin, height, width, -100.0, 100.0);
	xSin(margin, height, width, -100.0, 100.0);
	xSqure(margin, height, width, 0.0, 5.0);
	
	getch();
}

void function1(int margin, int height, int width, double x1, double x2){
	
	float nolX = width/2;
	float nolY = height/2;
	float y = 0.0;
	float function;
	
	for(float y=nolY; y>margin; y=y-0.1){
		function = (x1*x1*x1)-3*x1-1;
		putpixel(nolX+x1, nolY-function, WHITE);
		x1=x1+0.1;
		if(x1>=x2){
			break;
		}
	}
}

void xSin(int margin, int height, int width, double x1, double x2){
		
	float nolX = width/2;
	float nolY = height/2;
	float y = 0.0;
	
	for(float y=nolY; y>margin; y=y-0.1){
		putpixel(nolX+x1, nolY-(sin(x1)), WHITE);
		x1=x1+0.1;
		if(x1>=x2){
			break;
		}
	}
}

void xCos(int margin, int height, int width, double x1, double x2){
		
	float nolX = width/2;
	float nolY = height/2;
	float y = 0.0;
	
	for(float y=nolY; y>margin; y=y-0.1){
		putpixel(nolX+x1, nolY-(cos(x1)), WHITE);
		x1=x1+0.1;
		if(x1>=x2){
			break;
		}
	}
}

void xSqure(int margin, int height, int width, float x1, float x2){
	
	float nolX = width/2;
	float nolY = height/2;
	float y = 0.0;
	
	for(float y=nolY; y>margin; y=y-0.1){
		putpixel(nolX+x1, nolY-x1*x1, WHITE);
		x1=x1+0.1;
		if(x1>=x2){
			break;
		}
	}
}

void makeLine(int x1, int y1, int x2, int y2){
	
	// DDA Line Drawing Algorithm
	// source : https://www.thecrazyprogrammer.com/2017/01/dda-line-drawing-algorithm-c-c.html
	
	float x,y,dx,dy,step;
	int i;
 
	dx=abs(x2-x1);
	dy=abs(y2-y1);
 
	if(dx>=dy)
		step=dx;
	else
		step=dy;
 
	dx=dx/step;
	dy=dy/step;
 
	x=x1;
	y=y1;
 
	i=1;
	while(i<=step)
	{
		putpixel(x,y,5);
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
}

void makeLineMargin(int margin, int height, int width){
	
	// left padding
	makeLine(margin, margin, margin, height-margin);
	// right padding
	makeLine(width-margin, margin, width-margin, height-margin);
	// top padding
	makeLine(margin, margin, width-margin, margin);
	// botton padding
	makeLine(margin, height-margin, width-margin, height-margin);
}

void valueMarginPoint(int margin, int height, int width){
	
	printf("Value of X1 : %d \t and y1 : %d \n", margin, margin);
	printf("Value of X2 : %d \t and y2 : %d \n", width-margin, margin);
	printf("Value of X3 : %d \t and y3 : %d \n", width-margin, height-margin);
	printf("Value of X4 : %d \t and y4 : %d \n", margin, height-margin);
}

void makeKartesian(int margin, int height, int width){
	
	makeLine(width/2 , margin, width/2, height-margin);
	makeLine(margin, height/2, width-margin, height/2);
}

