import sys
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


def find_diameter(node):
    diameter = 0
    end_node = 0
    visited = [False] * (V + 1)
    visited[node] = True

    q = deque([(node, 0)])
    while q:
        now_n, sum_d = q.popleft()
        for n, d in tree[now_n]:
            if visited[n]:
                continue

            # 리프노드
            elif len(tree[n]) == 1 and d + sum_d > diameter:
                diameter = d + sum_d
                end_node = n
                continue
            visited[n] = True
            q.append((n, d + sum_d))

    return end_node, diameter


V = int(input())

tree = {}

for _ in range(V):
    lst = list(map(int, input().split()))
    node = lst[0]
    tree[node] = []
    for i in range(1, len(lst) - 1, 2):
        tree[node].append((lst[i], lst[i + 1]))

print(find_diameter(find_diameter(1)[0])[1])
