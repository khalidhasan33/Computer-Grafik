#ifndef STROKE_H
# define STROKE_H

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
void makeLineMarginThickStroke(int margin, int height, int width, int color, int thick, char stroke);

#endif

