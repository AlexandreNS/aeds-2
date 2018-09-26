typedef struct ElementoTag Elemento;
typedef struct ElementoTag{
  int valor;
  Elemento* proximo;
} Elemento;

typedef struct FilaTag{
  Elemento* inicio;
  Elemento* final;
} Fila;

Fila* criaFila();
void liberaFila(Fila*);
int inserir(Fila*, int);
int retirar(Fila*, int*);
int filaVazia(Fila*);

Fila* criaFila(){
  Fila *f = (Fila*)malloc(sizeof(Fila));
  f->inicio = NULL;
  f->final = NULL;
}
void liberaFila(Fila* f){
  while(f->inicio != NULL){
    Elemento *aux = f->inicio;
    f->inicio = f->inicio->proximo;

    if(f->inicio == NULL) f->final = NULL;
    free(aux);
  }
}
int inserir(Fila* f, int v){
  Elemento *e = (Elemento*)malloc(sizeof(Elemento));
  e->valor = v;
  e->proximo = NULL;

  if(filaVazia(f)) f->inicio = e;
  else f->final->proximo = e;

  f->final = e;
}
int retirar(Fila* f, int* v){
  if(filaVazia(f)) return 0;
  else{
    *v = f->inicio->valor;
    Elemento *aux = f->inicio;
    f->inicio = f->inicio->proximo;

    if(f->inicio == NULL) f->final = NULL;
    free(aux);

    return 1;
  }

}
int filaVazia(Fila* f){
  if(f->inicio == NULL && f->final == NULL) return 1;
  else return 0;
}
