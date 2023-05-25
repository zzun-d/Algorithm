#include <iostream>
#include <string>

using namespace std;
string S, P;

int main() {
	cin >> S >> P;
	int S_l = S.length();
	int P_l = P.length();
	
	int idx_S, idx_P = 0;
	int cnt = 0;

	while (idx_P < P_l) {
		idx_S = 0;
		int word_len = 0;
		int mx = 0;
 		while (idx_S < S_l) {
			if (S[idx_S+word_len] == P[idx_P+word_len]) {
				word_len += 1;
			}
			else {
				if (mx < word_len) {
					mx = word_len;
				}
				if (mx > S_l - idx_S) {
					break;
				}
				word_len = 0;
				idx_S += 1;

			}
		}
		idx_P += mx;
		cnt += 1;
	}

	cout << cnt;
	return 0;
}