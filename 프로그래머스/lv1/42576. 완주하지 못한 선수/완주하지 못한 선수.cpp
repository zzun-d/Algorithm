#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (string part:participant) {
        if (m.find(part) != m.end()) {
            m[part]++;
        } else {
            m[part] = 1;    
        }
        
    }
    for (string comp:completion) {
        m[comp]--;
    }
    for (auto itr = m.begin(); itr!=m.end(); itr++) {
        if (itr->second == 1) {
            answer = itr->first;
            break;
        }
    }
    
    

    return answer;
}