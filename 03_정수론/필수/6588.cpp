#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100000;
//테스트 케이스마다 소수 판별하니 시간 초과. -> MAX_SIZE 이용!

void isPrime(vector<bool>& v) {
	v[0] = v[1] = false;
	for (int i = 2; i * i <= MAX_SIZE; i++) { //<=MAX_SIZE에서 등호 빼먹지 말기
		if (v[i] == false) {
			continue;
		}
		for (int j = i * i; j <= MAX_SIZE; j += i) {
			v[j] = false;
		}
	}
}

void prove(int n, vector<bool>& v, pair<int,int>& ans) {
	//for (int i = n; i >= 0; i--) {
	//	if (v[i] == true) {
	//		if (n - i > 1) {
	//			ans.second = i;
	//			break;
	//		}
	//	}
	//}

	for (int i = 3; i <= n/2; i+=2) {
		if (v[i] && v[n-i]) {
			ans.first = i;
			break;
		}
	}
	
	//ans.first = n-ans.second;
	ans.second = n - ans.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<bool>v(MAX_SIZE+1, true); //0~MAX_SIZE까지이므로 MAX_SIZE+1
	isPrime(v);
	pair<int, int> ans;

	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		prove(n,v,ans);

		//for (int i = n; i >= 0; i--) {
		//	if (v[i] == true) {
		//		if (n - i > 1) {
		//			ans.second = i;
		//			break;
		//		}
		//	}
		//}
		//ans.first = n-ans.second;

		if (v[ans.second] == false) {
			cout << "Goldbach's conjecture is wrong.";
			return 0;
		}
		//cout << n << " = " << get<0>(ans) << " + " << get<1>(ans) << "\n";
		cout << n << " = " << ans.first << " + " << ans.second << "\n";
	}
	return 0;
}


