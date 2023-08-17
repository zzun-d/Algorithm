#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool isPrefix(string a, string b){
    for (int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i=1; i<phone_book.size(); i++) {
        if (isPrefix(phone_book[i-1], phone_book[i])) {
            answer = false;
        }
    }
    return answer;
}