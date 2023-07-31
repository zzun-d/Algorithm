#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    for (int move:moves) {
        for (int i=0; i < board.size(); i++) {
            if (board[i][move-1] != 0) {
                if (v.size() > 0 && v[v.size()-1] == board[i][move-1]) {
                    v.pop_back();
                    answer += 2;
                } else {
                    v.push_back(board[i][move-1]);
                }    
                board[i][move-1] = 0;
                break;
            }
        }
    }
    return answer;
}