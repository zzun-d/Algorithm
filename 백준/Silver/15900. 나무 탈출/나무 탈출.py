import sys

input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N + 1)]
d_lst = [0] * (N + 1)
v_lst = [False] * (N + 1)
v_lst[1] = True
leaf_lst = []
for _ in range(N - 1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)


q = [1]
depth = 0
while q:
    depth += 1
    nxt_q = []
    while q:
        node = q.pop()
        for n in graph[node]:
            if v_lst[n]:
                continue
            v_lst[n] = True
            nxt_q.append(n)
            d_lst[n] = depth
    q = nxt_q[:]

ans = 0
for i in range(2, N + 1):
    if len(graph[i]) == 1:
        ans += d_lst[i]

if ans % 2 == 0:
    print("No")
else:
    print("Yes")
