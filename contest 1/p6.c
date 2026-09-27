#include <stdio.h>

int golpe(int m1, int m2, int vez, int num) {
    
    if (((m1 == 1 && m2 <= 0) || (m2 == 1 && m1 <= 0)) && (num >= 1)) return 1;
    if (m1 <= 0 || m2 <= 0) return 0;
    
    if (vez == 0) {
        m2 -= m1;
        vez = 1;
    } else {
        m1 -= m2;
        vez = 0;
    }
    
    return golpe(m1, m2, vez, num + 1);
}

void att(int t, int l[t], int* idx1, int* idx2) {
    
    int encontrou = 0;
    for (int i = 0; i < t && !encontrou; i++) {
        for (int j = i + 1; j < t; j++) {
            
            int flag = golpe(l[i], l[j], 0, 0);
            if (flag == 1) {
                encontrou = 1;
                *idx1 = i + 1;
                *idx2 = j + 1;
                break;
            } else {
                flag = golpe(l[i], l[j], 1, 0);
                if (flag == 1) {
                    encontrou = 1;
                    *idx1 = j + 1;
                    *idx2 = i + 1;
                    break;
                }
            }
        }
    }
    
    return;
    
}

int main() {
    int n;
    scanf("%d\n", &n);
    
    int montros[n];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &montros[i]);
    }
    
    int idx1 = -1, idx2 = -1;
    att(n, montros, &idx1, &idx2);
    
    if (idx1 == -1) {
        puts("impossible");
    } else {
        printf("%d %d", idx1, idx2);
    }
    
}
