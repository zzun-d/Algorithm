def solution(s):
    answer = []
    s = s[1:-1].split('},')
    
    for i in range(len(s)):
        s[i] = s[i].replace('{', '')
        s[i] = s[i].replace('}', '')
        s[i] = set(map(int, s[i].split(',')))
    ordered_s = [set() for _ in range(len(s)+1)]
    for i in range(len(s)):
        ordered_s[len(s[i])] = s[i]
    for i in range(1, len(ordered_s)):
        plus =ordered_s[i] - ordered_s[i-1]
        answer.append(plus.pop())
        
    return answer