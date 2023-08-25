#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

bool comp(string s1, string s2) {
    int s3=stoi(s1+s2);
    int s4=stoi(s2+s1);
    return s3 > s4;
}

string solution(vector<int> numbers) {
    string answer = "";
    for (int num:numbers) {
        v.push_back(to_string(num));
    }
    sort(v.begin(), v.end(), comp);
    for (int i=0; i<v.size(); i++) {
        answer += v[i];
    }
    if (answer[0] == '0') answer = "0";
    return answer;
}