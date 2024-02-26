#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sum(string a, string b) {
	string c;
	int x, y, d;
	int digit=0,carry=0;
	for (int j = a.size()-1; j >= 0; j--) {
		x = a[j] - '0';
		y = b[j] - '0';
		digit++;
		if (x + y+ carry > 9) {
			d = (x + y +carry) % 10;
			c += d+'0'; //d값을 c에 문자로 저장
			carry = 1;
			if (digit == a.size()) {
				c += "1";
			}
		}
		else {
			d = x + y + carry;
			c += d+'0';
			carry = 0;
		}
	}
	
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b,t;
	cin >> a >> b;

	if (a.size() < b.size()) {
		swap(a, b);
	}
	if (a.size() != b.size()) {
		for (int i = 0; i < a.size() - b.size(); i++) {
			 t+= "0";
		}
		b = t + b;
	}
	string ans = sum(a, b);
	
	for (int i = ans.size()-1; i >= 0; i--) {
		cout << ans[i];
	}
	return 0;
}