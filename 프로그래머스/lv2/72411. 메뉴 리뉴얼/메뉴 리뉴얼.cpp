#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
void make_combi(string menu, string combi, int cnt) {
    if (combi.size() == cnt) {
        m[combi]++;
    } else if (menu.size() > 0) {
        char m = menu[0];
        menu = menu.substr(1);
        make_combi(menu, combi, cnt);
        combi += m;
        make_combi(menu, combi, cnt);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int c:course) {
        m.clear();
        int mx = 2;
        vector<string> v;
        for (string order:orders) {
            sort(order.begin(), order.end());
            make_combi(order, "", c);
        }
        for (auto iter=m.begin(); iter != m.end(); iter++) {
            if (iter->second > mx) {
                v.clear();
                mx = iter->second;
                v.push_back(iter->first);
            } else if (iter->second == mx) {
                v.push_back(iter->first);
            }
        }
        for (int i=0; i<v.size(); i++) {
            answer.push_back(v[i]);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}