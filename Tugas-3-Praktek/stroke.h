#include <windows.h>
#include <graphics.h>

void makeLine(int x1, int y1, int x2, int y2, int color);
void makeLineStroke(int x1, int y1, int x2, int y2, int color, char stroke);
void makeLineStrokeThickHorizontal(int x1, int y1, int x2, int y2, int color, int thick, char stroke);
void makeLineStrokeThickVertical(int x1, int y1, int x2, int y2, int color, int thick, char stroke);
void makeLineThickHorizontal(int x1, int y1, int x2, int y2, int color, int thick);
void makeLineThickVertical(int x1, int y1, int x2, int y2, int color, int thick);
void makeLineThickHorizontal2(int x1, int y1, int x2, int y2, int color, int thick);
void makeLineThickVertical2(int x1, int y1, int x2, int y2, int color, int thick);
void rectangel(int x1, int y1, int length, int width, int color, int thick, char stroke);
void square(int x1, int y1, int length, int color, int thick, char stroke);
void parallelogram(int x1, int y1, int b, int height, int width, int color, int thick, char stroke);
void angledtriangle(int x1, int y1, int adjacent, int opposite, int color, int thick, char stroke);
void trapezoid(int x1, int y1, int x2, int y2, int width1, int width2, int color, int thick, char stroke);
void rhombush(int x1, int y1, int adjacent, int opposite, int color, int thick, char stroke);
void makeLineMargin(int margin, int height, int width, int color);
void makeLineMarginThickStroke(int margin, int height, int width, int color, int thick, char stroke);

int main(){
	
	// initiate
	int height = 500;
	int width = 500;
	int margin = 10;
	
	// open windows
	initwindow(width, height, "sample");
	
//	makeLineThickVertical2(margin, margin, margin+100, height-margin, WHITE, 10);
//	makeLineThickHorizontal2(margin, margin+100, width-margin, margin, WHITE, 10);
//	makeLineStroke(margin, margin, width-margin, margin, WHITE, 'C');
//	makeLineMarginThickStroke(margin, height, width, WHITE, 10, 'D');
//	makeLineStrokeThickHorizontal(margin, margin+100, width-margin, margin, WHITE, 10, 'D');
//	rectangel(50, 50, 100, 200, WHITE, 2, 'C');
//	square(50, 50, 100, WHITE, 2, 'C');
//	parallelogram(25, 25, 50, 100, 200, WHITE, 2, 'C');
//	trapezoid(25, 25, 0, 125, 200, 300, WHITE, 2, 'C');
//	angledtriangle(100, 100, 100, 125, WHITE, 10, 'C');
//	rhombush(10, 250, 300, 150, WHITE, 10, 'A');
	
	getch();
}

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

void makeLineStrokeThickHorizontal(int x1, int y1, int x2, int y2, int color, int thick, char stroke){
			
	bool isOdd = false;
	int i, j;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
	for(i = 0; i <= thick; i++){
		makeLineStroke(x1, y1+i, x2, y2+i, color, stroke);
	}
	for(j = 0; j >= -thick; j--){
		makeLineStroke(x1, y1+j, x2, y2+j, color, stroke);
	}
	if(isOdd){
		makeLineStroke(x1, y1+i, x2, y2+i, color, stroke);
	}
}

void makeLineStrokeThickVertical(int x1, int y1, int x2, int y2, int color, int thick, char stroke){
			
	bool isOdd = false;
	int i, j;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
	for(i = 0; i <= thick; i++){
		makeLineStroke(x1+i, y1, x2+i, y2, color, stroke);
	}
	for(j = 0; j >= -thick; j--){
		makeLineStroke(x1+j, y1, x2+j, y2, color, stroke);
	}
	if(isOdd){
		makeLineStroke(x1+i, y1, x2+i, y2, color, stroke);
	}
}

void makeLineStroke(int x1, int y1, int x2, int y2, int color, char stroke){
		
	// DDA Line Drawing Algorithm
	// source : https://www.thecrazyprogrammer.com/2017/01/dda-line-drawing-algorithm-c-c.html
	
	float x, y, dx, dy, step;
	int cStep;
 
	dx = abs(x2-x1);
	dy = abs(y2-y1);
 
	if(dx>=dy)
		step = dx;
	else
		step = dy;
 
	dx = (x2-x1)/step;
	dy = (y2-y1)/step;
 
	x = x1;
	y = y1;
 
	cStep = 1;
	while(cStep<=step)
	{
		switch(stroke) {
    	case 'A' :
    		// point
			if(cStep %2 != 0){
				putpixel(x, y, color);
			}
        	break;
    	case 'B' :
    		// dash
			if(cStep %8 != 0){
				putpixel(x, y, color);
			}
    		break;
    	case 'C' :
    		// dash point
			if(cStep %2 != 0){
				putpixel(x, y, color);
			}
			if(cStep %6 == 0){
				putpixel(x, y, color);
			}
        	break;
    	case 'D' :
    		// dash point point
			if(cStep %2 != 0){
				putpixel(x, y, color);
			}
			if(cStep %8 == 0){
				putpixel(x, y, color);
			}
        	break;
      	default :
      		// line
			putpixel(x, y, color);
		}
		x = x+dx;
		y = y+dy;
		cStep = cStep+1;
	}
}

void makeLineThickHorizontal(int x1, int y1, int x2, int y2, int color, int thick){
	
	// DDA Line Drawing Algorithm
	// source : https://www.thecrazyprogrammer.com/2017/01/dda-line-drawing-algorithm-c-c.html
	
	float x, y, dx, dy, step;
	int cStep, i, j;
	bool isOdd = false;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
 
	dx = abs(x2-x1);
	dy = abs(y2-y1);
 
	if(dx >= dy)
		step = dx;
	else
		step = dy;
 
	dx = (x2-x1)/step;
	dy = (y2-y1)/step;
 
	x = x1;
	y = y1;
 
	cStep = 1;
	while(cStep <= step)
	{
		for(i = 0; i <= thick; i++){
			putpixel(x, y+i, color);
		}
		for(j = 0; j >= -thick; j--){
			putpixel(x, y+j, color);
		}
		if(isOdd){
			putpixel(x, y+i, color);
		}
		x = x+dx;
		y = y+dy;
		cStep = cStep+1;
	}
}

void makeLineThickVertical(int x1, int y1, int x2, int y2, int color, int thick){
	
	// DDA Line Drawing Algorithm
	// source : https://www.thecrazyprogrammer.com/2017/01/dda-line-drawing-algorithm-c-c.html
	
	float x, y, dx, dy, step;
	int cStep, i, j;
	bool isOdd = false;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
 
	dx = abs(x2-x1);
	dy = abs(y2-y1);
 
	if(dx >= dy)
		step = dx;
	else
		step = dy;
 
	dx = (x2-x1)/step;
	dy = (y2-y1)/step;
 
	x = x1;
	y = y1;
 
	cStep = 1;
	while(cStep <= step)
	{
		for(i = 0; i <= thick; i++){
			putpixel(x+i, y, color);
		}
		for(j = 0; j >= -thick; j--){
			putpixel(x+j, y, color);
		}
		if(isOdd){
			putpixel(x+i, y, color);
		}
		x = x+dx;
		y = y+dy;
		cStep = cStep+1;
	}
}

void makeLine(int x1, int y1, int x2, int y2, int color){
	
	// DDA Line Drawing Algorithm
	// source : https://www.thecrazyprogrammer.com/2017/01/dda-line-drawing-algorithm-c-c.html
	
	float x, y, dx, dy, step;
	int cStep;
 
	dx = abs(x2-x1);
	dy = abs(y2-y1);
 
	if(dx>=dy)
		step = dx;
	else
		step = dy;
 
	dx = (x2-x1)/step;
	dy = (y2-y1)/step;
 
	x = x1;
	y = y1;
 
	cStep = 1;
	while(cStep<=step)
	{
		putpixel(x, y, color);
		x = x+dx;
		y = y+dy;
		cStep = cStep+1;
	}
}

void makeLineMarginThickStroke(int margin, int height, int width, int color, int thick, char stroke){
	
	rectangel(margin, margin, width-(margin*2), height-(margin*2), WHITE, thick, stroke);
}

void makeLineThickHorizontal2(int x1, int y1, int x2, int y2, int color, int thick){
		
	bool isOdd = false;
	int i, j;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
	for(i = 0; i <= thick; i++){
		makeLine(x1, y1+i, x2, y2+i, color);
	}
	for(j = 0; j >= -thick; j--){
		makeLine(x1, y1+j, x2, y2+j, color);
	}
	if(isOdd){
		makeLine(x1, y1+i, x2, y2+i, color);
	}
}

void makeLineThickVertical2(int x1, int y1, int x2, int y2, int color, int thick){
		
	bool isOdd = false;
	int i, j;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
	for(i = 0; i <= thick; i++){
		makeLine(x1+i, y1, x2+i, y2, color);
	}
	for(j = 0; j >= -thick; j--){
		makeLine(x1+j, y1, x2+j, y2, color);
	}
	if(isOdd){
		makeLine(x1+i, y1, x2+i, y2, color);
	}
}

void makeLineMargin(int margin, int height, int width, int color){
	
	// left padding
	makeLine(margin, margin, margin, height-margin, color);
	// right padding
	makeLine(width-margin, margin, width-margin, height-margin, color);
	// top padding
	makeLine(margin, margin, width-margin, margin, color);
	// botton padding
	makeLine(margin, height-margin, width-margin, height-margin, color);
}

