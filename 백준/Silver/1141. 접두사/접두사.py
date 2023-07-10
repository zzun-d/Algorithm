import sys


def input():
    return sys.stdin.readline().rstrip()


N = int(input())
lst = []
for _ in range(N):
    lst.append(input())

lst.sort()
cnt = 1
for i in range(N - 1):
    if len(lst[i]) <= len(lst[i + 1]) and lst[i] == lst[i + 1][: len(lst[i])]:
        continue
    cnt += 1
print(cnt)
