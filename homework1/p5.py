n, q = map(int, input().split())

lista = input().split()

for idx in range(n - q + 1):
    subLista = lista[idx : idx + q]
    
    contador = len(set(subLista))
    
    print(f'{contador}', end=' ')
