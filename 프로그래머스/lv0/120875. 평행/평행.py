def solution(dots):
    answer = 0
    
    s = {0, 1, 2, 3}
    
    for i in range(4):
        for j in range(i+1, 4):
            point_1 = set()
            point_2 = set()
            point_1.add(i)
            point_1.add(j)
            point_2 = s - point_1
            point_1 = list(point_1)
            point_2 = list(point_2)
            if ((dots[point_1[0]][1] - dots[point_1[1]][1])/(dots[point_1[0]][0] - dots[point_1[1]][0])) == ((dots[point_2[0]][1] - dots[point_2[1]][1])/(dots[point_2[0]][0] - dots[point_2[1]][0])):
                answer = 1
    return answer