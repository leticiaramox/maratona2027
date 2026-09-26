lista = input()

tam = lista.split(' ')

a = int(tam[0])
b = int(tam[1])
c = int(tam[2])


listaA = input().split(" ")

listaB = input().split(" ")

min = 100000
if (a < b):
    for i in range(b - a):
        listaA.append('1000000000000000')
else:
    for i in range(a - b):
        listaB.append('1000000000000000')

    
listac = []
i = 0
k = 0
j = 0

while (j < c):
    if (int(listaA[i]) < int(listaB[k])):
        listac.append('A')
        i = i + 1
    else:
        listac.append('B')
        k = k + 1
        
    j = j + 1
        
for i in range(c):
    print(f"{listac[i]}", end="")
