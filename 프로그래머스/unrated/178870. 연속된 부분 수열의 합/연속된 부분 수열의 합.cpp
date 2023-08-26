#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(sequence.size());
    int s=0, e=0;
    int sm = sequence[0];
    while (e<sequence.size()) {
        if (sm == k) {
            if (answer[1] - answer[0] > e-s) {
                answer[0] = s;
                answer[1] = e;
            }
            sm -= sequence[s];
            s++;
            e++;
            sm += sequence[e];
        } else if (sm > k) {
            if (s < e) {
                sm -= sequence[s];
                s++;
            } else {
                sm = sequence[s+1];
                s++;
                e++;
            }
        } else {
            e++;
            sm += sequence[e]; 
        }
    }
    return answer;
}