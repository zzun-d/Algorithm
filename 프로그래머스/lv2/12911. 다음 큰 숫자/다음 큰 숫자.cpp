#include <string>
#include <vector>

using namespace std;

int count_one(int num) {
    int cnt = 0;
    while (num > 0) {
        if(num%2==1) cnt++;
        num /= 2;
    }
    return cnt;
}

int solution(int n) {
    int std = count_one(n);
    int target = n+1;
    while (count_one(target) != std) {
        target++;
    }
    return target;
}