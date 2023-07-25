#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> answer(nums.begin(), nums.end());
    // sort(nums.begin(), nums.end());
    // nums.erase(unique(nums.begin(), nums.end()), nums.end());
    // if (nums.size() > l/2) {
    //     answer = l/2;
    // } else {
    //     answer = nums.size();
    // }
    return min(answer.size(), nums.size()/2);
}