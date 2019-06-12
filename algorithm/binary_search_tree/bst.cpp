#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct BSTNode{
	int val;
	BSTNode *parent;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x):val(x), parent(NULL), left(NULL), right(NULL) {}
};

BSTNode* search_node(BSTNode *Root, int x){
	if (Root == NULL || Root->val == x)
		return Root;
	if (x < Root->val)
		Root = search_node(Root->left, x);
	else
		Root = search_node(Root->right, x);
	return Root;
}

BSTNode* iterative_search_node(BSTNode *Root, int x){
	while (Root != NULL && Root->val != x){
		if (x < Root->val)
			Root = Root->left;
		else
			Root = Root->right;
	}
	return Root;
}

BSTNode* insert_node(BSTNode *Root, int x){
	BSTNode *node = Root;
	BSTNode* temp = NULL;
	while (node != NULL){
		temp = node;
		if (x < node->val)
			node = node->left;
		else
			node = node->right;
	}
	BSTNode* newNode = new BSTNode(x);
	newNode->parent = temp;	
	if (temp == NULL)
		Root = newNode;
	else if (newNode->val < temp->val)
		temp->left = newNode;
	else
		temp->right = newNode;
	return Root;
}

BSTNode* minimum_node(BSTNode *Root){
	if (Root == NULL)
		return NULL;
	while (Root->left)
		Root = Root->left;
	return Root;
}

BSTNode* maximum_node(BSTNode *Root){
	if (Root == NULL)
		return NULL;
	while (Root->right)
		Root = Root->right;
	return Root;
}

BSTNode* successor(BSTNode *node){
	if (node->right != NULL)
		return minimum_node(node->right);
	BSTNode *temp = node->parent;
	while (temp != NULL && node == temp->right){
		node = temp;
		temp = temp->parent;
	}
	return temp;
}

/* 用一个棵以n2为根的子树来替换一课以n1为根的子树*/
void TRANSPLANT(BSTNode *&Root, BSTNode *n1, BSTNode *n2){
	if (n1->parent == NULL)
		Root = n2;
	else if (n1 == n1->parent->left)
		n1->parent->left = n2;
	else
		n1->parent->right = n2;
	if (n2 != NULL)
		n2->parent = n1->parent;
}

BSTNode* delete_node(BSTNode *Root, int x){
	BSTNode *node = search_node(Root, x);
	if (node == NULL){
		return Root;
	}
	if (node->left == NULL){
		TRANSPLANT(Root, node, node->right);
	}
	else if (node->right == NULL){
		TRANSPLANT(Root, node, node->left);
	}
	else{
		BSTNode *succ = minimum_node(node->right);
		if (succ->parent != node){
			TRANSPLANT(Root, succ, succ->right);
			succ->right = node->right;
			succ->right->parent = succ;
		}
		TRANSPLANT(Root, node, succ);
		succ->left = node->left;
		succ->left->parent = succ;
	}
	return Root;
}

BSTNode* build_tree(vector<int> &nums){
	if (nums.empty())
		return NULL;

	BSTNode *root = NULL;
	for (size_t i = 0; i < nums.size(); i++){
		root = insert_node(root, nums[i]);
	}
	return root;
}

void inOrder(BSTNode *Root){
	if (Root != NULL){
		inOrder(Root->left);
		cout << Root->val << " ";
		inOrder(Root->right);
	}
}

void iterative_inOrder(BSTNode *Root){
	if (Root == NULL)
		return ;
	BSTNode *node = Root;
	stack<BSTNode*> Stack;
	while (node != NULL || !Stack.empty()){
		while (node != NULL){
			Stack.push(node);
			node = node->left;
		}
		BSTNode *temp = Stack.top();
		Stack.pop();
		cout << temp->val << " ";
		node = temp->right;
	}
}

void preOrder(BSTNode *Root){
	if (Root != NULL){
		cout << Root->val << " ";
		preOrder(Root->left);
		preOrder(Root->right);
	}
}

void iterative_preOrder(BSTNode *Root){
	if (Root == NULL)
		return ;
	BSTNode *node = Root;
	stack<BSTNode*> Stack;
	while (node != NULL || !Stack.empty()){
		while (node != NULL){
			cout << node->val << " ";
			Stack.push(node);
			node = node->left;
		}
		BSTNode *temp = Stack.top();
		Stack.pop();
		node = temp->right;
	}
}

void postOrder(BSTNode *Root){
	if (Root != NULL){
		postOrder(Root->left);
		postOrder(Root->right);
		cout << Root->val << " ";
	}
}

void iterative_postOrder(BSTNode *Root){
	if (Root == NULL)
		return ;
	stack<BSTNode*> Stack;
	BSTNode *cur = Root;
	BSTNode *pre = NULL;
	while (cur){
		Stack.push(cur);
		cur = cur->left;
	}
	while (!Stack.empty()){
		cur = Stack.top();
		if (cur->right == NULL || cur->right == pre){
			Stack.pop();
			cout << cur->val << " ";
			pre = cur;
		}
		else{
			cur = cur->right;
			while (cur){
				Stack.push(cur);
				cur = cur->left;
			}
		}
	}
}

int main(){
	int arr[] = {12, 5, 18, 2, 9, 15, 19, 17};
	vector<int> nums(arr, arr+8);

	BSTNode* root = build_tree(nums);
	inOrder(root);
	cout << endl;
	//iterative_inOrder(root);
	//cout << endl;
	//preOrder(root);
	//cout << endl;
	//iterative_preOrder(root);
	//cout << endl;
	//postOrder(root);
	//cout << endl;
	//iterative_postOrder(root);
	//cout << endl;

	insert_node(root, 7);
	inOrder(root);
	cout << endl;

	root = delete_node(root, 5);
	inOrder(root);
	cout << endl;
	root = delete_node(root, 15);
	inOrder(root);
	cout << endl;
	root = delete_node(root, 12);
	inOrder(root);
	cout << endl;
}
