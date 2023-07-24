#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i=0; i<commands.size(); i++) {
        int s = commands[i][0], e = commands[i][1], k = commands[i][2];
        vector<int> lst;
        for (int j=s; j<=e; j++) {
            lst.push_back(array[j-1]);    
        }
        sort(lst.begin(), lst.end());
        answer.push_back(lst[k-1]);
        
    }
    return answer;
}