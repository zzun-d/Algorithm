def solution(k, tangerine):
    answer = 0
    tangerine.sort()
    size_lst = []
    idx = 1
    cnt = 1
    exValue = tangerine[0]
    while idx < len(tangerine):
        if tangerine[idx] != exValue:
            exValue = tangerine[idx]
            size_lst.append(cnt)
            cnt = 1
        else:
            cnt += 1
        idx += 1
    size_lst.append(cnt)
    size_lst.sort(reverse=True)
    idx = 0
    while k > 0 and idx < len(size_lst):
        k -= size_lst[idx]
        idx+=1
        answer+=1

    return answer