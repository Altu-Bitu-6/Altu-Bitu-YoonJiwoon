#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, a, v;
	cin >> n;
	priority_queue<int> present;

	while (n--) {
		cin >> a;

		if (a == 0) {
			if (present.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << present.top() << "\n";
				present.pop();
			}
		}
		else {
			while (a--) {
				cin >> v;
				present.push(v);
			}
		}
	}

	return 0;
}