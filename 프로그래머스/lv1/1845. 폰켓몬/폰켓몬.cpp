#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int l = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if (nums.size() > l/2) {
        answer = l/2;
    } else {
        answer = nums.size();
    }
    return answer;
}