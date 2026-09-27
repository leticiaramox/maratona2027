N = int(input())

numeros = input().split(' ')

disc = 0
i = 0
j = 1
while (1):
    
    if (i == len(numeros)):
        i = 0
        j = 1
        continue
    
    if (len(numeros) == 2):
        break
    
    if (int(numeros[i]) < int(numeros[j])):
        numeros.pop(i)
        i = i + 1
        j = j + 1
        continue
    else:
        numeros.pop(j)
        i = i + 1
        j = j + 1
        continue
    
disc = abs(int(numeros[0]) - int(numeros[1]))

print(f"{int(disc)}")
        
