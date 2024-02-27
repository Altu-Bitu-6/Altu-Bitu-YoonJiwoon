#include <iostream>
#include <string>
#include <vector> 
#include <map> 

using namespace std;

int overtake(int n, vector<int>& output) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) { //현재 차보다 늦게 나온 차들 확인 -> j는 i+1부터!
            if (output[i] > output[j]) { //더 늦게 들어간 차가 먼저 나오는 경우 -> 추월
                ans++;
                break;
            }
        } 
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n;
    map<string, int>input;
    string car;

    cin >> n;
    vector<int>output(n+1); //1부터 n이 필요하니 크기는 n+1이어야함. 초기화 안해주면 39 line에서 오류남.
    //n+1 초기화 안해줄 거면 39line에서 output.push_back(input[car])해야함
    
    for (int i = 1; i <= n;i++) {
        cin >> car;
        input[car] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> car;
        output[i]=input[car]; //input에 들어온 순서대로 output[car]의 value에 저장
    }

    
    cout << overtake(n,output);

    return 0;
}