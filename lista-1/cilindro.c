#include <stdio.h>
#include <stdlib.h>
/* includes */
const float PI = 3.14159265359;

typedef struct CilindroTag{
    float altura;
    float raio;
} Cilindro;

Cilindro* cilindro_padrao();
Cilindro* contruir_cilindro(float, float);
void modifica_cilindro(Cilindro*, float, float);
float altura_cilindro(Cilindro*);
float raio_cilindro(Cilindro*);
float area_cilindro(Cilindro*);
float volume_cilindro(Cilindro*);
void exclui_cilindro(Cilindro*);

int main(int argc, char const *argv[]){
    Cilindro *c;

    c = cilindro_padrao();
    modifica_cilindro(c, 3, 2);

    // c = contruir_cilindro(2);

    printf("%f\n", area_cilindro(c));
    printf("%f\n", volume_cilindro(c));

    exclui_cilindro(c);
    return 0;
}
Cilindro* cilindro_padrao(){
    Cilindro *c;
    c = (Cilindro*)malloc(1*sizeof(Cilindro));
    c->altura = 1;
    c->raio = 1;
    return c;
}
Cilindro* contruir_cilindro(float altura, float raio){
    Cilindro *c;
    c = (Cilindro*)malloc(1*sizeof(Cilindro));
    c->altura = altura <= 0 ? 1 : altura;
    c->raio = raio <= 0 ? 1 : raio;
    return c;
}
void modifica_cilindro(Cilindro* c, float altura, float raio){
    c->altura = altura <= 0 ? 1 : altura;
    c->raio = raio <= 0 ? 1 : raio;
}
float altura_cilindro(Cilindro* c){
    return c->altura;
}
float raio_cilindro(Cilindro* c){
    return c->raio;
}
float area_cilindro(Cilindro* c){
    return 2*PI*c->raio*(c->raio+c->altura);
}
float volume_cilindro(Cilindro* c){
    return c->raio*c->raio*PI*c->altura;
}
void exclui_cilindro(Cilindro* c){
    free(c);
}
