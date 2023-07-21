#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int cnt = 0;
    int sm = 0;
    for (int i=0; i<arr.size(); i++) {
        sm += arr[i];
        cnt++;
    }
    answer = (double)sm / cnt;
    return answer;
}