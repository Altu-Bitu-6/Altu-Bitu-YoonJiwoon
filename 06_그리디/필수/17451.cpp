#include <iostream>
#include <vector>

using namespace std;

long long findSpeed(vector<long long>& d) {
	long long min = 0;
	for (long long i : d) {
		if (i > min) {
			min = i;
		}
		else {
			min = ((min-1) / i + 1) * i;
			// min-1 안해주면 틀림! 
			// 그냥 min 하면 같은 속도 연속으로 주어졌을 때 오류
		}
	}

	return min;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<long long>d;
	cin >> n;
	
	d.assign(n, 0);

	for (int i = n-1; i >= 0; i--) {
		cin >> d[i];
	}

	cout << findSpeed(d);

	return 0;
}