// 测时间

#include <iostream>
#include <string>
using namespace std;

string minus_string(string C1, string C2){
	int len_C1 = C1.size();
	int len_C2 = C2.size();
	string res;
	for(int j = len_C1 -1, k = len_C2 - 1; j >= 0 && k >= 0; j--, k--){
		if(C1[j] - C2[k] >= 0) res.insert(res.begin(), C1[j] - C2[k]);
		else{
			res.insert(res.begin(), 10 + C1[j] - C2[k]);
			C1[j-1] -= 1;
		}
	}
	return res;
}


string process_hour(string C){
	
}


string process_minute(string C){

}


string process_second(string C){



}


int main(){
	int hour;
	int minute;
	int second;
	const int CLK_TCK = 100;

	string C1, C2;
	cin >> C1 >> C2;

	string C3;
	C3 = minus_string(C1, C2);



	printf("%02d:%02d:%02d", hour, minute, second);
	return 0;
}