#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int n;
	string ppl, log;
	cin >> n;
	set<string>s; //set 선언 연습!
	for (int i = 0; i < n; i++) {
		cin >> ppl >> log;
		if (log == "enter") {
			s.insert(ppl);
		}
		if (log == "leave") {
			s.erase(ppl); //set에서 제거하는 함수 erase()
		}
	}
	
	// iterator 선언과 동시에 순회 연습! (사전 순의 역순 배열)
	for (auto iter = s.rbegin(); iter != s.rend();iter++) {
		cout << *iter << "\n";
	}
	
	return 0;
}