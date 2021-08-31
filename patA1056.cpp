// 第一次i, j写傻了
// 第二次debug半天
// ini[cnt++] = {maxl, maxp}; 这个要设置完rank之后写
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;

const int N = 1010;
int w[N];
int t[N];
PII ini[N];
int r[N];

int main(){
    int np, ng;
    cin >> np >> ng;
    memset(r, -1, sizeof(r));
    for(int i = 0;i < np;i++){
        cin >> w[i];
    }
    for (int i = 0; i < np; i ++ ){
        cin >> t[i];
    }
    
    for (int i = 0; i < np; i ++ ){
        ini[i] = {w[t[i]], t[i]};
    }
    
    int cnt = 10;
    int oldnp = np;
    
    int maxl, maxp;
    while(cnt > 1) {
        cnt = 0;
        for(int i = 0;i < np;i += ng){
            maxl = ini[i].first;
            maxp = ini[i].second;
            for(int j = i + 1;j < i + ng && j < np;j++){
                if(ini[j].first > maxl){
                    maxl = ini[j].first; 
                    maxp = ini[j].second;
                }
            }
            for(int j = i;j < i + ng && j < np;j++){
                if(ini[j].second != maxp){
                    r[ini[j].second] = (np + ng - 1)/ng + 1;
                }
            }
            ini[cnt++] = {maxl, maxp};
        }
        np = cnt;
    }
    r[ini[0].second] = 1;
    
    for(int i = 0;i < oldnp;i++){
        cout << r[i] << " ";
    }
    
    return 0;
}
