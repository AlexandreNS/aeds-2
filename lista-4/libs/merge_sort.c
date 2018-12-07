void intercala_nome(int a[], int n);
void mergeSort_nome(int a[], int n);

void intercala_matricula(int a[], int n);
void mergeSort_matricula(int a[], int n);

void intercala_nota(int a[], int n);
void mergeSort_nota(int a[], int n);

void intercala_nome(int a[], int n)
{
  int *tmp = (int*)malloc(n*sizeof(int));
  int meio = n / 2;
  int i, j, k;
  i = 0;
  j = meio;
  k = 0;

  while (i < meio && j < n){
    if ( strcmp(a[i].nome, a[j].nome) < 0){
      strcpy(tmp[k].nome, a[i].nome);
      ++i;
    } else {
      strcpy(tmp[k].nome, a[j].nome);
      ++j;
    }
    ++k;
  }
  if (i == meio) {

    while (j < n) {
      strcpy(tmp[k].nome, a[j].nome);
      ++j;
      ++k;
    }

  } else {

    while (i < meio) {
      strcpy(tmp[k].nome, a[i].nome);
      ++i;
      ++k;
    }
  }
  for (i = 0; i < n; ++i){
    strcpy(tmp[i].nome, a[i].nome);
  }
  free(tmp);
  tmp = NULL;
}
void mergeSort_nome(int a[], int n){
  int k;
  if(n > 1){
    k = n/2;
    mergeSort(a, k);
    mergeSort(a+k, n-k);
    intercala(a, n);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void intercala_matricula(int a[], int n)
{
  int *tmp = (int*)malloc(n*sizeof(int));
  int meio = n / 2;
  int i, j, k;
  i = 0;
  j = meio;
  k = 0;

  while (i < meio && j < n){
    if (a[i].nome < a[j].nome){
      strcpy(tmp[k].nome, a[i].nome);
      ++i;
    } else {
      strcpy(tmp[k].nome, a[j].nome);
      ++j;
    }
    ++k;
  }
  if (i == meio) {

    while (j < n) {
      strcpy(tmp[k].nome, a[j].nome);
      ++j;
      ++k;
    }

  } else {

    while (i < meio) {
      strcpy(tmp[k].nome, a[i].nome);
      ++i;
      ++k;
    }
  }
  for (i = 0; i < n; ++i){
    strcpy(tmp[i].nome, a[i].nome);
  }
  free(tmp);
  tmp = NULL;
}
void mergeSort_matricula(int a[], int n){
  int k;
  if(n > 1){
    k = n/2;
    mergeSort(a, k);
    mergeSort(a+k, n-k);
    intercala(a, n);
  }
}
