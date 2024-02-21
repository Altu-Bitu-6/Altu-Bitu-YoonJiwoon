#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	string input;
	map<string, int>poke;
	map<int, string>num; //입력이 숫자일때는 이름, 이름일때는 숫자를 출력해야 하므로 map이 2개 필요!
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		poke[input] = i;
		num[i] = input;
	}

	for (int i = 0; i < m; i++) {
		cin >> input;
		if (isdigit(input[0])) {   //입력이 숫자인 경우:이름 출력
			cout << num[stoi(input)] << "\n";  //stoi: string to int
		}
		else {
			cout << poke[input] << "\n";
		}
	}
	
	return 0;
}