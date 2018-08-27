#include <stdio.h>
#include <stdlib.h>
/* includes */
typedef struct CuboTag{
    float lado;
} Cubo;

Cubo* cria_cubo();
void exclui_cubo();
int modifica_cubo(Cubo*, float);
float area_cubo(Cubo*);
float volume_cubo(Cubo*);

int main(int argc, char const *argv[]){
    /* code */
    return 0;
}
