#include <stdio.h>
#include <stdlib.h>
/* includes */
int insertionSort(int a[], int n);
void printVetor(char texto[],int a[], int n);

int main(int argc, char const *argv[]){
  int a[10] = {72,12,62,69,27,67,41,56,33,74};
  printVetor("Vetor orginal: ", a, 10);
  printf("Houve %d copias de valores\n", insertionSort(a, 10));
  printVetor("Vetor ordenado: ", a, 10);
  return 0;
}
int insertionSort(int a[], int n){
  int move = 0;
  int j, x;
  for(int i = 1; i < n; i++){
    x = a[i];
    j = i-1;
    while(x < a[j] && j >= 0){
      a[j+1] = a[j];
      j--;
      move++;
    }
    a[j+1] = x;
  }
  return move;
}
void printVetor(char texto[], int a[], int n){
  printf("%s", texto);
  for (int i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
}
