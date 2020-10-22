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
void makeLineMargin(int margin, int height, int width, int color);
void makeLineMarginThick(int margin, int height, int width, int color, int thick);

int main(){
	
	// initiate
	int height = 250;
	int width = 250;
	int margin = 10;
	
	// open windows
	initwindow(width, height, "sample");
	
	//makeLineMarginThick(margin, height, width, WHITE, 4);
	//makeLineThickVertical2(margin, margin, margin+100, height-margin, WHITE, 10);
	//makeLineThickHorizontal2(margin, margin+100, width-margin, margin, WHITE, 10);
	//makeLineDash(margin, margin, width-margin, margin, WHITE, 'C');
	makeLineStrokeThickHorizontal(margin, margin+100, width-margin, margin, WHITE, 10, 'D');
	
	getch();
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
 
	dx = dx/step;
	dy = dy/step;
 
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
 
	dx = dx/step;
	dy = dy/step;
 
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
 
	dx = dx/step;
	dy = dy/step;
 
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
 
	dx = dx/step;
	dy = dy/step;
 
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

void makeLineMarginThick(int margin, int height, int width, int color, int thick){
	
	bool isOdd = false;
	int i, j;
	
	if (thick % 2 != 0)
    	isOdd = true;
	
	thick = thick / 2;
	for(i = 0; i <= thick; i++){
		// left padding
		makeLine(margin+i, margin+i, margin+i, height-margin-i, color);
		// right padding
		makeLine(width-margin-i, margin+i, width-margin-i, height-margin-i, color);
		// top padding
		makeLine(margin+i, margin+i, width-margin-i, margin+i, color);
		// botton padding
		makeLine(margin+i, height-margin-i, width-margin-i, height-margin-i, color);
	}
	for(j = 0; j >= -thick; j--){
		// left padding
		makeLine(margin+j, margin+j, margin+j, height-margin-j, color);
		// right padding
		makeLine(width-margin-j, margin+j, width-margin-j, height-margin-j, color);
		// top padding
		makeLine(margin+j, margin+j, width-margin-j, margin+j, color);
		// botton padding
		makeLine(margin+j, height-margin-j, width-margin-j, height-margin-j, color);	
	}
	if(isOdd){
		// left padding
		makeLine(margin+i, margin+i, margin+i, height-margin-i, color);
		// right padding
		makeLine(width-margin-i, margin+i, width-margin-i, height-margin-i, color);
		// top padding
		makeLine(margin+i, margin+i, width-margin-i, margin+i, color);
		// botton padding
		makeLine(margin+i, height-margin-i, width-margin-i, height-margin-i, color);
	}
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

