#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
const int SAW_NUM = 8;
vector<string> li;  //톱니 바퀴를 저장
// li[0] -> 1번째 톱니바퀴 저장
vector<pair<int, int>> stack;  //회전톱니바퀴의 인덱스와 방향 저장
vector<int>visited; //회전했는지 검사하는 벡터


void check_rotation(int n, int dir) {
	if (n > 0 && visited[n - 1] == 0) { // 첫번째 바퀴를 제외 + 왼쪽 바퀴가 회전 검사 X 이면
		if (li[n][6] != li[n - 1][2]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
			stack.push_back(make_pair(n - 1, dir * -1));
			visited[n - 1] = 1;
			check_rotation(n - 1, dir * -1); // n-1번째는 dir 반대방향으로 회전하므로
		}
	}

	if (n < li.size() - 1 && visited[n + 1] == 0) { // 마지막 바퀴를 제외 + 오른쪽 바퀴가 회전 검사 X 이면
		if (li[n][2] != li[n + 1][6]) {  // 맞닿아 있는 면이 서로 다른 극인지 체크
			stack.push_back(make_pair(n + 1, dir * -1));
			visited[n + 1] = 1;
			check_rotation(n + 1, dir * -1); // n+1번째는 dir 반대방향으로 회전하므로
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, k;
	cin >> t;

	li.resize(t);
	//li.assign(t,""); // 벡터크기는 t회로

	for (int i = 0; i < t; i++) {
		cin >> li[i]; //톱니바퀴의 상태 입력
	}

	cin >> k;
	for (int i = 0; i < k; i++) {   //입력을 받자마자 처리
		int num, direction;
		cin >> num >> direction; //회전 번호와 방향 입력
		stack.clear(); //벡터 초기화
		stack.push_back(make_pair(num - 1, direction));  // 인덱스 1차이 나는 점 주의!
		visited.assign(t, 0);  //0으로 방문처리 초기화
		visited[num - 1] = 1; // 첫 회전 톱니바퀴 방문처리

		check_rotation(num - 1, direction); //로테이션 확인

		//stack에 돌려야하는 톱니바퀴들 전부 저장됨.

		while (!stack.empty()) {  //스택이 빌 때까지 톱니바퀴를 돌려줌
			pair<int, int>top = stack.back(); //마지막 원소
			stack.pop_back(); //마지막 원소 삭제

			int tmp_num = top.first; //현재 돌려야할 톱니바퀴 인덱스
			int tmp_dir = top.second;  //돌릴 방향
			

			if (tmp_dir == 1) { //시계방향 회전
				//0번 -> 1번, 7번 -> 0번
				li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
				//맨 뒤 7번 인덱스 붙이고 0~6번 인덱스 붙임 (0번째위치부터 7자리)
			}
			else { //반시계방향 회전
				//0번 -> 7번, 7번 -> 6번
				li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
				// 1~7번 붙여주고 0번 인덱스 붙여줌
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < t; i++) {
		if (li[i][0] == '1') { // 12시 방향이 S극인 톱니바퀴의 개수 출력.
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}