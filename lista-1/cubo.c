#include <stdio.h>
#include <stdlib.h>
/* includes */
typedef struct CuboTag{
    float lado;
} Cubo;

Cubo* cubo_padrao();
Cubo* contruir_cubo(float);
int modifica_cubo(Cubo*, float);
float lado_cubo(Cubo*);
float area_cubo(Cubo*);
float volume_cubo(Cubo*);
void exclui_cubo(Cubo*);

int main(int argc, char const *argv[]){
    Cubo *cubo;

    cubo = cubo_padrao();
    modifica_cubo(cubo, 3);

    // cubo = contruir_cubo(2);

    printf("%f\n", area_cubo(cubo));
    printf("%f\n", volume_cubo(cubo));

    exclui_cubo(cubo);
    return 0;
}
Cubo* cubo_padrao(){
    Cubo *c;
    c = (Cubo*)malloc(1*sizeof(Cubo));
    c->lado = 1;
    return c;
}
Cubo* contruir_cubo(float l){
    Cubo *c;
    c = (Cubo*)malloc(1*sizeof(Cubo));
    c->lado = (l <= 0) ? 1 : l;
    return c;
}
void exclui_cubo(Cubo* c){
    free(c);
}
int modifica_cubo(Cubo* c, float l){
    if(l <= 0) return 0;
    else{
        c->lado = l;
        return 1;
    }
}
float lado_cubo(Cubo* c){
    return c->lado;
}
float area_cubo(Cubo* c){
    return 6 * c->lado * c->lado;
}
float volume_cubo(Cubo* c){
    return c->lado * c->lado * c->lado;
}
