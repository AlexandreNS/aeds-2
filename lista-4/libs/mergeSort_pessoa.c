void intercala_nome(Pessoa a[], int n);
void mergeSort_nome(Pessoa a[], int n);

void intercala_matricula(Pessoa a[], int n);
void mergeSort_matricula(Pessoa a[], int n);

void intercala_nota(Pessoa a[], int n);
void mergeSort_nota(Pessoa a[], int n);

void intercala_nome(Pessoa a[], int n)
{
  Pessoa *tmp = (Pessoa*)malloc(n*sizeof(Pessoa));
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
    strcpy(a[i].nome, tmp[i].nome);
  }
  free(tmp);
  tmp = NULL;
}
void mergeSort_nome(Pessoa a[], int n){
  int k;
  if(n > 1){
    k = n/2;
    mergeSort_nome(a, k);
    mergeSort_nome(a+k, n-k);
    intercala_nome(a, n);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void intercala_matricula(Pessoa a[], int n)
{
  Pessoa *tmp = (Pessoa*)malloc(n*sizeof(Pessoa));
  int meio = n / 2;
  int i, j, k;
  i = 0;
  j = meio;
  k = 0;

  while (i < meio && j < n){
    if (a[i].matricula < a[j].matricula){
      tmp[k].matricula = a[i].matricula;
      ++i;
    } else {
      tmp[k].matricula = a[j].matricula;
      ++j;
    }
    ++k;
  }
  if (i == meio) {

    while (j < n) {
      tmp[k].matricula = a[j].matricula;
      ++j;
      ++k;
    }

  } else {

    while (i < meio) {
      tmp[k].matricula = a[i].matricula;
      ++i;
      ++k;
    }
  }
  for (i = 0; i < n; ++i){
    a[i].matricula = tmp[i].matricula;
  }
  free(tmp);
  tmp = NULL;
}
void mergeSort_matricula(Pessoa a[], int n){
  int k;
  if(n > 1){
    k = n/2;
    mergeSort_matricula(a, k);
    mergeSort_matricula(a+k, n-k);
    intercala_matricula(a, n);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void intercala_nota(Pessoa a[], int n)
{
  Pessoa *tmp = (Pessoa*)malloc(n*sizeof(Pessoa));
  int meio = n / 2;
  int i, j, k;
  i = 0;
  j = meio;
  k = 0;

  while (i < meio && j < n){
    if (a[i].nota < a[j].nota){
      tmp[k].nota = a[i].nota;
      ++i;
    } else {
      tmp[k].nota = a[j].nota;
      ++j;
    }
    ++k;
  }
  if (i == meio) {

    while (j < n) {
      tmp[k].nota = a[j].nota;
      ++j;
      ++k;
    }

  } else {

    while (i < meio) {
      tmp[k].nota = a[i].nota;
      ++i;
      ++k;
    }
  }
  for (i = 0; i < n; ++i){
    a[i].nota = tmp[i].nota;
  }
  free(tmp);
  tmp = NULL;
}
void mergeSort_nota(Pessoa a[], int n){
  int k;
  if(n > 1){
    k = n/2;
    mergeSort_nota(a, k);
    mergeSort_nota(a+k, n-k);
    intercala_nota(a, n);
  }
}
