// pat 向leetcode 靠近的趋势还是蛮明显的
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        while(a[i] > 0 &&  a[i] != a[a[i] - 1]){
            swap(a[i], a[a[i] - 1]);
        }
    }
    int sign = 0;
    for(int i = 0;i < n;i++){
        if(a[i] != i + 1){
            sign = 1;
            cout << i + 1 << endl;
            break;
        }
    }
    if(sign == 0)
        cout << n + 1 << endl;
    
    
    return 0;
}
