#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]]++;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= iter->second+1;
    }
    return answer-1;
}