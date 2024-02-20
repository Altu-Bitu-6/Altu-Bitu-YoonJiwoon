#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int sum(const string& n1){
    int sum=0;
    for (int i=0;i<n1.size();i++){
        if(n1[i]>=48 &&n1[i]<=57){
            sum+=n1[i]-48;
        }
    }
    return sum;
}

bool cmp(const string& n1, const string& n2){
    int n1_size = n1.size();
    int n2_size = n2.size();
    int n1_sum=sum(n1);
    int n2_sum=sum(n2);
    if (n1_size==n2_size){
        if (n1_sum==n2_sum){
            return n1 < n2;
        }
        else{
            return n1_sum < n2_sum;
        }
    }
    else {
        return n1_size < n2_size;
    }
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

}