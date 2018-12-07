#include <stdio.h>
#include <stdlib.h>
/* includes */

void insertion_vector(int *a, int n, int v);

int main(int argc, char const *argv[]){
  int n = 5;
  int add = -10;
  int *a = (int*)malloc(n*sizeof(int));

  for (int i = 1; i <= n; i++) a[i-1] = i*4+1;
  printf("vetor original: ");
  for (int i = 0; i < n; i++) printf("%d\t", a[i]);
  printf("\n\nNumero adicionado: %d", add);
///////////////////////////////
  insertion_vector(a, n, add);
///////////////////////////////

  printf("\n\nvetor com adição: ");
  for (int i = 0; i < n+1; i++) printf("%d\t", a[i]);
  printf("\n");

  return 0;
}

void insertion_vector(int *a, int n, int v){
  a = (int*)realloc(a, (n+1)*sizeof(int));
  int i = n-1;
  while(a[i] > v && i > -1){
    a[i+1] = a[i];
    i--;
  }
  a[i+1] = v;
}
