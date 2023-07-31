#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {50, 50, 0, 0};
    
    for (int i=0; i<wallpaper.size(); i++) {
        for (int j=0; j<wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                if (answer[0] > i) {
                    answer[0] = i;
                }
                if (answer[1] > j) {
                    answer[1] = j;
                }
                if (answer[2] < i+1) {
                    answer[2] = i+1;
                }
                if (answer[3] < j+1) {
                    answer[3] = j+1;
                }
            }
        }
    }
    return answer;
}