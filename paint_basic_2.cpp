// 先完成排版后输出
#include <iostream>
using namespace std;

int main(){
	int outPutBuf[82][82];
	char a, b;
	int n;
	bool firstCase = true;
	while(scanf("%d %c %c", &n, &a, &b) == 3){
		if(firstCase == true){
			firstCase = false;
		}
		else printf("\n");
		for(int i = 1, j = 1;i<=n;i+=2, j++){
			int x = n/2 + 1, y = x;
			x -= j - 1;
			y -= j - 1;
			char c = j%2 == 1?a :b;
			for(int k = 1;k<=i;k++){
				outPutBuf[x + k - 1][y] = c;
				outPutBuf[x][y + k - 1] = c;
				outPutBuf[x + i - 1][y + k - 1] = c;
				outPutBuf[x + k - 1][y + i - 1] = c;
			}
			if(n != 1){
				outPutBuf[1][1] = '';
				outPutBuf[n][1] = '';
				outPutBuf[1][n] = '';
				outPutBuf[n][n] = '';
			}
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					printf("%c", outPutBuf[i][j]);
				}
				printf("\n");
			}
		}
		return 0;
	}
}


// 二分查找
int base = 0, top = size;
while(base <= top){
	int mid = (base + top) / 2;
	if(buf[mid] <= target)
		base = mid + 1;
	else
		top = mid - 1;
}

int ans = top;