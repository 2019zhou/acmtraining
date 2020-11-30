// 还是要仔细一点，第一次交的时候，string.size()没有判断就直接return string了
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string decimalTo13(int a){
	string ans;
	int temp;
	while(a!= 0){
		temp = a%13;
		a = a/13;
		if(temp < 10)
			ans.insert(ans.begin(), temp + '0');
		else 
			ans.insert(ans.begin(), temp-10 + 'A');
	}
	while(ans.size() < 2){
		ans.insert(ans.begin(), '0');
	}
	return ans;
}



int main(){
	int red, green, blue;
	cin >> red >> green >> blue;


	cout << "#" << decimalTo13(red) << decimalTo13(green) << decimalTo13(blue);

	return 0;
}
