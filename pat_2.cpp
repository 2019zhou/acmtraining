// 反转链表写的也不容易
// 1. 像reverse这样的函数需要#include <algorithm> 文件导入
// 2. 注意vector push_back结构体的写法
// 3. printf对于精确结果输出的控制太好用了
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Node {
    int address;
    int data;
};
 
 
int main() {
    vector<Node> ls;
    int FirstAddress;
    int N;
    int K;
    cin >> FirstAddress >> N >> K;
 
    int address[100000] = { 0 };
    int value[100000] = { 0 };
    for (int i = 0; i < N; i++) {
        int CurAddress;
        int CurData;
        int CurNext;
        cin >> CurAddress >> CurData >> CurNext;
        address[CurAddress] = CurNext;
        value[CurAddress] = CurData;
    }
 
    int cur = FirstAddress;
 
    while (address[cur] != -1) {
        Node temp;
        temp.address = cur;
        temp.data = value[cur];
        ls.push_back(temp);
        cur = address[cur];
    }
 
    Node temp;
    temp.address = cur;
    temp.data = value[cur];
    ls.push_back(temp);
 
    int cnk = ls.size() / K;
    auto iter = ls.begin();
    for (int i = 0; i < cnk; i++) {
        reverse(iter, iter + K);
        iter += K;
    }
 
    //打印结果
    for (int i = 0; i < (int)ls.size(); i++) {
        if (i != (int)ls.size() - 1)
            printf("%05d %d %05d\n", ls[i].address, ls[i].data, ls[i + 1].address);
        else
            printf("%05d %d -1\n", ls[i].address, ls[i].data);
    }
 
    return 0;
}