// patNote --Important
//有关于图相关的比较重要的模板


// DFS模板
DFS(u){ // 对于u的访问
	vis[u] = true;  // 设置u已经被访问
	for(从u出发可以到达的所有顶点v){
		if( vis[v] == false)
			DFS(v);
	}
}

DFSTrave(G){ // 遍历图G
	for(G的所有顶点u){
		if(vis[u] == false) // 如果u没有被访问
			DFS(u);
	}
}

// #include <algorithm> 方便的功能
find()
next_permutation()
reverse()
priority_queue<int, vector<int>, greater<int>>q;


// 并查集
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
		father[faA] = faB;
}

// findFather 步骤
int findFather(int x){
	// x 在下面的while会变成根节点，先把x保存一下
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a; // 因为a要被father[a]覆盖，所以需要先保存a的值, 来修改father[a]
		a = father[a]; // a回溯父亲节点
		father[z] = x; // 将原先的结点a的父亲改为根结点x
	}
	return x;
}

// Dijkstra算法的伪代码
Dijkstra(G, d[], s){ //G为图,一般设置为全局变量; d 为到达个点的最短路径长度，s为起点
	//初始化;
	for(循环n次){
		u = 使d[u]最小的还未被访问的顶点的标号;
		设置u已经被访问
		for(从u出发可以到达的所有顶点v){
			if(v未被访问 && 以u为中介点使s到达v的最短距离d[v]更优){
				优化d[v]
			}
		}
	}
}


// 拓扑排序
// 拓扑排序争对的是有向无环图, 一个有向图的任意顶点都无法通过一些有向边回到自身 directed acyclic graph
// 1. 定义一个队列Q, 并且把所有入度为0的结点加入队列
// 2. 取出队首结点，删去所有从他出发的边，并且这些边到达的顶点的入度-1
// 3. 反复进行进行2, 知道队列为空, 如果队列为空

vector<int> G[MAXV]; // 邻接表
int n, m, inDegree[MAXV];

bool topologicalSort(){
	int num = 0;
	queue<int> q;
	for(int i = 0;i < n;i++){
		if(inDegree[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
		// printf("%d", u); 输出topologicalSort的顶点
		q.pop();
		for(int i = 0;i < G[u].size();i++){
			int v = G[v][i];
			inDegree[v]--;
			if(inDegree[v] == 0)
				q.push(v);
		}
		G[u].clear(); // 清空u的所有出边
		num++;
	}
	if(num == n) return true;
	else return false;
}