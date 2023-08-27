#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt_zero = 0, cnt_one = 0;

bool isSame(vector<vector<int>> v) {
    int target = v[0][0];
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v.size(); j++) {
            if (v[i][j] != target) return false;
        }
    }
    return true;
}


void press(vector<vector<int>> v) {
    int target = v[0][0];
    if (isSame(v)) {
        target==0 ? cnt_zero++ : cnt_one++;
    } else {
        int div = v.size()/2;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                vector<vector<int>> v2;
                
                for (int k=i*div; k<(i+1)*div; k++) {
                    vector<int> v3;
                    for (int l=j*div; l<(j+1)*div; l++) {
                        v3.push_back(v[k][l]);
                    }
                    v2.push_back(v3);
                }
                press(v2);
            }
        }
    }
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    press(arr);
    answer.push_back(cnt_zero);
    answer.push_back(cnt_one);
    return answer;
}