#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for (int i=0; i<s.size(); i++) {
        bool tmp = true;
        for (int j=i-1; j >=0; j--) {
            if (s[i] == s[j]) {
                answer.push_back(i-j);
                tmp = false;
                break;
            }
        }
        if (tmp) {
            answer.push_back(-1);
        }
    }
    return answer;
}