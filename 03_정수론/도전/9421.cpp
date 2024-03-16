#include <iostream>
#include <vector>
#include <set>

using namespace std;

//에라토스테네스의 체
vector<bool> getPrime(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++) {
		if (is_prime[i] == false) {
			continue;
		}
		for (int j = i * i; j <= n; j += i) {
			is_prime[j] = false;
		}
	}
	
	return is_prime;
}

//각 자리수의 제곱의 합
int getSum(int num) {
	int total=0;
	int tmp;

	while (num != 0) {
		tmp = num % 10;
		num /= 10;
		total += tmp * tmp;
	}

	return total;
}

//소수상근수 여부 반환 함수
bool isValid(int num) {
	set<int> visited;
	visited.insert(num);
	while (true) {
		num=getSum(num);
		if (num == 1) {
			return true;
		}
		if (visited.find(num) != visited.end()) {  //set 내부에 num값이 존재하는지 순회. 공식 기억 !!
			return false;
		}
		visited.insert(num);
	}

}

//소수 상근수 반환 함수
vector<int> solution(int n) {
	vector<bool>is_prime = getPrime(n);
	vector<int>result;

	//i가 소수이면서 상근수이면 result에 i 추가
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && isValid(i)) {
			result.push_back(i);
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	vector<int>ans=solution(n);

    //for-each 반복문
    for (int num : ans) {
        cout << num << "\n";
    }

	// for (int i = 0; i < ans.size(); i++) {
	// 	cout << ans[i] << "\n";
	// }

	return 0;
}