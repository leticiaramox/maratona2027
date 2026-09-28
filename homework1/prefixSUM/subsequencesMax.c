#include <stdio.h>
#include <stdlib.h>

int prefSum(int n, long long arr[n]) {
    
    int cont;
    long long* pre = malloc(n * sizeof(long long));
    if (pre == NULL) return 1;
    
    pre[0] = arr[0];
    if (arr[0] >= 0) cont = 1;
    else cont = 0;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
        
        if (pre[i] < 0) {
            pre[i] = pre[i - 1];
            continue;
        }
        printf("%lld ", pre[i]);
        cont++;
    }
    
    
    free(pre);
    return cont;
}

int main() {
    int n;
    scanf("%d\n", &n);
    
    long long pocoes[n];
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &pocoes[i]);
    }
    
    int cont = prefSum(n, pocoes);
    
    printf("%d\n", cont);
}
