#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1001][1001];

int d[3][2] = {{1, 0}, {0, 1}, {-1, -1}};

vector<int> solution(int n) {
    vector<int> answer;
    
    if (n == 1) {
        answer = {1};
        return answer;
    } else if (n==2) {
        answer = {1, 2, 3};
        return answer;
    }
    
    
    for (int i=0; i<n; i++) {
        arr[i][0] = i+1;
    }
    for (int i=1; i<n; i++) {
        arr[n-1][i] = i+n;
    }
    
    int num = n*2;
    int didx = 2;
    int x=n-1, y=n-1;
    int cnt = 0;
    
    while (cnt < 2) {
        if (arr[x+d[didx][0]][y+d[didx][1]] != 0) {
            didx++;
            didx %= 3;
            cnt++;
            continue;
        }
        cnt = 0;
        
        x += d[didx][0];
        y += d[didx][1];
        arr[x][y] = num;
        num++;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] == 0) {
                break;
            }
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}