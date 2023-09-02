#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i=1; i<=s.size()/2; i++) {
        int slen = s.size()%i;
        string target = s.substr(0, i);
        int cnt = 0;
        for (int j=i; j<=s.size()-i; j+=i) {
            if (s.substr(j, i) == target) cnt++;
            else {
                target = s.substr(j, i);
    
                if (cnt > 0) {
                    if (cnt >= 9) {
                        if (cnt >= 99) {
                            slen += i+3;
                        }
                        else {
                            slen += i+2;    
                        }
                    } else {
                        slen += i + 1;    
                    }
                } else {
                    slen += i;
                }
                cnt = 0;
            }
        }
        if (cnt == 0) {
            slen += i;
        } else {
            if (cnt >= 9) {
                if (cnt >= 99) {
                    slen += i+3;
                }
                else {
                    slen += i+2;    
                }
            } else {
                slen += i + 1;    
            }
        }
        if (answer>slen) answer = slen;
    }
    return answer;
}