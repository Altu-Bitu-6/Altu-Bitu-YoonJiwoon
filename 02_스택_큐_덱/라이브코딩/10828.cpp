#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,x;
	string cmd;
	stack<int>s;

	cin >> n;
	while(n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			s.push(x);
		}
		else if (cmd == "pop") {
			if (s.empty()) {
				cout <<"-1\n"; //cout <<-1<<"\n"; 이렇게 하니 런타임 에러!
			}
			else {
				cout << s.top()<<"\n";
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout<< s.size() << "\n";
		}
		else if (cmd == "empty") {
			if (s.empty()) {
				cout << "1\n";
			}
			else {
				cout <<"0\n";
			}
		}
		else if (cmd == "top") {
			if (s.empty()) {
				cout <<"-1\n";
			}
			else {
				cout << s.top() << "\n";
			}	
		}
	}
	return 0;
}