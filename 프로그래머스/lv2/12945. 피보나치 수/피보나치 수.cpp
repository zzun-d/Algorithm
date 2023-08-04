#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 0;
    int b = 1;
    for (int i=2; i<= n; i++) {
        int tmp = b;
        b = (a+b)%1234567;
        a = tmp;
    }
    return b;
}