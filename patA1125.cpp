// 好像直接快排 ，用a[0] 做贪心就可以了。。。
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 10010;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
        pq.push(a[i]);
    }
    
    while(pq.size() > 1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        pq.push((num1 + num2)/2);
    }
    printf("%d", pq.top());
    return 0;
}
