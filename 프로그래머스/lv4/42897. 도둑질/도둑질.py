def solution(money):
    # 털 때, 안털 때
    dp_1 = [[0, 0] for _ in range(len(money)-1)]
    dp_2 = [[0, 0] for _ in range(len(money)-1)]
    dp_1[0] = [money[0], 0]
    dp_2[0] = [money[1], 0]
    for i in range(1, len(money)-1):
        dp_1[i][0] = money[i] + dp_1[i-1][1]
        dp_1[i][1] = max(dp_1[i-1][0], dp_1[i-1][1])
        dp_2[i][0] = money[i+1] + dp_2[i-1][1]
        dp_2[i][1] = max(dp_2[i-1][0], dp_2[i-1][1])
    answer = max(dp_1[-1] + dp_2[-1])    
            
    
    return answer