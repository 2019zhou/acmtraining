// 王道练习1
// 使用Hash
#include <stdio.h>
int main(){
	int n;
	while(scanf("%d", &n)!= EOF && n!= 0){
		int Hash[101] = {0};
		for(int i = 1;i <= n;i++){
			int x;
			scanf("%d", &x);
			Hash[x]++;
		}
		int x;
		scanf("%d", &x);
		print("%d\n", Hash[x]);
	}
	return 0;
}

// 有关时间复杂度的题目要注意这种方法

// 给定n个整数，请按从大到小的顺序输出其中前m大的数




#include <stdio.h>
#define OFFSET 500000
int Hash[1000001];
int main(){
	int n, m;
	while((scanf("%d%d"), &n, &m)!= EOF){
		for(int i = -500000;i <= 500000;i++){
			Hash[i + OFFSET] = 0
		}
		for(int i = 1;i <= n;i++){
			int x;
			scanf("%d", &x);
			Hash[x + OFFSET] = 1;
		}
		for(int i = 500000;i >= - 500000;i--){
			if(Hash[i + OFFSET] == 1){
				printf("%d", i);
				m --;
				if(m != 0) printf(" ");
				else{
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}