#include <string>
#include <vector>

using namespace std;

int trans23(int a) {
    if (a == 2) return 3;
    else if (a == 3) return 2;
    return a;
}
int trans12(int a) {
    if (a == 1) return 2;
    else if (a == 2) return 1;
    return a;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer = {{1, 3}};
    vector<vector<int>> nxt_ans;
    for (int i=1; i<n; i++) {
        for (int j=0; j<answer.size(); j++) {
            int a = trans23(answer[j][0]), b = trans23(answer[j][1]);
            nxt_ans.push_back(vector<int>{a, b});
        }
        nxt_ans.push_back(vector<int>{1, 3});
        for (int j=0; j<answer.size(); j++) {
            int a = trans12(answer[j][0]), b = trans12(answer[j][1]);
            nxt_ans.push_back(vector<int>{a, b});
        }
        answer = nxt_ans;
        nxt_ans.clear();
    }
    return answer;
}