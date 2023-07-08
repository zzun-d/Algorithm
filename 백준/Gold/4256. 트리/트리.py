import sys


def input():
    return sys.stdin.readline().rstrip()


def post_order(preorder_lst, inorder_lst):
    l = len(preorder_lst)
    if l == 0:
        return
    elif l == 1:
        postorder_lst.append(preorder_lst[0])
        return
    elif l == 2:
        postorder_lst.append(preorder_lst[1])
        postorder_lst.append(preorder_lst[0])
        return

    root_idx = inorder_lst.index(preorder_lst[0])

    left_inorder = inorder_lst[:root_idx]
    left_preorder = preorder_lst[1 : 1 + root_idx]
    post_order(left_preorder, left_inorder)

    right_inorder = inorder_lst[root_idx + 1 :]
    right_preorder = preorder_lst[1 + root_idx :]
    post_order(right_preorder, right_inorder)
    postorder_lst.append(preorder_lst[0])


T = int(input())

for _ in range(T):
    postorder_lst = []
    N = int(input())
    preorder_lst = list(map(int, input().split()))
    inorder_lst = list(map(int, input().split()))
    post_order(preorder_lst, inorder_lst)
    print(*postorder_lst)
