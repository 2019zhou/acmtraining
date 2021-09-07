#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

const int N = 205;
int g[N][N];
const int K = 1010;
int a[1010];
bool st[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int c1, c2, d;
    memset(g, 0x3f, sizeof g);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d", &c1, &c2, &d);
        g[c1][c2] = min(g[c1][c2], d);
        g[c2][c1] = min(g[c2][c1], d);
    }
    
    int k;
    scanf("%d", &k);
    int cnt;
    int mindis = INT_MAX;
    int num;
    for(int i = 0;i < k;i++){
        scanf("%d", &cnt);
        memset(st, 0, sizeof st);
        for(int j = 0;j < cnt;j++){
            scanf("%d", &a[j]);
        }
        int type = 3;
        int sum = 0;
        if(a[0] != a[cnt - 1]){
            type = 1;
            //cout << a[0] << a[cnt - 1] << endl;
        }
            // 连通
        for(int j = 1;j < cnt;j++){
            if(g[a[j]][a[j - 1]] == 0x3f3f3f3f){
                type = 0;
                break;
            }
            if(st[a[j - 1]] == 1){
                type = 2;
            }else{
                st[a[j - 1]] = 1;
            }
            sum += g[a[j]][a[j - 1]];
        }
        if(type != 0){
           for(int i = 1;i <= n;i++){
                if(st[i] != true){
                    type = 1;
                    break;
                }
            } 
        }
        
            
        
        if(type == 2 or type == 3){
            if(sum < mindis){
                mindis = sum;
                num = i + 1;
            }
                
        }
        
        
        if(type != 0)
            printf("Path %d: %d ", i + 1, sum);
        else
            printf("Path %d: NA ", i+ 1);
        
        
        if(type == 3){
            printf("(TS simple cycle)\n");
        }else if(type == 2){
            printf("(TS cycle)\n");
        }else{
            printf("(Not a TS cycle)\n");
        }
    }
    printf("Shortest Dist(%d) = %d", num,mindis);  
    
    
    return 0;
}
