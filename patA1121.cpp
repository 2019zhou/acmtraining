// 输出格式错误！
#include <iostream>
#include <set>
using namespace std;

const int N = 50010;
int a[N];
int b[N];


int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }
    int m;
    int tmp;
    cin >>m;
    while(m--){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i = 0;i < n;i++){
        if(s.count(a[i]) && s.count(b[i])){
            s.erase(a[i]);
            s.erase(b[i]);
        }
    }
    cout <<(int) s.size() << endl;
    int flag = 0;
    for(auto it = s.begin(); it!= s.end();it++){
        if(!flag){
            printf("%05d", *it);
            flag = 1;
        }else{
            printf(" %05d", *it);
        }
    }
    
    
    
    return 0;
}
