#include <iostream>
#include <string>
using namespace std;


//{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}

int main() {
	int N;
	cin >> N;
	char M[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	bool sign = 0;
	int tempsum = 0;
	int cnt = 0;
	for (int j = 0; j < N; j++) {
		string temp;
		cin >> temp;
		tempsum = 0;
		sign = 0;
		for (int i = 0; i < 17; i++) {
			if (!isdigit(temp[i])) {
				sign = 1;
				break;
			}
			tempsum += weight[i] * (temp[i] - '0');
		}
		tempsum = tempsum % 11;
		//cout << M[tempsum] << ends << temp[17] << endl;
		if (M[tempsum] != temp[17])
			sign = 1;
		if (sign == 1)
			cout << temp << endl;
		else
			cnt++;
	}
	if (cnt == N)
		cout << "All passed";

	return 0;
}

// 开始主要存在的问题是isdigit函数不会用 isdigit是看一个字符isdigit(char)
// 还有一会是取模11的题目没有看到