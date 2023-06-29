c = int(input())
for _ in range(c):
    lst = list(map(int, input().split()))
    sm = sum(lst[1:])
    ever = sm / lst[0]
    cnt = 0

    for i in range(1, lst[0] + 1):
        if lst[i] > ever:
            cnt += 1
    ans = (cnt / lst[0]) * 100
    print(f"{ans:.3f}%")