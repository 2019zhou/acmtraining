//下次记得写一遍打表的大数据可能TLE
#include <iostream>
using namespace std;

typedef long long LL;


bool isprime(LL a){
    if(a == 1) return false;
    for(LL i = 2;i <= a/i;i++){
        if(a%i == 0)
            return false;
    }
    return true;
}

bool check(int a, int d){
    LL t = 0;
    while(a){
        t = t * d + a%d;
        a = a/d;
    }
    //cout << t << endl;
    LL t2 = 0;
    if(isprime(t))
        return true;
    else 
        return false;
}

int main(){
    int n, d;
    while(true){
        cin >> n;
        if(n < 0)
            break;
        cin >> d;
        if(isprime(n)){
            if(check(n, d)){
                cout << "Yes" << endl;
            }else
                cout << "No" << endl;
        }else
            cout << "No" << endl;
    }
    
}
