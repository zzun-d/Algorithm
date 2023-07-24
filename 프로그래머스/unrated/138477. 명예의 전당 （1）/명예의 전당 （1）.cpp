#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> record;
    for (int sc:score) {
        record.push_back(sc);
        sort(record.begin(), record.end(), comp);
        if(record.size() > k) {
            record.pop_back();
        }
        answer.push_back(record[record.size()-1]);
    }
    return answer;
}