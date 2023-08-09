#include <iostream>

using namespace std;

int T, N;

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N;
        long long ans=0, pos=0, neg=0, n;
        for (int j=0; j<N; j++) {
            cin >> n;
            if (n > 0) {
                if (pos > 0) ans++;
                pos = n;
                if (neg < 0 && neg+n > 0) {
                    pos = neg+n;
                    neg = 0;
                } else if (neg < 0) {
                    ans--;
                    neg = 0;
                }
            } else if (n < 0) {
                if (neg < 0) neg+=n;
                else {
                    neg = n;
                    if (pos > 0 && pos+n >0) {
                        pos += n;
                        neg = 0;
                    } else if (pos > 0) {
                        ans++;
                        pos = 0;
                    }
                }
            }
        }
        if (pos > 0) ans++;
        if (neg < 0) ans--;
        ans > 0 ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}