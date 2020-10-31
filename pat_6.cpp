// 测时间
// 积累一下四舍五入一般是使用函数round

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int hour;
	int minute;
	int second;
	const int CLK_TCK = 100;

	string C1, C2;
	cin >> C1 >> C2;

	int diff = stoi(C2) - stoi(C1);
	
	hour = diff/360000;
	minute = (diff - hour*360000)/6000;
	second = round((diff - hour*360000 - minute*6000)/(double)100);


	printf("%02d:%02d:%02d", hour, minute, second);
	return 0;
}