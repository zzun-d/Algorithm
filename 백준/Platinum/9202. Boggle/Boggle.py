import sys, copy


def input():
    return sys.stdin.readline().rstrip()


class Node:
    def __init__(self, head, data="", is_word=False):
        self.head = head
        self.is_word = is_word
        self.data = data
        self.children = {}


class Trie:
    def __init__(self):
        self.root = Node(None)

    def insert(self, string):
        curr_node = self.root
        for s in string:
            if not curr_node.children.get(s):
                curr_node.children[s] = Node(s, curr_node.data + s)
            curr_node = curr_node.children[s]
        curr_node.is_word = True


def find_word(x, y, v, node):
    s = board[x][y]
    if node.children.get(s):
        node = node.children[s]
        if node.is_word:
            ans.add(node.data)
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 4 > nx >= 0 and 4 > ny >= 0 and not v[nx][ny]:
                v[nx][ny] = True
                find_word(nx, ny, v, node)
                v[nx][ny] = False


dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
w = int(input())
trie = Trie()
visited = [[False] * 4 for _ in range(4)]
for _ in range(w):
    word = input()
    trie.insert(word)
input()
b = int(input())
for _ in range(b):
    board = [input() for _ in range(4)]
    ans = set()
    for i in range(4):
        for j in range(4):
            v = copy.deepcopy(visited)
            v[i][j] = True
            find_word(i, j, v, trie.root)
    if _ < b - 1:
        input()
    score = 0
    long_word = [0, ""]
    cnt = len(ans)
    for w in ans:
        l = len(w)
        if l > long_word[0]:
            long_word = [l, w]
        elif l == long_word[0] and long_word[1] > w:
            long_word[1] = w

        if l == 8:
            score += 11
        elif l == 7:
            score += 5
        elif l == 6:
            score += 3
        elif l == 5:
            score += 2
        elif l >= 3:
            score += 1

    print(score, long_word[1], cnt)
