#include <string>
#include <vector>

using namespace std;

vector<long long> v = {1, 2};

long long solution(int n) {
    long long answer = n;
    for (int i=0; i < n-2; i++) {
        v.push_back((v[i] + v[i+1])%1234567);
    }
    if (n > 2){
        answer = v.back();
    }
    return answer;
}