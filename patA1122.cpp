// 明确哈密顿回路是什么
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 202;
const int M = 40000;
int n, m;
bool st[N];
int idx = 0;
int e[M], ne[M], h[N];
int c[N * 2];


void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


int main(){
    cin >> n >> m;
    int a, b;
    memset(h, -1, sizeof h);
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    int k;
    cin >> k;
    int cnt;
    while(k--){
        cin >> cnt;
        unordered_set<int> s;
        int sign = 0;
        int sign2 = 0;
        for(int i = 0;i < cnt;i++){
            cin >> c[i];
            if(s.count(c[i]) && i != cnt - 1)
                sign = 1;
            else
                s.insert(c[i]);
        }

        if(c[0] != c[cnt - 1] || cnt != n + 1 || sign){
            
            cout << "NO" << endl;
        }else{
            memset(st, 0, sizeof(st));
            for(int i = 0;i < cnt - 1;i++){
                int success = 0;
                st[c[i]] = 1;
               
                for(int j = h[c[i]];j != -1;j= ne[j]){
                    if(e[j] == c[i + 1]){
                        success = 1;
                        break;
                    }
                }
                if(success == 0){
                    sign2 = 1;
                    break;
                }
                if(sign2 == 1)
                    break;
            }
            for(int i = 1;i <= n;i++){
                if(st[i] == 0){
                    sign2 = 1;
                    break;
                }
            }
            if(sign2 == 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    
    
    return 0;
}
