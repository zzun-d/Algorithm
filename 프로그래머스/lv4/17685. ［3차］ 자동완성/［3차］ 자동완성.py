class Node:
    def __init__(self, head, cnt=0):
        self.head = head
        self.cnt = cnt
        self.end = False
        self.child = {}

class Trie:
    def __init__(self):
        self.root = Node(None)

    def insert(self, word):

        curr = self.root
        for c in word:
            if not curr.child.get(c):
                curr.child[c] = Node(c)
            curr.cnt += 1
            curr = curr.child[c]
        curr.end = True




def solution(words):


    answer = 0
    trie = Trie()
    for word in words:
        trie.insert(word)




    q = [(trie.root, 0)]

    while q:
        t, step = q.pop()
        if t.end:
            answer += step
            if t.cnt == 1:
                answer += 1
        if t.cnt == 1:
            answer += step
        if t.cnt > 1:
            for ct in t.child.values():
                q.append((ct, step+1))

    return answer