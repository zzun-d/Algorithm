#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long long sum(vector<int> q) {
    long long ans = 0;
    for (int i=0; i<q.size(); i++) {
        ans += q[i];
    }
    return ans;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    bool ispos = false;
    long long sm_q1 = sum(queue1), sm_q2 = sum(queue2);
    queue<int> q1, q2;
    for (int i=0; i<queue1.size(); i++) {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    if ((sm_q1+sm_q2)%2 == 1) return -1;
    
    int l = q1.size();
    for (int i=0; i<=3*l; i++) {
        if (sm_q1 == sm_q2) {
            ispos = true;
            break;
        } else if (sm_q1 > sm_q2) {
            int pop = q1.front();
            q1.pop();
            q2.push(pop);
            sm_q1 -= pop;
            sm_q2 += pop;
        } else {
            int pop = q2.front();
            q2.pop();
            q1.push(pop);
            sm_q2 -= pop;
            sm_q1 += pop;
        }
        answer++;
    }
    if (ispos) {
        return answer;    
    } else {
        return -1;
    }
    
}
