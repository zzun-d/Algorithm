#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> v;
    int answer = 0;
    v = priorities;
    sort(v.rbegin(), v.rend());
    int idx = 0;
    for (int i=0; i<v.size(); i++) {
        while (priorities[idx] != v[i] || priorities[idx] < 0) {
            idx = (idx+1)%priorities.size();
        }
        priorities[idx] = -1;
        if (idx == location) {
            answer = i+1;
        }
    }    
    
    return answer;
}