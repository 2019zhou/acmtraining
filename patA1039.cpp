// unordered_map 中的string与 vector<int> 的映射方式
// 用char []   数据做，会输出不了vector<int> 中的内容，所以只能用string
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


unordered_map<string, vector<int>> st;


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int ci, cn;
    string s;
    for(int i = 0;i < k;i++){
        cin >> ci >> cn;
        while(cn--){
            cin >> s;
            st[s].push_back(ci);
        }
    }
    

    for(int i = 0;i < n;i++){
        cin >> s;
        printf("%.4s %d", s.c_str(), st[s].size());
        sort(st[s].begin(), st[s].end());
        //cout << st[s][0] << endl;
        for(int j = 0;j < st[s].size();j++){
            printf(" %d", st[s][j]);
        }
        printf("\n");
    }

    return 0;
}
