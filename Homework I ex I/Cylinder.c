#include <stdlib.h>
#include <math.h>
#include "Cylinder.h" //inclui struct do cilindro e protótipo das funções
#define PI 3.14

struct cylinder{
	float ray;
	float h;
};

Cylinder* Cylinder_create (float ray, float h){
	Cylinder* c = (Cylinder*)malloc(sizeof(Cylinder));
	if (c!=NULL){
		c->ray = ray;
		c->h = h;
	}
	return (c);
}

void Cylinder_free(Cylinder* c){
	free(c);
}

float Cylinder_area(Cylinder* c){
	if (c == NULL){
		return (0);
	}
	float area = (2 * PI * (c->ray) * (c->h));
	return area;	
}

float Cylinder_volume(Cylinder* c){
	if (c == NULL){
		return (0);
	}
	float volume = (PI*(c->ray * c->ray)*(c->h));
	return volume;	
}
