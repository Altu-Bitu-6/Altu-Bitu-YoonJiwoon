#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000000; //테스트케이스의 개수와 n의 범위를 헷갈렸다..
//테스트 케이스마다 소수 판별하니 시간 초과. -> MAX_SIZE 이용!

//에라토스테네스의 체
void isPrime(vector<bool>& v) {
	v[0] = v[1] = false;
	for (int i = 2; i * i <= MAX_SIZE; i++) { //<=MAX_SIZE에서 등호 빼먹지 말기
		if (v[i] == false) {
			continue;
		}
		for (int j = i * i; j <= MAX_SIZE; j += i) {
			v[j] = false;
		}
	}
}

void prove(int n, vector<bool>& v, pair<int,int>& ans) {
	for (int i = 3; i <= n; i += 2) { //a,b가 홀수이니 i=3부터 홀수만 판별(시간 감소)
		if (v[i] == false) {  //i가 소수일 때만 n-i가 소수인지 확인.
			continue;
		}
		if (v[n - i] == true) { //i와 n-i가 소수이면 a=i, b=n-i
				ans.first=i;
				break;
		}
	}
	
	ans.second=n-ans.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); //시간 감소

	int n;
	vector<bool>v(MAX_SIZE + 1, true); //0~MAX_SIZE까지이므로 MAX_SIZE+1
	isPrime(v);  
	pair<int,int> ans;

	while (true) {
		cin >> n;
		if (n == 0) {
			break;  // n=0일 때 종료.
		}
		prove(n, v, ans);  // a,b구하기.

		if (v[ans.second] ==false){
			cout << "Goldbach's conjecture is wrong."; //b가 소수가 아니면 출력
			return 0;
		}

		cout << n << " = " << ans.first << " + " << ans.second << "\n";  //결과 출력

	}
	return 0;
}
