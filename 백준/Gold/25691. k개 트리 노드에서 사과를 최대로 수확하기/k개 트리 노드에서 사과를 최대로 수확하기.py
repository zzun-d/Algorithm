from itertools import combinations


def is_tree(nodes):
    visited = {0}
    nxt_nodes = []
    for node in tree[0] & nodes:
        visited.add(node)
        nxt_nodes.append(node)

    while nxt_nodes:
        node = nxt_nodes.pop()
        pos_nodes = tree[node] & (nodes-visited)
        if pos_nodes:
            nxt_nodes += list(pos_nodes)
            visited |= pos_nodes
    if len(visited) == k:
        return True
    return False


n, k = map(int, input().split())
tree = [set() for _ in range(n)]

for _ in range(n-1):
    p, c = map(int, input().split())
    tree[p].add(c)
    tree[c].add(p)

apples = list(map(int, input().split()))
apples_idx = [i for i in range(n) if apples[i]]
none_idx = [i for i in range(n) if not apples[i]]
cnt = 0 if len(apples_idx) >= k else k - len(apples_idx)
tmp = True
ans = 0
while tmp:
    app_lst = set(combinations(apples_idx, k-cnt))
    none_lst = set(combinations(none_idx, cnt))
    for app in app_lst:
        for non in none_lst:
            nodes = set(app) | set(non)
            if nodes.intersection({0}):
                if is_tree(nodes):
                    tmp = False
                    ans = k-cnt
                    break
    cnt += 1
print(ans)
