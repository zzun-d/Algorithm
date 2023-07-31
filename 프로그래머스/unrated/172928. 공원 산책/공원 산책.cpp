#include <string>
#include <vector>
#include <map>

using namespace std;

pair<int, int> find_start(vector<string> park) {
    for (int i=0; i<park.size(); i++) {
        for (int j=0; j<park[0].size(); j++) {
            if (park[i][j] == 'S') {
                return make_pair(i, j);
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h=park.size(), w=park[0].size();
    pair<int, int> s = find_start(park);
    map<char, pair<int, int>> m;
    m['E'] = make_pair(0, 1);
    m['W'] = make_pair(0, -1);
    m['S'] = make_pair(1, 0);
    m['N'] = make_pair(-1, 0);
    for (string route:routes) {
        int x = s.first, y = s.second;
        char d = route[0];
        int l = stoi(route.substr(2, route.size()));
        bool isCan = true;
        for (int i=1; i<=l; i++) {
            int nx = x + m[d].first;
            int ny = y + m[d].second;
            if (h<=nx || nx<0 || w<=ny || ny<0 || park[nx][ny] == 'X') {
                isCan = false;
                break;
            } else {
                x = nx;
                y = ny;
            }
        }
        if (isCan) {
            s.first = x;
            s.second = y;
        }
        
    }
    answer.push_back(s.first);
    answer.push_back(s.second);
   
    
    return answer;
}