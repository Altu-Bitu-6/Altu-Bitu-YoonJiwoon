#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> meet;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0;
	int end;
	vector<meet>v;
	cin >> n;
	v.assign(n, { 0,0 });

	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;  // first에 끝나는 시간 넣어야 정렬!
	}

	sort(v.begin(), v.end()); // 정렬해야 가장 빨리 끝나는 회의 찾을 수 있음!
	end = 0;

	for (int i = 0; i < n; i++) {
		if (end > v[i].second) {
			continue;
		}
		cnt++;
		end = v[i].first;
	}

	cout << cnt;


	return 0;
}