import sys

input = sys.stdin.readline

N, M = map(int, input().split())
lst = list(map(int, input().split()))
tree = [[] for _ in range(N + 1)]
compliments = {}
answer = [0] * (N + 1)
for i in range(1, N):
    tree[lst[i]].append(i + 1)
    compliments[i] = 0
compliments[N] = 0

for _ in range(M):
    i, w = map(int, input().split())
    compliments[i] += w

q = [1]
while q:
    nxt_q = []
    while q:
        n = q.pop()
        for sub_n in tree[n]:
            answer[sub_n] += answer[n] + compliments[sub_n]
            nxt_q.append(sub_n)
    q = nxt_q[:]

print(*answer[1:])
