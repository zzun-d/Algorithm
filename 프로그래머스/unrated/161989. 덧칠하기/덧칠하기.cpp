#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int s = section[0];
    for (int i=0; i<section.size(); i++) {
        if (section[i] > s-1 + m) {
            answer++;
            s = section[i];            
        }
    }
    
    return answer;
}