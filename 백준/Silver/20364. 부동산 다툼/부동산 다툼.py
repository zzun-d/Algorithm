import sys

input = sys.stdin.readline

N, Q = map(int, input().split())
visited = [False] * (N + 1)
for _ in range(Q):
    want_land = int(input())
    land = want_land
    ans = 0
    lst = []

    while land:
        lst.append(land)
        land = land // 2
    while lst:
        check_land = lst.pop()

        if visited[check_land]:
            ans = check_land
            break
    if ans == 0:
        visited[want_land] = True
    print(ans)
