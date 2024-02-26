#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	queue<int>q;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int j = 0; j < n-1; j++) {
		cout << v[j] << ", ";
	}
	cout << v[n - 1] << ">";

	return 0;
}