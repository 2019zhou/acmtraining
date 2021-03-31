// 数字三角形
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const in N = 510;
int n;
int w[N][N];
int f[N][N];

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < i;j++)
			cin >> w[i][j];
	}

	// 初始化
	for(int i = 0;i < n;i++)
		f[n][i] = w[n][i];
	for(int i = n - 1;i;i--){
		for(int j = 1;j < = i;j++){
			f[i][j] = max(f[i + 1][j] + w[i][j], f[i + 1][j+1]+w[i][j])

		}
	}
	cout << f[i][j] << endl;
	return 0;
}

// f数组和w数组可以合二为一
