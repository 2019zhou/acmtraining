#include <iostream>
#include <algorithm>
using namespace std;


struct tim{
	int shh;
	int smm;
	int sss;
	int ehh;
	int emm;
	int ess;
};

const int N = 2010;
tim times[N];

bool cmp(tim a, tim b){
	if(a.shh != b.shh)
		return a.shh < b.shh;
	if(a.smm != b.smm)
		return a.smm < b.smm;
	if(a.sss != b.sss)
		return a.sss < b.sss;
	return a.sss < b.sss;
}



bool check1(int i, int j){
	if(times[i].ehh != times[j].ehh)
		return times[i].ehh < times[j].ehh;
	else if(times[i].emm != times[j].emm)
		return times[i].emm < times[j].emm;
	else{
		return times[i].ess < times[j].ess;
	}
}

bool check2(int i, int j){
	if(times[i].shh != times[j].ehh)
		return times[i].shh > times[j].ehh;
	else if(times[i].smm != times[j].emm)
		return times[i].smm > times[j].emm;
	else{
		return times[i].sss >= times[j].ess;
	}
}

void print(tim a){
	printf("%d:%d:%d %d:%d:%d", a.shh,a.smm,a.sss,a.ehh, a.emm,a.ess);
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d:%d:%d %d:%d:%d\n", &times[i].shh,&times[i].smm,&times[i].sss,&times[i].ehh, &times[i].emm,&times[i].ess);
	}

	sort(times, times + n, cmp);
	// for(int i = 0;i < n;i++)
	// 	print(times[i]);

	int cur = 0;
	int ans = 1;
	for(int i = 1;i < n;i++){
		if(check1(i, cur)){
			cur = i;
		}else if(check2(i, cur)){ // i start > cur end
			cur = i;
			ans ++;
			//print(times[i]);
		}
	}

	cout << ans << endl;


	return 0;
}
