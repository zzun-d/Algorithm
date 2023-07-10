N = int(input())
lst = list(map(int, input().split()))
tree = {}
for idx, n in enumerate(lst[1:], 1):
    if tree.get(n):
        tree[n].append(idx)
    else:
        tree[n] = [idx]


def calling(node):
    cnt_lst = []
    if not tree.get(node):
        return 1

    for n in tree[node]:
        cnt_lst.append(calling(n))
    cnt_lst.sort(reverse=True)
    mx_cnt = cnt_lst[0]
    for i in range(1, len(cnt_lst)):
        if cnt_lst[i] + i > mx_cnt:
            mx_cnt = cnt_lst[i] + i
    return mx_cnt + 1


print(calling(0) - 1)
