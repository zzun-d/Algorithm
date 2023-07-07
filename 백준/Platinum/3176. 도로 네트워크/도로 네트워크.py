import sys, math


def input():
    return sys.stdin.readline().rstrip()


N = int(input())

LOG = int(math.log2(N)) + 1

# graph 구현
graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))


# 1차원: 노드 번호, 2차원: 2^n의 부모 정보, 3차원: 부모 노드, 최소 길이, 최대 길이
parent = [[[0, 0, 0] for _ in range(LOG)] for _ in range(N + 1)]
d_lst = [0] * (N + 1)
visited = [False] * (N + 1)
visited[1] = True
q = [1]
depth = 0
while q:
    depth += 1
    nxt_q = []
    while q:
        node = q.pop()
        d_lst[node] = depth
        for n, d in graph[node]:
            if visited[n]:
                continue
            visited[n] = True
            parent[n][0] = [node, d, d]
            nxt_q.append(n)
    q = nxt_q[:]

for i in range(1, LOG):
    for j in range(1, N + 1):
        parent[j][i][0] = parent[parent[j][i - 1][0]][i - 1][0]
        parent[j][i][1] = min(
            parent[parent[j][i - 1][0]][i - 1][1], parent[j][i - 1][1]
        )
        parent[j][i][2] = max(
            parent[parent[j][i - 1][0]][i - 1][2], parent[j][i - 1][2]
        )
K = int(input())
for _ in range(K):
    d, e = map(int, input().split())
    mx = 0
    mn = 10**6

    if d_lst[d] > d_lst[e]:
        d, e = e, d

    for i in range(LOG - 1, -1, -1):
        if d_lst[e] - d_lst[d] >= 2**i:
            mn = min(parent[e][i][1], mn)
            mx = max(parent[e][i][2], mx)
            e = parent[e][i][0]
    if d == e:
        print(mn, mx)

    else:
        for i in range(LOG - 1, -1, -1):
            if parent[d][i][0] != parent[e][i][0]:
                mn = min(parent[d][i][1], parent[e][i][1], mn)
                mx = max(parent[d][i][2], parent[e][i][2], mx)
                d = parent[d][i][0]
                e = parent[e][i][0]

        mn = min(parent[d][0][1], parent[e][0][1], mn)
        mx = max(parent[d][0][2], parent[e][0][2], mx)
        print(mn, mx)
