#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "settings.h"
#include "spider.h"

void display();
void reshape(int w, int h);
void arrowKeypressed(int key, int x, int y);
void arrowKeyReleased(int key, int x, int y);

void drawWAxes();
void drawAxes(float *basePoint, float *i, float *j, float *k);

void drawGrid();

#endif