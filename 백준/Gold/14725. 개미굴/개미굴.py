import sys


def input():
    return sys.stdin.readline().rstrip()


def output(depth, parent):
    if not d_lst[depth].get(parent):
        return
    for r in d_lst[depth][parent]:
        print("--" * depth + r)
        output(depth + 1, parent + r)


N = int(input())
d_lst = [{} for _ in range(16)]
d_lst[0]["root"] = []
for _ in range(N):
    lst = input().split()
    K = int(lst[0])
    lst = lst[1:]
    parent = ""
    for i in range(len(lst)):
        if not d_lst[i].get(parent):
            d_lst[i][parent] = []

        if lst[i] not in d_lst[i][parent]:
            d_lst[i][parent].append(lst[i])

        parent += lst[i]

for i in range(15):
    for k in d_lst[i].keys():
        d_lst[i][k].sort()

output(0, "")
