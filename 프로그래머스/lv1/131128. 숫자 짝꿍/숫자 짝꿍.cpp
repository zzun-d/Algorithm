#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int lst[10] = {0};

string solution(string X, string Y) {
    string answer = "";
    for (char c = '0'; c <= '9'; c++) {
        lst[c-'0'] = min(count(X.begin(), X.end(), c), count(Y.begin(), Y.end(), c));
    }
    for (int i=9; i>=0; i--) {
        for (int j=0; j < lst[i]; j++) {
            answer += to_string(i);    
        }
    }
    if (answer[0] == '0') {
        answer = "0";
    } else if (answer == "") {
        answer = "-1";
    }
    return answer;
}