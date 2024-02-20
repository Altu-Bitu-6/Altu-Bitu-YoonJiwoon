#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >>m;
    map <string, int> _map;
    string str;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> str;
        _map[str]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (_map.find(str) != _map.end()) {
            count++;
        }
    }

    cout << count;
    return 0;

}