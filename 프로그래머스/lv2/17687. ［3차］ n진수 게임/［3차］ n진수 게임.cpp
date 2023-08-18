#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char to_char(int n) {
    char answer = '0';
    if (n < 10) {
        answer += n;
        return answer;
    } else {
        answer = 'A';
        answer += n-10;
        return answer;
    }
}

string chage_n(int n, int l) {
    string answer = "0";
    int number = 1;
    while (answer.size() < l) {
        string changed = "";
        int num = number;
        while (num > 0) {
            changed += to_char(num%n);
            num /= n;
        }
        reverse(changed.begin(), changed.end());
        answer += changed;
        number++;
    }
    return answer;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int turn = 0;
    int num = 1;
    string gameS = chage_n(n, t*m);
    for (int i=p-1; answer.size() < t; i+=m) {
        answer += gameS[i];
    }
        
    
    
    return answer;
}
