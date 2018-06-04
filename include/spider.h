#ifndef SPIDER_H_
#define SPIDER_H_
#include "settings.h"
#include "vector.h"

#define RAD2DEG 180.0f / M_PI
#define DEG2RAD M_PI / 180.0f

//spider defines
#define HEAD_RADIUS 0.25f
#define BODY_RADIUS 0.4f
#define JOINT_SIZE 0.55f
#define FOOT_SIZE 0.75f

#define THETA_JOINT_X 1.0f
#define THETA_JOINT_Z 2.0f

#define THETA_FOOT_X  1.0f
#define THETA_FOOT_Z  2.0f

#define INCREASE 0.8f
#define UP_INCREASE 0.5f
#define LEG_HEIGHT 1.5f

typedef struct spider_t{
    vec3 pos;
    GLfloat direction;

    float spider_JX, spider_JZ;
    float spider_FX, spider_FZ;
    int front_up;
    
}spider_t;

spider_t *spider_create(vec3 *initial, GLfloat direction);
void spider_init(spider_t *spider, vec3 *initial, GLfloat direction);
void spider_destroy(spider_t *spider);
void spider_draw(spider_t *spider);

void spider_move(spider_t* spider, GLfloat x, GLfloat y, GLfloat z);
void spider_direction(spider_t* spider, GLfloat direction);

#endif