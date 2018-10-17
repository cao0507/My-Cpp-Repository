#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void insertLeftChild(TreeNode* root, vector<int>& nums, int i, int j){
        if (i > j){
            root->left = NULL;
            return ;
        }
        int mid = (i+j)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        root->left = node;
        insertLeftChild(node, nums, i, mid-1);
        insertRightChild(node, nums, mid+1, j);
    }

    void insertRightChild(TreeNode* root, vector<int>& nums, int i, int j){
        if (i > j){
            root->right = NULL;
            return ;
        }
        int mid = (i+j)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        root->right = node;
        insertLeftChild(node, nums, i, mid-1);
        insertRightChild(node, nums, mid+1, j);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        int mid = (len-1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        insertLeftChild(root, nums, 0, mid-1);
        insertRightChild(root, nums, mid+1, len-1);
        return root;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        TreeNode* ret = Solution().sortedArrayToBST(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
