// 货仓选址, 使得X取到中位数 n log n 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;
int a[N];

int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a, a + n);
	int res = 0;
	for(int i = 0;i < n;i++){
	    res += abs(a[i] - a[n / 2]);
	    cout << res << endl;
	}
		

	cout << res << endl;
	return 0;
}
// 相关题目: 以为扩展成二维, 星星还是树
// 扩展到D维, 需要用蚂蚁退火算法

// 可以不排序
// 记得要用g++, 开始连这个都忘记了

// 用nth_element o(n)
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;
int a[N];

int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	int k = nth_element(a, a + n/2,  a + n); // nth_element, a, a + n 头尾， 要取的数字 a + n / 2
	int res = 0;
	for(int i = 0;i < n;i++){
	    res += abs(a[i] - a[n / 2]);
	    cout << res << endl;
	}
		

	cout << res << endl;
	return 0;
}

