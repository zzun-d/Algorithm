import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())
tree = {}
cnt_lst = [0] * (N + 1)
for idx, _ in enumerate(range(N - 1), 2):
    tp, cnt, p = input().split()
    if tp == "S":
        cnt_lst[idx] += int(cnt)
    else:
        cnt_lst[idx] += -int(cnt)

    p = int(p)

    if tree.get(p):
        tree[p].append(idx)
    else:
        tree[p] = [idx]


def how_many_sheep(n):
    cnt = 0
    if not tree.get(n):
        return max(0, cnt_lst[n])

    for island in tree[n]:
        cnt += how_many_sheep(island)

    cnt += cnt_lst[n]
    return max(cnt, 0)


print(how_many_sheep(1))
