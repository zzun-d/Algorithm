#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0;
    int cnt = 0;
    for (int i=0; i<progresses.size(); i++) {
        progresses[i] += days*speeds[i];
        if (progresses[i] >= 100) {
            cnt++;
        } else {
            if (cnt > 0) {
                answer.push_back(cnt);
                cnt = 0;
            }
            while (progresses[i] < 100) {
                progresses[i] += speeds[i];
                days++;
            }
            cnt++;
        }
    }
    if (cnt > 0) answer.push_back(cnt);
    return answer;
}