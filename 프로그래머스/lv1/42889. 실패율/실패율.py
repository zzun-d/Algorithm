def solution(N, stages):
    answer = []
    lst = []
    l = len(stages)
    stages.sort()
    idx = 0
    for i in range(1, N+1):
        cnt = 0
        if idx >= l or stages[idx] > i:
            lst.append((0, -i))
            continue
        while idx < l and stages[idx] == i:
            cnt+=1
            idx+=1
        lst.append((cnt/(l-idx+cnt), -i))
    lst.sort(reverse=True)
    for _, n in lst:
        answer.append(-n)
            
        
    return answer

