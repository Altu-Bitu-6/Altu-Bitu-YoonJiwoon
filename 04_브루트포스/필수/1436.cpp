#include <iostream>

using namespace std;

int movieName(int n) {
	int series = 0;
	
	for (int i = 666; i<=10000000; i++) {  //i값을 어디까지 제한해야하는지 잘 모르겠다..
		int digit = 0;
		int tmp = i; //tmp없이 i를 나누면 i 값이 달라짐.
		while (tmp != 0) {
			if (tmp % 10 == 6) {
				digit++;
			}
			else {
				digit = 0;
			}
			tmp /= 10;
			if (digit == 3) {
				series++;
				break;
			}
		}
		
		if (series == n) {
			return i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int result = movieName(n);
	cout << result;

	return 0;
}