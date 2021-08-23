// 想清楚是字符串还是数字
// 前导零的处理最后还是直接全部变成一个字符串了，注意s.size() > 1这个边界条件
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;
int n;
string s[N];
void rz(string &s){
    while(s.size()>1 && s[0] == '0') s = s.substr(1, s.size() - 1);
}

bool cmp(string  a, string b){
    return a + b < b + a;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> s[i];
    sort(s, s + n, cmp);
    string ans;
    for(int i = 0;i < n;i++)
        ans += s[i];
    rz(ans);
    cout << ans;
}
