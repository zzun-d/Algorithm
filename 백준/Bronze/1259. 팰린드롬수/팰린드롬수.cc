#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	int i = 0, e = s.length()-1;
	while (i < e) {
		if (s[i] != s[e]) {
			return false;
		}
		i++;
		e--;
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	while (s != "0") {
		isPalindrome(s) ? cout << "yes" : cout << "no";
		cout << endl;
		cin >> s;
	}
	
	return 0;
}
