import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    ans = 0
    pos = 0
    neg = 0
    for n in map(int, input().split()):

        if n > 0:
            if pos > 0:
                ans += 1
            pos = n
            if neg < 0 and neg + n > 0:
                pos = neg + n
                neg = 0
            elif neg < 0:
                ans -= 1
                neg = 0
        elif n < 0:
            if neg < 0:
                neg += n
            else:
                neg = n
                if pos > 0 and pos + n > 0:
                    pos += n
                    neg = 0
                elif pos > 0:
                    ans += 1
                    pos = 0
    if pos > 0:
        ans += 1
    if neg < 0:
        ans -= 1

    if ans > 0:
        print("YES")
    else:
        print("NO")
