def solution(brown, yellow):
    answer = []
    for i in range(3, brown//2):
        j = (brown - i*2)//2 + 2
        if (i-2)*(j-2) == yellow:
            answer = [i, j]
            break
    answer.sort(reverse=True)
        
    return answer