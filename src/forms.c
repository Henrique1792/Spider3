#include <math.h>
#include "../include/settings.h"
#include "../include/vector.h"
#include "../include/forms.h"

void drawLine(GLfloat x1, GLfloat y1,GLfloat z1,
		GLfloat x2, GLfloat y2, GLfloat z2){

	glBegin(GL_LINES);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
	glEnd();
}
