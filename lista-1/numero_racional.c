#include <stdio.h>
#include <stdlib.h>
/* includes */
typedef struct RacionalTag{
    int numerador;
    int denominador;
} Racional;

Racional* cria_racional();
int alterar_racional(Racional*, int, int);
Racional soma_racional(Racional*, Racional*);
Racional multiplica_racional(Racional*, Racional*);
int compara_racional(Racional*, Racional*);

int main(int argc, char const *argv[]){

    return 0;
}
