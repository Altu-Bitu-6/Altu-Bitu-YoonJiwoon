#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//c++은 구조체 정의시 typedef 없어도 됨!
struct student {
	string name;
	int kor, eng, math;
};

// cmp 함수 정의 주의!! 특히 매개변수
bool cmp(const student& s1,const student& s2) {
	if (s1.kor != s2.kor) {
		return s1.kor > s2.kor;
	}
	if (s1.eng != s2.eng) {
		return s1.eng < s2.eng;
	}
	if (s1.math != s2.math) {
		return s1.math > s2.math;
	}
	return s1.name < s2.name; //문자열 사전식 배열
}

int main() {
	int n;
	cin >> n;
	vector<student>studentarr(n);
	for (int i = 0; i < n; i++) {
		cin >> studentarr[i].name >> studentarr[i].kor >> studentarr[i].eng >> studentarr[i].math;
	}
	sort(studentarr.begin(), studentarr.end(),cmp);
	for (int i = 0; i < n; i++) {
		cout << studentarr[i].name << "\n";
	}
	return 0;
}