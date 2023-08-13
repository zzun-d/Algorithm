#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

deque<string> cache;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (auto city:cities) {
        int tmp = true;
        for (int i=0; i<city.size(); i++) {
            if (city[i] <= 'Z' && city[i] >= 'A') {
                city[i] += 32;
            }
        }
        for (int i=0; i<cache.size(); i++) {
            if (city == cache[i]) {
                answer++;
                tmp = false;
                cache.erase(cache.begin()+i);
                break;
            }
        }
        if (tmp) answer += 5;
        cache.push_back(city);
        if (cache.size() > cacheSize) cache.pop_front();
        
    }
    
    return answer;
}