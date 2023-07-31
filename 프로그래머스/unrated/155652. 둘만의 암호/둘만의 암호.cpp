#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isSkip(char c, string s) {
    for (char ss:s) {
        if (c == ss) {
            return true;
        }
    }
    return false;
}

char changeAlphabet(char c) {
    if (c != 'z') {
        c++;
        return c;
    } else {
        return 'a';
    }
}

string solution(string s, string skip, int index) {
    string answer = "";
    for (char c:s) {
        int cnt = 0;
        while (cnt < index) {
            c = changeAlphabet(c);
            if (isSkip(c, skip)) {
                continue;
            }
            cnt++;
            
        }
        answer += c;
    }
    
    return answer;
}