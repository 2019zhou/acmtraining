// patA1146就是写一个正常拓扑排序
// patA1146就是写一个正常拓扑排序
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXV = 1005;

vector<int> G[MAXV];
int n, m, inDegree[MAXV];

int main(){
	//freopen("C:\\Users\\hhh\\Desktop\\in.txt","r",stdin);
	cin >> n >> m;
	int start, end;
	for(int i = 0;i < m;i++){
		cin >> start >> end;
		G[start].push_back(end);
		inDegree[end]++;
	}

	int k;
	int cur;
	vector<int> ans;
	cin >> k;
    int flag = 0;
	for(int i = 0;i < k;i++){
            flag = 0;
			vector<int> tin(inDegree, inDegree+MAXV);
		for(int j = 0;j < n;j++){
			cin >> cur;
			//printf("%d\n", inDegree[cur]);
			if(tin[cur]!= 0){
				flag = 1;
			}
			for(int index = 0; index < G[cur].size();index++){
				int des = G[cur][index];
				tin[des]--;
			}
		}
        if(flag == 1)
            ans.push_back(i);
	}

	for(int i = 0;i < ans.size();i++){
		cout << ans[i];
		if(i != ans.size() -1) cout << " ";
	}


	return 0;
}

// 有一个非常坑的地方，就是开始写的时候就直接看到一个inDegree != 0 就直接break了
// 这样造成的结果是可能会造成后面的几个数都没有读入，所以必须继续continue读完后面输入的数据。