// unordered_set的用法
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 55;

unordered_set<int> s[N];


int main(){
    int n;
    cin >> n;
    int m;
    int x;
    for (int i = 1; i <= n; i ++ ){
        cin >> m;
        for (int j = 0; j < m; j ++ ){
            cin >>x;
            s[i].insert(x);
        }
    }
    
    int k;
    cin >> k;
    int a, b;
    for(int i = 0;i < k;i++){
        cin >> a >> b;
        int cnt = 0;
        
        // int cnt2 = 0;
        for(auto t:s[a]){
            if(s[b].count(t)){
                cnt ++;
            }
        }
        int nt = s[a].size() + s[b].size() - cnt;
        printf("%.1lf\%\n", (double)cnt/nt*100);
    }
    
    return 0;
}
