n, q = map(int, input().split()) # lê apenas os inteiros

lista = input().split()

for idx in range(n - q + 1):
    subLista = lista[idx : idx + q] # faz o recorte -> sub lista
    
    contador = len(set(subLista)) # a função set() anula elementos repetidos
    
    print(f'{contador}', end=' ')
