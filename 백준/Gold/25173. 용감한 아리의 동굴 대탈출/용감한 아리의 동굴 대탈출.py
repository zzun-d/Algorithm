from collections import deque


# 아리 이동 함수
def ari_move(ari):
    cnt = 0
    x, y = ari
    for i in range(4):
        nx = x + D[(ari_direct + i) % 4][0]
        ny = y + D[(ari_direct + i) % 4][1]
        if N > nx >= 0 and M > ny >= 0 and arr[nx][ny] == 0:
            # 체력 감소량, 아리 이동방향, 아리 좌표
            arr[x][y] = 0
            arr[nx][ny] = 2
            return cnt, (ari_direct + i) % 4, (nx, ny)
        cnt += 1

    return cnt, ari_direct, ari


# 석순 탐색 함수
def search_sucksoon(boss):
    d = boss_direct
    step_up = 2
    step_size = 1
    now_step = 0
    x, y = boss

    while True:
        if N > x >= 0 and M > y >= 0 and arr[x][y] == 1:
            return (x, y)

        if now_step == step_size:
            step_up -= 1
            now_step = 0
            if step_up == 0:
                step_size += 1
                step_up = 2
            d = (d + 1) % 4

        now_step += 1
        x += D[d][0]
        y += D[d][1]


# 부하 공격 함수
def enemy_atk(enemy):
    x, y = enemy
    q = deque([(x, y, boss_atk)])
    visited = [[False] * M for _ in range(N)]
    visited[x][y] = True

    while q:
        x, y, cnt = q.popleft()
        if cnt == 0:
            continue
        if arr[x][y] == 2:
            return cnt
        for dx, dy in D:
            nx = x + dx
            ny = y + dy
            if N > nx >= 0 and M > ny >= 0 and not visited[nx][ny]:
                visited[nx][ny] = True
                if arr[nx][ny] in [0, 2]:
                    q.append((nx, ny, cnt - 1))

    return 0


# 이동 방향(위, 우, 아래, 좌)
D = [(-1, 0), (0, 1), (1, 0), (0, -1)]

N, M = map(int, input().split())
arr = []
is_sucksoon = False
for i in range(N):
    row = list(map(int, input().split()))
    arr.append(row)
    for j in range(M):
        if row[j] == 3:
            boss = (i, j)
        elif row[j] == 2:
            ari = (i, j)
        elif row[j] == 1:
            is_sucksoon = True

ari_direct = boss_direct = D.index((ari[0] - boss[0], ari[1] - boss[1]))
ari_hp, ari_atk, boss_hp, boss_atk = map(int, input().split())

while True:
    # 아리 공격
    boss_hp -= ari_atk
    if boss_hp <= 0:
        print("VICTORY!")
        break

    # 아리 이동
    pre_ari = ari
    damage, ari_direct, ari = ari_move(ari)
    ari_hp -= damage
    if ari_hp <= 0:
        print("CAVELIFE...")
        break

    # 보스 공격
    if is_sucksoon:
        enemy = search_sucksoon(boss)
        ari_hp -= enemy_atk(enemy)

        if ari_hp <= 0:
            print("CAVELIFE...")
            break

    # 보스 이동
    if pre_ari != ari:
        arr[boss[0]][boss[1]] = 0
        boss = pre_ari
        arr[boss[0]][boss[1]] = 3
    boss_direct = ari_direct
