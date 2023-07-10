#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    if (a*b*2 <= stoi(to_string(a) + to_string(b))) {
        answer = stoi(to_string(a) + to_string(b));
    } else {
        answer = a*b*2;
    }
    return answer;
}