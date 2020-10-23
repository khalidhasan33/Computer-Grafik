#ifndef SHAPE_H
# define SHAPE_H

void rectangel(int x1, int y1, int length, int width, int color, int thick, char stroke);
void square(int x1, int y1, int length, int color, int thick, char stroke);
void parallelogram(int x1, int y1, int b, int height, int width, int color, int thick, char stroke);
void angledtriangle(int x1, int y1, int adjacent, int opposite, int color, int thick, char stroke);
void trapezoid(int x1, int y1, int x2, int y2, int width1, int width2, int color, int thick, char stroke);
void rhombush(int x1, int y1, int adjacent, int opposite, int color, int thick, char stroke);

#endif

