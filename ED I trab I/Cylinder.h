typedef struct cylinder Cylinder;

Cylinder* Cylinder_create (float ray, float h);
//Cria um novo cilindro baseado em raio e altura

void Cylinder_free(Cylinder* c);
//Libera o espaço alocado para o cilindro

//float Cylinder_acess(Cylinder* c, float ray, float h);
//Acessa(retorna) o raio e a altura de um cilindro

//float Cylinder_assign(Cylinder* c, float ray, float h);
//Atribui novos valores ao raio e à altura de um cilindro

float Cylinder_area(Cylinder* c);
//Calcula a área de um cilindro

float Cylinder_volume(Cylinder* c);
//Calcula o volume de um cilindro
