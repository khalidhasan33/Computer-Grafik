#include "stroke.h"
#include "shape.h"

int menu(int height, int width, int margin, int color, int thick, char stroke) 
{
    int chose;
	
	printf("\n/---Menu---/\n");
	printf("/----------/\n");
    printf("1. Color\n");
    printf("2. Thick\n");
    printf("3. Type Stroke\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    scanf( "%d", &chose );
    
    switch (chose){
        case 1: {
			printf("Chose color form (1-15) : (default WHITE)\n");
			scanf( "%d", &color );
            break;
        }
        case 2: {
			printf("input the line thickness pixel  : (default 1)\n");
			scanf( "%d", &thick );
            break;
        }
        case 3: {
			printf("Chose type stroke (please use uppercase) (default line)\n");
			printf("A. point\n");
			printf("B. dash\n");
			printf("C. dash point\n");
			printf("D. dash point point\n");
			scanf( " %c", &stroke );
            break;
        }
        case 4: {
			// open windows
			initwindow(width, height, "181511050_CG_3_2");
			
			makeLineThickVertical2(margin, margin, margin+100, height-margin, color, thick);
			makeLineThickHorizontal2(margin, margin+100, width-margin, margin, color, thick);
			makeLineStroke(margin, margin, width-margin, margin, color, stroke);
			makeLineMarginThickStroke(margin, height, width, color, thick, stroke);
			makeLineStrokeThickHorizontal(margin, margin+100, width-margin, margin, color, thick, stroke);
			rectangel(50, 50, 100, 200, color, thick, stroke);
			square(50, 50, 100, color, thick, stroke);
			parallelogram(25, 25, 50, 100, 200, color, thick, stroke);
			trapezoid(25, 25, 0, 125, 200, 300, color, thick, stroke);
			angledtriangle(100, 100, 100, 125, color, thick, stroke);
			rhombush(10, 250, 300, 150, color, thick, stroke);
		
		    getch();
		    closegraph();
            break;
        }
        default: {
            exit(0);
            break;
        }
    }
    
    return menu(height, width, margin, color, thick, stroke);
}

int main(){
	
	// initiate
	int height = 500;
	int width = 500;
	int margin = 10;
	int color = WHITE;
	int thick = 1;
	char stroke = 'T';
	
	menu(height, width, margin, color, thick, stroke);
}

