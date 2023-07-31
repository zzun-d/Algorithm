#include <string>
#include <vector>
#include <cmath>

using namespace std;

int coord[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int r[2] = {3, 2};
    int l[2] = {3, 0};
    for (int num:numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            l[0] = coord[num][0];
            l[1] = coord[num][1];
        } else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            r[0] = coord[num][0];
            r[1] = coord[num][1];
        } else {
            if (abs(coord[num][0] - l[0]) + abs(coord[num][1] - l[1]) > abs(coord[num][0] - r[0]) + abs(coord[num][1] - r[1])) {
                answer += 'R';
                r[0] = coord[num][0];
                r[1] = coord[num][1];
            } else if (abs(coord[num][0] - l[0]) + abs(coord[num][1] - l[1]) < abs(coord[num][0] - r[0]) + abs(coord[num][1] - r[1])) {
                answer += 'L';
                l[0] = coord[num][0];
                l[1] = coord[num][1];
            } else {
                if (hand == "right") {
                    answer += 'R';
                    r[0] = coord[num][0];
                    r[1] = coord[num][1];
                } else {
                    answer += 'L';
                    l[0] = coord[num][0];
                    l[1] = coord[num][1];
                }
            }
        }
    }
    return answer;
}