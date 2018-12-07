void selectionSort_nome(Pessoa a[], int n);
void selectionSort_matricula(Pessoa a[], int n);
void selectionSort_nota(Pessoa a[], int n);

void selectionSort_nome(Pessoa a[], int n){
  int menor;
  Pessoa aux;
  for (int i = 0; i < n; i++) {
    menor = i;
    for (int j = i+1; j < n; j++){
      if (strcmp(a[j].nome, a[menor].nome) < 0){
        menor = j;
      }
    }
    strcpy(aux.nome, a[i].nome);
    strcpy(a[i].nome, a[menor].nome);
    strcpy(a[menor].nome, aux.nome);
  }
}
void selectionSort_matricula(Pessoa a[], int n){
  int menor;
  Pessoa aux;
  for (int i = 0; i < n; i++) {
    menor = i;
    for (int j = i+1; j < n; j++){
      if (a[j].matricula < a[menor].matricula){
        menor = j;
      }
    }
    aux.matricula = a[i].matricula;
    a[i].matricula = a[menor].matricula;
    a[menor].matricula = aux.matricula;
  }
}
void selectionSort_nota(Pessoa a[], int n){
  int menor;
  Pessoa aux;
  for (int i = 0; i < n; i++) {
    menor = i;
    for (int j = i+1; j < n; j++){
      if (a[j].nota < a[menor].nota){
        menor = j;
      }
    }
    aux.nota = a[i].nota;
    a[i].nota = a[menor].nota;
    a[menor].nota = aux.nota;
  }
}
