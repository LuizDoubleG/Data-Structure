#include <stdio.h>
#include <stdlib.h>
#include "Cylinder.h"

int main() {
	float area, volume;
	Cylinder *c;
	printf("Enter the ray and the height of the cylinder: ");
	scanf("%f %f", &area, &volume);
	c = Cylinder_create(area, volume);
	area = Cylinder_area(c);
	volume = Cylinder_volume(c);
	printf("Cylinder area: %f\n", area);
	printf("Cylinder volume: %f\n", volume);
	return 0;
}
