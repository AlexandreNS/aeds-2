typedef struct ListaTag{
  Elemento *inicio;
}Lista;

Lista* criarLista();
void limparLista(Lista*);
void excluirLista(Lista*);
int insere_ultimoLista(Lista*, Produto);
int insere_posicaoLista(Lista*, int, Produto);
int remove_ultimoLista(Lista*, Produto*);
int remove_posicaoLista(Lista*, int, Produto*);
int recupera_chaveLista(Lista*, Produto);
int recupera_posicaoLista(Lista*, int, Produto*);
int countLista(Lista*);
int listaVazia(Lista*);
void printLista(Lista*);

Lista* criarLista(){
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->inicio = NULL;
  return l;
}
void limparLista(Lista* l){
  Elemento* aux_prox = l->inicio;
  Elemento* aux_ant;
  while(aux_prox != NULL){
    aux_ant = aux_prox;
    aux_prox = aux_prox->proximo;
    free(aux_ant);
  }
  l->inicio = NULL;
}
void excluirLista(Lista* l){
  limparLista(l);
  free(l);
}
int insere_ultimoLista(Lista* l, Produto v){
  Elemento* e = (Elemento*)malloc(sizeof(Elemento));
  e->proximo = NULL;
  e->valor = v;
  if(listaVazia(l)) l->inicio = e;
  else{
    Elemento* aux;
    aux = l->inicio;
    while(aux->proximo != NULL) aux = aux->proximo;
    aux->proximo = e;
  }
  return 1;
}
int insere_posicaoLista(Lista* l, int p, Produto v){
  Elemento* e = (Elemento*)malloc(sizeof(Elemento));
  e->valor = v;
  e->proximo = NULL;

  if(p < 1 || p > countLista(l)+1) return 0;
  else if(listaVazia(l)) l->inicio = e;
  else if(p == 1){
    e->proximo = l->inicio;
    l->inicio = e;
  }else{
    Elemento* aux = l->inicio;
    int count = 1;
    while(aux != NULL && count+1 < p){
      aux = aux->proximo;
      count++;
    }
    e->proximo = aux->proximo;
    aux->proximo = e;
  }
  return 1;
}
int remove_ultimoLista(Lista* l, Produto* v){
  if(listaVazia(l)) return 0;
  else{
    Elemento* aux = l->inicio;
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
int remove_posicaoLista(Lista* l, int p, Produto* v){
  Elemento *aux = l->inicio;

  if(p < 1 || p > countLista(l)) return 0;
  else if(p == 1){
    l->inicio = l->inicio->proximo;
    free(aux);
  }else{
    int count = 1;
    while (aux->proximo != NULL && count+1 < p) {
      aux = aux->proximo;
      count++;
    }
    Elemento *aux2 = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(aux2);
  }
}
int recupera_chaveLista(Lista* l, Produto v){
  Elemento *aux = l->inicio;
  int count = 1, retorno = 0;

  while(aux != NULL){
    if(aux->valor.codProd == v.codProd){
      retorno = count;
      break;
    }else{
      aux = aux->proximo;
      count++;
    }
  }
  return retorno;
}
int recupera_posicaoLista(Lista* l, int p, Produto *v){
  Elemento *aux = l->inicio;
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
int countLista(Lista* l){
  Elemento* aux = l->inicio;
  int count = 0;
  while(aux != NULL){
    aux = aux->proximo;
    count++;
  }
  return count;
}
int listaVazia(Lista* l){
  if(l->inicio == NULL) return 1;
  else return 0;
}
void printLista(Lista* l){
  if(listaVazia(l)) printf("A lista está Vazia!!!\n");
  Elemento* aux = l->inicio;
  for (int i = 0; aux != NULL; i++) {
    printf("Produto codProd - %d\n", aux->valor.codProd);
    printf("\tnomeProd: %s\n", aux->valor.nomeProd);
    printf("\tvalor: %f\n", aux->valor.valor);
    printf("\tqtdeEstoque: %d\n\n", aux->valor.qtdeEstoque);
    aux = aux->proximo;
  }
}
