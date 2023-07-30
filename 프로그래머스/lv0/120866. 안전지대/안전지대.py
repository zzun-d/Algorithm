def solution(board):
    answer = 0
    n = len(board)
    DX = [-1, -1, 0, 1, 1, 1, 0, -1]
    DY = [0, 1, 1, 1, 0, -1, -1, -1]
    for y in range(n):
        for x in range(n):
            if board[y][x] == 1:
                for i in range(8):
                    ny, nx = y + DY[i], x + DX[i]
                    if 0 <= ny < n and 0 <= nx < n and board[ny][nx] == 0:
                        board[ny][nx] = 2
    for y in range(n):
        for x in range(n):
            if board[y][x] == 0:
                answer += 1


    return answer