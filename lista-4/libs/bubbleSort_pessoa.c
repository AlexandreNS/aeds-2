void bubbleSort_nome(Pessoa a[], int n);
void bubbleSort_nota(Pessoa a[], int n);
void bubbleSort_matricula(Pessoa a[], int n);

void bubbleSort_nome(Pessoa a[], int n){
  Pessoa aux;
  for (int i = 0; i < n-1; i++) {
    for (int j = 1; j < n-i; j++) {
      if (strcmp(a[j].nome, a[j-1].nome) < 0) {
        aux = a[j];
        a[j] = a[j-1];
        a[j-1] = aux;
      }
    }
  }
}
void bubbleSort_nota(Pessoa a[], int n){
  Pessoa aux;
  for (int i = 0; i < n-1; i++) {
    for (int j = 1; j < n-i; j++) {
      if (a[j].nota < a[j-1].nota) {
        aux = a[j];
        a[j] = a[j-1];
        a[j-1] = aux;
      }
    }
  }
}
void bubbleSort_matricula(Pessoa a[], int n){
  Pessoa aux;
  for (int i = 0; i < n-1; i++) {
    for (int j = 1; j < n-i; j++) {
      if (a[j].matricula < a[j-1].matricula) {
        aux = a[j];
        a[j] = a[j-1];
        a[j-1] = aux;
      }
    }
  }
}
