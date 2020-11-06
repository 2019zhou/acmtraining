// important template for pat 
// 排序
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct Student{
	string id;//准考证号
	int score;	// 分数
	int r;		// 排名, 考场内排名
	int location; // 考场号就是K
}stu[30010];


bool cmp(Student a, Student b){
	if(a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}


int main(){
	//freopen("input.txt", "r", stdin);
	int N;
	int K;
	int num = 0; // 总考生数
	cin >> N;
	for(int location = 1;location <= N;location++){
		cin >> K;
		for(int i  = 0;i < K;i++){
			cin >> stu[num].id;
			cin >> stu[num].score;
			stu[num].location = location;
			num++;
		}
		sort(stu + num - K, stu + num, cmp);
		stu[num-K].r = 1;
		for(int i = num - K + 1;i < num;i++){
			if(stu[i].score == stu[i-1].score)
				stu[i].r = stu[i-1].r;
			else
				stu[i].r = i-(num - K) + 1;
		}
	}

	sort(stu, stu + num, cmp);
	cout << num << endl;
	int finalRank = 1;
	for(int i = 0;i < num;i++){
		if(i>0 && stu[i].score == stu[i - 1].score){
			cout << stu[i].id << ends;
			cout << finalRank << ends;
			cout << stu[i].location  <<ends;
			cout << stu[i].r << ends;
			cout << endl;
		}else{
			finalRank = i + 1;
			cout << stu[i].id << ends;
			cout << finalRank << ends;
			cout << stu[i].location << ends;
			cout << stu[i].r << ends;
			cout << endl;
		}

	}
	return 0;
}

// 最后提交的时候出错了
// 主要原因是pat的OJ系统不接受 cout << ends这样的结果，如果需要输出使用 cout <<" ",以及行末注意使用cout << endl;而不是 cout << " "