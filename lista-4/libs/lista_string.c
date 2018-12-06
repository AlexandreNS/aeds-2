typedef struct ElementoTag Elemento;
typedef struct ElementoTag{
  char nome[50];
  Elemento* proximo;
} Elemento;

typedef struct ListaTag{
  Elemento *inicio;
}Lista;

Lista* criarLista();
void limparLista(Lista*);
void excluirLista(Lista*);
int insere_posicaoLista(Lista*, int, char*);
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
int insere_posicaoLista(Lista* l, int p, char* v){
  Elemento* e = (Elemento*)malloc(sizeof(Elemento));
  strcpy(e->nome, v);
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
  if(listaVazia(l)) printf("Não há nomes na lista!!!\n");
  Elemento* aux = l->inicio;
  for (int i = 0; aux != NULL; i++) {
    printf("%d° Nome : %s\n", i+1, aux->nome);
    aux = aux->proximo;
  }
}
