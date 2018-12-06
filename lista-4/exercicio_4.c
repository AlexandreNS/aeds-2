#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* includes */
void printVetor(char texto[], char a[], int n);
void ordena_chars(char a[], int n);

int main(int argc, char const *argv[]){
  srand(time(NULL));
  char v[11];
  for (int i = 9; i >= 0; i--) {
    v[9-i] = i + 65;
  }
  printf("String :%s\n", v);
  ordena_chars(v, 10);
  printf("String ordenada :%s\n", v);

  return 0;
}
void ordena_chars(char a[], int n){
  char aux;
  for (int i = 0; i < n-1; i++) {
    for (int j = 1; j < n-i; j++) {
      if ((int)a[j] < (int)a[j-1]) {
        aux = a[j];
        a[j] = a[j-1];
        a[j-1] = aux;
      }
    }
  }
}
void printVetor(char texto[], char a[], int n){
  printf("%s", texto);
  for (int i = 0; i < n; i++) {
    printf("%c\t", a[i]);
  }
  printf("\n");
}
