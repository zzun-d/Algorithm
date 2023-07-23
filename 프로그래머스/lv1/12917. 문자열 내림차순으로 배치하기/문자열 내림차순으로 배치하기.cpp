#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

string solution(string s) {
    string answer = "";
    answer = s;
    sort(answer.begin(), answer.end(), comp);
    return answer;
}