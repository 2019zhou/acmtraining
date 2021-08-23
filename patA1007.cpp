// towards robust code
// 小于0， 只有一个0的值怎么处理
#include <iostream>
using namespace std;

const int N = 10005;
int a[N];

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int temp = 0;
    int maxn = -1e9;
    int l = 0, r = 0;
    int ll = 0, rr = 0;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
        maxn = max(maxn, a[i]);
        if(temp + a[i] < 0){
            temp = 0;
            ll = i + 1;
        }
        else{
            temp = temp + a[i];
            rr = i;
        }
            
        if(temp > ans){
            l = ll;
            r = rr;
            ans = temp;
        }else if(temp == 0 && temp == ans){
            l = ll;
            r = rr;
            ans = temp;
        }
    }
    //cout << l << " " << r << endl;
    if(maxn < 0)
        cout << "0" << " " << a[0] << " " << a[n - 1];
    else
        cout << ans << " " << a[l] << " " << a[r];
    
    return 0;
}
