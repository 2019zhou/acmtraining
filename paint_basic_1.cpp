#include <iostream>
using namespace std;

const int N = 100;
int a[100][100];

int main(){
	int n, m;
	cin >> n >> m;
	int t = 1;
	int k = min(n / 2 + 1, m / 2 + 1);
	for(int i = 0;i < k;i++){
		for(int j = i;j < m - i;j++){
			//cout << i << ends << j << endl;
			if(a[i][j] != 0) 
				break;
			a[i][j] = t;
			t += 1;
		}
		for(int j = i + 1;j < n - i - 1;j++){
			//cout << j << ends << m - i << endl;
			if(a[j][m - i - 1] != 0) 
				break;
			a[j][m - i - 1] = t;
			t += 1;
		}
		for(int j = m - i - 1;j >= i;j--){
			///cout << n - i - 1<< ends << j << endl;
			if(a[n - i - 1][j] != 0) 
				break;
			a[n - i - 1][j] = t;
			t += 1;
		}
		for(int j = n - i - 2;j > i;j--){
		//	cout << j << ends << i << endl;
		    if(a[j][i] != 0) 
				break;
			a[j][i] = t;
			t += 1;
		}
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
		    if(j == m - 1)
		        cout << a[i][j];
			else{
			    cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}


	return 0;
}

// 网格题目 技巧
// (x, y - 1) ,  (x, y), (x, y + 1), (x + 1, y), (x - 1, y)
// 1020
// 记录各个方向的偏移量

// (x', y') = (x,)
// 0 -> 1, 1 --> 2, 2 --> 3, 3 --> 0, d -->  (d + 1)%4
// 重复, 

#include <iostream>
using namespace std;
const int N = 110;
int n, m;
int q[N][N];


int main(){
	cin >> n >> m;
	int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	int x = 0, y = 0, d = 1;
	for(int i = 1;i <= n * m;i++){
		q[x][y] = i;
		int a = x + dx[d], b = y + dy[d];
		if(a < 0 || a >= n || b < 0 || b >= m || q[a][b]){
			d =(d + 1)%4;
			a = x + dx[d];
			b = y + dy[d];
		}
		x = a, y = b;
	}
		for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
		    if(j == m - 1)
		        cout << q[i][j];
			else{
			    cout << q[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
