def solution(numbers, target):
    q = {numbers[0]:1, -numbers[0]:1}
    for i in range(1, len(numbers)):
        dct = {}
        for idx, cnt in q.items():
            if dct.get(idx+numbers[i]):
                dct[idx+numbers[i]] += cnt
            else:
                dct[idx+numbers[i]] = cnt
            if dct.get(idx-numbers[i]):
                dct[idx-numbers[i]] += cnt
            else:
                dct[idx-numbers[i]] = cnt
        q = dct
        dct = {}
    if q.get(target):
        return q[target]
    else:
        return 0