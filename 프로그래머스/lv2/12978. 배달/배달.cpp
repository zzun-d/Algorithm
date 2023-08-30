#include <iostream>
#include <vector>
#include <iostream>

using namespace std;
bool v[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int dij[N+1][N+1];
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if(i==j) dij[i][j] = 0;
            else dij[i][j] = 500000;
        }
    }
    for (int i=0; i<road.size(); i++) {
        int x = road[i][0], y = road[i][1], z = road[i][2];
        if (dij[x][y] > z) dij[x][y] = z;
        if (dij[y][x] > z) dij[y][x] = z;
    }
    
    v[1] = true;
    for (int i=1; i<N;i++) {
        int mn = 500000;
        int idx = 0;
        for (int j=2; j<=N; j++){
            if (mn > dij[1][j] && !v[j]) {
                mn = dij[1][j];
                idx = j;
            }
        }
        v[idx] = true;
        for (int j=2; j<=N; j++) {
            if (!v[j] && dij[1][j] > dij[idx][j]+mn) {
                dij[1][j] = dij[idx][j]+mn;
            }
        }       
    }
    for (int i=1; i<=N; i++) {
        if (dij[1][i] <= K) answer++;
    }
    
    
    return answer;
}