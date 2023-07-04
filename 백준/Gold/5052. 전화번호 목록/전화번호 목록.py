import sys


def input():
    return sys.stdin.readline().rstrip()


class Node(object):
    def __init__(self, data=False):
        self.data = data
        self.children = {}


class Trie(object):
    def __init__(self):
        self.root = Node()

    def insert(self, num):
        curr_node = self.root
        for n in num:
            if not curr_node.children.get(n):
                curr_node.children[n] = Node()

            curr_node = curr_node.children[n]

            if curr_node.data:
                return False
        if curr_node.children:
            return False
        curr_node.data = True
        return True


T = int(input())

for _ in range(T):
    N = int(input())
    lst = [input().replace(" ", "") for _ in range(N)]
    tmp = True
    trie = Trie()
    for num in lst:
        if not trie.insert(num):
            tmp = False
            break
    if tmp:
        print("YES")
    else:
        print("NO")
