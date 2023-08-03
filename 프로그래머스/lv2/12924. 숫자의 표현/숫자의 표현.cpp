#include <string>
#include <vector>

using namespace std;

int Sum(int s_num, int e_num) {
    int ans = 0;
    for (int i=s_num; i<=e_num; i++) {
        ans += i;
    }
    return ans;
}

int Finn(int target) {
    int s_num = 1;
    int e_num = 1;
    int ans = 0;
    while (s_num <= target) {
        int sm = Sum(s_num, e_num);
        if (sm == target) {
            ans++;
        }
        if (sm > target) {
            s_num++;
        } else {
            e_num++;
        }
    }
    return ans;
}

int solution(int n) {
    int answer = Finn(n);
    
    return answer;
}