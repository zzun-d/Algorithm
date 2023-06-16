# 1, 2, 3의 합으로 대칭되게 나타내는 경우의 수 구하기
dp = [1, 1, 2, 2, 3, 3]
T = int(input())
for _ in range(T):
    N = int(input())
    cnt = 0
    l = N - len(dp) + 1
    for _ in range(l):
        dp.append(
            (dp[-2] % 1000000009 + dp[-4] % 1000000009 + dp[-6] % 1000000009)
            % 1000000009
        )
    print(dp[N])
