#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1;
    int idx = 0;
    char target = s[0];
    int tmp = 0;
    while(idx < s.size()) {
        if (s[idx] == target) {
            tmp++;
        } else {
            tmp--;
        }
        idx++;
        if (tmp == 0 && idx < s.size()) {
            answer++;
            target = s[idx];
            tmp = 0;
        }
    }
    return answer;
}