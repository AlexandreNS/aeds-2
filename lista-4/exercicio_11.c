#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printVetor(char texto[],int a[], int n);
void intercala(int a[], int n, int meio);
void mergeSort(int a[], int n);
// void mergeSort_comum(int a[], int n);
int main(int argc, char const *argv[]){
  int numbers[] = {94,56,13,85,23,85,12,64,1};
  printVetor("vetor: ", numbers, 9);
  // mergeSort_comum(numbers, 10);
  mergeSort(numbers, 9);
  printVetor("vetor: ", numbers, 9);
  return 0;
}
void intercala(int a[], int n, int meio){
  int *tmp = (int*)malloc(n*sizeof(int));
  // int meio = n / 2;
  int i, j, k;
  i = 0;
  j = meio;
  k = 0;
  while (i < meio && j < n){
    if (a[i] < a[j]){
      tmp[k] = a[i];
      ++i;
    } else {
      tmp[k] = a[j];
      ++j;
    }
    ++k;
  }
  if (i == meio) {
    while (j < n) {
      tmp[k] = a[j];
      ++j;
      ++k;
    }
  } else {
    while (i < meio) {
      tmp[k] = a[i];
      ++i;
      ++k;
    }
  }
  for (i = 0; i < n; ++i){
    a[i] = tmp[i];
  }
  free(tmp);
  tmp = NULL;
}
void mergeSort(int a[], int n){
  int i1 = (int)ceil(log2f(n));
  int res = 0;
  for(int i = 2; i < pow(2,i1); i = 2*i){
    for (int j = 0; j <= n+i; j += i) {
      if(j+i > n) intercala(a+j, n%i, (n%i)/2 );
      else intercala(a+j, i, i/2);
    }
    res = i;
  }
  intercala(a, n, res);
}
// void mergeSort_comum(int a[], int n){
//   int k;
//   if(n > 1){
//     k = n/2;
//     mergeSort_comum(a, k);
//     mergeSort_comum(a+k, n-k);
//     intercala(a, n, n/2);
//   }
// }
void printVetor(char texto[], int a[], int n){
  printf("%s", texto);
  for (int i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
}
