#include <stdio.h>
#include <stdlib.h>
/* includes */
typedef struct ConjuntoTag{
    int* conjunto;
    int tamanho;
    int ordenado;
} Inteiros;

Inteiros* cria_conjunto();
void exclui_conjunto(Inteiros*);
void corrigir_conjunto(Inteiros*); // Ordena Elementos do Conjunto
int insere_elemento_conjunto(Inteiros*, int);
int remove_elemento_conjunto(Inteiros*, int);
Inteiros* uniao_conjunto(Inteiros*, Inteiros*);
Inteiros* intersecao_conjunto(Inteiros*, Inteiros*);
Inteiros* diferenca_conjunto(Inteiros*, Inteiros*);
int num_pertence_conjunto(Inteiros*, int);
int menor_valor_conjunto(Inteiros*, int*);
int maior_valor_conjunto(Inteiros*, int*);
int compara_conjunto(Inteiros*, Inteiros*);
void copia_conjunto(Inteiros*, Inteiros*);
int tamanho_conjunto(Inteiros*);
int vazio_conjunto(Inteiros*);
void imprimi_conjunto(Inteiros*);

void testes();

int main(int argc, char const *argv[]){
    printf("Execução da Funcao testes()\n");
    testes();
    return 0;
}

Inteiros* cria_conjunto(){
    Inteiros *conj_int;
    conj_int = (Inteiros*)malloc(1*sizeof(Inteiros));
    conj_int->tamanho = 0;
    conj_int->ordenado = 1;
    conj_int->conjunto = (int*)malloc(1*sizeof(int));
    return conj_int;
}
void exclui_conjunto(Inteiros* a){
    free(a->conjunto);
    free(a);
}
int insere_elemento_conjunto(Inteiros *conj_int, int inserir){
    if(num_pertence_conjunto(conj_int, inserir) != -1) return 0;
    else{
        conj_int->tamanho++;
        conj_int->conjunto = (int*)realloc(conj_int->conjunto, conj_int->tamanho*sizeof(int));
        conj_int->conjunto[conj_int->tamanho-1] = inserir;
        if(inserir >= conj_int->conjunto[conj_int->tamanho-2]) conj_int->ordenado = 1;
        else{
            conj_int->ordenado = 0;
            corrigir_conjunto(conj_int);
        }
        return 1;
    }
}
int remove_elemento_conjunto(Inteiros *conj_int, int remover){
    int posicao = num_pertence_conjunto(conj_int, remover);
    if(posicao == -1) return 0;
    else{
        int temp_conjunto[conj_int->tamanho-1];
        int cont = 0;
        for (int i = 0; i < conj_int->tamanho; i++) {
            if(i == posicao) continue;
            else{
                temp_conjunto[cont] = conj_int->conjunto[i];
                cont++;
            }
        }
        conj_int->tamanho--;
        conj_int->conjunto = (int*)realloc(conj_int->conjunto, conj_int->tamanho*sizeof(int));
        for (int i = 0; i < conj_int->tamanho; i++) conj_int->conjunto[i] = temp_conjunto[i];
        return 1;
    }
}
Inteiros* uniao_conjunto(Inteiros *a, Inteiros *b){
    Inteiros *a_cpy, *b_cpy;
    a_cpy = cria_conjunto();
    b_cpy = cria_conjunto();

    copia_conjunto(a, a_cpy);
    copia_conjunto(b, b_cpy);

    if (a_cpy->tamanho < b_cpy->tamanho) {
        for (int i = 0; i < a_cpy->tamanho; i++) {
            remove_elemento_conjunto(b_cpy, a_cpy->conjunto[i]);
        }
    }else{
        for (int i = 0; i < b_cpy->tamanho; i++) {
            remove_elemento_conjunto(a_cpy, b_cpy->conjunto[i]);
        }
    }
    Inteiros *uniao;
    uniao = cria_conjunto();
    for (int i = 0; i < a_cpy->tamanho; i++) insere_elemento_conjunto(uniao, a_cpy->conjunto[i]);
    for (int i = 0; i < b_cpy->tamanho; i++) insere_elemento_conjunto(uniao, b_cpy->conjunto[i]);
    exclui_conjunto(a_cpy);
    exclui_conjunto(b_cpy);
    return uniao;
}
Inteiros* intersecao_conjunto(Inteiros *a, Inteiros *b){
    Inteiros *a_cpy, *b_cpy;
    a_cpy = cria_conjunto();
    b_cpy = cria_conjunto();

    copia_conjunto(a, a_cpy);
    copia_conjunto(b, b_cpy);

    Inteiros *intersecao;
    intersecao = cria_conjunto();
    if (a_cpy->tamanho < b_cpy->tamanho) {
        for (int i = 0; i < a_cpy->tamanho; i++) {
            if(num_pertence_conjunto(b_cpy, a_cpy->conjunto[i]) != -1){
                insere_elemento_conjunto(intersecao, a_cpy->conjunto[i]);
            }
        }
    }else{
        for (int i = 0; i < b_cpy->tamanho; i++) {
            if(num_pertence_conjunto(a_cpy, b_cpy->conjunto[i]) != -1){
                insere_elemento_conjunto(intersecao, b_cpy->conjunto[i]);
            }
        }
    }
    exclui_conjunto(a_cpy);
    exclui_conjunto(b_cpy);
    return intersecao;
}
Inteiros* diferenca_conjunto(Inteiros *a, Inteiros *b){
    Inteiros *a_cpy, *b_cpy;
    a_cpy = cria_conjunto();
    b_cpy = cria_conjunto();

    copia_conjunto(a, a_cpy);
    copia_conjunto(b, b_cpy);

    for (int i = 0; i < b_cpy->tamanho; i++) {
        remove_elemento_conjunto(a_cpy, b_cpy->conjunto[i]);
    }
    Inteiros *diferenca;
    diferenca = cria_conjunto();
    diferenca = a_cpy;
    return diferenca;
}
int num_pertence_conjunto(Inteiros *conj_int, int busca){
    corrigir_conjunto(conj_int);
    int e = 0, d = conj_int->tamanho-1, m;
    while (e <= d){
        m = (e+d)/2;
        if ( conj_int->conjunto[m] == busca ) return m;
        if ( conj_int->conjunto[m] >  busca ) d = m-1;
        if ( conj_int->conjunto[m] <  busca ) e = m+1;
    }
    return -1;
}
void corrigir_conjunto(Inteiros* conj_int){
    if (!conj_int->ordenado){
        int atual, j, i;
        for (i = 1; i < conj_int->tamanho; i++) {
            atual = conj_int->conjunto[i];
            for (j = i - 1; (j >= 0) && (atual < conj_int->conjunto[j]); j--) {
                conj_int->conjunto[j + 1] = conj_int->conjunto[j];
            }
            conj_int->conjunto[j+1] = atual;
        }
        conj_int->ordenado = 1;
    }
}
int menor_valor_conjunto(Inteiros *a, int* menor){
    if (vazio_conjunto(a)) return 0;
    else{
        *menor = a->conjunto[0];
        return 1;
    }
}
int maior_valor_conjunto(Inteiros* a, int* maior){
    if (vazio_conjunto(a)) return 0;
    else{
        *maior = a->conjunto[a->tamanho-1];
        return 1;
    }
}
int compara_conjunto(Inteiros* a, Inteiros* b){
    if (a->tamanho == b->tamanho){
        for (int i = 0; i < a->tamanho; i++) {
            if (a->conjunto[i] != b->conjunto[i]) {
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}
void copia_conjunto(Inteiros* a, Inteiros* cpy){
    cpy->tamanho = a->tamanho;
    cpy->conjunto = (int*)realloc(cpy->conjunto, a->tamanho*sizeof(int));
    for (int i = 0; i < cpy->tamanho; i++) cpy->conjunto[i] = a->conjunto[i];
}
int tamanho_conjunto(Inteiros* a){
    return a->tamanho;
}
int vazio_conjunto(Inteiros* a){
    if (a->tamanho == 0) return 1;
    else return 0;
}
void imprimi_conjunto(Inteiros* a){
    if (vazio_conjunto(a)) printf("Conjunto Vazio");
    else{
        printf("Conjunto: { ");
        for (int i = 0; i < a->tamanho; i++) {
            if (i == a->tamanho-1) {
                printf("%d }", a->conjunto[i]);
            }else{
                printf("%d, ", a->conjunto[i]);
            }
        }
    }
}
void testes(){
    // // A = {5,6,9,8} e B = {0,1,2,3,4,5} INTERSECAO
        Inteiros *A, *B, *I_AB, *D_AB, *U_AB;
        A = cria_conjunto();
        B = cria_conjunto();

        for (int i = 5; i < 10; i++) insere_elemento_conjunto(A, i);
        for (int i = 0; i < 6; i++) insere_elemento_conjunto(B, i);

        I_AB = intersecao_conjunto(A, B);

        printf("\nTeste_INTERSECAO_1\n\n");
        imprimi_conjunto(A);
        printf("\n");
        imprimi_conjunto(B);
        printf("\n");
        imprimi_conjunto(I_AB);
        printf("\n");

        exclui_conjunto(I_AB);
        exclui_conjunto(A);
        exclui_conjunto(B);

        // A = { x | x é inteiro e -1 < x < 2} e B = {1,2,3,4} UNIAO
        A = cria_conjunto();
        B = cria_conjunto();

        for (int i = 0; i < 2; i++) insere_elemento_conjunto(A, i);
        for (int i = 1; i < 5; i++) insere_elemento_conjunto(B, i);

        U_AB = uniao_conjunto(A, B);

        printf("\nTeste_UNIAO_1\n\n");
        imprimi_conjunto(A);
        printf("\n");
        imprimi_conjunto(B);
        printf("\n");
        imprimi_conjunto(U_AB);
        printf("\n");

        exclui_conjunto(U_AB);
        exclui_conjunto(A);
        exclui_conjunto(B);

        // A = {1,2,3} e B = {1,2,3,4,5} DIFERENCA
        A = cria_conjunto();
        B = cria_conjunto();

        for (int i = 1; i < 4; i++) insere_elemento_conjunto(A, i);
        for (int i = 1; i < 6; i++) insere_elemento_conjunto(B, i);

        D_AB = diferenca_conjunto(A, B);

        printf("\nTeste_DIFERENCA_1\n\n");
        imprimi_conjunto(A);
        printf("\n");
        imprimi_conjunto(B);
        printf("\n");
        imprimi_conjunto(D_AB);
        printf("\n");

        exclui_conjunto(D_AB);
        exclui_conjunto(A);
        exclui_conjunto(B);

}
