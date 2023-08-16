#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dungeonClear(int clearCnt, int stamina, vector<vector<int>> dungeons) {
    // cout << clearCnt << ", " << stamina << ", " << dungeons.size() << endl;
    if (dungeons.empty()) {
        answer = max(answer, clearCnt);
    }
    for (int i=0; i<dungeons.size(); i++) {
        vector<vector<int>> dungeonCopy = dungeons;
        vector<int> v = dungeons[i];
        dungeonCopy.erase(dungeonCopy.begin()+i, dungeonCopy.begin()+i+1);
        if (stamina >= v[0]) {
            dungeonClear(clearCnt + 1, stamina - v[1], dungeonCopy);
        } else {
            dungeonClear(clearCnt, stamina, dungeonCopy);    
        }
        
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    dungeonClear(0, k, dungeons);
    return answer;
}