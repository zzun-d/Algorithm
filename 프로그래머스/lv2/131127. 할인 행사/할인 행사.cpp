#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = 0;
    for (int num:number) {
        n += num;
    }
    for (int i=0; i <= discount.size() - n; i++) {
        map<string, int> m;
        bool pos = true;
        for (int j=0; j<want.size(); j++) {
            m[want[j]] = number[j];
        }
        for (int j=0; j<n; j++) {
            if (m.find(discount[i+j]) == m.end()) {
                pos=false;
                break;
            }
            m[discount[i+j]]--;
        }
        if (pos) {
            for (int j=0; j<want.size(); j++) {
                if (m[want[j]] != 0) {
                    pos = false;
                    break;
                }
            }
        }
        if (pos) answer++;
    }
    
    return answer;
}