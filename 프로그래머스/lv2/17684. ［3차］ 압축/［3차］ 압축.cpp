#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    int cnt = 1;
    int dict_idx = 27;
    for (char c='A'; c<='Z'; c++) {
        string s;
        s += c;
        m[s] = cnt;
        cnt++;
    }
    while (msg.size() > 0) {
        int cnt = 1;
        while (cnt <= msg.size() && m.find(msg.substr(0, cnt)) != m.end()) {
            cnt++;
        }
        answer.push_back(m[msg.substr(0, cnt-1)]);
        m[msg.substr(0, cnt)] = dict_idx;
        msg = msg.substr(cnt-1, msg.size()-cnt+1);
        
        dict_idx++;
    }
    
    return answer;
}