while True:
    try:
        N = int(input())
        s = "-"
        for _ in range(N):
            s = s + " " * len(s) + s
        print(s)

    except:
        break
