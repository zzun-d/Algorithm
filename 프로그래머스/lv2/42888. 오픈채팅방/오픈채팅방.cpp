#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

map<string, string> m;
vector<string> v;
vector<string> vid;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i=0; i<record.size(); i++) {
        stringstream ss(record[i]);
        string tp, id, nick;
        ss >> tp >> id >> nick;
        if (tp == "Enter") {
            v.push_back("들어왔습니다.");
            m[id] = nick;
        } else if (tp == "Leave") {
            v.push_back("나갔습니다.");
        } else {
            m[id] = nick;
            continue;
        }
        vid.push_back(id);
    }
    for (int i=0; i < v.size(); i++) {
        string print;
        print = m[vid[i]] + "님이 " + v[i];
        answer.push_back(print);
    }
    return answer;
}