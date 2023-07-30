#include <string>
#include <vector>

using namespace std;

bool isCan(string s){
    char tmp = '1';
    while (s.size() > 0) {
        if (s[0] == 'a') {
            if (s.substr(0, 3) == "aya" && tmp != 'a') {
                s = s.substr(3, s.size());
                tmp = 'a';
            } else {
                return false;
            }
        } else if (s[0] == 'y') {
            if (s.substr(0, 2) == "ye" && tmp != 'y') {
                s = s.substr(2, s.size());
                tmp = 'y';
            } else {
                return false;
            }
        } else if (s[0] == 'w') {
            if (s.substr(0, 3) == "woo" && tmp != 'w') {
                s = s.substr(3, s.size());
                tmp = 'w';
            } else {
                return false;
            }
        } else if (s[0] == 'm') {
            if (s.substr(0, 2) == "ma" && tmp != 'm') {
                s = s.substr(2, s.size());
                tmp = 'm';
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (string s:babbling) {
        if (isCan(s)) {
            answer++;
        }    
    }
    
    return answer;
}