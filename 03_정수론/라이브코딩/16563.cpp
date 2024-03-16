#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 5000000;

void getPrime(vector<int>& prime) {
	for (int i = 2; i * i <= MAX_SIZE; i++) {
		if (prime[i]) {
			continue; //소수가 아니면 탐색 안함.
		}
		for (int j = i * i; j <= MAX_SIZE; j+=i) {
			if (prime[j]) {
				continue; //이미 소인수 존재하면, 넘김
			}
			prime[j] = i;
		}
	}
}

vector<int> getPrimeFactor(int k, vector<int>& prime) {
	vector<int> ans;
	while (prime[k] !=0 ) {
		ans.push_back(prime[k]);
		k /= prime[k];
	}
	ans.push_back(k);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> prime(MAX_SIZE + 1, 0);  

	getPrime(prime); //배열에 가장 작은 소인수 넣음.

	while (n--) {
		int k;
		cin >> k;
		vector<int> ans = getPrimeFactor(k,prime); //소인수분해

		for (int i : ans) { //ans길이만큼 for문 돈다.
			cout << i << " ";
		}
		cout << "\n";
	}
}