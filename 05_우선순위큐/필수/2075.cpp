#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n) {
	// 우선순위 큐에 모든 수를 저장하니 메모리 초과 실패! 
	// 우선순위큐에 5개만 저장하기
	priority_queue<int, vector<int>, greater<>> pq;
	int num;

	for (int i = 0; i < n * n; i++) {
		cin >> num;
		if (pq.size() < n) {
			pq.push(num);
		}
		else {
			if (pq.top() < num) {
				pq.pop();
				pq.push(num);
			}
		}
	}

	return pq.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	cout << solution(n);

	return 0;
}