#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n = 0;
    string s = to_string(x);
    for (int i=0; i<s.size(); i++) {
        n += s[i] - '0'; 
    }
    if (x%n != 0) {
        answer = false;
    }
    return answer;
}