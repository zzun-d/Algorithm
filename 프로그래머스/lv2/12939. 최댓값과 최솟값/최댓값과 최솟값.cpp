#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int mx, mn, idx=0;
    while (s[idx] != ' ') {
        idx++;
    }
    mx = stoi(s.substr(0, idx));
    mn = stoi(s.substr(0, idx));
    while (idx < s.length()) {
        idx++;
        int start = idx;
        while (idx < s.length() && s[idx] != ' '){
            idx++;
        }
        mx = max(mx, stoi(s.substr(start, idx-start)));
        mn = min(mn, stoi(s.substr(start, idx-start)));
    }
    answer += to_string(mn) + " " + to_string(mx);
    return answer;
}