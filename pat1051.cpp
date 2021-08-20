// 不能使用格外的数组标记 st[idx - 1] < tmp 这个就可以判断
// 可以不用栈模拟
// 注意处理好输入，不能没有处理完输入就开始break!!


#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


const int N = 1005;
int st[N];

int main(){
    int m, n, k;
    cin >> m >> n >>k;
    int tmp;
    int sign = 0;
    int idx = 0;
    while(k--){
        sign = 0;
        idx = 0;
        int val = 1;
        for(int i = 0;i < n;i++){
            cin >> tmp;
            while(idx == 0 or st[idx - 1] < tmp ){
                st[idx++] = val++;
            }
            if(idx > m or st[idx - 1] != tmp){
                sign = 1;
            }
            idx--;
        }
        if(sign == 1)
            cout << "NO"<< endl;
        else
            cout << "YES" << endl;
    }
    
    
    return 0;
}
