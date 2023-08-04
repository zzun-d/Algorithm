#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i=3; i<brown/2; i++) {
        int j = (brown - i*2)/2 + 2;
        if ((i-2)*(j-2) == yellow) {
            if (j > i) {
                answer.push_back(j);
                answer.push_back(i);
            } else {
                answer.push_back(i);
                answer.push_back(j);
            }
            break;
        }
    }
    return answer;
}