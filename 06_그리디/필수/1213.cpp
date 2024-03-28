#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHA_NUM = 26;

string makePalindrome(string name, vector<int>& cnt) {
	string ans = "";
	char center_alpha;
	int center_cnt = 0;

	for (char c : name) {
		cnt[c - 'A']++;
	}

	for (int i = 0; i < ALPHA_NUM; i++) {
		// 써줘야 없는 글자 출력 안됨! 
		// 0도 2로 나누면 나머지 0이라 이 조건문 없으면 출력되기 때문!
		if (cnt[i] == 0) {
			continue; 
		}

		if (cnt[i] % 2 != 0) {
			center_alpha = i+'A';
			center_cnt++;
			if (center_cnt == 2) {
				return  "I'm Sorry Hansoo";
			}
		}

		int n = cnt[i]/2;
		while (n--) {
			ans += i + 'A';
		}

	}

	if (center_cnt == 1) {
		ans += center_alpha;
	}
	for (int i = name.size()/2 - 1; i >= 0; i--) {
		//이렇게 해야 name의 길이가 짝수든 홀수든 알맞게 거꾸로 출력됨
		ans += ans[i];
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string name;
	vector<int>cnt(ALPHA_NUM, 0);
	cin >> name;

	cout << makePalindrome(name, cnt);

	return 0;
}