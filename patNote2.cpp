// n件物品，每件物品的重量w[i], 价值c[i], 现在需要选出若干见物品放入一个容量为V的背包中，使得选入背包的物品重量和不超过容量V的前提下，包中的物品价值之和最大。

#include <cstdio>
const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];
void DFS(int index, int sumW, int sumC){
	if(index == n){
		if(sumW <= V && sumC > maxValue){
			maxValue = sumC;
		}
		return;
	}
	DFS(index + 1, sumW + w[index], sumC + c[index]);
	DFS(index + 1, sumW, sumC);
}

int main(){
	scanf("%d%d", &n, &V);
	for(int i = 0;i < n;i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d", &c[i]);
	}
	DFS(0, 0, 0);
	printf("%d", maxValue);
	return 0;
}