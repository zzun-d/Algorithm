
priorop = [['*', '+', '-'], ['*', '-', '+'], ['+', '-', '*'], ['+', '*', '-'], ['-', '*', '+'] ,['-', '+', '*']]

def calcu(a, b, o):
    if o == '*':
        return a*b
    elif o == '+':
        return a+b
    else:
        return a-b

def solution(expression):
    answer = 0
    nums = []
    opers = []
    idx = 0
    num = ""
    while idx < len(expression):
        if '9'>=expression[idx] >='0':
            num+=expression[idx] 
        else:
            nums.append(int(num))
            num = ""
            opers.append(expression[idx])
        idx+=1
    nums.append(int(num))
    
    for oper in priorop:
        nxtnums = nums[:]
        nxtopers = opers[:]
        for o in oper:
            idx = 0
            while idx < len(nxtopers):
                
                if nxtopers[idx] == o:
                    nxtnums = nxtnums[:idx] + [calcu(nxtnums[idx], nxtnums[idx+1], o)] + nxtnums[idx+2:]
                    nxtopers = nxtopers[:idx] + nxtopers[idx+1:]
                    continue
                idx+=1
                
        if abs(nxtnums[0]) > answer:
            answer = abs(nxtnums[0])
    return answer