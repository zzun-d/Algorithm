#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> m;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (string key:keymap) {
        for (int i=0; i<key.size(); i++) {
            if (m.find(key[i]) == m.end()) {
                m[key[i]] = i+1;
            } else if (m[key[i]] > i+1){
                m[key[i]] = i+1;
            }
        }
    }
    for (string target:targets) {
        int ans = 0;
        for (char c:target) {
            if (m.find(c) == m.end()) {
                ans = -1;
                break;
            } else {
                ans += m[c];
            }
        }
        answer.push_back(ans);
    }
    
    return answer;
}