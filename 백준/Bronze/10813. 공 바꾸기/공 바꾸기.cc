#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int lst[n+1] = {0};
    for (int i=1; i<n+1; i++){
        lst[i] = i;
    }
    for (int i=0; i< m; i++) {
        int s1, s2;
        int tmp;
        cin >> s1 >> s2;
        tmp = lst[s1];
        lst[s1] = lst[s2];
        lst[s2] = tmp;
    }
    for (int i=1; i<n+1; i++) {
        cout << lst[i] << " ";
    }
    return 0;
}