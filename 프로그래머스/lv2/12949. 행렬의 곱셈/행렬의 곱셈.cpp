#include <string>
#include <vector>

using namespace std;

vector<vector<int>> oper(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> ans;
    
    
    for (int i=0; i<a.size(); i++) {
        vector<int> row;
        for (int j=0; j<b[0].size(); j++) {
            int sm = 0;
            for (int k=0; k<b.size(); k++) {
                sm += a[i][k] * b[k][j];
            }
            row.push_back(sm);
        }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer=oper(arr1, arr2);
    return answer;
}