#include <iostream>
#include<vector>

using namespace std;
int arr[1002][1002];
int solution(vector<vector<int>> board) {
    int answer = 0;
    int l = 0;
    for (int i=1; i<=board.size(); i++) {
        for (int j=1; j<=board[0].size(); j++) {
            arr[i][j] = board[i-1][j-1] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    for (int i=1; i<=board.size() && board.size()-i+1 > l; i++) {
        for (int j=1; j<=board[0].size() && board[0].size()-j+1 > l; j++) {
            if (arr[i][j] - arr[i-1][j] - arr[i][j-1] + arr[i-1][j-1] > 0) {
                while (arr[i+l][j+l] - arr[i-1][j+l] - arr[i+l][j-1] + arr[i-1][j-1] == (l+1)*(l+1)) {
                    l++;
                    answer = l*l;
                }
            }
        }
    }
    
    return answer;
}