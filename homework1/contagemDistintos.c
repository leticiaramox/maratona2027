#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    long long x = *(const long long*)a, y = *(const long long*)b;
    return (x > y) - (x < y);
}

int buscaIndice(long long* v, int m, long long val) {
    int lo = 0, hi = m - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == val) return mid;
        if (v[mid] < val) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long long* x = malloc(n * sizeof(long long));
    long long* ord = malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
        ord[i] = x[i];
    }

    qsort(ord, n, sizeof(long long), cmp);
    int m = 0;
    for (int i = 0; i < n; i++)
        if (i == 0 || ord[i] != ord[i - 1]) ord[m++] = ord[i];

    int* id = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) id[i] = buscaIndice(ord, m, x[i]);

    int* freq = calloc(m, sizeof(int));
    int distintos = 0;

    for (int i = 0; i < n; i++) {
        if (freq[id[i]]++ == 0) distintos++;

        if (i >= k) {
            if (--freq[id[i - k]] == 0) distintos--;
        }

        if (i >= k - 1) printf("%d ", distintos);
    }
    printf("\n");

    free(x); free(ord); free(id); free(freq);
    return 0;
}
