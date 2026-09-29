#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void* a, const void* b) {
const char *strA = *(const char **)a;
const char *strB = *(const char **)b;
int i = 0, j = 0;
while (strA[i + 1] != '\0' && strB[j + 1] != '\0'){
char cA = strA[i];
char cB = strB[j];
int dif = cB - cA;            
if (strA[i + 1] != '\0') i++;
if (strB[j + 1] != '\0') j++;

return dif;
    }
return 0;
}

int main() {
int n;
if (scanf("%d\n", &n) != 1) return 1;

char** lista = (char**)malloc(n * sizeof(char*));
if (lista == NULL) return 1;

for (int i = 0; i < n; i++) {
char buffer[100];
if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
buffer[strcspn(buffer, "\n")] = '\0';
lista[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
strcpy(lista[i], buffer);
        }
    }

qsort(lista, n, sizeof(char*), compara);

// Print FORWARDS to get "aaaab" ("a" + "aa" + "ab")
for (int i = n - 1; i >= 0; i--) {
printf("%s", lista[i]);
    }

for (int i = 0; i < n; i++) {
free(lista[i]);
    }
free(lista);

return 0;
}

'''


so i wanna order strings. for exemple:
5
x
xx
xxa
xxaa
xxaaa
turns into xxaaaxxaaxxaxxx

or for exemple:
4
abba
abacaba
bcd
er

turns into : abacabaabbabcder



and my code does this! the problem is: when i put 
3
a
aa
ab
apears : abaaa
when it should be: aaaab



'''

what is going on?
