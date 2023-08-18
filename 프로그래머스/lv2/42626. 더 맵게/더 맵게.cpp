#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int mixed(long long a, long long b) {
    return a + b*2;
}


int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int sco:scoville) {
        pq.push(-sco);
    }
    long long lowSpicy1 = -pq.top();
    pq.pop();
    long long lowSpicy2 = -pq.top();
    pq.pop();
    while (lowSpicy1 < K) {
        answer++;
        pq.push(-mixed(lowSpicy1, lowSpicy2));
        if (pq.size() < 2) {
            if (-pq.top() < K) return -1;
            return answer;
        } 
        lowSpicy1 = -pq.top();
        pq.pop();
        lowSpicy2 = -pq.top();
        pq.pop();
    }
    return answer;
}