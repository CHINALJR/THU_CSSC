
a = []
a.append(1)
for i in range(1,1111):
    a.append(a[i-1] * i)

while True:
    try:
        t = input()
        t = int(t)
        print(a[t])
    except EOFError:
        break
