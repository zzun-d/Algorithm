def solution(skill, skill_trees):
    answer = len(skill_trees)
    
    for skills in skill_trees:
        lst = []
        for c in skills:
            if c in skill:
                lst.append(skill.find(c))
        for i in range(len(lst)):
            if i != lst[i]:
                answer -= 1
                break
    return answer