import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    lst = [0] * (N + 1)
    ans = 1
    for i in range(N):
        a, b = map(int, input().split())
        lst[a] = b
    now_score = lst[1]
    for i in range(2, N + 1):
        if lst[i] < now_score:
            ans += 1
            now_score = lst[i]

    print(ans)
