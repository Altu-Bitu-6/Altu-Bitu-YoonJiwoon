#include <iostream>
#include <string>

using namespace std;

void operation(int& s, string command, int num) {
	if (command == "add") {
		s = s | (1 << num);
	}
	if (command == "remove") {
		s = s & ~(1 << num);
	}
	if (command == "check") {
		if (s & (1<<num)) {
			cout << 1 << "\n"; //출력을 main에서 해야하는 것은 알지만 어떻게 해야될지 모르겠어요..
		}
		else {
			cout << 0 << "\n";
		}
	}
	if (command == "toggle") {
		s = s ^ (1 << num);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, num;
	int s = 0;
	string command;
	
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> command ;
		if (command == "all" || command == "empty") {
			if (command == "empty") {
				s = s & 0;
			}
			if (command == "all") {
				s = (1<<21)-1; //1로 20자리 채우기 
			}
		}
		else {
			cin >> num;
			operation(s, command, num);
		}
	}

	return 0;
}


//방법 2 (set 이용)
// #include <set>

// void operation(set<int>& s, string command, int num) {
// 	if (command == "add") {
// 		if (s.find(num) == s.end()) {
// 			s.insert(num);
// 		}
// 	}
// 	if (command == "remove") {
// 		if (s.find(num) != s.end()) {
// 			s.erase(num);
// 		}
// 	}
// 	if (command == "check") {
// 		if (s.find(num) != s.end()) {
// 			cout << 1 << "\n";  
// 		}
// 		else {
// 			cout << 0 << "\n";
// 		}
// 	}
// 	if (command == "toggle") {
// 		if (s.find(num) != s.end()) {
// 			s.erase(num);
// 		}
// 		else {
// 			s.insert(num);
// 		}
// 	}
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// 	int m, num;
// 	string command;
// 	set<int>s;
// 	cin >> m;

// 	for (int i = 0; i < m; i++) {
// 		cin >> command ;
// 		if (command == "all" || command == "empty") {
// 			if (command == "empty") {
// 				s.clear();
// 			}
// 			if (command == "all") {
// 				for (int n = 1; n <= 20; n++) {
// 					s.insert(n);
// 				}
// 			}
// 		}
// 		else {
// 			cin >> num;
// 			operation(s, command, num);
// 		}
// 	}

// 	return 0;
// }