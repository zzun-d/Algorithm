#include <string>
#include <set>

using namespace std;

pair<int, int> move(char c) {
    if (c == 'U') return make_pair(-1, 0);
    if (c == 'D') return make_pair(1, 0);
    if (c == 'L') return make_pair(0, -1);
    if (c == 'R') return make_pair(0, 1);
}

set<pair<pair<int, int>, pair<int, int>>> s;

int solution(string dirs) {
    pair<int, int> start_idx = {0, 0};
    pair<int, int> end_idx = {0, 0};
    for (char c:dirs) {
        int dx= move(c).first, dy = move(c).second;
        int nx = end_idx.first + dx;
        int ny = end_idx.second + dy;
        if (nx >= -5 && ny >= -5 && 5 >= nx && 5 >= ny) {
            start_idx = end_idx;
            end_idx = make_pair(nx, ny);
            s.insert(make_pair(start_idx, end_idx));
            s.insert(make_pair(end_idx, start_idx));
        }
    }
    int answer = s.size()/2;
    return answer;
}