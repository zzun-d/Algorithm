#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lst[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    fill_n(lst, 32, 1);
    for (int i:reserve) {
        lst[i]++;
    }
    for (int i:lost) {
        lst[i]--;
    }
    lst[0] = 0;
    lst[31] = 0;
    for (int i=1; i<=n; i++) {
        if (lst[i] == 0) {
            if (lst[i-1] > 1) {
                lst[i-1]--;
                lst[i]++;
                answer++;
            } else if (lst[i+1] > 1) {
                lst[i+1] --;
                lst[i]++;
                answer++;
            }
        } else {
            answer++;
        }
    }
    
    return answer;
}