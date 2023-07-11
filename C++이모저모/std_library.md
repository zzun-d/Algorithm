```cpp
#include <tuple>
#include <algorithm>
#include <vector>

// vector 내부에 값을 튜플로 받을 수 있게 됨
vector<tuple<int, int, int> > cells;
int main(){

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            // vector에 tuple을 만들어서 푸시백!
            cells.push_back(make_tuple(arr[i][j], i, j));
    // sort: vector의 시작지점부터 끝까지 정렬해줌
    sort(cells.begin(), cells.end());

    for(int i=0; i< (int) cells.size(); i++) {
        int x, y;
        // tie: pair, tuple로 묶여서 반환되는 정보들을 한번에 받아올 수 있게 해줌
        tie(ignore, x, y) = cells[i];
    }
    return 0;
}
```
