#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool pang(vector<string> &board) {
    int n=board.size(), m=board[0].size();
    set<pair<int, int>> s;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            if (board[i][j] != '-' && board[i][j] == board[i+1][j] && board[i][j+1] == board[i+1][j+1] && board[i][j+1] == board[i+1][j]) {
                s.insert(make_pair(i, j));
                s.insert(make_pair(i+1, j));
                s.insert(make_pair(i, j+1));
                s.insert(make_pair(i+1, j+1));
            }
        }
    }
    for (auto iter=s.begin(); iter != s.end(); iter++) {
        board[(*iter).first][(*iter).second] = '-';
    }
    return s.size() > 0 ?  true : false;
}

void gravity(vector<string> &board) {
    int n=board.size(), m=board[0].size();
    for (int i=n-1; i>0; i--) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == '-') {
                for (int k=i-1; k>=0; k--) {
                    if (board[k][j] != '-') {
                        board[i][j] = board[k][j];
                        board[k][j] = '-';
                        break;
                    }
                }    
            }
            
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (pang(board)) {
        gravity(board);     
    } 
      
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (board[i][j] == '-') {
                answer++;
            }   
        }
    }
    

    
   
    return answer;
}