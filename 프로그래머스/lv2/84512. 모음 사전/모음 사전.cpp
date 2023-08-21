#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> v;

void recur(string s, int n) {
    if (s.size() == n) {
        v.push_back(s);
        if (n < 5) {
            recur(s, n+1);
        }
    } else {
        recur(s+'A', n);
        recur(s+'E', n);
        recur(s+'I', n);
        recur(s+'O', n);
        recur(s+'U', n);
    }    
}

int solution(string word) {
    int answer = 0;
    recur("", 1);
    for (int i=0; i<v.size(); i++) {
        if (v[i] == word) {
            answer = i+1;
        }
    }
    return answer;
}