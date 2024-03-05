#include <iostream>
#include <vector>

using namespace std;

int getPrime(int n, int k) {
	vector<bool> is_prime(n + 1, true); //0~n까지 배열이므로 크기는 n+1
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			if (!is_prime[j]) {
				continue;
			}
			is_prime[j] = false;
			if (++cnt == k) {
				return j;
			}
		}
	}
	return -1;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << getPrime(n, k);
}