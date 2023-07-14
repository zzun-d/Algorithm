N = int(input())
s = 1
while (s + 1) * s / 2 <= N:
    s += 1
print(s - 1)
