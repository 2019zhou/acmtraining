#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2505;
vector<string> lesson[N];

int main(){
    int n, k;
    cin >> n >> k;
    string tmp;
    int num;
    int tt;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        cin >> num;
        while(num--){
            cin >> tt;
            lesson[tt].push_back(tmp);
        }
    }
    
    for(int i = 1;i <= k;i++){
        sort(lesson[i].begin(), lesson[i].end());
        printf("%d %d\n", i, lesson[i].size());
        for(int j = 0;j < lesson[i].size();j++){
            printf("%.4s\n", lesson[i][j].c_str()); 
        }
    }
    
    return 0;
}
