#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N];


int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    int sum = 0;
    int sum1 = 0;
    for(int i = 0;i < n;i++){
        sum += a[i];
        if(i == n/2 - 1){
            sum1 = sum;
        }
    }
    
    
    if(n%2 == 0){
        cout << 0 << " " << sum - sum1 - sum1 <<endl;
    }else{
        cout << 1 << " " << sum - sum1 - sum1 << endl;
    }
    
    
    return 0;
}
