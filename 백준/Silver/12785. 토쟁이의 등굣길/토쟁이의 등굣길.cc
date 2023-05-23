#include <iostream>
using namespace std;

int w, h;
int arr[201][201] ;

int main() {
	cin >> w >> h;
	int x, y;
	cin >> x >> y;

	for (int i = 0; i < 201; i++) {
		arr[0][i] = 1;
		arr[i][0] = 1;
	}

	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 1000007;
			//cout << arr[i][j] << " ";
		}
		//cout << endl;
	}
	
	long long result = arr[x - 1][y - 1];

	result = (result * arr[w - x][h - y]) % 1000007;

	cout << result;
	return 0;
}