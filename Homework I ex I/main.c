#include <stdio.h>
#include <stdlib.h>
#include "Cylinder.h"

int main() {
	float area, volume;
	Cylinder *c;
	c = Cylinder_create(4,8);
	area = Cylinder_area(c);
	volume = Cylinder_volume(c);
	printf("Area desse cilindro: %f\n", area);
	printf("Volume desse cilindro: %f\n", volume);
	return 0;
}
