#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char c = words[0][words[0].size()-1];
    int idx = 1;
    set<string> s;
    s.insert(words[0]);
    while (idx < words.size()) {
        if (words[idx][0] != c || s.find(words[idx]) != s.end()) {
            break;
        }
        s.insert(words[idx]);
        c = words[idx][words[idx].size()-1];
        idx++;
    }
    cout << idx;
    if (idx == words.size()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(idx%n + 1);
        answer.push_back(idx/n + 1);
    }
    
    return answer;
}