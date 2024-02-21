#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int sum(const string& n1){
    int sum=0;
    for (int i=0;i<n1.size();i++){
        if(isdigit(n1[i])){ //n1 문자열에서 숫자만 뽑아서
            sum+=n1[i]-48;   //48='0' 아스키코드
        }
    }
    return sum;
}

bool cmp(const string& n1, const string& n2) {
    int n1_sum = sum(n1);
    int n2_sum = sum(n2);
    if (n1.size() != n2.size()) {
        return n1.size() < n2.size();
    }
    if (n1_sum != n2_sum) {
        return n1_sum < n2_sum;
    }
    return n1 < n2;
}

int main(){
    int n;
    cin >> n;
    vector <string> num (n);
    for (int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end(),cmp);

    for (int i=0;i<n;i++){
        cout<<num[i]<<"\n";
    }
    return 0;
}