#include <iostream>
#include <string>
#include <map>
using namespace std;

void noChange() {
    int w_change = l_start - (l_start + a);
    w_end += w_change*d;
}

void change() {
    int w_change = l_diet - (l_diet + a);
    if (w_change > t) {
        l_diet+=
    }
}

int main() {
    int w,l_start,t;
    int d, l_end, a;
    int w_end;
    cin >> w >> l_start >> t;
    cin >> d >> l_end >> a;
    noChange(w, l_start, t, d, l_end, a);
    return 0;

}