#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int lst[n+1];
    for (int i=1; i<n+1; i++) {
        lst[i] = i;
    }
    for (int i=0; i<m; i++) {
        int a, b;
        int tmp;
        cin >> a >> b;
        for (int j=0; j<(b-a+1)/2; j++){
            tmp = lst[a+j];
            lst[a+j] = lst[b-j];
            lst[b-j] = tmp;
        }
    }
    for (int i=1; i<n+1; i++) {
        cout << lst[i] << " ";
    }
    return 0;
}