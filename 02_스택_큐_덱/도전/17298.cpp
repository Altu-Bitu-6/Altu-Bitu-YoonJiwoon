#include <iostream>
#include <vector> //벡터에 수열의 값 저장
#include <stack> //스택에는 수열의 값이 아닌 인덱스를 저장!

using namespace std;

vector<int> getNGE(int n, vector<int>& v) {
    stack<int>s;
    vector<int>answer(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            // 새로 들어오는 값이 v[s.top()]보다 크면 오큰수. 
            // 스택에 수 하나 들어올 때 오큰수는 하나 이상 결정될 수 있으므로 if문이 아닌 while문을 사용해야함.
            answer[s.top()] = v[i];
            // answer.push_back(v[i]);  push_back 사용하면 무조건 뒤에 붙여서 순서 뒤죽박죽 됨.
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {  //스택 비우기
        answer[s.top()] = -1; //ans에 넣고 스택 비워야 함!
        s.pop();
        //answer.push_back(-1);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int>answer = getNGE(n, v);
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}