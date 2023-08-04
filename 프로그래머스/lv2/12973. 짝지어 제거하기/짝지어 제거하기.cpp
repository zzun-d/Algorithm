#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<char> v;
    int answer=0;
    while (s.size() > 0) {
        if (v.size() > 0 && v.back() == s.back()) {
            v.pop_back();
            s.pop_back();
        } else {
            v.push_back(s.back());
            s.pop_back();
        }
    }
    if(v.size() == 0) {
        answer = 1;
    }
    
    return answer;
}