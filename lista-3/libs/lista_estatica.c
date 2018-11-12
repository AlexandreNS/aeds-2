typedef struct ListaTag{
  int quant;
  int vetor[100];

} Lista;

Lista* criarLista();
void limparLista(Lista*);
void excluirLista(Lista*);
int insere_ultimoLista(Lista*, int);
int insere_posicaoLista(Lista*, int, int);
int remove_ultimoLista(Lista*, int*);
int remove_posicaoLista(Lista*, int, int*);
int recupera_chaveLista(Lista*, int);
int recupera_posicaoLista(Lista*, int, int*);
int countLista(Lista*);
int listaVazia(Lista*);
void printLista(Lista*);
/* includes */
// int main(int argc, char const *argv[]){
//   Lista* lista = criarLista();
//   insere_ultimoLista(lista, 12);
//   insere_ultimoLista(lista, 13);
//   insere_ultimoLista(lista, 14);
//
//   insere_posicaoLista(lista, 4, 20);
//
//   printLista(lista);
//   return 0;
// }

Lista* criarLista(){
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->quant = 0;
  return l;
}
void limparLista(Lista* l){
  l->quant = 0;
}
void excluirLista(Lista* l){
  free(l);
}
int insere_ultimoLista(Lista* l, int v){
  l->vetor[l->quant] = v;
  l->quant++;
}
int insere_posicaoLista(Lista* l, int p, int v){
  if(p > l->quant+1 || p <= 0) return 0;
  if(p == l->quant+1){
    l->vetor[p-1] = v;
    l->quant++;
  }else{
    for (int i = l->quant+1; i > 0; i--) {
      if(p == i){
        l->vetor[i-1] = v;
        break;
      }
      else l->vetor[i-1] = l->vetor[i-2];
    }
    l->quant++;
  }
}
// int remove_ultimoLista(Lista*, int*){
//
// }
// int remove_posicaoLista(Lista*, int, int*){
//
// }
// int recupera_chaveLista(Lista*, int){
//
// }
// int recupera_posicaoLista(Lista*, int, int*){
//
// }
// int countLista(Lista*){
//
// }
// int listaVazia(Lista*){
//
// }
void printLista(Lista* l){
  printf("\tElementos da Lista:\n");
  for (int i = 0; i < l->quant; i++) {
    printf("%d° %d\n", i+1, l->vetor[i]);
  }
}
