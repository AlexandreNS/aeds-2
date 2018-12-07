void insertionSort_nome(Pessoa a[], int n);
void insertionSort_nota(Pessoa a[], int n);
void insertionSort_matricula(Pessoa a[], int n);

void insertionSort_nome(Pessoa a[], int n){
  int j;
  Pessoa x;
  for(int i = 1; i < n; i++){
    strcpy(x.nome, a[i].nome);
    j = i-1;
    while(strcmp(x.nome, a[j].nome) < 0 && j >= 0){
      strcpy(a[j+1].nome, a[j].nome);
      j--;
    }
    strcpy(a[j+1].nome, x.nome);
  }
}
void insertionSort_nota(Pessoa a[], int n){
  int j;
  Pessoa x;
  for(int i = 1; i < n; i++){
    x.nota = a[i].nota;
    j = i-1;
    while(x.nota < a[j].nota && j >= 0){
      a[j+1].nota = a[j].nota;
      j--;
    }
    a[j+1].nota = x.nota;
  }
}
void insertionSort_matricula(Pessoa a[], int n){
  int j;
  Pessoa x;
  for(int i = 1; i < n; i++){
    x.matricula = a[i].matricula;
    j = i-1;
    while(x.matricula < a[j].matricula && j >= 0){
      a[j+1].matricula = a[j].matricula;
      j--;
    }
    a[j+1].matricula = x.matricula;
  }
}
