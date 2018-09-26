#define TAM 100

typedef struct PilhaTag{
  int topo;
  int vetor[TAM];
} Pilha;

Pilha* criaPilha();
void excluirPilha(Pilha*);
void liberaPilha(Pilha*);
int empilha(Pilha*, int);
int desempilha(Pilha*, int*);
int pilhaVazia(Pilha*);
int pilhaCheia(Pilha*);

Pilha* criaPilha(){
  Pilha* p;
  p = (Pilha*)malloc(sizeof(Pilha));
  p->topo = 0;
  return p;
}
void excluirPilha(Pilha* p){
  free(p);
}
void liberaPilha(Pilha* p){
  p->topo = 0;
}
int empilha(Pilha* p, int v){
  if(pilhaCheia(p)) return 0;
  else{
    p->vetor[p->topo] = v;
    p->topo++;
    return 1;
  }
}
int desempilha(Pilha* p, int* v){
  if(pilhaVazia(p)) return 0;
  else{
    *v = p->vetor[p->topo-1];
    p->topo--;
    return 1;
  }
}
int pilhaVazia(Pilha* p){
  if(p->topo <= 0) return 1;
  else return 0;
}
int pilhaCheia(Pilha* p){
  if(p->topo >= TAM) return 1;
  else return 0;
}
