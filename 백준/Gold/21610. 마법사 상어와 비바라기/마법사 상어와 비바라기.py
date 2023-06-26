import pprint

# 방향 idx에 따른 i, j 변화값
Dr = [0, 0, -1, -1, -1, 0, 1, 1, 1]
Dc = [0, -1, -1, 0, 1, 1, 1, 0, -1]

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
clouds = [(N - 1, 0), (N - 1, 1), (N - 2, 0), (N - 2, 1)]
for _ in range(M):
    d, s = map(int, input().split())
    except_set = set()

    # 1 ~ 2
    nxt_clouds = []
    while clouds:
        r, c = clouds.pop()
        dr = (Dr[d] * s) % N
        dc = (Dc[d] * s) % N

        nr = (r + dr) % N if r + dr >= 0 else N + r + dr
        nc = (c + dc) % N if c + dc >= 0 else N + c + dc

        arr[nr][nc] += 1
        nxt_clouds.append((nr, nc))
    except_set = set(nxt_clouds)

    # 3
    for nr, nc in nxt_clouds:
        for i in [2, 4, 6, 8]:
            cr = nr + Dr[i]
            cc = nc + Dc[i]
            if N > cr >= 0 and N > cc >= 0 and arr[cr][cc] > 0:
                arr[nr][nc] += 1

    # 5
    for i in range(N):
        for j in range(N):
            if arr[i][j] >= 2 and not except_set.intersection({(i, j)}):
                clouds.append((i, j))
                arr[i][j] -= 2
ans = 0
for i in range(N):
    for j in range(N):
        ans += arr[i][j]
print(ans)
