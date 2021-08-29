// 做pat学习输入输出 qaq
// 好像大数据不能过，pat数据全过了
#include <iostream>
using namespace std;

typedef long long LL;


LL gcd(LL a, LL b){
    return b? gcd(b, a%b): a;
}

const int N = 105;
LL a[N], b[N];

int main(){
    int n;
    cin >> n;
    LL t = 1;
    for (int i = 0; i < n; i ++ ){
        scanf("%lld/%lld", &a[i], &b[i]);
        //cout << a[i] << " " << b[i] << endl;
        LL t2 = gcd(t, b[i]);
        t = t*b[i] / t2;
    }
    //cout << t << endl;
    
    LL num = 0;
    LL res = 0;
    for(int i = 0;i < n;i++){
        res += a[i] * (t/b[i]);
        num += res/t;
        //cout << num << endl;
        res = res%t;
    }
    LL t3 = gcd(res, t);
    if(num != 0){
        cout << num;
    }
    if(res!= 0)
        if(num!= 0)
            cout << " " <<res/t3 << "/" << t/t3;
        else
            cout <<res/t3 << "/" << t/t3;
    if(num == 0 && res== 0)
        cout << "0";
    
    return 0;
}
