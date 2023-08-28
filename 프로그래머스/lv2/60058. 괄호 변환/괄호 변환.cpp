#include <string>
#include <vector>

using namespace std;

bool isCorrect(string s) {
    vector<char> v;
    for (char c:s) {
        if (c == '(') {
            v.push_back('(');
        } else {
            if (v.empty()) {
                return false;
            }
            v.pop_back();
        }
    }
    return true;
}

bool isBalance(string s) {
    int l=0, r=0;
    for (char c:s) {
        c=='(' ? l++:r++;
    }
    return l==r;
}

string change(string s) {
    string ans = "", u = "", v="";
    if (s.size() == 2) return "()";
    if (s.size() == 0) return "";
    for (int i=2; i<=s.size(); i+=2) {
        u = s.substr(0, i);
        v = s.substr(i);
        if (isBalance(u)) break;
    }    
    if (isCorrect(u)) {
        ans = u + change(v);
    } else {
        ans += '(' + change(v) + ')';
        u = u.substr(1, u.size()-2);
        for (char &c:u) {
            c == '(' ? c = ')' : c = '(';
        }
        ans += u;
    }
    return ans;
}

string solution(string p) {
    string answer = "";
    answer = change(p);
    
    return answer;
}