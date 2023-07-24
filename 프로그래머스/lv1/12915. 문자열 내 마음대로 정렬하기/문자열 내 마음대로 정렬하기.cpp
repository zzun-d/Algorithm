#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool comp(string a, string b) {
    
        if (a[n] < b[n]) {
            return true;
        } else if (a[n] > b[n]) {
            return false;
        } else {
            return a < b;
        }
    }

vector<string> solution(vector<string> strings, int num) {
    vector<string> answer;
    n = num;
    sort(strings.begin(), strings.end(), comp);
    
    return strings;
}