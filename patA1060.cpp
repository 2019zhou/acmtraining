// 1. 找到小数点
// 2. 将小数点移到最前面
// 3. 移除前导零
// 4. 补足0位

#include <iostream>
using namespace std;
int n;

string print(string a){
    int k = a.find(".");
    if(k == -1){
        a += '.';
        k = a.find(".");
    }
    string s = a.substr(0, k) + a.substr(k + 1);
    while(s.size() && s[0] == '0'){
        s = s.substr(1);
        k--;
    }
    if(s.empty()) k = 0;
    if(s.size() > n) s = s.substr(0, n);
    else s += string(n - s.size(), '0');
    
    return "0." + s + "*10^" + to_string(k);
}

int main(){
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = print(a);
    b = print(b);
    
    if(a == b)
        cout << "YES " <<a << endl;
    else
        cout << "NO " <<a << ' ' << b << endl;
}
