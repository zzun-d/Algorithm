import sys

input = sys.stdin.readline

N = int(input())
w_lst = [0] + list(map(int, input().split()))
graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

visited = [False] * (N + 1)


def dp_tree(node, c_lst, not_c_lst):
    # cnt = -1
    c = w_lst[node]
    not_c = 0
    visited[node] = True
    c_lst.append(node)
    for n in graph[node]:
        if visited[n]:
            continue
        # cnt += 1
        cc, nc, cc_lst, nc_lst = dp_tree(n, [], [])
        c += nc
        c_lst += nc_lst
        if cc > nc:
            not_c += cc
            not_c_lst += cc_lst
        else:
            not_c += nc
            not_c_lst += nc_lst
    # print(node, cnt)
    # if cnt > 0:
    #     c -= cnt * w_lst[node]

    # print(c, not_c, c_lst, not_c_lst)

    return c, not_c, c_lst, not_c_lst


c1, c2, l1, l2 = dp_tree(1, [], [])
if c1 > c2:
    print(c1)
    print(*sorted(l1))
else:
    print(c2)
    print(*sorted(l2))
