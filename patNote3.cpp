// 求给定矩阵中块的个数，就是bfs的应用
//这里也说明了矩阵实际上 100 * 100是可以正常运行的
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
struct node{
	int x;
	int y;
}Node;

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y){
	if(x >= n || x < 0 || y >=m || y < 0) return false;
	if(matrix[x][y] == 0 ||inq[x][y] == true) return false;
	return true;
}

void BFS(int x, int y){
	queue<node> Q;
	Node.x = x, Node.y = y;
	Q.push(node);
	inq[x][y] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		for(int i = 0;i < 4;i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if(judge(newX, newY)){
				Node.x = newX;
				Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(matrix[i][j] == 1 && inq[i][j] == false){
				ans++;
				BFS(i, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}