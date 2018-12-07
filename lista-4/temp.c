#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int a[], int n);
void particionar(int esq, int dir, int *i, int *j, int a[]);
void printVetor(int a[], int n);
void ordenar(int esq, int dir, int a[]);
void quickSort(int a[], int n);
void mergeSort(int a[], int n);


int main(){

    clock_t ti_1, tf_1, ti_2, tf_2; 
    double tempo_1, tempo_2;
    srand(time(NULL));
    int *v_1, *v_2;

    int n, j = 0;
	int temp;
	for(n = 100; n < 5000000; n = n + 50000){




		v_1 = (int *) malloc(n*sizeof(int));
		v_2 = (int *) malloc(n*sizeof(int));

		for (int i=0; i<n; ++i){

			temp = 100-i;
		    v_1[i] = temp;
			v_2[i] = temp;
		}
		    ti_1 = clock();


			mergeSort(v_1, n);



		    tf_1 = clock();

			ti_2 = clock();


			quickSort(v_2, n);



		    tf_2 = clock();

		    tempo_1 = ( (double) (tf_1 - ti_1) ) / CLOCKS_PER_SEC;
		    tempo_2 = ( (double) (tf_2 - ti_2) ) / CLOCKS_PER_SEC;
			printf("Teste %d\n", j++);
		    printf("\tTempo para ordenar %d elementos pelo metodo mergeSort: %f \n", n, tempo_1);

		    printf("\tTempo para ordenar %d elementos pelo metodo quickSort: %f \n", n, tempo_2);

			printf("\n\n");

		    free(v_1);
		    free(v_2);
	}
        return 0;
}


void intercala(int a[], int n)
{
	int *tmp = (int*)malloc(n*sizeof(int));
    int meio = n / 2;
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
void mergeSort(int a[], int n){
	int k;
	if(n > 1){
		k = n/2;
		mergeSort(a, k);
		mergeSort(a+k, n-k);
		intercala(a, n);
	}
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
void printVetor(int a[], int n){
	for(int i = 0; i < n; i++) printf("%d\t", a[i]);
	printf("\n");
}
