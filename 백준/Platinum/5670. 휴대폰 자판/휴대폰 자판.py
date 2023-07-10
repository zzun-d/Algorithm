import sys


def input():
    return sys.stdin.readline().rstrip()


class Node:
    def __init__(self, head):
        self.head = head
        self.is_word = False
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
        curr_node.is_word = True

    def push_cnt(self):
        curr_node = self.root
        total_cnt = 0
        q = [(nn, 1) for nn in list(curr_node.children.values())]
        while q:
            nxt_q = []
            while q:
                tmp = False
                node, cnt = q.pop()

                if node.is_word:
                    total_cnt += cnt
                    cnt += 1
                    tmp = True

                if len(node.children) == 1:
                    nxt_q.append((list(node.children.values())[0], cnt))
                    continue
                if not tmp:
                    cnt += 1

                for n in node.children.values():
                    nxt_q.append((n, cnt))
            q = nxt_q[:]

        return total_cnt


while True:
    try:
        N = int(input())
        trie = Trie()
        for _ in range(N):
            word = input()
            trie.insert(word)

        print(f"{trie.push_cnt() / N:.2f}")
    except:
        break
