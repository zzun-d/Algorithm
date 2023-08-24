#include <string>
#include <vector>

using namespace std;

vector<int> v1, v2;
int solution(vector<int> order) {
    for (int i=order.size(); i>0; i--) {
        v1.push_back(i);
    }
    int idx=0;
    while (!v1.empty()) {
        if (v1.back() == order[idx]) {
            v1.pop_back();
            idx++;
        } else if (!v2.empty() && v2.back() == order[idx]) {
            v2.pop_back();
            idx++;
        } else {
            v2.push_back(v1.back());
            v1.pop_back();
        }
    }
    for (int i=idx; i<order.size(); i++) {
        if (v2.empty() || order[idx] != v2.back()) break;
        v2.pop_back();
        idx++;
    }
    
    return idx;
}