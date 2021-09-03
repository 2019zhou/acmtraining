#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 505;
int n, m, start, en;
int d[N][N], a[N][N];
int dist[N], cost[N];
bool st[N];
int pre[N];

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    memset(cost, 0x3f, sizeof cost);
    dist[start] = 0, cost[start] = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 0;j < n;j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        st[t] = true;
        for(int j = 0;j < n;j++){
            if(dist[j] > dist[t] + d[t][j]){
                dist[j] = dist[t] + d[t][j];
                cost[j] = cost[t] + a[t][j];
                pre[j] = t;
            }else if(dist[j] == dist[t] + d[t][j]){
                if(cost[j] > cost[t] + a[t][j]){
                    cost[j] = cost[t] + a[t][j];
                    pre[j] = t;
                }
            }
        }
    }
    
}




int main(){
    scanf("%d%d%d%d", &n, &m, &start, &en);
    int a1, a2, a3, a4;
    memset(d, 0x3f, sizeof d);
    memset(a, 0x3f, sizeof a);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
        d[a1][a2] = d[a2][a1] = min(d[a2][a1], a3);
        a[a1][a2] = a[a2][a1] = min(a[a2][a1], a4);
        //cout << a[a1][a2] << d[a1][a2];
    }
    
    dijkstra();
    vector<int> path;
    for(int i = en;i != start;i = pre[i]){
        path.push_back(i);
    }
    cout << start <<" ";
    for(int i = path.size() - 1;i >=0;i--){
        cout << path[i] << " ";
    }
    cout << dist[en] << " ";
    cout << cost[en];
    
    
}
