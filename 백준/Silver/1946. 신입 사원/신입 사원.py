import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    ans = 1
    standard_lst = [0]
    lst = [tuple(map(int, input().split())) for _ in range(N)]
    lst.sort()
    now_score = lst[0][1]
    for i, scores in enumerate(lst[1:], start=1):
        score = scores[1]
        if score < now_score:
            ans += 1
            now_score = score

    print(ans)
