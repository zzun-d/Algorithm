#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;



int solution(vector<int> topping) {
    int answer = 0;
    map<int ,int> m1, m2;
    
    for (int i:topping) {
        m1[i]++;
    }
    
    for (int i=0; i<topping.size(); i++) {
        m2[topping[i]]++;
        m1[topping[i]]--;
        if (m1[topping[i]] == 0) m1.erase(topping[i]);
        if (m1.size() == m2.size()) answer++;
    }
    
    return answer;
}