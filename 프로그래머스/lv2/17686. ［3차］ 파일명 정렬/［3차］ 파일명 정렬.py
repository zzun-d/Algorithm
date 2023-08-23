def solution(files):
    def name_split(name, idx):
        for i in range(len(name)):
            if name[i].isdigit():
                head = name[:i]
                for j in range(i+1, len(name)):
                    if not name[j].isdigit():
                        number = name[i:j]
                        tail = name[j:]
                        return (head, number, tail, idx)
                number = name[i:]
                tail = ""
                return (head, number, tail, idx)
                
                    
    lst = []
    answer = []
    for i in range(len(files)):
        lst.append(name_split(files[i], i))
    lst.sort(key=lambda x: (x[0].lower(), int(x[1]), x[3]))
    for head, number, tail, idx in lst:
        answer.append(head+number+tail)

    return answer