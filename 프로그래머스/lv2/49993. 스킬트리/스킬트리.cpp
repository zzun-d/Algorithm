#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer =skill_trees.size();
    
    for (string skills:skill_trees) {
        vector<char> compare;
        for (char c:skills) {
            for (char s:skill) {
                if (c == s) {
                    compare.push_back(c);
                }
            }
        }
        for (int i=0; i<compare.size(); i++) {
            if (compare[i] != skill[i]) {
                answer--;
                break;
            }
        }
    }
    
    return answer;
}