import sys

sys.setrecursionlimit(10**6)


def input():
    return sys.stdin.readline().rstrip()


N = int(input())

tree = {}
p_lst = [0] * (N + 1)
d_dict = {}
for _ in range(N):
    n, c1, c2 = map(int, input().split())
    tree[n] = [c1, c2]
    if c1 > 0:
        p_lst[c1] = n
    if c2 > 0:
        p_lst[c2] = n

for i in range(1, N + 1):
    if p_lst[i] == 0:
        root_node = i
        break

q = [root_node]
cnt = 0

while q:
    nxt_q = []
    cnt += 1
    q.sort()
    d_dict[cnt] = q[:]
    while q:
        n = q.pop()
        c1, c2 = tree[n]
        if c1 > 0:
            nxt_q.append(c1)
        if c2 > 0:
            nxt_q.append(c2)
    q = nxt_q[:]

order_lst = [0] * (N + 1)
cnt = 1


def preorder(n):
    global cnt

    if tree[n][0] > 0:
        preorder(tree[n][0])
    order_lst[n] = cnt
    cnt += 1
    if tree[n][1] > 0:
        preorder(tree[n][1])


preorder(root_node)
ans_lst = [0, 0]
for k, v_lst in d_dict.items():
    mx_d = 0
    mn_d = N
    for v in v_lst:
        if mn_d > order_lst[v]:
            mn_d = order_lst[v]
        if order_lst[v] > mx_d:
            mx_d = order_lst[v]
    if mx_d - mn_d + 1 > ans_lst[1]:
        ans_lst[1] = mx_d - mn_d + 1
        ans_lst[0] = k

print(*ans_lst)
