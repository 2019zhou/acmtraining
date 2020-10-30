#include <iostream>
#include <map>
using namespace std;

int main(){
	string N;
	cin >> N;
	map<int, int> mp;

	for(auto ch:N){
		mp[ch-'0']++;
	}

	for(auto iter= mp.begin(); iter!=mp.end();iter++){
		cout << iter->first << ":";
		cout << iter->second << endl;
	}
	return 0;
}