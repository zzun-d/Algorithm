import sys

sys.setrecursionlimit(10**6)
def input():
    return sys.stdin.readline().rstrip()


N, R, Q = map(int, input().split())

graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

visited = [False] * (N + 1)
# key = parent_name, value = [[child_1, child_2, ...], children count]
tree_child_num = {}
visited[R] = True
q = [R]
while q:
    nxt_q = []
    while q:
        n = q.pop()
        tree_child_num[n] = [[], 0]
        lst = graph[n]
        for l in lst:
            if visited[l]:
                continue

            visited[l] = True
            nxt_q.append(l)
            tree_child_num[n][0].append(l)
    q = nxt_q[:]


def children_num_count(node, cnt):
    ans = cnt
    if not tree_child_num[node][0]:
        tree_child_num[node][1] = 1
        return 1

    for n in tree_child_num[node][0]:
        ans += children_num_count(n, cnt)

    tree_child_num[node][1] = ans + 1

    return ans + 1


children_num_count(R, 0)

for _ in range(Q):
    u = int(input())
    print(tree_child_num[u][1])
