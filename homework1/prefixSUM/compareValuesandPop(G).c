#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

long long* prefSum(int n, const int* lista) {
    long long* pre = (long long*) malloc((n + 1) * sizeof(long long));
    if (pre == NULL) return NULL;

    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + lista[i - 1];
    }
    return pre;
}

void naoColidiram(int n, const long long* pos, const long long* vel, int arr[]) {
    int* left = (int*) malloc(n * sizeof(int));
    int* right = (int*) malloc(n * sizeof(int));

    if (left == NULL || right == NULL) {
        free(left);
        free(right);
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = 1;
        left[i] = i - 1;
        right[i] = (i + 1 < n) ? (i + 1) : -1;
    }

    while (1) {
        double min_time = DBL_MAX;
        int collide_i = -1;
        int collide_j = -1;

        for (int i = 0; i < n; i++) {
            if (!arr[i]) continue;

            int j = right[i];
            if (j == -1) continue;

            if (vel[i] > vel[j]) {
                double time = (double)(pos[j] - pos[i]) / (double)(vel[i] - vel[j]);
                if (time < min_time) {
                    min_time = time;
                    collide_i = i;
                    collide_j = j;
                }
            }
        }

        if (collide_i == -1) break;

        arr[collide_i] = 0;
        arr[collide_j] = 0;
        
        int l = left[collide_i];
        int r = right[collide_j];

        if (l != -1) right[l] = r;
        if (r != -1) left[r] = l;
    }

    free(left);
    free(right);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) return 0;

    long long* pos = (long long*) malloc(N * sizeof(long long));
    long long* vel = (long long*) malloc(N * sizeof(long long));
    int* arr = (int*) malloc(N * sizeof(int));

    if (pos == NULL || vel == NULL || arr == NULL) {
        free(pos);
        free(vel);
        free(arr);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%lld %lld", &pos[i], &vel[i]) != 2) break;
    }

    naoColidiram(N, pos, vel, arr);

    long long* pre = prefSum(N, arr);
    if (pre != NULL) {
        printf("%lld\n", pre[N]);
        for (int i = 0; i < N; i++) {
            if (arr[i] == 1) {
                printf("%d", i + 1);
                if (i < N - 1) printf(" ");
            }
        }
        free(pre);
    }

    free(pos);
    free(vel);
    free(arr);
    return 0;
}
