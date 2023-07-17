#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    int tmp = 100000000;
    sort(targets.begin(), targets.end());
    
    for (int i=0; i<targets.size(); i++) {
        int l, r;
        l = targets[i][0];
        r = targets[i][1];
        if (l >= tmp) {
            answer++;
            tmp = r;
            continue;
        }
        if (tmp > r){
            tmp = r;
        }
    }
    
    return answer;
}