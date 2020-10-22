#include <windows.h>
#include <graphics.h>

void makeLine(int x1, int y1, int x2, int y2);
void makeLineMargin(int margin, int height, int width);
void valueMarginPoint(int margin, int height, int width);
void makeKartesian(int margin, int height, int width);

void xQuadrad (float x, float y, float xAwal, float xAkhir)
{
    float y1,x1;
    x1 = xAwal;
    while(x1 <= xAkhir){
        y1 = pow(x1,2);
        putpixel(x+x1,y-y1,WHITE);
        y1 = 0;
        x1+=0,2;
    }
}

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
	xQuadrad(23, 23, 220, 220);
	
	getch();
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

