// 先是输入错，再是输出错。。。。。
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, int> PDI;

const int N = 1005;
PDI t[N];
double b[N];
double a[N];

int main(){
    int n, d;
    cin >> n >> d;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
        t[i] = {a[i] / b[i], i};
    }
    
    sort(t, t + n);
    double ans = 0;
    double cur = 0;
    int sign = 0;
    double cura = 0;
    for(int i = 0;i < n;i++){
        if(cur + a[t[i].second] > d){
            ans = cura + 1/ t[i].first * (d - cur);
            sign = 1;
            break;
        }else if(cur == d){
            ans = cura;
            sign = 1;
            break;
        }else{
            cur += a[t[i].second];
            cura += b[t[i].second];
        }
        //cout << cur << " " << cura << endl;
    }
    if(sign == 0) ans = cura;
    printf("%.2lf", ans);
    
    return 0;
}
