#include "../include/settings.h"
#include "../include/display.h"
#include "../include/vector.h"
#include "../include/spider.h"

int width=800, height=600;
spider_t *spider;

void init(){
	vec3 *init=(vec3 *)malloc(sizeof(vec3));
	for(int i=0; i<3; i++)
		init->cd[i]=0;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition((SCREEN_SIZEX)/2, (SCREEN_SIZEY)/2);
	glutInitWindowSize(width, height);
	glutCreateWindow("Spider - 3D");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	spider=spider_create(init, 0.0f);
	free(init);
}


int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	init();

		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutSpecialFunc(arrowKeypressed);
 		glutSpecialUpFunc(arrowKeyReleased);
		 
	glutMainLoop();
	spider_destroy(spider);
}
