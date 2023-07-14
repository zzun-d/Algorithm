N = list(input())
N.sort(reverse=True)
if "0" in N and sum(map(int, N)) % 3 == 0:
    print("".join(N))
else:
    print(-1)
