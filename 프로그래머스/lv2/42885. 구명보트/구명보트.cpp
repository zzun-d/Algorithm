#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int l = people.size();
    int idx = 0;
    while (l-1 > idx) {
        if (people[l-1] + people[idx] <= limit){
            l--;
            idx++;
        } else {
            l--;
        }
        answer++;
        }
    if (l-1 == idx) {
        answer++;
    }
        
    return answer;
}