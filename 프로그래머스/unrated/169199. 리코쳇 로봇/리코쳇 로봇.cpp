#include <string>
#include <vector>
#include <queue>

using namespace std;

int D[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
vector<string> arr;
bool visited[100][100];
vector<int> move(int x, int y, int dx, int dy) {
    int nx = x + dx, ny = y + dy;
    while (nx >= 0 && arr.size() > nx && ny >= 0 && arr[0].size() > ny && arr[nx][ny] != 'D') {
        nx += dx;
        ny += dy;
    }
    return vector<int>{nx-dx, ny-dy};
}

int bfs(int x, int y) {
    queue<vector<int>> q;
    visited[x][y] = true;
    q.push(vector<int>{x, y, 0});
    while (!q.empty()) {
        x = q.front()[0];
        y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if (arr[x][y] == 'G') return cnt;
        for (int d=0; d<4; d++) {
            int dx = D[d][0], dy = D[d][1];
            vector<int> coordi = move(x, y, dx, dy);
            int nx = coordi[0];
            int ny = coordi[1];
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(vector<int>{nx, ny, cnt+1});
        }
    }
    return -1;
        
}

vector<int> start(vector<string> board) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (board[i][j] == 'R') return vector<int>{i, j};
        }
    }
}
int solution(vector<string> board) {
    arr = board;
    vector<int> rs = start(board);
    
    return bfs(rs[0], rs[1]);
}