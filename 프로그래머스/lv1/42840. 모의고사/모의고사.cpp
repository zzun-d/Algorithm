#include <string>
#include <vector>

using namespace std;

vector<int> one = {1, 2, 3, 4, 5};
vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score1 = 0, score2 = 0, score3 = 0;
    for (int i=0; i < answers.size(); i++) {
        if (one[i%5] == answers[i]) {
            score1++;
        }
        if (two[i%8] == answers[i]) {
            score2++;
        }
        if (three[i%10] == answers[i]) {
            score3++;
        }
    }
    if (score1 > score2) {
        if (score3 > score1) {
            answer.push_back(3);
        } else if (score1 > score3) {
            answer.push_back(1);
        } else {
            answer.push_back(1);
            answer.push_back(3);
        }
    } else if (score2 > score1) {
        if (score3 > score2) {
            answer.push_back(3);
        } else if (score2 > score3) {
            answer.push_back(2);
        } else {
            answer.push_back(2);
            answer.push_back(3);
        }
    } else {
        if (score1 > score3) {
            answer.push_back(1);
            answer.push_back(2);
        } else if (score3 > score1) {
            answer.push_back(3);
        } else {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    return answer;
}