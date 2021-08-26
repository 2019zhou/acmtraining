// 奇奇怪怪的边界
//   if(n > 1)
//        ans.push_back({n, 1});
// 开始忘记了呜呜呜
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

vector<PII> ans;
int n;

void ctt(){
    int cnt = 0;
    for(int i = 2;i <= n/i;i++){
        cnt = 0;
        while(n%i == 0){
            n = n/i;
            cnt++;
        }
        if(cnt)
            ans.push_back({i, cnt});
    }
    if(n > 1)
        ans.push_back({n, 1});
}

int main(){
    cin >> n;
    int oldn = n; 
    if(n == 1){
        cout << "1=1" << endl;
    }else{
        ctt();
        printf("%d=", oldn);
        for(int i = 0;i < ans.size() -1;i++){
            if(ans[i].second != 1)
                printf("%d\^%d*",ans[i].first, ans[i].second);
            else
                printf("%d*",ans[i].first);
        }
        int po = ans.size() -1 ;
        if(ans[po].second != 1)
            printf("%d\^%d",ans[po].first, ans[po].second);
        else
            printf("%d",ans[po].first);
        return 0;
    }
    
}
