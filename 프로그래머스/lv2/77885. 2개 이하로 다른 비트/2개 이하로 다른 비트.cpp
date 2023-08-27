#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long pow(int num, int cnt) {
    long long ans = 1;
    for (int i=0; i<cnt; i++) {
        ans *= num;
    }
    return ans;
}


vector<int> to_binary(long long num) {
    vector<int> ans;
    if (num == 0) {
        ans.push_back(0);
    }
    else {
        while (num > 0) {
            ans.push_back(num%2);
            num/=2;
        }    
    }
    
    return ans;
}

long long to_decimal(vector<int> bn) {
    long long ans = 0;
    for (int i=0; i<bn.size(); i++) {
        ans += pow(2, i)*bn[i];
    }
    return ans;
}

long long nxt_num(vector<int> bn) {
    for (int i=0; i<bn.size(); i++) {
        if (bn[i] == 0) {
            bn[i] = 1;
            for (int j=i-1; j>=0; j--) {
                if (bn[j] == 1) {
                    bn[j] = 0;
                    break;
                }
            }
            return to_decimal(bn);
        }
    }
    bn[bn.size()-1] = 0;
    bn.push_back(1);
    return to_decimal(bn);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long number : numbers) {
        vector<int> bn = to_binary(number);
        answer.push_back(nxt_num(bn));
    }
    return answer;
}