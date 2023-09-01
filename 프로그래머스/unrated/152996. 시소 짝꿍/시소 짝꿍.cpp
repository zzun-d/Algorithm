#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int> m;
int cnt[1001];
long long solution(vector<int> weights) {
    long long answer = 0;
    for (int w:weights) {
        cnt[w]++;
        m[w*2]++;
        m[w*3]++;
        m[w*4]++;
    }
    for (int w:weights) {
        int c = cnt[w];
        answer += m[w*2] + m[w*3] + m[w*4] - 2*c - 1;
    }

    return answer/2;
}