#include "../include/spider.h"
#include "../include/forms.h"
#include <math.h>

static bool gDrawOrigin = false;
int count = 1;

spider_t *spider_create(vec3 *initial, GLfloat direction){
	spider_t *rt=(spider_t *)malloc(sizeof(spider_t));
	if(rt!=NULL)
		spider_init(rt, initial, direction);
	return rt;
}

void spider_init(spider_t *spider, vec3 *initial, GLfloat direction){
	for(int i=0; i<3; i++){
		spider->pos.cd[i]=initial->cd[i];
	}

	spider->direction = direction;
	spider->front_up= 0;
	//set leg values

	spider->spider_JX = THETA_JOINT_X; 
	spider->spider_JZ = THETA_JOINT_Z;
    spider->spider_FX = THETA_FOOT_X;
	spider->spider_FZ = THETA_FOOT_Z;
}

void spider_draw(spider_t *spider){

	glPushMatrix();	
		// Draw Head	
		glTranslatef(BODY_RADIUS, HEAD_RADIUS, BODY_RADIUS);
		glutSolidSphere(HEAD_RADIUS, 50, 50);
	glPopMatrix();	

	glPushMatrix();
		glTranslatef(BODY_RADIUS, HEAD_RADIUS, BODY_RADIUS);
		glRotatef(44.0f, 0.0f, -1.0f, 0.0f);
		// Draw legs	
		int i = 0;
		for(i = 0; i < 4; i++) {

			// printf("%d\n", count);
			
			float inc = INCREASE * i;

			if (i == 0) {
				
				if (spider->front_up == 0) {
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc + 0.2, LEG_HEIGHT + UP_INCREASE, spider->spider_JZ);
					drawLine(spider->spider_JX - inc + 0.2, LEG_HEIGHT + UP_INCREASE, spider->spider_JZ, spider->spider_FX - inc + 0.2, UP_INCREASE, spider->spider_FZ);
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc + 0.2, LEG_HEIGHT - UP_INCREASE, -spider->spider_JZ);
					drawLine(spider->spider_JX - inc + 0.2, LEG_HEIGHT - UP_INCREASE, -spider->spider_JZ, spider->spider_FX - inc + 0.2, 0.0, -spider->spider_FZ);	
				}
				else {
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc - 0.2, LEG_HEIGHT - UP_INCREASE, spider->spider_JZ);
					drawLine(spider->spider_JX - inc - 0.2, LEG_HEIGHT - UP_INCREASE, spider->spider_JZ, spider->spider_FX - inc - 0.2, 0.0, spider->spider_FZ);
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc - 0.2, LEG_HEIGHT + UP_INCREASE, -spider->spider_JZ);
					drawLine(spider->spider_JX - inc - 0.2, LEG_HEIGHT + UP_INCREASE, -spider->spider_JZ, spider->spider_FX - inc - 0.2, UP_INCREASE, -spider->spider_FZ);	
				}
			}
			else {
				if (count == i) {
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc  + 0.2, LEG_HEIGHT + UP_INCREASE, spider->spider_JZ);
					drawLine(spider->spider_JX - inc  + 0.2, LEG_HEIGHT + UP_INCREASE, spider->spider_JZ, spider->spider_FX - inc + 0.2, UP_INCREASE, spider->spider_FZ);
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc  - 0.2, LEG_HEIGHT + UP_INCREASE, -spider->spider_JZ);
					drawLine(spider->spider_JX - inc - 0.2, LEG_HEIGHT + UP_INCREASE, -spider->spider_JZ, spider->spider_FX - inc - 0.2, UP_INCREASE, -spider->spider_FZ);	
				}
				else {
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc - 0.2, LEG_HEIGHT , spider->spider_JZ);
					drawLine(spider->spider_JX - inc  - 0.2, LEG_HEIGHT, spider->spider_JZ, spider->spider_FX - inc  - 0.2, 0.0, spider->spider_FZ);
					drawLine(0.0, 0.0, 0.0, spider->spider_JX - inc + 0.2, LEG_HEIGHT, -spider->spider_JZ);
					drawLine(spider->spider_JX - inc  + 0.2, LEG_HEIGHT, -spider->spider_JZ, spider->spider_FX - inc  + 0.2, 0.0, -spider->spider_FZ);	
				}
			}
		}
		count++;

		if (count > 3){
			count = 1;
		}

	glPopMatrix();

	// // Draw Body
	glPushMatrix();
		glTranslatef(0.0, HEAD_RADIUS, 0.0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glutSolidSphere(BODY_RADIUS, 50, 50);
	glPopMatrix();

}

void spider_move(spider_t* spider, GLfloat x, GLfloat y, GLfloat z){
	spider->pos.cd[0]+=x;
	spider->pos.cd[1]+=y;
	spider->pos.cd[2]+=z;
}

void spider_direction(spider_t* spider, GLfloat direction){
	spider->direction += direction;
	if (spider->direction > 360.0f)
spider->direction =  fmodf(spider->direction, 360.0f);
	else if (spider->direction < -360.0f)
		spider->direction = fmodf(spider->direction, -360.0f);
}

void spider_destroy(spider_t *spider){
	free(spider);
}