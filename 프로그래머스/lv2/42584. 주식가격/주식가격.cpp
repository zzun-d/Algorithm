#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i=0; i< prices.size()-1; i++) {
        int price = prices[i];
        int cnt = 1;
        for (int j=i+1; j < prices.size() - 1; j++) {
            if (prices[j] < price) break;
            cnt++;
        }
        answer.push_back(cnt);
    }
    answer.push_back(0);
    return answer;
}