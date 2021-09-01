#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N];
int b[N];
int idx = 0;
int n;

void inorder(int x){
    if(x > n)
        return;
    if(2*x <= n) inorder(2*x);
    b[x] = a[idx++];
    if(2*x + 1 <= n) inorder(2*x + 1);
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    inorder(1);
    
    for(int j = 1;j <= n;j++)
        cout << b[j] << " ";
    
    return 0;
}
