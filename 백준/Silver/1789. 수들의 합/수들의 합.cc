#include <iostream>
using namespace std;

int main() {
    long long s, i=1;
    cin >> s;
    
    while ((i+1)*i/2 <= s) {
        i++;
    }
    cout << i-1;
    return 0;
}