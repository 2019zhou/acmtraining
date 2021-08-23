//聪明机制的我被读取数据难到了。

#include <iostream>
using namespace std;

int main(){
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    int a[256] = {0};
    for(int i = 0;i < s2.size();i++){
        a[s2[i]] = 1;
    }
    for(int i = 0;i < s1.size();i++){
        if(a[s1[i]] == 0)
            cout << s1[i];
    }
    return 0;
}

