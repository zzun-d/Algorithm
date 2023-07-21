#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    int num = sqrt(n);
    for (int i=0; i<2; i++) {
        if(pow(num+i, 2) == n) {
            answer = pow(num+i+1, 2);
        }
    }
    return answer;
}