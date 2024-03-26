#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, cnt = 0;
	vector<int>value;
	cin >> n >> k;

	value.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}

	while (n--) {
		cnt += k / value[n];  // n-1 -> n-2 -> ... -> 0
		k %= value[n];  //나머지 계산 가능
	}

	cout << cnt;

	//int n = 3;
	//while (n--) {
	//	cout << n << "\n";
	//}
	//2 -> 1 -> 0 출력

	//int n = 3;
	//while (--n) {
	//	cout << n << "\n";
	//}
	//2 -> 1 출력

	return 0;
}