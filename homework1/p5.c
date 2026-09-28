#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_num(long long *arr, int tamanho, long long alvo, long long* copia) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == alvo) {
            contador++;
            copia[i] = 0;
        }
    }
    return contador;
}

int cont(int q, int idx, long long* local) {
    
    int contador = 0;
    int l = q;
    
    long long* copia = malloc(q * sizeof(long long));
    if (copia == NULL) return 1;
    
    memcpy(copia, &local, q * sizeof(long long));
    for (int i = 0; i < q; i++) {
        if (copia[i] != 0) {
            int c = count_num(local, q, local[i], copia);
            contador++;
        }
    }
    
    free(copia);
    return contador;
}

long long* listona(int q, int n, long long lista[n], int idx) {
    
    long long* listinha = malloc(q * sizeof(long long));
    if (listinha == NULL) return NULL;
    
    memcpy(listinha, &lista[idx], q * sizeof(long long));
    
    return listinha;
}

int main() {
    int n, q;
    scanf("%d %d\n", &n, &q);
    
    long long numeros[n];
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &numeros[i]);
    }
    
    for (int i = 0; i < (n - q + 1); i++) {
        long long* listaLocal = listona(q, n, numeros, i);
        
        int c = cont(q, i, listaLocal);
        
        printf("%d ", c);
        
        free(listaLocal);
    }
}
