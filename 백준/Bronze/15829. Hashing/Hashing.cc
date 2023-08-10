#include <iostream>
#include <string>

using namespace std;

int L;
string S;
int main() {
	cin >> L >> S;
	long long ans = 0;
	for (int i = 0; i < L; i++) {
		long long c = S[i] - 'a' + 1;
		long long std = 1;
		for (int j=0; j<i; j++) {
			std *= 31;
		}
		ans = (ans + std * c)%1234567891;
	}
	cout << ans;
	
	return 0;
}
