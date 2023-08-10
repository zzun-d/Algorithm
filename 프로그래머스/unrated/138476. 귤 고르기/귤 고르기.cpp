#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int mx = *max_element(tangerine.begin(), tangerine.end());
    vector<int> v(mx+1, 0);
    for (auto t:tangerine) {
        v[t]++;
    }
    sort(v.rbegin(), v.rend());
    int idx = 0;
    while (k > 0) {
        k -= v[idx];
        idx++;
    }
    
    return idx;
}