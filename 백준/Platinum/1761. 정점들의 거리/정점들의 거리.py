import sys


def input():
    return sys.stdin.readline().rstrip()


# 두 노드 사이의 거리?
# 가장 가까운 공통 조상 찾으면서 거리 구하는 방법 시도

N = int(input())
graph = [{} for _ in range(N + 1)]
for _ in range(N - 1):
    a, b, d = map(int, input().split())
    graph[a][b] = d
    graph[b][a] = d

# root node : 1
# depth list 갱신
visited = [False] * (N + 1)
parent_lst = [0] * (N + 1)
d_lst = [0] * (N + 1)
q = [1]
d_lst[1] = 1

while q:
    nxt_q = []
    while q:
        node = q.pop()
        visited[node] = True
        for n in graph[node].keys():
            if visited[n]:
                continue
            parent_lst[n] = node
            d_lst[n] = d_lst[node] + 1
            nxt_q.append(n)
    q = nxt_q[:]

# print(d_lst)
# print(parent_lst)
M = int(input())
for _ in range(M):
    ans = 0
    a, b = map(int, input().split())
    if d_lst[a] > d_lst[b]:
        a, b = b, a

    for _ in range(d_lst[b] - d_lst[a]):
        ans += graph[b][parent_lst[b]]
        b = parent_lst[b]

    if a == b:
        print(ans)
    else:
        while a != b:
            ans += graph[a][parent_lst[a]]
            ans += graph[b][parent_lst[b]]
            a = parent_lst[a]
            b = parent_lst[b]
        print(ans)
