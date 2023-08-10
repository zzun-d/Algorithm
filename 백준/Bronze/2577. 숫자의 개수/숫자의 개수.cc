#include <iostream>

using namespace std;

int A, B, C;
int lst[10];

int main() {
    cin >> A >> B >> C;
    int ans = A*B*C;
    while (ans > 0) {
        lst[ans%10]++;
        ans /= 10;
    }
    for (int i=0; i<10; i++) {
        cout << lst[i] << endl;
    }

    return 0;
}