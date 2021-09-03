// 开始的低级错误忘记读入有几位数了
#include <iostream>
using namespace std;

const int N = 105;
bool w1[N];
int w2[N];

int main(){
    int n;
    cin >> n;
    string words;
    int tmp = 0;
    for(int i = 1;i <= n;i++){
        cin >> words;
        w1[i] = words[0] == '+'? false:true;
        tmp = 0;
        for(int j = 1;j < words.size();j++){
            tmp = tmp * 10 + words[j] - '0';
        }
        w2[i] = tmp;
    }
    int cnt = 0;
    int lie1 = -1;
    int lie2 = -1;
    int sign = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            cnt = 0;
            lie1 = -1;
            lie2 = -1;
            for(int k = 1;k <= n;k++){
                if(w1[k] == true){
                    if(!(w2[k] == i or w2[k] == j)){
                        cnt++;
                        if(lie1 == -1){
                            lie1 = k;
                        }else if(lie2 == -1){
                            lie2 = k;
                        }
                    }
                }
                if(w1[k] == false && (w2[k] == i or w2[k] == j)){
                    cnt++;
                    if(lie1 == -1){
                        lie1 = k;
                    }else if(lie2 == -1){
                        lie2 = k;
                    }
                }
            }
            //if(cnt !=2 ) continue;
            int cnt2 = 0;
            if(lie1 == i or lie2 == i){
                cnt2++;
            }
            if(lie1 == j or lie2 == j){
                cnt2++;
            }
            if(cnt == 2 && cnt2 == 1){
                cout << i << " "<< j << endl;
                sign = 1;
                break;
            }
        }
        if(sign == 1){
            break;
        }
    }
    if(sign == 0){
        cout << "No Solution";
    }
    
    return 0;
}
