typedef struct produto{
  int codProd;
  char nomeProd[10];
  float valor;
  int qtdeEstoque;
}Produto;
typedef struct ElementoTag Elemento;

typedef struct ElementoTag{
  Produto valor;
  Elemento* proximo;
} Elemento;
