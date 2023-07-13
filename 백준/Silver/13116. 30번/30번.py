import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    while a != b:
        if a > b:
            a, b = b, a
        b = b // 2
    print(a*10)
