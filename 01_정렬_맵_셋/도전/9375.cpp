#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, t;
	string name, cate;

	cin >> t;
	while (t--) {
		int num = 1; //곱셈 계산 해야하므로 1로 초기화
		cin >> n;
		map<string, int>m;
		for (int i = 0; i < n; i++) {
			cin >> name >> cate;
			m[cate]++; // 특정 종류의 옷 개수 +1
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			num *= (iter->second +1); //value값에 +1
		}
		cout<< num-1<<"\n";
	}
	return 0;
}