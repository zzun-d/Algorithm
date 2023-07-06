import sys


def input():
    return sys.stdin.readline().rstrip()


case_no = 0
while True:
    case_no += 1
    n, m = map(int, input().split())
    if n == 0:
        break
    graph = [set() for _ in range(n + 1)]
    for _ in range(m):
        n1, n2 = map(int, input().split())
        graph[n1].add(n2)
        graph[n2].add(n1)
    ans = 0
    visited = set()
    for i in range(1, n + 1):
        if visited.intersection({i}):
            continue
        visited.add(i)
        tmp = True
        q = list(graph[i])
        # print("=" * 30)
        # print("start :", i)

        while q:
            # print("q:", q)
            # print("vistied:", visited)
            nxt_q = []
            while q:
                node = q.pop()
                # print("node:", node)
                if len(graph[node] & visited) > 1:
                    # print("is loof")
                    tmp = False
                nxt_q += list(graph[node] - visited)
                visited.add(node)
            q = nxt_q[:]
        if tmp:
            ans += 1
        # print("=" * 30)
    if ans > 1:
        print(f"Case {case_no}: A forest of {ans} trees.")
    elif ans == 1:
        print(f"Case {case_no}: There is one tree.")
    else:
        print(f"Case {case_no}: No trees.")
