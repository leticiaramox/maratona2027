#include <stdio.h>
#include <stdlib.h>

void golpes(int *n1, int *n2, int vez, int *numGolpe) {
    // Aplica o golpe primeiro
    if (vez == 0) {
        *n2 -= *n1;
        vez = 1;
    } else {
        *n1 -= *n2;
        vez = 0;
    }
    (*numGolpe)++;

    // Condição de parada após pelo menos 1 golpe ter sido efetuado
    if (*n1 <= 1 || *n2 <= 1) return;

    golpes(n1, n2, vez, numGolpe);
}

int* duelo(int tamanho, int lista[tamanho]) {
    // Aloca 3 posições para evitar buffer overflow ao usar listaIdx[2]
    int *listaIdx = (int*) malloc(3 * sizeof(int));
    listaIdx[0] = -1;
    listaIdx[1] = -1;
    listaIdx[2] = -1;

    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            
            int numGolpe = 0;
            // Monstro 1 começa
            int t1 = lista[i], t2 = lista[j];
            golpes(&t1, &t2, 0, &numGolpe);

            if ((t1 == 1 || t2 == 1 || t1 <= 0 || t2 <= 0) && (numGolpe > 0)) {
                listaIdx[0] = i;
                listaIdx[1] = j;
                listaIdx[2] = 0;
                return listaIdx;
            }

            numGolpe = 0;
            // Monstro 2 começa
            int t3 = lista[i], t4 = lista[j];
            golpes(&t3, &t4, 1, &numGolpe);

            if ((t3 == 1 || t4 == 1 || t3 <= 0 || t4 <= 0) && (numGolpe > 0)) {
                listaIdx[0] = j;
                listaIdx[1] = i;
                listaIdx[2] = 1;
                return listaIdx;
            }
        }
    }

    return listaIdx;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int lista[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lista[i]);
    }

    int *idx = duelo(N, lista);

    if (idx[0] == -1 || idx[1] == -1) {
        puts("impossible");
    } else {
        if (idx[2] == 0) {
            int hold = idx[1];
            idx[1] = idx[0];
            idx[0] = hold;
        }
        printf("%d %d\n", idx[0] + 1, idx[1] + 1);
    }

    free(idx);
    return 0;
}
