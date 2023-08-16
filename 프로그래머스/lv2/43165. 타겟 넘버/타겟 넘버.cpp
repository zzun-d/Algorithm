#include <string>
#include <vector>

using namespace std;

int total;

void DFS(int n, int sum, int &target, vector<int> &v){
    if (n >= v.size()) {
        if (sum == target) {
            total++;
        }
    } else {
        DFS(n+1, sum+v[n], target, v);
        DFS(n+1, sum-v[n], target, v);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, target, numbers);
    return total;
}