#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool arr[10] = {false};
    for (int num: numbers){
        arr[num] = true;
    }
    for (int i=0; i<10; i++) {
        if (not arr[i]) {
            answer += i;
        }
    }
    return answer;
}