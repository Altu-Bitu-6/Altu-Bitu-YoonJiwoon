#include <iostream>
#include <vector>

using namespace std;
 
const int SAW_NUM = 8;

void rotateWheel(pair<int, int>& rotate, vector<vector<int>>& v) {
	int num = rotate.first;
	int dir = rotate.second;
	//if (num != 4) {
	//	if (v[num][3] != v[num+1][7]) {
	//		
	//	}
	//	
	//}

	return;
}

int printAnswer(vector<vector<int>>& v, int t) {
	int cnt = 0;

	for (int i = 1; i <= t; i++) {
		if (v[i][1] == 1) {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, k;
	vector<vector<int>> v;
	pair<int, int>rotate;
	cin >> t;

	v.assign(t + 1, vector<int>(SAW_NUM + 1));


	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= SAW_NUM; j++) {
			cin >> v[i][j];
		}
	}

	cin >> k;
	while (k--) {
		cin >> rotate.first >> rotate.second;
		rotateWheel(rotate, v);
	}
	
	cout << printAnswer(v, t);

	return 0;
}