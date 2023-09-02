#include <string>
#include <vector>

using namespace std;
bool visited[100];
int solution(vector<int> cards) {
    int answer = 0;
    int num1 = 0, num2 = 0;
    for (int i=0; i<cards.size(); i++) {
        if (visited[i]) continue;
        int cnt = 0;
        int now = cards[i]-1;
        while (!visited[now]) {
            visited[now] = true;
            now = cards[now] - 1;
            cnt++;
        }
        if (cnt > num1) num2 = num1, num1 = cnt;
        else if (cnt > num2) num2 = cnt;
    answer = num1*num2;
        
    }
    return answer;
}