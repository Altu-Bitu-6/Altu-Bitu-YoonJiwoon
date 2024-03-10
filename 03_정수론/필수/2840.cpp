#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, s;
	char c;
	cin >> n >> k;
	vector<char>v(n,'?');
	int pos = 0;

	while (k--) {
		cin >> s >> c;
		pos = (pos+s) % n;
		
		if (v[pos] != '?' && v[pos] != c) {
			v[pos] = '!';
			continue;
		}
		v[pos] = c;

	}

	for (int i = 0; i < n; i++) {
		if (v[i] == '!') {
			cout << "!"; //밑의 모든 for문이 안돌게 하고 싶으면?
			return 0; //이걸 써줘야함!
		}
		for (int j = i + 1; j < n; j++) {
			if (v[j] != '?' && v[i] == v[j]) {  //v[i]=v[j]='?'로 같은 건 ! 출력에서 제외!
				//같은 문자가 여러칸에 들어가도 ! 출력해야함.
				cout << "!";
				return 0;
			}
		}
	}

	for (int i = pos % n; i >= 0; i--) {
		if (v[i] == '?') {
			cout << '?';
			continue;
		}
		cout << v[i];
	}
	for (int i = n - 1; i > pos % n; i--) {
		if (v[i] == '?') {
			cout << '?';
			continue;
		}
		cout << v[i];
	}
}