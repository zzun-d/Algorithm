#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int gap = 'a' - 'A';
    if (s[0] >= 'a' && s[0] <= 'z') s[0] -= gap;
    
    for (int i=1; i<s.size(); i++) {
        if (s[i] == ' ') {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= gap;
            }
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += gap;
            }
        }
    }
    answer = s;
    return answer;
}