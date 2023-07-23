#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string triple = "";
    while (n) {
        triple = to_string(n%3) + triple;
        n /= 3;
    }
    
    for (int i=0; i<triple.size(); i++) {
        answer += pow(3, i) * (triple[i] - '0');
    }
    
    
    return answer;
}