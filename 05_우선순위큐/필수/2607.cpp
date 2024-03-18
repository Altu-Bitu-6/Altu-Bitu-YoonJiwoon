#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHA_NUM = 26;

void countAlpha(string word, vector<int>& v) {
	for (char alpha : word) {
		v[alpha - 'A']++;
	}
}

int solution(vector<int>& v, string word, int cnt, string flag) {
	vector<int> new_word(ALPHA_NUM, 0);
	countAlpha(word, new_word);
	int diff = 0;

	for (int i = 0; i < ALPHA_NUM; i++) {
		// 이렇게 하니 ABBBB와 A가 비슷한 단어로 판별
		//if (v[i] != new_word[i]) {
		//	diff++;
		//}

		// 배열 값의 차이만큼 diff 늘려야함
		// 둘 중 뭐가 큰지 모르니 절댓값 사용!
		diff += abs(v[i] - new_word[i]);
	}

	return diff;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int cnt = 0;
	cin >> n;

	string flag;
	cin >> flag;

	//기준단어 알파벳 개수 세기
	vector<int> v(ALPHA_NUM, 0);
	countAlpha(flag, v);

	for (int i = 1; i < n; i++) {
		string word;
		cin >> word;

		int diff = solution(v, word, cnt, flag);
		if (diff == 0 || diff == 1 || (diff == 2 && flag.size() == word.size())) {
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}