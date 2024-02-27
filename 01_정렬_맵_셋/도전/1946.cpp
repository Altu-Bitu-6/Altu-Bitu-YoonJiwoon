#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> ci;

int func(vector<ci> v) {
	int result = 0;
	int min = v.size();
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second <= min) {
			min = v[i].second;
			result++;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, a, b, result;
	cin >> t;
	
	while (t--) {
		cin >> n;
		vector<ci>v; //n으로 크기 지정해두면 그 뒤로 push_back해서 오류!
		//n으로 크기 지정할거면 밑에서 cin >>v[i].first>>v[i].second;이렇게 해야함
		for (int i = 0; i < n;i++) {
			cin >> a >> b;
			v.push_back({a,b});
		}
		sort(v.begin(), v.end());
		result = func(v);
		cout << result << "\n";
	}
	return 0;
}