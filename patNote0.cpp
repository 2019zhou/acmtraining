//pat 二分复习
typedef long long LL;

LL binaryPow(LL a, LL b, LL m){
	if(b == 0) return 1;
	if(b%2 == 1) return a * binaryPow(a, b - 1, m)%m;
	else{
		LL mul = binaryPow(a, b/2, m);
		return mul * mul %m;
	}
}


// 快速幂的迭代写法

typedef long long LL;

LL binaryPow(LL a, LL b, LL m){
	LL ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}


// two pointers
// 求序列中两个不同位置的数a和b 使他们的和恰好为M
while(i < j){
	if(a[i] + a[j] == m){
		printf("%d %d\n", i, j);
		i++;
		j--;
	}else if(a[i] + a[j] < m){
		i++;
	}else{
		j--;
	}
}

