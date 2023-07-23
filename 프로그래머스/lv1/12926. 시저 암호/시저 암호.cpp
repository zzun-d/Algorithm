#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char c : s) {
        if (c >= 'a' && c <= 'z'){
            int num = c - 'a';
            num += n;
            num %= 26;
            char cc = 'a';
            cc += num;
            answer += cc;
        } else if (c >= 'A' && c <= 'Z') {
            int num = c - 'A';
            num += n;
            num %= 26;
            char cc = 'A';
            cc += num;
            answer += cc;
        } else {
            answer += " ";
        }
        
    }
    
    return answer;
}