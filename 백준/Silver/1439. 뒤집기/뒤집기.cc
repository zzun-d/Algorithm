#include <iostream>
#include <string>

using namespace std;

string s;
int zeros = 0, ones = 0;
int main() {
    cin >> s;
    int l = s.length();
    int i = 1;
    char tmp = s[0];
    if (tmp == '1') {
        ones++;
    } else {
        zeros++;
    }
    while (i < l) {
        if (s[i] != tmp) {
            tmp = s[i];
            if(tmp == '1') {
                ones++;
            } else {
                zeros++;
            }
        }
        i++;
    }
    cout << min(ones, zeros);
    return 0;
}