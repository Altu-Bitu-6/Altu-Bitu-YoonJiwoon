#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

tuple<int, int, int> diet(int w0, int i0, int t, int d, int i, int a) {
    //w: 체중, m: 일일 기초 대사량
    int w1 = w0, m1 = i0; //일일 기초 대사량 변화 고려X
    int w2 = w0, m2 = i0; //일일 기초 대사량 변화 고려O
    while (d--) { //d일 간의 다이어트
        //체중 += (일일 에너지 섭취량 - 일일 에너지 소비량)
        //일일 에너지 소비량 = 일일 기초 대사량 (m) + 일일 활동 대사량(a)
        w1 += (i - (m1 + a));
        w2 += (i - (m2 + a));

        //일일 기초 대사량 변화
        if (abs(i - (m2 + a)) > t) {
            //음수의 나눗셈 주의! 
            //Ex) floor (-5/2)=-3 (c++상에서는 -2)
            m2 += float(i - (m2 + a)) / 2.0;  //float끼리의 나눗셈으로 수행하고 소숫점 버림.
        }
    }
    return { w1, w2, m2 };  //m1=i0이므로 w1,w2,m2만 return 한다. tuple값이므로 중괄호 사용
}

int main() {

    int w0, i0, t, d, i, a;   //변수 선언
    cin >> w0 >> i0 >> t;     //체중, 섭취량, 대사량 역치 입력
    cin >> d >> i >> a;       //다이어트 기간, 섭취량, 활동대사량 입력

    tuple<int, int, int> result = diet(w0, i0, t, d, i, a); //diet함수 return값 tuple에 저장
    int w1 = get<0>(result), m1 = i0;  //tuple에서 값 가져오기 get함수 사용
    int w2 = get<1>(result), m2 = get<2>(result);
    

    if (w1 <= 0) { //만약 체중이 0g이하인 경우
        cout << "Danger Diet\n";
    }
    else {
        cout << w1 << " " << m1 << "\n"; //변화 고려 안한 체중, 기초대사량 출력
    }

    if (w2 <= 0 || m2 <= 0) {  //만약 체중이 0g이하이거나 일일기초대사량이 0이하인 경우
        cout << "Danger Diet";
    }
    else {
        cout << w2 << " " << m2 << " "; //m2 변화 고려한 체중, 기초대사량 출력
        if (i0 > m2) { //원래기초대사량이 변화기초대사량보다 크면 요요현상
            cout << "YOYO";
        }
        else { //작으면  요요 발생X
            cout << "NO";
        }
    }
    return 0;
}