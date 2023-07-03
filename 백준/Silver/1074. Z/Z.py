N, r, c = map(int, input().split())

ans = 0


while N > 0:
    cnt = 0

    # 오른쪽
    if c >= (2**N) // 2:
        cnt += 1
        c -= 2 ** (N - 1)
        # 아래
        if r >= (2**N) // 2:
            cnt += 2
            r -= 2 ** (N - 1)

    # 왼쪽
    else:
        # 아래
        if r >= (2**N) // 2:
            cnt += 2
            r -= 2 ** (N - 1)
    ans += cnt * (4 ** (N - 1))
    N -= 1
print(ans)
