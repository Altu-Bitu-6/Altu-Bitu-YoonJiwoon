#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(char ch) {
	switch (ch) {
		case '(':
			return 0;
		case '+': case'-':
			return 1;
		case '*': case '/':
			return 2;
	}
}

string postfix(string input) {
	string result = "";
	stack<char>op;

	for (int i = 0; i < input.size(); i++) {
		char ch = input[i];
		switch (ch) {
			case '(':
				op.push(ch);
				break;

			case ')':
				while (!op.empty() && op.top() != '(') { //empty 꼭 써줘야함
					result += op.top();
					op.pop();
				}
				op.pop(); // '(' 지우기
				break;

			case '+': case '-': case '*': case '/':
				//스택에 현재 연산자보다 우선순위가 높은 (= 먼저 계산되어야 하는) 연산자가 있는 경우 pop
				while (!op.empty() && priority(op.top()) >= priority(ch)) {
					result += op.top();
					op.pop();
				}
				op.push(ch);
				break;

			default:
				result += ch;
		}
	}

	while (!op.empty()) {
		result += op.top();
		op.pop();
	}
	
	return result;
}

/*
 * [중위 표기식 -> 후위 표기식]
 * 1. 피연산자는 순서가 변하지 않으므로 바로 결과에 추가한다.
 * 2. 연산자는 우선순위에 따라 순서가 변하므로 스택에 잠시 저장한다.
 * 3. 스택의 top에 있는 연산자는 우선순위가 제일 높아야 한다.
 * 4. 스택의 top에 있는 연산자가 현재 연산자보다 우선순위가 같거나 높으면 스택에서 값을 꺼내야 한다.
 * 5. 여는 괄호는 무조건 스택에 넣는다.
 * 6. 닫는 괄호가 들어오면 여는 괄호가 나올 때까지 스택에 있는 연산자를 결과에 추가한다.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;

	cin >> input;
	cout << postfix(input);

	return 0;
}