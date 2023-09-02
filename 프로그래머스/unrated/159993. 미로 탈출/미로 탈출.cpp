#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<vector<int>> q;

int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<int> start(vector<string> m) {
    for (int i=0; i<m.size(); i++) {
        for (int j=0; j<m[0].size(); j++) {
            if (m[i][j] == 'S') return vector<int>{i, j};
        }
    }
}

int solution(vector<string> maps) {
    int answer = -1;
    int h=maps.size(), w = maps[0].size(), lx, ly;
    vector<int> s = start(maps);
    s.push_back(1);
    bool visited[100][100] = {{0,},}, isLever=false, isExit=false;
    visited[s[0]][s[1]] = true;
    q.push(s);
    while (!q.empty()) {
        vector<int> info = q.front();
        q.pop();
        int x = info[0], y = info[1], cnt = info[2];
        if (maps[x][y] == 'L') {
            lx = x, ly = y;
            isLever = true;
            answer += cnt;
            break;
        }
        for (int i=0; i<4; i++) {
            int nx = x + D[i][0], ny = y + D[i][1];
            if (nx >= 0 && ny >= 0 && h > nx && w > ny && !visited[nx][ny] && maps[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push(vector<int>{nx, ny, cnt+1});
            }
        }
    }
    if (!isLever) return -1;
    bool visited2[100][100] = {{0,},};
    visited2[lx][ly] = true;
    q = queue<vector<int>>();
    q.push(vector<int>{lx, ly, 0});
    while (!q.empty()) {
        vector<int> info = q.front();
        q.pop();
        int x = info[0], y = info[1], cnt = info[2];
        if (maps[x][y] == 'E') {
            isExit = true;
            answer += cnt;
            break;
        }
        for (int i=0; i<4; i++) {
            int nx = x + D[i][0], ny = y + D[i][1];
            if (nx >= 0 && ny >= 0 && h > nx && w > ny && !visited2[nx][ny] && maps[nx][ny] != 'X') {
                visited2[nx][ny] = true;
                q.push(vector<int>{nx, ny, cnt+1});
            }
        }
    }
    if (!isExit) return -1;
    return answer;
}