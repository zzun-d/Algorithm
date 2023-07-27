#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;
    for (int i=2; i<=number; i++) {
        int cnt = 2;
        for (int j=2; j < (int)sqrt(i)+1; j++) {
            if (i%j == 0) {
                cnt += 2;
            }
        }
        if (pow((int)sqrt(i), 2) == i) {
            cnt--;
        }
        if (cnt > limit) {
            answer += power;
        } else {
            answer += cnt;    
        }
        
    }
    return answer;
}