import sys

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    N = int(input())
    d_lst = [0] * (N + 1)
    p_lst = [0] * (N + 1)
    c_lst = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        a, b = map(int, input().split())
        p_lst[b] = a
        c_lst[a].append(b)
    for i in range(1, N + 1):
        if p_lst[i] == 0:
            root_node = i
            break
    q = [root_node]
    depth = 0
    while q:
        nxt_q = []
        depth += 1
        while q:
            n = q.pop()
            d_lst[n] = depth
            nxt_q += c_lst[n]
        q = nxt_q[:]

    n1, n2 = map(int, input().split())

    if d_lst[n1] > d_lst[n2]:
        n1, n2 = n2, n1
    for _ in range(d_lst[n2] - d_lst[n1]):
        n2 = p_lst[n2]
    if n1 == n2:
        print(n1)
    else:
        while True:
            n1 = p_lst[n1]
            n2 = p_lst[n2]
            if n1 == n2:
                print(n1)
                break
