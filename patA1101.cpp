// 如果一个数i之前的数都小于它本身，之后的数都大于它本身，那这个数排序后应在原位——但是结论不一定能反推定义
// 假设排序后的数组[1 2 3 4 5]，随机打乱后的顺序是[1 4 3 2 5]，按照pivot的定义，应只有1和5才是。
// 所有的格式错误都是没有换行导致的错误


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int input[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >>  input[i];
    }
    vector<int> vp(input, input + n);
    sort(vp.begin(), vp.begin() + n);
    vector<int> ans;
    int cnt = 0;
    int maxnum = -1;
    for(int i = 0;i < n;i++){
        if(input[i] == vp[i] && maxnum < input[i]){
            cnt++;
            ans.push_back(vp[i]);
            maxnum = max(input[i], maxnum);
        }
    }
    cout << cnt << endl;
    
    for(int i = 0;i < ans.size();i++){
        if(i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << endl;
    
    return 0;
}

// right answer
// 非常注意其实就是多了一行maxnum的代码, 相当于巧妙的保存了这个数字之前的所有数字

