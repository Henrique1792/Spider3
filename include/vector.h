#ifndef VECTOR_H_
#define VECTOR_H_
#include "settings.h"

typedef struct vec3{
    GLfloat cd[3];
}vec3;

void vector_add(vec3 *vr, vec3 *v1, vec3 *v2);
void vector_sub(vec3 *vr, vec3 *v1, vec3 *v2);
void vector_scalar_mul(vec3 *vr, vec3 *v, GLfloat scalar);
void vector_cross_mul(vec3 *vr, vec3 *v1, vec3 *v2);
GLfloat vector_norm(vec3 *v);
void vector_normalize(vec3 *vr, vec3 *v);
#endif