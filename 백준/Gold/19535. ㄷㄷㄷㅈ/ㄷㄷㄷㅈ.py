import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N + 1)]
l_lst = [0] * (N + 1)
visited = [False] * (N + 1)
for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    l_lst[a] += 1
    l_lst[b] += 1

visited[1] = True
q = deque([1])
d = 0
g = 0
while q:
    node = q.popleft()
    if l_lst[node] > 2:
        g += ((l_lst[node]) * (l_lst[node] - 1) * (l_lst[node] - 2)) // 6

    for n in graph[node]:
        if visited[n]:
            continue
        d += (l_lst[node] - 1) * (l_lst[n] - 1)
        visited[n] = True
        q.append(n)

g *= 3
if d==g:
    print('DUDUDUNGA')
elif d > g:
    print("D")
else:
    print("G")
