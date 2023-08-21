#include<vector>
#include<queue>
#include<tuple>

using namespace std;

bool visited[100][100];
int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1));
    visited[0][0] = true;
    while (q.size() > 0) {
        int x = get<0>(q.front()), y = get<1>(q.front()), cnt = get<2>(q.front());
        if (x == n-1 && y == m-1) {
            answer = cnt;
            break;
        }
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + D[i][0];
            int ny = y + D[i][1];
            if (n > nx && nx >= 0 && m > ny && ny >= 0 && !visited[nx][ny] && maps[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, cnt+1));
            }
        }
        
    }
    return answer;
}