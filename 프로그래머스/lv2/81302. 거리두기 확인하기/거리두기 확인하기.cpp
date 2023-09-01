#include <string>
#include <vector>
#include <iostream>

using namespace std;
int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int f(vector<string> place) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (place[i][j] == 'P') {
                vector<vector<int>> q;
                q.push_back(vector<int>{i, j, 2});
                bool visited[5][5] = {{0, }, };
                visited[i][j] = true;
                
                while (!q.empty()) {
                    vector<int> info = q.back();
                    q.pop_back();
                    int x = info[0], y = info[1], cnt = info[2];
                    for (int d =0; d<4; d++) {
                        int nx = x+D[d][0], ny = y+D[d][1];
                        if (nx >=0 && ny>=0 && 5>nx && 5>ny && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            if (place[nx][ny] == 'P') {
                                return 0;
                            }
                            else if (place[nx][ny] == 'O' && cnt > 1) q.push_back(vector<int>{nx, ny, cnt-1});
                        }
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto place:places) {
        answer.push_back(f(place));
    }
    return answer;
}