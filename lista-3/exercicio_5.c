#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/elemento_produto.c"
#include "libs/lista_dinamica_produto.c"
/* includes */
int min_preco_lista(Lista*, Produto*);
void preenche_lista(Lista*);
void preenche_produtos(Produto*);

int main(int argc, char const *argv[]){
  Lista *lista_produto = criarLista();
  preenche_lista(lista_produto);
  Produto min;

  min_preco_lista(lista_produto, &min);
  printLista(lista_produto);

  printf("*************Produto Menor Preço codProd - %d********************\n", min.codProd);
  printf("\tnomeProd: %s\n", min.nomeProd);
  printf("\tvalor: %f\n", min.valor);
  printf("\tqtdeEstoque: %d\n\n", min.qtdeEstoque);


  return 0;
}
int min_preco_lista(Lista* l, Produto* retorno){
  if(listaVazia(l)) return 0;
  else{
    float min_preco;
    Elemento *aux = l->inicio;

    min_preco = aux->valor.valor;
    *retorno = aux->valor;

    aux = aux->proximo;
    while (aux != NULL) {
      if(min_preco > aux->valor.valor){
        *retorno = aux->valor;
        min_preco = aux->valor.valor;
      }
      aux = aux->proximo;
    }
  }

}
void preenche_lista(Lista* l){
  Produto produtos[10];
  preenche_produtos(produtos);
  for (int i = 0; i < 5; i++) {
    insere_ultimoLista(l, produtos[i]);
  }
}

void preenche_produtos(Produto* produtos){
  char nomes[10][20] = {"Sabão", "Suco em Pó", "Sabonete", "Arroz", "Feijão",
  "Tomate", "Batata", "Melancia", "Refrigerante", "Biscoito"};

  float valores[10] = {12.5, 2.5, 4.7, 5.6,
  7.8, 9.0, 10.2, 20.2, 40.5, 60.9};

  for (int i = 0; i < 10; i++) {
    produtos[i].codProd = 1000+i;
    produtos[i].qtdeEstoque = i*i+i+7;
    strcpy(produtos[i].nomeProd, nomes[i]);
    produtos[i].valor = valores[i];
  }
}
