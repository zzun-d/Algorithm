#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n < 3) {
        return n;
    } 
    long long a = 1, b = 2;
    for (int i=2; i<n; i++) {
        int tmp = a;
        a = b;
        b = (a+tmp)%1000000007;
    }
    return b;
}