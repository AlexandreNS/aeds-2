#include "elemento_duplo_int.c"

typedef struct ListaDuplaTag{
  ElementoDuplo *inicio;
}ListaDupla;

ListaDupla* criarListaDupla();
void limparListaDupla(ListaDupla*);
void excluirListaDupla(ListaDupla*);
int insere_ultimoListaDupla(ListaDupla*, int);
int insere_posicaoListaDupla(ListaDupla*, int, int);
int remove_ultimoListaDupla(ListaDupla*, int*);
int remove_posicaoListaDupla(ListaDupla*, int, int*);
int recupera_chaveListaDupla(ListaDupla*, int);
int recupera_posicaoListaDupla(ListaDupla*, int, int*);
int countListaDupla(ListaDupla*);
int listaDuplaVazia(ListaDupla*);
void printListaDupla(ListaDupla*);

ListaDupla* criarListaDupla(){
    ListaDupla *l = (ListaDupla*)malloc(sizeof(ListaDupla));
    l->inicio = NULL;
    return l;
}
void limparListaDupla(ListaDupla* l){
    ElementoDuplo* aux_prox = l->inicio;
    ElementoDuplo* aux_ant;
    while(aux_prox != NULL){
        aux_ant = aux_prox;
        aux_prox = aux_prox->proximo;
        free(aux_ant);
    }
    l->inicio = NULL;
}
void excluirListaDupla(ListaDupla* l){
    limparListaDupla(l);
    free(l);
}
int insere_ultimoListaDupla(ListaDupla* l, int v){
    ElementoDuplo* e = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
    e->anterior = NULL;
    e->proximo = NULL;
    e->valor = v;
    if(listaDuplaVazia(l)) l->inicio = e;
    else{
        ElementoDuplo* aux;
        aux = l->inicio;
        while(aux->proximo != NULL) aux = aux->proximo;
        aux->proximo = e;
        e->anterior = aux;
    }
    return 1;
}
int insere_posicaoListaDupla(ListaDupla* l, int p, int v){
    ElementoDuplo* e = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
    e->valor = v;
    e->proximo = NULL;
    e->anterior = NULL;

    if(p < 1 || p > countListaDupla(l)+1) return 0;
    else if(listaDuplaVazia(l)) l->inicio = e;
    else if(p == 1){
        e->proximo = l->inicio;
        l->inicio->anterior = e;
        l->inicio = e;
    }else{
        ElementoDuplo* aux = l->inicio;
        int count = 1;
        while(aux != NULL && count+1 < p){
            aux = aux->proximo;
            count++;
        }
        e->proximo = aux->proximo;
        if(aux->proximo != NULL) aux->proximo->anterior = e;
        e->anterior = aux;
        aux->proximo = e;
    }
    return 1;
}
int remove_ultimoListaDupla(ListaDupla* l, int* v){
    if(listaDuplaVazia(l)) return 0;
    else{
        ElementoDuplo* aux = l->inicio;
        if(aux->proximo == NULL){
            *v = aux->valor;
            free(aux);
            l->inicio = NULL;
        }else{
            while (aux->proximo->proximo != NULL) {
                aux = aux->proximo;
        }
            *v = aux->proximo->valor;
            free(aux->proximo);
            aux->proximo = NULL;
        }
        return 1;
    }
}
int remove_posicaoListaDupla(ListaDupla* l, int p, int* v){
    ElementoDuplo *aux = l->inicio;

    if(p < 1 || p > countListaDupla(l)) return 0;
    else if(p == 1){
        l->inicio = l->inicio->proximo;
        l->inicio->anterior = NULL;
        free(aux);
    }else{
        int count = 1;
        while (aux->proximo != NULL && count+1 < p) {
            aux = aux->proximo;
            count++;
        }
        ElementoDuplo *aux2 = aux->proximo;
        *v = aux2->valor;
        if(aux->proximo->proximo != NULL) aux->proximo->proximo->anterior = aux;
        aux->proximo = aux->proximo->proximo;
        free(aux2);
    }
}
int recupera_chaveListaDupla(ListaDupla* l, int v){
    ElementoDuplo *aux = l->inicio;
    int count = 1, retorno = 0;

    while(aux != NULL){
        if(aux->valor == v){
        retorno = count;
        break;
        }else{
            aux = aux->proximo;
            count++;
        }
    }
    return retorno;
}
int recupera_posicaoListaDupla(ListaDupla* l, int p, int* v){
    ElementoDuplo *aux = l->inicio;
    int count = 1;

    while(aux != NULL){
        if(count == p){
            *v = aux->valor;
            return 1;
            break;
        }else{
            aux = aux->proximo;
            count++;
        }
    }
    return 0;
}
int countListaDupla(ListaDupla* l){
    ElementoDuplo* aux = l->inicio;
    int count = 0;
    while(aux != NULL){
        aux = aux->proximo;
        count++;
    }
    return count;
}
int listaDuplaVazia(ListaDupla* l){
    if(l->inicio == NULL) return 1;
    else return 0;
}
void printListaDupla(ListaDupla* l){
    if(listaDuplaVazia(l)) printf("A listaDupla está Vazia!!!\n");
    ElementoDuplo* aux = l->inicio;
    for (int i = 0; aux != NULL; i++) {
        printf("%d° Elemento", i+1);
        // printf("\n\tElemento anterior: %d", (aux->anterior == NULL ? 0 : aux->anterior ));
        printf(": %d\n", aux->valor);
        // printf("\n\tElemento posterior: %d\n", (aux->proximo == NULL ? 0 : aux->proximo ));
        aux = aux->proximo;
    }
}
