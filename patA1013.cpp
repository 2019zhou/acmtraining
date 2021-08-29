// 并查集
#include <iostream>
using namespace std;

const int N = 1010;
const int M = 500005;

int p[N];

struct edge{
    int a, b;
}e[M];

int find(int x){
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++){
        scanf("%d%d", &e[i].a, &e[i].b);
    }
    
    int tmp;
    while(k--){
        cin >> tmp; 
        
        for(int i = 1;i <= n;i++){
            p[i] = i;
        }
        
        int cnt = n - 1;
        for(int i = 0;i < m;i++){
            if(e[i].a != tmp && e[i].b != tmp){
                int xa = find(e[i].a);
                int xb = find(e[i].b);
                if(xa != xb){
                    p[xa] = xb;
                    cnt--;
                }
            }
        }
        printf("%d\n", cnt - 1);
    }
    
    
    return 0;
}
