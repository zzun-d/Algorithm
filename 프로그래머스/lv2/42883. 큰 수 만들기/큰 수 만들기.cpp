#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int target_size = number.size() - k;
    while (k > 0 && number.size()>k) {
        int idx = 0, mx = number[0] - '0';
        for (int i=1; i<=k; i++) {
            if (number[i] -'0' > mx) {
                idx = i;
                mx = number[i] - '0';
            }
        }
        if (idx == 0) {
            answer += number[0];
            number = number.substr(1, number.size()-1);
        } else {
            k -= idx;
            number = number.substr(idx, number.size()-idx);    
        }
    }
    if (number.size() + answer.size() == target_size) {
        answer += number;    
    }
    
    return answer;
}