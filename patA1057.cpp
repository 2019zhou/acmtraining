// 这个分块查找的思路应该也适用于查找第k大的元素
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 100010;
const int sqrn = 316;

stack<int> st;
int block[sqrn];
int table[maxn];

void peekMedian(int K){
	int sum = 0;  //当前累计存在数的个数
	int idx = 0;
	while(sum + block[idx] < K){
		sum += block[idx++];
	}
	int num = idx * sqrn;
	while(sum + table[num] < K){
		sum += table[num++];
	}
	printf("%d\n", num);
}

void Push(int x){
	st.push(x);
	block[x / sqrn] ++;
	table[x]++;
}

void Pop(){
	int x = st.top();
	st.pop();
	block[x / sqrn]--;
	table[x]--;
	printf("%d\n", x);
}

int main(){
	int x, query;
	memset(block, 0, sizeof(block));
	memset(table, 0, sizeof(table));
	string command;
	cin >> query;
	for(int i = 0;i < query ;i++){
		cin >> command;
		if(command == "Push"){
			scanf("%d", &x);
			Push(x);
		}
		if(command == "Pop"){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				Pop();
			}
		}
		if(command == "PeekMedian"){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				int K = st.size();
				if(K%2 == 0) K = K/2;
				else K = (K + 1)/2;
				peekMedian(K);
			}
		}
	}


	return 0;
}