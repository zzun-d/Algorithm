#include <iostream>
#include <string>

using namespace std;

int queue[10000];
int header = -1;
int listStart = -1;

int main() {
	int N, n;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			cin >> n;
			header++;
			queue[header] = n;
			
		}
		else if (s == "back") {
			header > listStart ? cout << queue[header] : cout << -1;
			cout << endl;
		}
		else if (s == "front") {
			header > listStart ? cout << queue[listStart+1] : cout << -1;
			cout << endl;
		}
		else if (s == "pop") {
			if (header > listStart) {
				cout << queue[listStart + 1];
				listStart++;
			}
			else {
				cout << -1;
			}
			cout << endl;
			
		}
		else if (s == "size") {
			cout << header - listStart << endl;
		}
		else if (s == "empty") {
			header > listStart ? cout << 0 : cout << 1;
			cout << endl;
		}

	}
	return 0;
}
