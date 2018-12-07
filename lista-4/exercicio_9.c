#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particionar(int esq, int dir, int *i, int *j, int a[]);
void ordenar(int esq, int dir, int a[]);
void quickSort(int a[], int n);

void particionar_rand(int esq, int dir, int *i, int *j, int a[]);
void ordenar_rand(int esq, int dir, int a[]);
void quickSort_rand(int a[], int n);

void particionar_rand_3(int esq, int dir, int *i, int *j, int a[]);
void ordenar_rand_3(int esq, int dir, int a[]);
void quickSort_rand_3(int a[], int n);

int insertionSort(int a[], int n);
void printVetor(int a[], int n);

int main(){
  clock_t ti_1, tf_1, ti_2, tf_2, ti_3, tf_3;
  double tempo_1, tempo_2, tempo_3;
  srand(time(NULL));
  int *v_1, *v_2, *v_3;
  int n, j = 0;
  int temp;
  for(n = 100; n < 5000000; n = n + 50000){
  // for(n = 1; n < 15; n++){
    v_1 = (int *) malloc(n*sizeof(int));
    v_2 = (int *) malloc(n*sizeof(int));
    v_3 = (int *) malloc(n*sizeof(int));
    for (int i=0; i<n; ++i){
      temp = rand() % (n*3) + 1;
      v_1[i] = temp;
      v_2[i] = temp;
      v_3[i] = temp;
    }
////////////////////////////////////////////////////////////////////////////////
    ti_1 = clock();
    quickSort(v_1, n);
    tf_1 = clock();
////////////////////////////////////////////////////////////////////////////////
    ti_2 = clock();
    quickSort_rand(v_2, n);
    tf_2 = clock();
////////////////////////////////////////////////////////////////////////////////
    ti_3 = clock();
    quickSort_rand_3(v_3, n);
    tf_3 = clock();
////////////////////////////////////////////////////////////////////////////////
    tempo_1 = ( (double) (tf_1 - ti_1) ) / CLOCKS_PER_SEC;
    tempo_2 = ( (double) (tf_2 - ti_2) ) / CLOCKS_PER_SEC;
    tempo_3 = ( (double) (tf_3 - ti_3) ) / CLOCKS_PER_SEC;
    printf("Teste %d\n", j++);
    printf("\tTempo para ordenar %d elementos com pivo do meio: %f \n", n, tempo_1);
    printf("\tTempo para ordenar %d elementos com pivo aleatorio: %f \n", n, tempo_2);
    printf("\tTempo para ordenar %d elementos com pivo 3 nums aleatorios: %f \n", n, tempo_3);

    printf("\n\n");

    free(v_1);
    free(v_2);
    free(v_3);
  }
  return 0;
}
void particionar(int esq, int dir, int *i, int *j, int a[]) {
  int x, temp;
  *i = esq;
  *j = dir;

  x = a[(*i + *j) / 2];
  do
  {
    while (x > a[*i]){
      (*i)++;
    }
    while (x < a[*j]){
      (*j)--;
    }
    if (*i <= *j){
      temp = a[*i];
      a[*i] = a[*j];
      a[*j] = temp;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}
void quickSort(int a[], int n){
  ordenar(0, n-1, a);
}
void ordenar(int esq, int dir, int a[]){
  int i, j;
  particionar(esq, dir, &i, &j, a);
  if(esq < j) ordenar(esq, j, a);
  if(i < dir) ordenar(i, dir, a);
}
////////////////////////////////////////////////////////////////////////////////
void particionar_rand(int esq, int dir, int *i, int *j, int a[]) {
  int x, temp;
  *i = esq;
  *j = dir;
  // int indice_pivo = (*i + *j)/2;
  int indice_pivo = (rand()%(*j - *i + 1))+(*i);
  x = a[indice_pivo];
  do
  {
    while (x > a[*i]){
      (*i)++;
    }
    while (x < a[*j]){
      (*j)--;
    }
    if (*i <= *j){
      temp = a[*i];
      a[*i] = a[*j];
      a[*j] = temp;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}
void quickSort_rand(int a[], int n){
  ordenar_rand(0, n-1, a);
}
void ordenar_rand(int esq, int dir, int a[]){
  int i, j;
  particionar_rand(esq, dir, &i, &j, a);
  if(esq < j) ordenar_rand(esq, j, a);
  if(i < dir) ordenar_rand(i, dir, a);
}
////////////////////////////////////////////////////////////////////////////////
void particionar_rand_3(int esq, int dir, int *i, int *j, int a[]) {
  int x, temp;
  *i = esq;
  *j = dir;
  int indices_pivo[3];
  indices_pivo[0] = (rand()%(*j - *i + 1))+(*i);
  indices_pivo[1] = (rand()%(*j - *i + 1))+(*i);
  indices_pivo[2] = (rand()%(*j - *i + 1))+(*i);

  insertionSort(indices_pivo, 3);
  x = a[indices_pivo[1]];
  do
  {
    while (x > a[*i]){
      (*i)++;
    }
    while (x < a[*j]){
      (*j)--;
    }
    if (*i <= *j){
      temp = a[*i];
      a[*i] = a[*j];
      a[*j] = temp;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}
void quickSort_rand_3(int a[], int n){
  ordenar_rand_3(0, n-1, a);
}
void ordenar_rand_3(int esq, int dir, int a[]){
  int i, j;
  particionar_rand_3(esq, dir, &i, &j, a);
  if(esq < j) ordenar_rand_3(esq, j, a);
  if(i < dir) ordenar_rand_3(i, dir, a);
}
////////////////////////////////////////////////////////////////////////////////
int insertionSort(int a[], int n){
  int j, x;
  for(int i = 1; i < n; i++){
    x = a[i];
    j = i-1;
    while(x < a[j] && j >= 0){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = x;
  }
}
void printVetor(int a[], int n){
  for(int i = 0; i < n; i++) printf("%d\t", a[i]);
  printf("\n");
}
