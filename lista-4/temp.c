/*
Copie este arquivo para seu computador e complete o codigo fazendo o que e pedido em cada um dos exercicios dos comentarios.

Exercicio de compreensao das tecnicas de ordenacao por MergeSort e por QuickSort.

 1) Analise o codigo abaixo.
	a) Veja que incluimos as bibliotecas stdlib.h e time neste codigo. Elas permitem geracao de numeros aleatorios e medir tempo.
	b) Veja que criamos um arranjo dinamicamente com o tamanho pedido.
	c) Veja que a funcao rand() gera numeros aleatorios que sao inseridos no arranjo.
	d) Veja que temos algumas funcoes que nao sao utilizadas ainda (intercala e particiona).

 2) Veja a função intercala:
	a) Ela recebe um arranjo que comeca no endereco a e seu tamanho n
	b) Se a primeira metade do arranjo (de a[0] até a[n/2]) e a segunda metade (de a[n/2+1] ate a[n-1]) estiverem ordenadas
			a funcao faz a intercalacao dos dois e deixa o arranjo inteiro ordenado
	c) Utilize a funcao para fazer uma funcao que ordene um arranjo com o mergeSort.

 3) Veja a funcao particionar:
	a) Ela recebe um arranjo e particiona os elementos entre a[esq] e a[dir].
	b) Apos fazer o particionamento ela guarda as posicoes finais nos elementos i e j, que sao passados por referencia
	c) O particionamento com os elementos menores fiquem entre a[esq] e a[j]. Os elementos maiores ficam entre a[i] e a[dir].
	d) Utilize esta funcao para fazer uma funcao que ordena um arranjo com o quickSort.

 4) Altere o codigo de modo que as duas ordenacoes sejam usadas e compare o tempo entre as duas

 5) Coloque o codigo dentro de um for
	a) Faca com que neste for, a variavel contadora seja utilizada para testar os algoritmos em arranjos de varios tamanhos
	b) Altere o codigo de modo que ele imprima apenas o tamanho do arranjo, o tempo com uma ordenacao, e o tempo com a outra
	c) Qual e a relacao entre os algoritmos e o tamanho do arranjo?

 6) No geral, qual a relacao entre os dois metodos de ordenacao?

*/

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

    clock_t ti_1, tf_1, ti_2, tf_2; //variaveis que serao usadas para controlar o tempo gasto na ordenacao
    double tempo_1, tempo_2; //variavel que armazenara a diferenca entre o tempo final e o tempo inicial gasto na ordenacao
    srand(time(NULL)); // inicializa um gerador de numeros aleatorios que sera usado na funcao de embaralhar o arranjo
    int *v_1, *v_2;  // ponteiro para o arranjo na memoria que sera alocado com tamanho n

    int n, j = 0; // variavel que contera o tamanho do arranjo
	int temp; // valor temporario
	for(n = 100; n < 5000000; n = n + 50000){
	//for(n = 1; n < 20; n++){
		//printf("Digite o tamanho do arranjo: ");
		//scanf("%d", &n);

		v_1 = (int *) malloc(n*sizeof(int)); //alocacao de memoria para o vetor
		v_2 = (int *) malloc(n*sizeof(int)); //alocacao de memoria para o vetor

		for (int i=0; i<n; ++i){
			//temp = rand() % (n*3) + 1;
			temp = 100-i;
		    v_1[i] = temp; // numero entre 1 e n*3
			v_2[i] = temp; // numero entre 1 e n*3
		}
		    ti_1 = clock();
		    // Chame a sua função de ordenação aqui
			//printVetor(v_1, n);
			mergeSort(v_1, n);
			//printVetor(v_1, n);

		    // Termina de medir tempo
		    tf_1 = clock();

			ti_2 = clock();
		    // Chame a sua função de ordenação aqui
			//printVetor(v_2, n);
			quickSort(v_2, n);
			//printVetor(v_2, n);

		    // Termina de medir tempo
		    tf_2 = clock();

		    tempo_1 = ( (double) (tf_1 - ti_1) ) / CLOCKS_PER_SEC;
		    tempo_2 = ( (double) (tf_2 - ti_2) ) / CLOCKS_PER_SEC;
			printf("Teste %d\n", j++);
		    printf("\tTempo para ordenar %d elementos pelo metodo mergeSort: %f \n", n, tempo_1);
			//printVetor(v_1, n);
		    printf("\tTempo para ordenar %d elementos pelo metodo quickSort: %f \n", n, tempo_2);
			//printVetor(v_2, n);
			printf("\n\n");
		    //libera a memoria gasta
		    free(v_1);
		    free(v_2);
	}
        return 0;
}


void intercala(int a[], int n)
{
	int *tmp = (int*)malloc(n*sizeof(int)); // Arranjo temporario para intercalacao
    int meio = n / 2; // Indice que marca o meio do arranjo
	int i, j, k; //Indices para a estrutura de repeticao
    i = 0; // Indice i marca itens intercalados do primeiro arranjo
	j = meio; // Indice j marca itens intercalados do segundo arranjo
	k = 0; // Indice k marca itens ja intercalados no arranjo temporario
	// Enquanto os indices i e j não tenham chegado ao fim de seus arranjos
	while (i < meio && j < n){
		// colocamos o menor item entre a[i] e a[j] no arranjo temporario
		if (a[i] < a[j]){
			tmp[k] = a[i];
			++i;
		} else {
			tmp[k] = a[j];
			++j;
		}
		++k;
	}
	// se o indice i chegou ao fim de seu arranjo primeiro
	if (i == meio) {
		// os outros elementos do segundo arranjo vao para o arranjo temporario
		while (j < n) {
			tmp[k] = a[j];
			++j;
			++k;
		}
		// se foi o índice j que chegou ao fim de seu arranjo primeiro
	} else {
		// os outros elementos do primeiro arranjo vao para o arranjo temporario
		while (i < meio) {
			tmp[k] = a[i];
			++i;
			++k;
		}
	}
	// neste ponto, o arranjo temporario tem todos os elementos intercalados
	// estes elementos sao copiados de volta para o arranjo int a[]
	for (i = 0; i < n; ++i){
			a[i] = tmp[i];
	}
	// o arranjo temporario pode entao ser desalocado da memoria
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
