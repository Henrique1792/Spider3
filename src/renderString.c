#include "../include/renderString.h"


void renderString(GLfloat x, GLfloat y, int size, char *str){
	int i;
	glRasterPos2d(x, y);

	for(i=0;i<size; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str[i]);
	}
}
