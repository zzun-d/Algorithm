#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    
    if (b==0) {
        return a;
    }
    
    return gcd(b, a%b);
}

bool ispos(vector<int> array, int num) {
    for (int i=0; i<array.size(); i++) {
        if (array[i]%num == 0) {
            return false;
        }
    }
    return true;
} 

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int agcd = arrayA[0], bgcd = arrayB[0];
    for (int i=1; i<arrayA.size(); i++) {
        agcd = gcd(agcd, arrayA[i]);
    }
    
    for (int i=1; i<arrayB.size(); i++) {
        bgcd = gcd(bgcd, arrayB[i]);
    }
    if (ispos(arrayA, bgcd) && bgcd > answer) answer = bgcd;
    if (ispos(arrayB, agcd) && agcd > answer) answer = agcd;
    
    
    return answer;
}