N, M = map(int, input().split())

l = list(map(int, input().split()))
l.sort()
ans = []

def dfs():
    if len(ans) == M:
        print(*ans)
        return
    
    for i in l:
        if ans and ans[-1] > i:
            continue
        if i not in ans:
            ans.append(i)
            dfs()
            ans.pop()
            
dfs()