#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}

	return a;
}

vector<int> solution(int n, vector<int>& v) {
	vector<int>result;
	sort(v.begin(), v.end()); //오름차순 정렬

	// 1. 검문소 사이 간격의 최대공약수(최대 M) 계산
	int gcd = v[1] - v[0]; // 첫번째 차로 초기화
	for (int i = 2; i < n; i++) {
		gcd = getGCD(gcd, v[i] - v[i - 1]);
	}

	// 2. 가능한 모든 M 찾기: 최대공약수의 약수 찾기
	for (int i = 2; i * 2 <= gcd; i++) {   
		// i<=gcd로 하면 시간초과! gcd 본인 다음으로 큰 약수는 gcd/2 -> 2가 gcd의 약수라면.
		if (gcd % i == 0) {
			result.push_back(i);
		}
	}
	result.push_back(gcd);  //i가 gcd까지 못가서 따로 추가.

	return result;
}

/*
*A, B, C를 M으로 나눴을 때의 나머지가 모두 같을 때, 이 나머지 값을 K라 하면
* A = M * a + K, B = M * b + K, C = M * c + K 이므로
* B - A = (M * b + K) - (M * a + K) = M(b - a)
* C - B = (M * c + K) - (M * b + K) = M(c - b)
* 즉, 우리가 구해야 하는 M은 각 검문소 사이 간격 간의 모든 공약수!
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int>result = solution(n, v);

	for (int i : result) {
		cout << i << " ";
	}

	return 0;
}