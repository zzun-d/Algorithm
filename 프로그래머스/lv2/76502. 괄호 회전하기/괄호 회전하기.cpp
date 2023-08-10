#include <string>
#include <vector>
#include <stack>

using namespace std;

int isCorrect(string s) {
    stack<char> sOpen;
    int cnt = 0;
    for (char c:s) {
        if (c == '{' || c == '[' || c == '(') {
            sOpen.push(c);
        } else {
            if (sOpen.empty()) return 0;
            if (c == '}' && sOpen.top() == '{') sOpen.pop();
            else if (c == ']' && sOpen.top() == '[') sOpen.pop();
            else if (c == ')' && sOpen.top() == '(') sOpen.pop();
            else return 0;
            if (sOpen.empty()) cnt++;
        }
    }
    if (sOpen.empty()) {
        return cnt;
    }
    return 0;
}

stack<int> stac;
int solution(string s) {
    int answer = 0;
    for (int i=0; i<s.size(); i++) {
        int cnt = isCorrect(s.substr(i, s.size() - i) + s.substr(0, i));
        if (cnt > 0) {
            answer = cnt;
            break;
        } 
    }
    return answer;
}