#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    while (s.size() > 1) {
        int zero = count(s.begin(), s.end(), '0');
        int one = s.size() - zero;
        answer[1] += zero;
        answer[0]++;
        s = "";
        while (one > 0) {
            if (one % 2 == 1) {
                s = '1' + s;
            } else {
                s = '0' + s;
            }
            one /= 2;
        }
        
    }
    return answer;
}