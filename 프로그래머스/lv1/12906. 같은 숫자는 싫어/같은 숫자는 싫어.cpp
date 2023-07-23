#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int tmp = arr[0];
    answer.push_back(arr[0]);
    for (int i=1; i<arr.size(); i++) {
        if (tmp == arr[i]) {
            continue;
        }
        tmp = arr[i];
        answer.push_back(arr[i]);
    }
    return answer;
}