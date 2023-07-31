#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<char, int> m;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int s_year = stoi(today.substr(0, 4));
    int s_month = stoi(today.substr(5, 7));
    int s_day = stoi(today.substr(8, 10));
    for (string s:terms) {
        m[s[0]] = stoi(s.substr(2, s.size()));
    }
    
    for (int i = 0; i<privacies.size(); i++) {
        int term = 0;
        int p_year = stoi(privacies[i].substr(0, 4));
        int p_month = stoi(privacies[i].substr(5, 7));
        int p_day = stoi(privacies[i].substr(8, 10));
        char p_type = privacies[i][11];
        
        if (p_day <= s_day) {
            term++;
        }
        
        term += 12*(s_year - p_year) + s_month - p_month;
        if (term > m[p_type]) {
            answer.push_back(i+1);
        }
        
    }
    return answer;
}