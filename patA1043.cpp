//Is it a binary Search Tree

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct node{
	int data;
	node* right;
	node* left;
};

void insert(node* & root, int data){
	if(root == NULL){ // 在这里插入
		root = new node;
		root->data = data;
		root->right = NULL;
		root->left = NULL;
		return;
	}
	if(root->data > data){
		insert(root->left, data);
	}else{
		insert(root->right, data);
	}
}


void preOrder(node* root, vector<int>& vp){
	if(root == NULL)
		return;
	vp.push_back(root->data);
	preOrder(root->left, vp);
	preOrder(root->right, vp);
}


void preOrderMirror(node * root, vector<int> & vp){
	if(root == NULL) return;
	vp.push_back(root->data);
	preOrderMirror(root->right, vp);
	preOrderMirror(root->left, vp);
}

void postOrder(node * root, vector<int>& vp){
	if(root == NULL) return;
	postOrder(root->left, vp);
	postOrder(root->right, vp);
	vp.push_back(root->data);
}

void postOrderMirror(node * root, vector<int>& vp){
	if(root == NULL) return;
	postOrderMirror(root->right, vp);
	postOrderMirror(root->left, vp);
	vp.push_back(root->data);
}


vector<int> origin, pre, preM, post, postM;

int main(){
	int n, data;
	node * root = NULL;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}

	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);

	// for test
	for(int i = 0;i < origin.size();i++){
		printf("%d ", origin[i]);
	}
	cout << endl;
	for(int i = 0;i < pre.size();i++){
		printf("%d ", pre[i]);
	}
	cout << endl;


	if(origin == pre){
		printf("YES\n");
		for(int i = 0;i < post.size();i++){
			printf("%d", post[i]);
			if(i < post.size() - 1) printf(" ");
		}
	}else if(origin == preM){
		printf("YES\n");
		for(int j = 0; j < postM.size();j++){
			printf("%d", postM[j]);
			if(j < postM.size() - 1) printf(" ");
		}
	}else{
		printf("NO\n");
	}

	return 0;
}