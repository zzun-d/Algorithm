import sys

def input():
    return sys.stdin.readline().rstrip()

D = [(1, 0), (0, 1), (-1, 0), (0, -1)]
R, C, T = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(R)]

# 공기청정기 위치
for i in range(R):
    if arr[i][0] == -1:
        clean_air = [i, i + 1]
        break

for _ in range(T):
    add_arr = [[0] * C for _ in range(R)]

    # 미세먼지 확산
    for i in range(R):
        for j in range(C):
            if arr[i][j] >= 5:
                cnt = 0
                amount = arr[i][j] // 5
                for di, dj in D:
                    ni = i + di
                    nj = j + dj
                    if R > ni >= 0 and C > nj >= 0 and arr[ni][nj] != -1:
                        cnt += 1
                        add_arr[ni][nj] += amount
                arr[i][j] -= cnt * amount

    for i in range(R):
        for j in range(C):
            arr[i][j] += add_arr[i][j]

    # 공기청정기 작동

    # 반시계는 D의 1번 idx부터 +1, 시계는 D의 1번 idx부터 -1
    r, c = (clean_air[0], 1)
    d = 1
    tmp = 0
    while arr[r][c] != -1:
        nr = D[d][0] + r
        nc = D[d][1] + c
        if R > nr >= 0 and C > nc >= 0:
            arr[r][c], tmp = tmp, arr[r][c]
            r = nr
            c = nc
        else:
            d += 1
            if d >= 4:
                d -= 4

    r, c = (clean_air[1], 1)
    d = 1
    tmp = 0
    while arr[r][c] != -1:
        nr = D[d][0] + r
        nc = D[d][1] + c
        if R > nr >= 0 and C > nc >= 0:
            arr[r][c], tmp = tmp, arr[r][c]
            r = nr
            c = nc
        else:
            d -= 1
            if d < 0:
                d += 4

ans = 2
for i in range(R):
    for j in range(C):
        ans += arr[i][j]

print(ans)
