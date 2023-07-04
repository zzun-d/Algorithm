import sys

sys.setrecursionlimit(10**6)


def input():
    return sys.stdin.readline().rstrip()


N = int(input())

graph = [set() for _ in range(N + 1)]

for _ in range(N - 1):
    u, v = map(int, input().split())
    graph[u].add(v)
    graph[v].add(u)

visited = [False] * (N + 1)
dp = [[0, 1] for _ in range(N + 1)]


def is_early(node):
    visited[node] = True
    for n in graph[node]:
        if visited[n]:
            continue
        is_early(n)
        dp[node][0] += dp[n][1]
        dp[node][1] += min(dp[n])


is_early(1)
print(min(dp[1]))
