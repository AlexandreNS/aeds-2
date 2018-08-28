#include <stdio.h>
#include <stdlib.h>
/* includes */
const float PI = 3.14159265359;

typedef struct EsferaTag{
    float raio;
} Esfera;

Esfera* esfera_padrao();
Esfera* contruir_esfera(float);
void modifica_esfera(Esfera*, float);
float raio_esfera(Esfera*);
float area_esfera(Esfera*);
float volume_esfera(Esfera*);
void exclui_esfera(Esfera*);

int main(int argc, char const *argv[]){
    Esfera *e;

    e = esfera_padrao();
    modifica_esfera(e, 10);

    // c = contruir_esfera(2);

    printf("%f\n", area_esfera(e));
    printf("%f\n", volume_esfera(e));

    exclui_esfera(e);
    return 0;
}
Esfera* esfera_padrao(){
    Esfera *e;
    e = (Esfera*)malloc(1*sizeof(Esfera));
    e->raio = 1;
    return e;
}
Esfera* contruir_esfera(float raio){
    Esfera *e;
    e = (Esfera*)malloc(1*sizeof(Esfera));
    e->raio = raio <= 0 ? 1 : raio;
    return e;
}
void modifica_esfera(Esfera* e, float raio){
    e->raio = raio <= 0 ? 1 : raio;
}
float raio_esfera(Esfera* e){
    return e->raio;
}
float area_esfera(Esfera* e){
    return 4*PI*e->raio*e->raio;
}
float volume_esfera(Esfera* e){
    return (float)4/3*PI*e->raio*e->raio*e->raio;
}
void exclui_esfera(Esfera* e){
    free(e);
}
