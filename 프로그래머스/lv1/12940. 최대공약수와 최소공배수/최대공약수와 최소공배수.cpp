#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer = {1, 0};
    if (n > m) {
        int tmp = n;
        n = m;
        m = tmp;
    }
    answer[1] = m;
    for (int i=n; i>0; i--) {
        if (n%i == 0 && m%i == 0) {
            answer[0] = i;
            break;
        }
    }
    while (true) {
        if (answer[1]%n == 0) {
            break;
        } else {
            answer[1] += m;
        }
    }    
    return answer;
}