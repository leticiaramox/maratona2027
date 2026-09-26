#include <stdio.h>

// Função recursiva para somar os dígitos de N
int somaDigitos(int n) {
    if (n == 0) {
        return 0; 
    }
    return (n % 10) + somaDigitos(n / 10);
}

// Função recursiva para contar quantas vezes a soma precisa ser feita até ser < 10
int vezes(int N) {
    int k = somaDigitos(N);
    
    if (k >= 10) {
        return 1 + vezes(k);
    }
    
    return 1;
}

int main() {
    int N;
    if (scanf("%d", &N) == 1) {
        int n = vezes(N);
        
        if (N == 0) n = 0;
        
        printf("%d\n", n);
    }
    return 0;
}
