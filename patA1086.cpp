// 终于能快点写树木的题目了
#include <iostream>
#include <stack>
using namespace std;
int n;

const int N = 30;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
    }
};


void postorder(node * root){
    if(!root)
        return;
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    cout << root->val << " ";
}

int main(){
    cin >> n;
    string op;
    int x;
    stack<node *> st;
    cin >> op;
    node * root;
    node * p;
    if(op == "Push"){
        cin >> x;
        root = new node(x);
        p = root;
        st.push(root);
        for(int i = 1;i < 2 * n;i++){
            cin >> op;
            if(op == "Push"){
                cin >> x;
                node * tmp = new node(x);
                st.push(tmp);
                if(p->left == NULL){
                    p->left = tmp;
                    p = p->left;
                }else{
                    p->right = tmp;
                    p = p->right;
                }
            }else{
                p = st.top();
                st.pop();
            }
        }
    }
    postorder(root);
    
    return 0;
}
