#include <stdio.h>
#include <stdlib.h>

long long* prefSum(int n, const int lista[n]) {
    long long* pre = malloc((n + 1) * sizeof(long long));
    if (pre == NULL) return NULL;

    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + lista[i - 1];
    }
    return pre;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 1;
    
    int numero[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numero[i]);
    }
    
    long long* lista = prefSum(n, numero);
    if (lista == NULL) return 1;
    
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", lista[b] - lista[a - 1]);
    }
    
    free(lista);
    return 0;
}
