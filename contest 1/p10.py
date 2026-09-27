#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int dif = abs(N - K);
    int anos = 0;
    
    int inicio = N;
    
    for (int i = 0; i < dif; i++) {
        
        if (i > 0) N += (inicio + i);
        anos = i;
        
        if (N > K) break;
    }
    
    printf("%d", anos);
}
