#include <iostream>

using namespace std;

int gcdIter(int a, int b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int gcdRecur(int a, int b) {
    //b==0 -> return a
	if (!b) {
		return a;
	}
    //b!=0 -> a에는 b, b에는 a%b 넣음.
	return gcdRecur(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;

	//int gcd = gcdIter(a, b);
	int gcd = gcdRecur(a, b);

	int lcm = a * b / gcd;

	cout << gcd << "\n" << lcm;
}