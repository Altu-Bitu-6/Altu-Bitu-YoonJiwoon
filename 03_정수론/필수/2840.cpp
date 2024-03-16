#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic;
const int ALPHA = 26;

string printWheel(int n, int pos, vector<char>& wheel) {
	string ans = "";

	for (int i = pos + n; i > pos; i--) {
		ans += wheel[i % n];  //pos부터 - 방향으로 출력하고 싶을 때!
		//이걸 못해서 같은 for문 두 번 사용했었음. 기억하기!
	}

	return ans;
}

string makeWheel(int n, int k, vector<ic>& record) {
	vector<char> wheel(n, '?');
	vector<bool> is_available(ALPHA, false); //알파벳 중복 체크

	int pos = 0;

	for (int i = 0; i < k; i++) {
		int s = record[i].first;
		char ch = record[i].second;

		pos = (pos + s) % n;

		//해당 칸이 이미 같은 문자로 채워져있음
		if (wheel[pos] == ch) {
			continue;
		}
		//해당 칸이 다른 문자로 채워져있음
		//해당 글자가 이미 사용된 알파벳인 경우
		if (wheel[pos] != '?' || is_available[ch - 'A']) { //벡터 배열 효율적 이용
			return "!";
		}

		wheel[pos] = ch;
		is_available[ch - 'A'] = true;
	}
	return printWheel(n, pos, wheel);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<ic> record(k);
	int pos = 0;

	for (int i = 0; i < k; i++) {
		cin >> record[i].first >> record[i].second;
	}

	cout << makeWheel(n, k, record);

	return 0;
}


// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// 	int n, k, s;
// 	char c;
// 	cin >> n >> k;
// 	vector<char>v(n,'?');
// 	int pos = 0;

// 	while (k--) {
// 		cin >> s >> c;
// 		pos = (pos+s) % n;
		
// 		if (v[pos] != '?' && v[pos] != c) {
// 			v[pos] = '!';
// 			continue;
// 		}
// 		v[pos] = c;

// 	}

// 	for (int i = 0; i < n; i++) {
// 		if (v[i] == '!') {
// 			cout << "!"; //밑의 모든 for문이 안돌게 하고 싶으면?
// 			return 0; //이걸 써줘야함!
// 		}
// 		for (int j = i + 1; j < n; j++) {
// 			if (v[j] != '?' && v[i] == v[j]) {  //v[i]=v[j]='?'로 같은 건 ! 출력에서 제외!
// 				//같은 문자가 여러칸에 들어가도 ! 출력해야함.
// 				cout << "!";
// 				return 0;
// 			}
// 		}
// 	}

// 	for (int i = pos % n; i >= 0; i--) {
// 		if (v[i] == '?') {
// 			cout << '?';
// 			continue;
// 		}
// 		cout << v[i];
// 	}
// 	for (int i = n - 1; i > pos % n; i--) {
// 		if (v[i] == '?') {
// 			cout << '?';
// 			continue;
// 		}
// 		cout << v[i];
// 	}
// }