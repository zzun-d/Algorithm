import sys, heapq

input = sys.stdin.readline

N = int(input())
ans = 0
lst = []
for _ in range(N):
    heapq.heappush(lst, int(input()))

for _ in range(N - 1):
    new_deck = heapq.heappop(lst)
    new_deck += heapq.heappop(lst)
    ans += new_deck
    heapq.heappush(lst, new_deck)

print(ans)
