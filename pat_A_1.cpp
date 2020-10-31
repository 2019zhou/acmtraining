#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin>> a>> b;
    string s= to_string(a+ b);
    int len= s.length();
    for (int i= 0; i< len; ++i) {
        cout<< s[i];
        if (s[i] == '-')continue;
        if ((i+ 1) % 3 == len% 3 && i!= len- 1)
            cout<< ",";
    }
    cout << endl;
    return 0;
}

// 开始的时候自己用auto iter = s.begin() 乱写了一会，但是iter很容易就和想象的不一样了
// 还是从开始的时候写成 s[i]这种比较对
// 数字转化字符串 to_string