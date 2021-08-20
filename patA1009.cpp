// 注意上面是N*2，循环数组c的时候
//结束条件写错了就很尴尬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;

double a[N], b[N], c[2 * N];

int main(){
    int k;
    cin >> k;
    int n;
    double v;
    while(k--){
        cin >> n >> v;
        a[n] = v;
    }
    cin >> k;
    while(k--){
        cin >> n >> v;
        b[n] = v;
    }
    
    for(int i = 0;i <= N;i++){
        for(int j = 0;j <= N;j++){
            if(a[i] != 0 && b[j] != 0){
                c[i + j] += a[i] * b[j];
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0;i <= N*2;i++){
        if(c[i])
            cnt++;
    }
    cout << cnt;
    for(int i = N*2 ;i >= 0;i--){
        if(c[i])
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
