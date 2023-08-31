#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 1;
    answer += (d/k)*2;
    long long new_d = d;
    for (long long i=k; i<new_d; i+=k) {
        long long num = sqrt(new_d*new_d - i*i);
        answer += num/k;
    }
    
    return answer;
}