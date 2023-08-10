#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int L;
string S;
int main() {
	cin >> L >> S;
	long long ans = 0;
	for (int i = 0; i < L; i++) {
		int c = S[i] - 'a' + 1;
		ans += pow(31, i) * c;
		ans %= 1234567891;
	}
	cout << ans;
	
	return 0;
}
