import sys


def input():
    return sys.stdin.readline().rstrip()


N = int(input())
graph = [[] for _ in range(N + 1)]

visited = [False] * (N + 1)
depth = [0] * (N + 1)
parent = [[0] * 21 for _ in range(N + 1)]

for _ in range(N - 1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

# 1번을 루트노드로 깊이와 parent 갱신
nodes = [(1, 0)]
visited[1] = True
while nodes:
    n, d = nodes.pop()

    for nxt_n in graph[n]:
        if visited[nxt_n]:
            continue
        visited[nxt_n] = True
        depth[nxt_n] = d + 1
        nodes.append((nxt_n, d + 1))
        parent[nxt_n][0] = n

# 2의 제곱에 해당하는 부모 갱신

for i in range(1, 21):
    for j in range(1, N + 1):
        parent[j][i] = parent[parent[j][i - 1]][i - 1]

M = int(input())
for _ in range(M):
    n1, n2 = map(int, input().split())
    if depth[n1] > depth[n2]:
        n1, n2 = n2, n1

    binary_idx = 20
    while binary_idx >= 0:
        if depth[n2] - depth[n1] >= 2**binary_idx:
            n2 = parent[n2][binary_idx]
        binary_idx -= 1

    if n1 == n2:
        print(n1)
    else:
        for i in range(20, -1, -1):
            if parent[n1][i] != parent[n2][i]:
                n1 = parent[n1][i]
                n2 = parent[n2][i]
        print(parent[n1][0])
