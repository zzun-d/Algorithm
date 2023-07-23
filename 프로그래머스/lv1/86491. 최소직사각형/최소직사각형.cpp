#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mx_w = 0, mx_h = 0;
    for (int i=0; i<sizes.size(); i++) {
        int h=sizes[i][0], w=sizes[i][1];
        if (w > h) {
            int tmp=w;
            w = h;
            h = tmp;
        }
        if (w > mx_w) {
            mx_w = w;
        }
        if (h > mx_h) {
            mx_h = h;
        }
    }
    answer = mx_w * mx_h;
    
    return answer;
}