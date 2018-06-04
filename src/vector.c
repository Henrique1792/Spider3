#include "../include/vector.h"

void vector_add(vec3 *vr, vec3 *v1, vec3 *v2){
    for(int i=0;i<3;i++) vr->cd[i]=v1->cd[i]+v2->cd[i];
}
void vector_sub(vec3 *vr, vec3 *v1, vec3 *v2){
    for(int i=0;i<3;i++) vr->cd[i]=v1->cd[i]+v2->cd[i];
}
void vector_scalar_mul(vec3 *vr, vec3 *v, GLfloat scalar){
    for(int i=0; i<3; i++) vr->cd[i]=v->cd[i]*scalar;
}
void vector_cross_mul(vec3 *vr, vec3 *v1, vec3 *v2){

	vr->cd[0]=(v1->cd[1]*v2->cd[2])-(v1->cd[2]*v2->cd[1]);
	vr->cd[1]=(v1->cd[2]*v2->cd[0])-(v1->cd[0]*v2->cd[2]);
	vr->cd[2]=(v1->cd[0]*v2->cd[1])-(v1->cd[1]*v2->cd[0]);
}

void vector_normalize(vec3 *vr, vec3 *v){
    GLfloat norm=vector_norm(v);
    for(int i=0; i<3; i++)
        vr->cd[i]=v->cd[i]/norm;
}
GLfloat vector_norm(vec3 *v){
    GLfloat rt = sqrtf(pow(v->cd[0], 2)+pow(v->cd[1], 2)+ pow(v->cd[2], 2));
    return rt;
}