#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CNT = 9;

void select(vector<int>& height) {
	int sum = 0;
	for (int i = 0; i < CNT; i++) {
		sum += height[i];
	}
	for (int i = 0; i < CNT; i++) {
		for (int j = i + 1; j < CNT; j++) {
			if (sum - height[i] - height[j] == 100) {
				//height[i], height[j]를 vector에서 지워야함.
				// i< j이므로 height[i]를 먼저 삭제할 경우 height[j] 값이 height[j-1]로 옮겨짐
				height.erase(height.begin() + j);
				height.erase(height.begin() + i);
				return;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int>height(CNT);
	vector<int>ans;
	
	for (int i = 0; i < CNT; i++) {
		cin >> height[i];
	}

	select(height);

	//height를 오름차순으로 정렬
	sort(height.begin(), height.end());

	for (int h : height) {
		cout << h << "\n";
	}

	return 0;
}