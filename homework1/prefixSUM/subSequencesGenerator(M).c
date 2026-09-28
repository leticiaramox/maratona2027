'''
#include <stdio.h>
#include <stdlib.h>

long long prefSum(int size, long long* subSeq) {
    if (size == 0) return 0; 
    
    long long* pre = malloc(size * sizeof(long long));
    if (pre == NULL) return 0;
    
    pre[0] = subSeq[0];
    for (int i = 1; i < size; i++) {
        pre[i] = pre[i - 1] + subSeq[i];
    }
    
    long long total = pre[size - 1];
    free(pre); 
    return total;
}

void findSubsequences(int curr, long long* arr, int n, long long* subarr, int subarrSize, long long** res, int* resSize, long long* colSizes) {

    if (curr == n) {
        res[*resSize] = (long long*)malloc(subarrSize * sizeof(long long));
        for (int i = 0; i < subarrSize; i++) {
            res[*resSize][i] = subarr[i];
        }
        colSizes[*resSize] = subarrSize;
        (*resSize)++;
        return;
    }

    subarr[subarrSize] = arr[curr];
    findSubsequences(curr + 1, arr, n, subarr, subarrSize + 1, res, resSize, colSizes);

    findSubsequences(curr + 1, arr, n, subarr, subarrSize, res, resSize, colSizes);
}

int main() {
    long long soma;
    int n;
    if (scanf("%d %lld", &n, &soma) != 2) return 0;
    
    long long* arr = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &arr[i]);
    }

    int maxSubsequences = 1 << n;

    long long** res = (long long**)malloc(maxSubsequences * sizeof(long long*));
    long long* colSizes = (long long*)malloc(maxSubsequences * sizeof(long long));
    int resSize = 0;

    long long* subarr = (long long*)malloc(n * sizeof(long long));

    findSubsequences(0, arr, n, subarr, 0, res, &resSize, colSizes);

    long long* sum = (long long*)malloc(maxSubsequences * sizeof(long long));
    int cont = 0;

    
    for (int i = 0; i < resSize; i++) {
        sum[i] = prefSum(colSizes[i], res[i]);
        if (sum[i] == soma && colSizes[i] != n) cont++;
    }

    printf("%d\n", cont);

    for (int i = 0; i < resSize; i++) {
        free(res[i]);
    }
    free(res);
    free(colSizes);
    free(subarr);
    free(arr);
    free(sum);

    return 0;
}
'''
'''
#include <stdio.h>

long long countSubsets(long long arr[], int n, long long target) {
    if (n == 0) {
        return (target == 0) ? 1 : 0;
    }

    long long exclude = countSubsets(arr, n - 1, target);

    long long include = countSubsets(arr, n - 1, target - arr[n - 1]);

    return exclude + include;
}

int main() {
    int n;
    long long soma;
    if (scanf("%d %lld", &n, &soma) != 2) return 0;

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    long long count = countSubsets(arr, n, soma);
    
    if (sum == soma) count--;
    printf("%lld\n", count);

    return 0;
} '''


