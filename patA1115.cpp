// root一定要初始化为null
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;


struct ListNode{
    int val;
    ListNode * left;
    ListNode * right;
    ListNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

ListNode * insert(ListNode * root, int x){
    if(root == NULL){
        root = new ListNode(x);
        return root;
    }
    if(root->val > x){
        root->right = insert(root->right, x);
    }else{
        root->left = insert(root->left, x);
    }
    return root;
}

int dfs(ListNode * root){
    if(root == NULL)
        return 0;
    int t = 0;
    if(root->left != NULL){
        t = dfs(root->left) + 1;
    }
    if(root->right != NULL){
        t = max(t, dfs(root->right) + 1);
    }
    return t;
}

int main(){
    int n;
    cin >> n;
    int tmp;
    ListNode * root = nullptr;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        root = insert(root, tmp);
    }
    
    
    int depth = dfs(root);
    // cout << depth << endl;
    
    queue<ListNode* > q;
    // queue<ListNode* > q;
    q.push(root);
    //int ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while(q.size()){
        depth--;
        int sz = q.size();
        for(int i = 0;i < sz;i++){
            ListNode * t = q.front();
            //cout << t->val << endl;
            if(depth == 1) cnt1++;
            if(depth == 0) cnt2++;
            q.pop();
            if(t->left!= NULL) q.push(t->left);
            if(t->right != NULL) q.push(t->right);
        }
    }
    
    printf("%d + %d = %d", cnt1, cnt2, cnt1 + cnt2);
    
    
    
}
