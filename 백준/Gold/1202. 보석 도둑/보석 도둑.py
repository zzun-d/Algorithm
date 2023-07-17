import sys, heapq

input = sys.stdin.readline
N, K = map(int, input().split())
ans = 0
v_lst = []
check_v_lst = []
bag_lst = []
for _ in range(N):
    m, v = map(int, input().split())
    heapq.heappush(v_lst, (m, v))

for _ in range(K):
    bag_lst.append(int(input()))
bag_lst.sort()

for bag in bag_lst:
    mx_v = 0
    while v_lst and v_lst[0][0] <= bag:
        heapq.heappush(check_v_lst, -heapq.heappop(v_lst)[1])
    if check_v_lst:
        ans += -heapq.heappop(check_v_lst)
print(ans)