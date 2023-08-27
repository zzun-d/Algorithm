#include <string>
#include <vector>

using namespace std;

vector<int> v;
char c[3] = {'1', '2', '4'};
string solution(int n) {
    string answer = "";
    n--;
    do {
        v.push_back(n%3);
        n /= 3;
    }
    while (n > 3);
    if (n > 0) v.push_back(n);
    answer = c[v[0]];
    for (int i=1; i<v.size()-1; i++) {
        if (v[i] < 0) {
            v[i] = 2;
            v[i+1]--;
        } else if (v[i] == 0) {
            v[i+1]--;
            v[i] = 3;
        }
        answer = c[(v[i]-1)%3] + answer;
    }
    if (v.size() > 1 && v[v.size()-1] > 0) {
        answer = c[(v[v.size()-1]-1)%3] + answer;
    }
    return answer;
}