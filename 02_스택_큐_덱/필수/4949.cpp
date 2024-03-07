#include <iostream>
#include <string>
#include <stack>

using namespace std;

string func(string line) {
	stack<char>s;

	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '(' || line[i]=='[') {
			s.push(line[i]);
		}
		if (line[i] == ')') {
			if (!s.empty() && s.top() == '(') {  
				//!s.empty() 없으면 에러 발생! s.top()은 스택에 값이 존재할 때만 사용!
				s.pop();
			}
			else {
				return "no";
			}
		}
		if (line[i] == ']') {
			if (!s.empty() && s.top() == '[') {
				s.pop();
			}
			else {
				return "no";
			}
		}
	}
	if (!s.empty()) {
		return "no";
	}
	return "yes";
}

int main() {
	string line;

	while (true) {
		getline(cin, line);
		if (line == "." &&line.size()==1) {  //입력 맨 뒤 온점에서 끝나는게 아닌 .만 있을 때 끝
			break;
		}
		cout << func(line) << "\n";
	}
	return 0;
}