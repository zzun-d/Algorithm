#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    int score = 0;
    for (int i=0; i<dartResult.length(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            v.push_back(score);
            if (dartResult[i] == '1' && dartResult[i+1] == '0') {
                i++;
                score = 10;
            } else {
                score = dartResult[i] - '0';
            }
        } else if (dartResult[i] >= 'D' && dartResult[i] <='T') {
            if (dartResult[i] == 'S') {
                score *= 1;
            } else if (dartResult[i] == 'D') {
                score = pow(score, 2);
            } else {
                score = pow(score, 3);
            }
        }  else {
            if (dartResult[i] == '*') {
                if (v.size() > 0) {
                    v[v.size()-1] *= 2;
                }
                score *= 2;
            } else {
                score *= -1;
            }
        }
    }
    
    v.push_back(score);
    
    for (int i=0; i<v.size(); i++) {
        answer += v[i];
    }
    return answer;
}