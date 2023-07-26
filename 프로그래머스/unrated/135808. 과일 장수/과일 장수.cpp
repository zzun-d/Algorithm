#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());
    for (int i=0; i+m-1 < score.size(); i+= m) {
        answer += score[i+m-1] * m;
    }
    return answer;
}