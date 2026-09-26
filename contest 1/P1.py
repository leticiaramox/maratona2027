n = int(input())

listaNum = input()

lista = listaNum.split(' ')

lista.sort()

idx = 1
for i in range(n - 1):
    if (int(lista[i]) != (i + 1)):
        idx = i + 1
        break
        
print(f'{idx}')
        
