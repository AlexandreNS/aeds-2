void particionar_nome(int esq, int dir, int *i, int *j, Pessoa a[]);
void quickSort_nome(Pessoa a[], int n);
void ordenar_nome(int esq, int dir, Pessoa a[]);

void particionar_matricula(int esq, int dir, int *i, int *j, Pessoa a[]);
void quickSort_matricula(Pessoa a[], int n);
void ordenar_matricula(int esq, int dir, Pessoa a[]);

void particionar_nota(int esq, int dir, int *i, int *j, Pessoa a[]);
void quickSort_nota(Pessoa a[], int n);
void ordenar_nota(int esq, int dir, Pessoa a[]);

void particionar_nome(int esq, int dir, int *i, int *j, Pessoa a[]) {
  Pessoa x, temp;
  *i = esq;
  *j = dir;

  x = a[(*i + *j) / 2];
  do
  {
    while (strcmp(x.nome, a[*i].nome) > 0){
      (*i)++;
    }
    while (strcmp(x.nome, a[*j].nome) < 0){
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
void quickSort_nome(Pessoa a[], int n){
  ordenar_nome(0, n-1, a);
}
void ordenar_nome(int esq, int dir, Pessoa a[]){
  int i, j;
  particionar_nome(esq, dir, &i, &j, a);
  if(esq < j) ordenar_nome(esq, j, a);
  if(i < dir) ordenar_nome(i, dir, a);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void particionar_nota(int esq, int dir, int *i, int *j, Pessoa a[]) {
  Pessoa x, temp;
  *i = esq;
  *j = dir;

  x = a[(*i + *j) / 2];
  do
  {
    while (x.nota > a[*i].nota){
      (*i)++;
    }
    while (x.nota < a[*j].nota){
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
void quickSort_nota(Pessoa a[], int n){
  ordenar_nota(0, n-1, a);
}
void ordenar_nota(int esq, int dir, Pessoa a[]){
  int i, j;
  particionar_nota(esq, dir, &i, &j, a);
  if(esq < j) ordenar_nota(esq, j, a);
  if(i < dir) ordenar_nota(i, dir, a);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void particionar_matricula(int esq, int dir, int *i, int *j, Pessoa a[]) {
  Pessoa x, temp;
  *i = esq;
  *j = dir;

  x = a[(*i + *j) / 2];
  do
  {
    while (x.matricula > a[*i].matricula){
      (*i)++;
    }
    while (x.matricula < a[*j].matricula){
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
void quickSort_matricula(Pessoa a[], int n){
  ordenar_matricula(0, n-1, a);
}
void ordenar_matricula(int esq, int dir, Pessoa a[]){
  int i, j;
  particionar_matricula(esq, dir, &i, &j, a);
  if(esq < j) ordenar_matricula(esq, j, a);
  if(i < dir) ordenar_matricula(i, dir, a);
}
