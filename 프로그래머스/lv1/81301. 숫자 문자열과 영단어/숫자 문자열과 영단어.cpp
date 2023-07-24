#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans = "";
    int idx = 0;
    while (idx < s.size()) {
        if (s[idx] >= 'a' && s[idx] <= 'z') {
            if (s[idx] == 'z') {
                idx += 4;
                ans += '0';
            } else if (s[idx] == 'o') {
                idx += 3;
                ans += '1';
            } else if (s[idx] == 't') {
                if (s[idx+1] == 'w') {
                    idx += 3;
                    ans += '2';
                } else {
                    idx += 5;
                    ans += '3';
                }
            } else if (s[idx] == 'f') {
                if (s[idx+1] == 'o') {
                    ans += '4';
                } else {
                    ans += '5';
                }
                idx += 4;
            } else if (s[idx] == 's') {
                if (s[idx+1] == 'i') {
                    idx += 3;
                    ans +='6';
                } else {
                    idx += 5;
                    ans +='7';
                }
            } else if (s[idx] == 'e') {
                idx += 5;
                ans += '8';
            } else if (s[idx] == 'n') {
                idx += 4;
                ans += '9';
            }
        } else {
            ans += s[idx];
            idx++;
        }
    }
    answer = stoi(ans);
    return answer;
}