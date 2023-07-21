#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while (answer <= 500){
        if (num == 1){
            break;
        }
        if (num % 2 == 1) {
            num *= 3;
            num++;
        } else {
            num /= 2;
        }
        answer++;
    }
    if (answer > 500) {
        answer = -1;
    }
    return answer;
}