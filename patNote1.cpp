// 数学部分
// 最大公约数 欧几里得算法
// gcd(a, b) = gcd(b, a%b)
// 递归边界 gcd(a, 0) = a

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

// 记最大公约数是d, 最小公倍数是 a/d * b
// 这样写不容易溢出


// 分数的化简
// 如果分母 < 0 全部取反
// up = 0, down = 1
// 除去最大公约数

struct Fraction{
	int up;
	int down;
};

Fraction redution(Fraction result){
	if(result.down < 0){
		result.up = -result.up;
		result.down = - result.down;
	}
	if(result.up == 0)
		result.down = 1;
	else{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}


// 求素数
// 注意点
// 1. 1不是素数
// 2. 素数表至少要比n大1
// 3. 在Find_Prime()函数中要特别留意 i < maxn 而不是 i <= maxn

//筛法
#include <stdio.h>
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] ={0};
void Find_Prime(int n){
	for(int i = 0;i < maxn;i++){
		if(p[i] == false){
		prime[num++] = i;
		if(num > n) break;
		for(j = i + 1;j < maxn;j += i)
			p[j] = true;
		}
	}
}

int main(){
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	Find_Prime(n);
	for(int i = m;i <= n;i++){
		printf("%d", prime[i -1]);
		count ++;
		if(count %10 == 0 && i < n) printf(" ");
		else printf("\n");
	}
}