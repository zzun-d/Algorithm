#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    for (int i=s.size(); i > 0; i--) {
        answer.push_back(s[i-1] - '0');
    }
    return answer;
}