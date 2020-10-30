#include <iostream>
#include <string>
using namespace std;

int main(){
	int N;
	string young;
	cin >> N;
	int maxyear = -1, maxmonth = -1, maxday = -1;
	int minyear = 2020, minmonth = 13, minday = 30;
	string old;
	int tempyear;
	int tempmonth;
	int tempday;
	int curname;
	int validate = 0;
	while(N--){
		string name;
		cin >> name;
		scanf("%d/%d/%d", &tempyear, &tempmonth, &tempday);
		//cout << tempyear << tempmonth << tempday << endl;
		if(tempyear < 1814 ||(tempyear == 1814 && tempmonth < 9) || (tempyear == 1814 && tempmonth == 9 && tempday < 6))
			continue;
		if(tempyear > 2014 || (tempyear == 2014 && tempmonth >9 )||(tempyear == 2014 && tempmonth == 9 && tempday >6))
			continue;

		if(maxyear  < tempyear ||(maxyear == tempyear && maxmonth < tempmonth) || (maxyear == tempyear && maxmonth == tempmonth && maxday < tempday)){
			maxyear = tempyear;
			maxmonth = tempmonth;
			maxday = tempday;
			old = name;
		}
		if(minyear > tempyear || (minyear == tempyear && minmonth > tempmonth) || (minyear == tempmonth && minmonth == tempmonth && minday > tempday)){
			minyear = tempyear;
			minmonth = tempmonth;
			minday = tempday;
			young = name;
		}
		validate++;
	}

	cout << validate << ends << young << ends << old << endl;

	return 0;
}

// 这里的测试点非常神奇，就是使用cout << ends会出现错误，只能使用 cout << " "
// 然后if else if的逻辑不对，一个人 可能既为最大候选又为最小候选