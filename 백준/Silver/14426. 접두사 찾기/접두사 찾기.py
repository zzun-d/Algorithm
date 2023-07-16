import sys


class Node:
    def __init__(self, head, data=False):
        self.head = head
        self.data = data
        self.children = {}


class Trie:
    def __init__(self):
        self.root = Node(None)

    def insert(self, string):
        curr_node = self.root
        for s in string:
            if not curr_node.children.get(s):
                curr_node.children[s] = Node(s)
            curr_node = curr_node.children[s]
        curr_node.data = True

    def search(self, string):
        curr_node = self.root
        for s in string:
            if not curr_node.children.get(s):
                return False
            curr_node = curr_node.children[s]
        return True


def input():
    return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
trie = Trie()
ans = 0
for _ in range(N):
    word = input()
    trie.insert(word)
for _ in range(M):
    word = input()
    if trie.search(word):
        ans += 1
print(ans)
