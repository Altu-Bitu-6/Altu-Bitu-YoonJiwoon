#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >>m;
    set <string> s;
    string str;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (s.find(str) != s.end()) { //str을 가리키는 반복자를 반환, 없다면 s.end()와 같은 반복자 반환.
            count++;
        }
    }

    cout << count;
    return 0;

}