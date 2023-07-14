#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;
    if (s%10 != 0){
        cout << -1;
    } else {
        int a, b, c;
        a = s/300;
        s = s%300;
        b = s/60;
        s = s%60;
        c = s/10;
        cout << a << " " << b << " " << c;
    }
    return 0;
}