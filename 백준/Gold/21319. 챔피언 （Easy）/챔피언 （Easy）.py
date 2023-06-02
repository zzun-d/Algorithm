N = int(input())
lst = list(map(int, input().split()))

if N == 1:
    print(1)
else:
    lst = [lst[0]] + lst + [lst[-1]]
    ans = []
    need_power = 0
    for i in range(N, 1, -1):
        # 현재 인덱스와 앞 인덱스의 값이 같다면
        if lst[i] == lst[i - 1]:
            if need_power > 0:
                need_power -= 1

        else:
            if i - 1 > need_power:
                ans.append(i)
                need_power = max(
                    lst[i] - lst[i - 1], need_power + lst[i] - lst[i - 1] - 1
                )
            else:
                break

    if ans:
        print(*reversed(ans))
    else:
        print(-1)
