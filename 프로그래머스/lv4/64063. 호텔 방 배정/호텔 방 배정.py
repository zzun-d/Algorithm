import sys

sys.setrecursionlimit(1000000)

def solution(k, room_number):
    def find_parent(x):
        if not table.get(x):
            table[x] = x + 1
            return x
        else:
            table[x] = find_parent(table[x])
            return table[x]
    result = []
    table = dict()
    for room in room_number:
        result.append(find_parent(room))

    return result