#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
//get新技能, 正常的数组也可以使用find, find的最后一个参数是要查询的值
// 写了老半天，还有段错误, 上面说明递归调用太多,,就
// 写代码过程中最犯的错误其实是题目没有看清楚，m,n各自代表什么还是非常注意

int pre[1005];
int in[1005];

struct node {
	int data;
	int layer;
	node* lchild;
	node* rchild;
	node* father;
};

// preL, preR对应于先序遍历的left 和 right
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k = -1;
	for (k = inL; k <= inR; k++) {
		if (in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	if(root->lchild != NULL)
		root->lchild->father = root;
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	if(root->rchild != NULL)
		root->rchild->father = root;

	return root;
}

node* findTr(int u, node* root) {
	queue<node*> q;
	node* ans = NULL;
	q.push(root);
	root->layer = 1;
	while (!q.empty()) {
		node* cur = q.front();
		if (cur->data == u)
			ans = cur;
// 		if(ans != NULL)
// 			printf("ans->data  %d  cur->data\n", ans->data, cur->data);
		q.pop();
		if (cur->lchild != NULL) {
			cur->lchild->layer = cur->layer + 1;
			q.push(cur->lchild);
		}
		if (cur->rchild != NULL) {
			cur->rchild->layer = cur->layer + 1;
			q.push(cur->rchild);
		}
	}
	return ans;
}



int main() {
	int m, n;
	scanf("%d%d", &m, &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	// 从中序和先序遍历中建树
	node* root = create(0, n - 1, 0, n - 1);

	// 对树进行层次遍历


	int u = -1, v = -1;
	for (int j = 0; j < m; j++) {
		node* unode;
		node* vnode;
		scanf("%d%d", &u, &v);
		unode = findTr(u, root);
		vnode = findTr(v, root);
		if (unode == NULL and vnode == NULL) {
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}
		if (unode == NULL and vnode != NULL) {
			printf("ERROR: %d is not found.\n", u);
			continue;
		}
		if (unode != NULL and vnode == NULL) {
			printf("ERROR: %d is not found.\n", v);
			continue;
		}
		// 使用BFS进行搜索
		node* finalans = root;
		while (true) {
			while (unode->layer > vnode->layer) {
				unode = unode->father;
			}
			while (vnode->layer > unode->layer) {
				vnode = vnode->father;
			}
			if (unode->data == vnode->data) {
				finalans = unode;
				break;
			}
			else {
				unode = unode->father;
				vnode = vnode->father;
			}
		}
		if (finalans->data == u) {
			printf("%d is an ancestor of %d.\n", u, v);
		}
		else if (finalans->data == v) {
			printf("%d is an ancestor of %d.\n", v, u);
		}
		else {
			printf("LCA of %d and %d is %d.\n", u, v, finalans->data);
		}
	}


	return 0;
}