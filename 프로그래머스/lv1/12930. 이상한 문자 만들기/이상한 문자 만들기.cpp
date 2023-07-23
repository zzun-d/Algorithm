#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    int plus = 'a' - 'A';
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ') {
            answer += " ";
            idx = 0;
            continue;
        }
        if (idx % 2 == 0 && s[i] > 'Z') {
            s[i] -= plus;
            answer += s[i];
        } else {
            if (idx % 2 == 1 && s[i] < 'a') {
                s[i] += plus;
            }
            answer += s[i];
        }
        
        idx++;
    }
    
    return answer;
}