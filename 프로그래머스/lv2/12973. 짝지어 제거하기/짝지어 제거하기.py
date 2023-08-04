def solution(s):
    answer = 0
    lst = list(s)
    stack = []
    while lst:
        c = lst.pop()
        if len(stack) > 0 and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    if not stack:
        answer = 1
        
    return answer