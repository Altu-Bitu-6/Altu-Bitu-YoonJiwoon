#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sum(const string& a, string& b) { //&: 속도 빨라짐!
	string t, c;
	int x, y, d;
	int digit = 0, carry = 0;

	if (a.size() != b.size()) {
		// for (int i = 0; i < a.size() - b.size(); i++) {
		// 	 t+= "0";
		// }
		t = string(a.size() - b.size(), '0');
		b = t +b; //자릿수 작은 수 앞에 0으로 채우기
	}

	for (int j = a.size() - 1; j >= 0; j--) {
		x = a[j] - '0';
		y = b[j] - '0';
		digit++;
		if (x + y + carry > 9) {
			d = (x + y + carry) % 10;
			c += d + '0'; //d값을 c에 문자로 저장
			carry = 1;
		}
		else {
			d = x + y + carry;
			c += d + '0';
			carry = 0;
		}
	}
	if (carry==1) {
		c += "1";
	}

	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b;
	cin >> a >> b;

	if (a.size() < b.size()) {
		swap(a, b);
	}

	string ans = sum(a, b);

	//for (int i = ans.size() - 1; i >= 0; i--) {
	//	cout << ans[i];
	//}
	reverse(ans.begin(),ans.end());
	cout << ans;

	return 0;
}