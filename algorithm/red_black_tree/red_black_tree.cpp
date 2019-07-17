#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define RED "red"
#define BLACK "black"

struct RBNode{
	int val;
	string color;
	RBNode *parent;
	RBNode *left;
	RBNode *right;
	RBNode(int x):val(x), color(RED), parent(NULL), left(NULL), right(NULL) {}
};

RBNode* LEFT_ROTATE(RBNode *root, RBNode *node);
RBNode* RIGHT_ROTATE(RBNode *root, RBNode *node);

RBNode* FIXUP_insert_rb_node(RBNode *root, RBNode *newNode){
	while (newNode->parent->color == RED){
		if (newNode->parent == newNode->parent->parent->left){
			RBNode *temp = newNode->parent->parent->right;
			if (temp->color == RED){
				newNode->parent->color = BLACK;
				temp->color = BLACK;
				newNode->parent->parent->color = RED;
				newNode = newNode->parent->parent;
			}
			else if (newNode == newNode->parent->right){
				newNode = newNode->parent;
				root = LEFT_ROTATE(root, newNode);
			}
			newNode->parent->color = BLACK;
			newNode->parent->parent->color = RED;
			root = RIGHT_ROTATE(root, newNode->parent->parent);
		}
		else{

		}
	}
	root->color = BLACK;
	return root;
}

RBNode* insert_rb_node(RBNode *root, int x){
	RBNode *node = root;
	RBNode *temp = NULL;
	while (node != NULL){
		temp = node;
		if (x < node->val)
			node = node->left;
		else
			node = node->right;
	}
	RBNode *newNode = new RBNode(x);
	newNode->parent = temp;
	if (temp == NULL)
		root = newNode;
	else if (x < temp->val)
		temp->left = newNode;
	else
		temp->right = newNode;
	root = FIXUP_insert_rb_node(root, newNode);
	return root;
}

RBNode* build_rb_tree(vector<int> &nums){
	if (nums.empty())
		return NULL;

	RBNode *root = NULL;
	for (size_t i = 0; i < nums.size(); i++){
		root = insert_rb_node(root, nums[i]);
	}
	return root;
}

void inOrder(RBNode *root){
	if (root){
		inOrder(root->left);
		cout << root->val << " " << root->color << endl;
		inOrder(root->right);
	}
}

int main(){
	int arr[] = {12, 5, 18, 2, 9, 15, 19, 17};
	vector<int> nums(arr, arr+8);

	RBNode *root = build_rb_tree(nums);
	inOrder(root);

	return 0;
}
