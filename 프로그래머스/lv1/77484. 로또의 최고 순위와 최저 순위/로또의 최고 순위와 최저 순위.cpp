#include <string>
#include <vector>

using namespace std;

int change_th(int cnt) {
    if (cnt > 5) {
        return 1;
    } else if (cnt > 4) {
        return 2;
    } else if (cnt > 3) {
        return 3;
    } else if (cnt > 2) {
        return 4;
    } else if (cnt > 1) {
        return 5;
    } else {
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0;
    int cor_cnt = 0;
    for (int l:lottos) {
        if (l == 0) {
            zero++;
        } else {
            for (int w_n:win_nums) {
                if(w_n == l) {
                    cor_cnt++;
                    break;
                }
            }
        }
    }
    answer.push_back(change_th(zero+cor_cnt));
    answer.push_back(change_th(cor_cnt));
    
    return answer;
}