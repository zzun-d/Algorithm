#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end(), comp);
    answer = stoll(s);
    return answer;
}