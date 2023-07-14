#include <iostream>

using namespace std;

int T;

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        int c;
        cin >> c;
        cout << c/25 << " ";
        c = c % 25;
        cout << c/10 << " ";
        c = c % 10;
        cout << c/5 << " ";
        c = c % 5;
        cout << c << endl;
        
        
    }
    return 0;
}