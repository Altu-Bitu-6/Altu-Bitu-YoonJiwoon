#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 60;  //2^10 ~= 10^3

pair<int, int> getPair(ll m) {
	int x, y;

	//m이 2의 제곱수인 경우 (m을 2진수로 나타냈을 때, 1이 한개)
	for (ll i = 1; i < MAX; i++) {
		if (m == ((ll)1 << i)) {  //1은 상수이기 때문에 longlong으로 형변환!
			return { i - 1,i - 1 };
		}
	}

	//m이 2의 제곱수가 아닌 경우 (m을 2진수로 나타냈을 때, 1이 두개)
	for (x = 0; x < MAX; x++) { // x 먼저 찾고
		if (m & ((ll)1 << x)) { // AND로 둘 다 1인 bit 찾기
			m -= (ll)1 << x; //x 감지한 곳에서 y도 멈추면 안되니까
			break;
		}
	}

	for (y = x + 1; y < MAX; y++) { // x<y이므로
		if (m & ((ll)1 << y)) {
			break;
		}
	}

	return { x,y };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	ll m;
	cin >> n;

	while (n--) {
		cin >> m;
		pair <int, int> ans = getPair(m);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}