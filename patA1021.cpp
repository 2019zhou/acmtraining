// 模板题的组合
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10010, M = 2 * N;
int e[M], ne[M], h[N],  idx;
int p[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int dfs(int u, int father){
    int depth = 0;
    for(int i = h[u];i != -1;i= ne[i]){
        int j = e[i];
        if(j == father) continue;
        depth = max(depth, dfs(j, u) + 1);
    }
    return depth;
}


int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) p[i] = i;
    int a, b;
    int k = n;
    memset(h, -1, sizeof(h));
    for(int i = 0;i < n - 1;i++){ 
        scanf("%d%d", &a, &b);
        int fa = find(a);
        int fb = find(b);
        if(fa != fb){
            p[fa] = fb;
            k--;
        }
        add(a, b);
        add(b, a);
    }
    
    if(k > 1)
        printf("Error: %d components", k);
    else{
        vector<int> nodes;
        int maxl = -1;
        for(int i = 1;i <= n;i++){
            int len = dfs(i, -1);
            if(len > maxl){
                maxl = len;
                nodes.clear();
                nodes.push_back(i);
            }else if(len == maxl){
                nodes.push_back(i);
            }
        }
        for(auto item:nodes)
            printf("%d\n",item);
    }

    
    return 0;
}
