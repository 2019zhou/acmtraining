#include <iostream>
using namespace std;

const int N = 100010;
const int mod = 1000000007;
int a[N];
int b[N];

int main(){
    string s;
    cin >> s;
    if(s[0] == 'P') a[0] = 1;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'P'){
            a[i] = a[i - 1] + 1;
        }else{
            a[i] = a[i - 1];
        }
    }
    if(s[s.size() - 1] == 'T') b[s.size() - 1] = 1;
    for(int i = s.size() - 2;i >= 0;i--){
        if(s[i] == 'T'){
            b[i] = b[i + 1] + 1;
        }else{
            b[i] = b[i + 1];
        }
    }
    long long ans = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'A'){
            ans = (ans + a[i] * b[i])%mod;
        }
    }
    cout << ans << endl;
    
}
