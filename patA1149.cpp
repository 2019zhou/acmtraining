// 学会分析数据范围
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }
    int x;
    int sign = 1;
    while(m--){
        int k;
        cin >> k;
        sign = 1;
        unordered_set<int> s;
        for(int j = 0;j < k;j++){
            cin >> x;
            s.insert(x);
        }
        for(int j = 0;j < n;j++){
            if(s.count(a[j]) && s.count(b[j])){
                sign = 0;
                break;
            }
        }
        if(sign == 0)
            cout << "No" << endl;
        else
            cout << "Yes"<< endl;
    }
    
    
    
}
