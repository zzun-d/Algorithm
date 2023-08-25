#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i=2; i<=sqrt(n); i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

set<int> st;

void makeNum(string s, string madeNum) {
    if (s.size() == 0 && madeNum.size() > 0) {
        st.insert(stoi(madeNum));
    } else {
        for (int i=0; i<s.size(); i++) {
            string nxt = s.substr(0, i) + s.substr(i+1, s.size()-i-1);
            makeNum(nxt, madeNum+s[i]);
            makeNum(nxt, madeNum);
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    makeNum(numbers, "");
    for (auto iter = st.begin(); iter != st.end(); iter++) {
        if (isPrime(*iter)) answer++;
        
    }
    return answer;
}