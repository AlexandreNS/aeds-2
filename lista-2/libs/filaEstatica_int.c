#define TAM 100

typedef struct FilaTag{
  int comeco;
  int final;
  int vetor[TAM];
} Fila;

Fila* criaFila();
void liberaFila(Fila*);
void excluirFila(Fila*);
int inserir(Fila*, int);
int retirar(Fila*, int*);
int filaVazia(Fila*);
int filaCheia(Fila*);

Fila* criaFila(){
  Fila* f;
  f = (Fila*)malloc(sizeof(Fila));
  f->comeco = 0;
  f->final = 0;
  return f;
}
void excluirFila(Fila* f){
  free(f);
}
void liberaFila(Fila* f){
  f->comeco = 0;
  f->final = 0;
}
int inserir(Fila* f, int v){
  if(filaCheia(f)) return 0;
  else{
    f->vetor[f->final] = v;
    f->final++;
    return 1;
  }
}
int retirar(Fila* f, int* v){
  if(filaVazia(f)) return 0;
  else{
    *v = f->vetor[f->comeco];
    f->comeco++;
    return 1;
  }
}
int filaVazia(Fila* f){
  if(f->comeco == f->final) return 1;
  else return 0;
}
int filaCheia(Fila* f){
  if(f->final == TAM) return 1;
  else return 0;
}
