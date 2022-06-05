typedef struct cylinder Cylinder;

Cylinder* Cylinder_create (float ray, float h);
//Creates a new cylinder with the given ray and height

void Cylinder_free(Cylinder* c);
//Frees the memory used by the cylinder

//float Cylinder_acess(Cylinder* c, float ray, float h);
//Access the ray or height of a cylinder

//float Cylinder_assign(Cylinder* c, float ray, float h);
//Assign new ray or height to a cylinder

float Cylinder_area(Cylinder* c);
//Calculates the area of a cylinder

float Cylinder_volume(Cylinder* c);
//Calculates the volume of a cylinder
