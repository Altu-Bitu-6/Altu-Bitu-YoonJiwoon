#include <iostream>
#include <vector>

using namespace std;

int solution (int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    vector<int> clothes_cnt (n+1, 1); //옷의 개수를 저장하는 벡터. 초기 설정값 1.
    
    //잃어버린 인덱스 -> --
    for (int i = 0; i < lost.size(); i++) {
        clothes_cnt[lost[i]]--;    
    }    
    //여벌 인덱스 -> ++
    for (int i = 0; i < reserve.size(); i++) {
        clothes_cnt[reserve[i]]++;
    }
    
    for (int i=0; i<= n; i++){
        if (clothes_cnt[i] >=1){
            continue;
        }
        
        if (clothes_cnt[i-1]==2){
            clothes_cnt[i-1]--;
            clothes_cnt[i]++;
        }
        else if (clothes_cnt[i+1]==2){
            clothes_cnt[i+1]--;
            clothes_cnt[i]++;
        }
    }
    
    for (int i=1; i<= n; i++){
        if (clothes_cnt[i] >= 1){
            answer++;
        }
    }
    
    return answer;
}