#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int remove_idx = 0, mn = arr[0];
    for (int i=1; i<arr.size(); i++) {
        if (mn > arr[i]){
            mn = arr[i];
            remove_idx = i;
        }
    }
    arr.erase(arr.begin()+remove_idx);
    if (arr.size() == 0) {
        arr.push_back(-1);
    }
    answer = arr;
    return answer;
}