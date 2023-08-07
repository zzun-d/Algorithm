#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    
    sort(arr.begin(), arr.end());    
    for (int i=1; i<arr.size(); i++) {
        int a=arr[0], b=arr[i];
        while (a != b) {
            if (a < b) {
                a += arr[0];
            } else {
                b += arr[i];
            }
        }
        arr[0] = a;
    }
    int answer = arr[0];
    
    return answer;
}