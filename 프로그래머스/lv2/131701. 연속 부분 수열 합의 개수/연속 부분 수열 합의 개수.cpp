#include <string>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int solution(vector<int> elements) {
    int answer = 1;
    int l = elements.size();
    set<int> st;
    for (int i=1; i<l; i++) {
        for (int j=0; j<l; j++) {
            if (j+i > l) {
                int sum1 = accumulate(elements.begin()+j, elements.end(), 0);
                int sum2 = accumulate(elements.begin(), elements.begin()+ (j+i)%l, 0);
                st.insert(sum1 + sum2);
            } else {
                int sum = accumulate(elements.begin()+j, elements.begin()+i+j, 0);
                st.insert(sum);
            }
        }
    }
    answer += st.size();
        
    return answer;
}