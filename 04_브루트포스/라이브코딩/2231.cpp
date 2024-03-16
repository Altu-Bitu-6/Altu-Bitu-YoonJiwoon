#include <iostream>

using namespace std;

int bruteforce(int n) {
	for (int i = 1; i < n; i++) {
		int m = i;
		int sum = m;

		while (m != 0) {
			sum += m % 10;
			m /= 10;
		}

		if (sum == n) {
			return i;  //return m 했더니 0 출력.. 당연함.. i 출력해야지!
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m;
	cin >> n;

	m= bruteforce(n);
	cout << m;

	return 0;
}