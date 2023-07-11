import sys

input = sys.stdin.readline


def find_depth(n, k):
    sm = 0
    d = 0
    while sm <= n:
        sm += k**d
        d += 1
    return d


def go_parnet(n, k, d):
    for _ in range(d):
        if n % k > 0:
            n = n // k
        else:
            n = n // k - 1
    return n


N, K, Q = map(int, input().split())
if K == 1:
    for _ in range(Q):
        x, y = map(int, input().split())
        print(abs(x - y))
else:
    for _ in range(Q):
        x, y = map(int, input().split())
        ans = 0
        x -= 1
        y -= 1
        x_depth = find_depth(x, K)
        y_depth = find_depth(y, K)
        if x_depth > y_depth:
            x_depth, y_depth = y_depth, x_depth
            x, y = y, x

        ans += y_depth - x_depth
        y = go_parnet(y, K, ans)
        while not x == y:
            ans += 2
            x = go_parnet(x, K, 1)
            y = go_parnet(y, K, 1)

        print(ans)
