#include <windows.h>
#include <graphics.h>

void makeLine(int x1, int y1, int x2, int y2);
void makeLineMargin(int margin, int height, int width);
void makeMainDiagonal(int margin, int height, int width);
void makeAntiDiagonal(int margin, int height, int width);
void makeRectangle(int x, int y, int height, int width);
void makeCircle(int x, int y, int r);
void makeElipse(int x, int y, int stangle, int endangle, int xradius, int yradius);
void makeSmiley(int height, int width);

int main(){
	
	// initiate
	int height = 250;
	int width = 250;
	int margin = 10;
	int mouseX;
	int mouseY;
	
	int heightRectangle = height/2;
	int widthRectangle = width/2;
	int r = 20;
	
	// open windows
	initwindow(width, height, "sample");
	
	// text menu initiate
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	outtextxy(margin, margin,"Click the text below");
	outtextxy(margin, margin*4,"1. margin");
	outtextxy(margin, margin*6,"2. diagonal");
	outtextxy(margin, margin*8,"3. antidiagonal");
	outtextxy(margin, margin*10,"4. rectangle");
	outtextxy(margin, margin*12,"5. circle");
	outtextxy(margin, margin*14,"6. line");
	outtextxy(margin, margin*16,"7. elipse");
	outtextxy(margin, margin*18,"8. smiley");
	outtextxy(margin, margin*20,"9. exit");
	
	while(1)
    {
    	getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
	    if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*4) && (mouseY<margin*6)){
			// make margin
			makeLineMargin(margin, height, width);
	 	}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*6) && (mouseY<margin*8)){
			// make diagonal
			makeMainDiagonal(margin, height, width);
		}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*8) && (mouseY<margin*10)){
			// make antidiagonal
			makeAntiDiagonal(margin, height, width);
	 	}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*10) && (mouseY<margin*12)){
			// make ractangle
			makeRectangle(margin, margin, heightRectangle, widthRectangle);
	 	}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*12) && (mouseY<margin*14)){
			// make circle
			makeCircle(height/2, width/2, r);
		}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*14) && (mouseY<margin*16)){
			// make line
			makeLine(margin, width/2, width-margin, height-margin);
	 	}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*16) && (mouseY<margin*18)){
			// make elipse
			makeElipse(height/2, width/2, 0, 180, r, r*2);
		}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*18) && (mouseY<margin*20)){
			// make smiley emoji
			makeSmiley(height, width);
	 	}
	 	if ((mouseX>margin) && (mouseX<width/2) && (mouseY>margin*20) && (mouseY<margin*22)){
	 		exit(0);
		}
	}
	getch();
}

void makeLine(int x1, int y1, int x2, int y2){
	
	// line function on lib
	line(x1, y1, x2, y2);
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

void makeMainDiagonal(int margin, int height, int width){
	
	int x = margin;
	// diagonal with looping
	for (int y = margin; x <= height-margin; y++) {
		putpixel(x, y, WHITE);
		x++;
	}
}

void makeAntiDiagonal(int margin, int height, int width){
	
	int x = margin;
	// anti diagonal with looping
	for (int y = height-margin; x <= width-margin; y--) {
		putpixel(x, y, WHITE);
		x++;
	}
}

void makeRectangle(int x, int y, int height, int width){
	
	// ractangle function on lib
	rectangle(x, y, height, width);
}

void makeCircle(int x, int y, int r){
	
	// circle function on lib
	circle(x, y, r);
}

void makeElipse(int x, int y, int stangle, int endangle, int xradius, int yradius){

	// ellipse function on lib
	ellipse(x, y, stangle, endangle, xradius, yradius);
}

void makeSmiley(int height, int width){
	
	int rEyes = 20;
	int rMouth = 80;
	
	// left eyes
	makeCircle(width*1/4, height*1/4, rEyes);
	// right eyes
	makeCircle(width*3/4, height*1/4, rEyes);
	// mouth
	makeElipse(width*1/2, height*1/2, 180, 0, rMouth, rMouth);
	makeElipse(width*1/2, height*1/2, 180, 0, rMouth, rMouth/2);
}
