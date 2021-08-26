// 扩展版本的公共子序列
//  ori(1 - i) , f(1 - j), 所有公共子序列的集合
// 长度最大值
// 分为四种情况, 不含ori(i), f(i)
// 含ori(i), 不含f(i)
// 不含ori(i), 含f(i)
// 含ori(i), f(i);
#include <iostream>
using namespace std;

int f[205];
int ori[10010];
int dp[205][10010];

int main(){
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ){
        cin >> f[i];
    }
    int l;
    cin >> l;
    for(int i = 1;i <= l;i++){
        cin >> ori[i];
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= l;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(f[i] == ori[j]) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    
    cout << dp[m][l] << endl;
    return 0;
}
