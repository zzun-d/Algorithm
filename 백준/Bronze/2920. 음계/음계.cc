#include <iostream>

using namespace std;

int asc[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int des[8] = {8, 7, 6, 5, 4, 3, 2, 1};
int pla[8];

bool isSame(int a[8], int b[8]) {
    for (int i=0; i<8; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i=0; i<8; i++) {
        cin >> pla[i];
    }
    if (isSame(asc, pla)) cout << "ascending";
    else if (isSame(pla, des)) cout << "descending";
    else cout << "mixed";
    return 0;
}