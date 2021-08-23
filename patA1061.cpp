// 注意中间的那个break
#include <iostream>
using namespace std;

int main(){
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    //cout << a << endl << b << endl << c << endl << d <<endl;
    int day = -1;
    int hour = -1;
    int minute = -1;
    string week[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int cnt = 0;
    for(int i = 0;i < a.size()&& i < b.size();i++){
        if(!cnt && a[i] >= 'A' && a[i] <= 'A' + 7 && a[i] == b[i]){
            day = a[i] - 'A';
            cnt = 1;
        }else if(cnt && a[i] == b[i] && (isdigit(a[i]) or ( a[i] >= 'A' && a[i] <= 'N'))){
            if(isdigit(a[i]))
                hour = a[i] - '0';
            else
                hour = a[i] - 'A' + 10;
            break;
        }
    }
    
    for(int i = 0;i < c.size() && i < d.size();i++){
        if(isalpha(c[i]) && c[i] == d[i]){
            minute = i;
        }
    }
    
    cout << week[day] << " ";
    printf("%.2d:%.2d",hour, minute);
    return 0;
}
