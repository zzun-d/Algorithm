#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> v1, v2;

string isAlpha(string s) {
    string answer = "";
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            answer += c;
        } else if (c >= 'A' && c <='Z') {
            c += 32;
            answer += c;
        } else {
            return "noAlpha";
        }
    }
    return answer;
}

vector<string> makeSet(string s) {
    vector<string> answer;
    for (int i=0; i < s.size() - 1; i++) {
        string target = s.substr(i, 2);
        string targetAlpha = isAlpha(target);
        if (targetAlpha == "noAlpha") {
            continue;
        } else {
            answer.push_back(targetAlpha);
        }
    }
    return answer;
}

int solution(string str1, string str2) {
    
    v1 = makeSet(str1);
    v2 = makeSet(str2);
    int uni=v1.size(), inter=0;
    for (int i=0; i < v2.size(); i++) {
        auto iter = find(v1.begin(), v1.end(), v2[i]);
        if (iter != v1.end()) {
            v1.erase(iter);
            inter++;
        } else {
            uni++;
        }
    }
    if (uni < 1) return 65536;
    else return inter*65536/uni;
}