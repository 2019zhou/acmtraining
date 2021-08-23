// 理清逻辑开始map
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 100005;
int a[N];

int main(){
    int n, m;
    cin >>n >> m;
    unordered_map<int, int> mp;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(!mp.count(a[i]))
            mp[a[i]] = 1;
        else
            mp[a[i]] ++;
    }
        
    sort(a, a + n);
    int sign = 0;
    for(int i = 0;i < n;i++){
        if(mp.count(m - a[i])){
            if(a[i] != m - a[i]){
                cout << a[i]<< " " << m - a[i] << endl;
                sign = 1;
                break;
            }else{
                if(mp[m - a[i]] >= 2){
                    cout << a[i]<< " " << a[i] << endl;
                    sign = 1;
                    break;
                }
            }
        }
    }
    
    if(sign == 0)
        puts("No Solution");
    return 0;
}
