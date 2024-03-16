#include <iostream>
#include<algorithm>

using namespace std;

int gcdIter(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d, ans1, ans2;
	cin >> a >> b >> c >> d;
	ans2 = b * d;
	ans1 = b * c + a * d;

	int gcd= gcdIter(ans1, ans2);
	ans2 /= gcd;
	ans1 /= gcd;
	
	cout << ans1 <<" " << ans2;
}