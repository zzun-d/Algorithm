#include <string>
#include <vector>

using namespace std;

bool isPrime[1000001];

int solution(int n) {
    int answer = 0;
    for (int i=2; i<=n; i++) {
        if (not isPrime[i]) {
            answer++;
            for (int j=i*2; j<=n; j+=i) {
                if (not isPrime[j]) {
                    isPrime[j] = true;
                }
            }
        }
    }
    return answer;
}