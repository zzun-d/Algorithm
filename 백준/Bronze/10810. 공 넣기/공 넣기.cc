#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int lst[n+1] = {0};
    for (int i=0; i<m; i++){
        int s, e, num;
        cin >> s >> e >> num;
        for (int j=s; j<e+1;j++){
            lst[j] = num;
        }
    }
    for (int i=1; i<n+1; i++) {
        cout << lst[i] << " ";
    }
    return 0;
}