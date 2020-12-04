// 1.用两个Dijkstra。一个求最短路径（如果相同求时间最短的那条），一个求最快路径（如果相同求结点数最小的那条）～～
// 2.求最短路径,和最快路径都可以在Dijkstra里面求前驱结点dispre和，Timepre数组～
// 3.dispre数组更新的条件是路径更短，或者路径相等的同时时间更短。
// 4.求最快路径时候要多维护一个NodeNum数组，记录在时间最短的情况下，到达此节点所需的节点数量。
// Time数组更新的条件是，时间更短，时间相同的时候，如果此节点能让到达次节点是数目也变小，则更新Timepre，heNodeNum数组
// 5.最后根据dispre 和Timepre数组递归出两条路径，比较判断，输出最终答案～

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510],Timepre[510], weight[510],NodeNum[510];
bool visit[510];
vector<int> dispath, Timepath, temppath;
int st, fin, minnode = inf;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == st) return ;
    dfsdispath(dispre[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) return ;
    dfsTimepath(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for(int i = 0; i < n; i++)
        dispre[i] = i;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v]= u;
                    NodeNum[v]=NodeNum[u]+1;
                } else if(w[u][v] + Time[u] == Time[v]&&NodeNum[u]+1<NodeNum[v]) {
                    Timepre[v]= u;
                    NodeNum[v]=NodeNum[u]+1;
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if(dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for(int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for(int i = Timepath.size() - 1; i >= 0; i--) {
        printf("%d", Timepath[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}


// 下面的好累，，写的
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct street{
	int v1;
	int v2;
	int oneway;
	int length;
	int time;
}streets[500];



int main(){
	int n, m;
	cin >> n >> m;
	int tempv1, tempv2, temponeway, templength, temptime;
	for(int i = 0;i < m;i++){
		cin >> tempv1 >> tempv2 >> temponeway >> templegnth >> temptime;
		streets[i].v1 = tempv1;
		streets[i].v2 = tempv2;
		streets[i].oneway = temponeway;
		streets[i].length= templength;
		streets[i].time = temptime;
	}


	return 0;
}