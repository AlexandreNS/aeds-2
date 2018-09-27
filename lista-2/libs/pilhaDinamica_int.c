typedef struct PilhaTag{
  Elemento *topo;
} Pilha;

Pilha* criaPilha();
void liberaPilha(Pilha*);
int empilha(Pilha*, int);
int desempilha(Pilha*, int*);
int pilhaVazia(Pilha*);
int pilhaCheia(Pilha*);

Pilha* criaPilha(){
  Pilha* p;
  p = (Pilha*)malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}
void liberaPilha(Pilha* p){
  while(p->topo != NULL){
    Elemento* aux;
    aux = p->topo;
    p->topo = aux->proximo;
    free(aux);
  }
}
int empilha(Pilha* p, int v){
  Elemento* e;
  e = (Elemento*)malloc(sizeof(Elemento));
  e->valor = v;
  e->proximo = p->topo;
  p->topo = e;
  return 1;
}
int desempilha(Pilha* p, int* v){
  if(pilhaVazia(p)) return 0;
  else{
    Elemento* aux;
    aux = p->topo;

    *v = aux->valor;
    p->topo = aux->proximo;

    free(aux);
    return 1;
  }
}
int pilhaVazia(Pilha* p){
  if(p->topo == NULL) return 1;
  else return 0;
}
