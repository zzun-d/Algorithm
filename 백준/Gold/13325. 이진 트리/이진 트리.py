from collections import deque

N = int(input())
w_lst = [0, 0] + list(map(int, input().split()))
sum_w_lst = []
ans = sum(w_lst)
visited = [False] * (2 ** (N + 1))

q = deque([[2], [3]])
while q:
    node_lst = q.popleft()
    if len(node_lst) >= N:
        sum_w_lst.append(sum(w_lst[i] for i in node_lst))
        continue
    q.append(node_lst + [node_lst[-1] * 2])
    q.append(node_lst + [node_lst[-1] * 2 + 1])

mx = max(sum_w_lst)
q = deque([sum_w_lst])
while q:
    s_nodes = q.popleft()
    plus = mx - max(s_nodes)
    ans += plus
    if len(s_nodes) == 1:
        continue

    for i in range(len(s_nodes)):
        s_nodes[i] += plus
    q.append(s_nodes[: len(s_nodes) // 2])
    q.append(s_nodes[len(s_nodes) // 2 :])

print(ans)
