// 一个应该是边界的测试点
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
int a[N];
int b[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    int i = 1;
    for(;i < n;i++){
        if(b[i] < b[i - 1])
            break;
    }
    int type = 1;
    int tmp = a[i];
    int tmppos = i;
    for(;i < n;i++){
        if(a[i] != b[i]){
            type = 2;
            break;
        }
    }
    if(type == 1)
        cout << "Insertion Sort" << endl;
    else
        cout << "Merge Sort" << endl;

    if(type == 1){
        int i = 0;
        for(;i < n;i++){
            if(b[i] > tmp){
                break;
            }
        }
        for(int j = tmppos - 1;j >= i;j--){
            b[j+1] = b[j];
        }
        b[i] =  tmp;
    }else{
        int t = 0;
        while(tmppos){
            tmppos = tmppos/2;
            t++;
        }
        int tt = 1;
        for(int i = 0;i < t;i++){
            tt *= 2;
        }
        for(int i = 0;i < n;i+=tt){
            if(i+tt <= n)
                sort(b + i, b + i + tt);
            else
                sort(b + i, b + n);
        }
    }

    int flag = 0;
        for(int i = 0;i < n;i++){
            if(flag == 0){
                cout << b[i];
                flag = 1;
            }else
                cout << " " << b[i]; 
        }

    return 0;
}
