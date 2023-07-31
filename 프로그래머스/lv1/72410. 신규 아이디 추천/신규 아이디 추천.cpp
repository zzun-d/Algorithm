#include <string>
#include <vector>
#include <iostream>

using namespace std;

string step(string s) {
    string answer = "";
    string answer2 = "";
    string answer3 = "";
    string answer4 = "";
    string answer5 = "";
    string answer6 = "";
    string answer7 = "";
    
    for (char c:s) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
        answer += c;
    } 
    
    
    for (char c:answer) {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.') {
            answer2 += c;
        }
    }
    char old = 'a';
    for (char c:answer2) {
        if (c != '.' || old != '.') {
            answer3 += c;    
        }
        old = c;
    }
    
    if (answer3[0] == '.') {
        answer4 = answer3.substr(1, answer3.size());
    } else {
        answer4 = answer3;
    }
    if (answer4[answer4.size() - 1] == '.') {
        answer4 = answer4.substr(0, answer4.size()-1);
    }
    
    if (answer4.size() == 0) {
        answer5 = "a";
    } else {
        answer5 = answer4;
    }
    
    if (answer5.size() >= 16) {
        answer6 = answer5.substr(0, 15);
    } else {
        answer6 = answer5;
    }
    
    if (answer6[14] == '.') {
        answer6 = answer6.substr(0, 14);
    }
    
    while (answer6.size() < 3) {
        answer6 += answer6[answer6.size()-1];
    }
    
    
    return answer6;
}


string solution(string new_id) {
    string answer = step(new_id);
    
    return answer;
}