#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int mymax(int n, vector<int> lst) {
    int answer = 0;
    for (int i=0; i<4; i++) {
        if (i == n) continue;
        if (lst[i] > answer) answer = lst[i];
    }
    return answer;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i=1; i<land.size(); i++) {
        for (int j=0; j<4; j++) {
            land[i][j] += mymax(j, land[i-1]);
        }
    }
    answer = mymax(4, land[land.size()-1]);
    return answer;
}