1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    void preOrder(TreeNode* node, vector<int> &ans){
15        if(node== NULL) return ;
16
17        ans.push_back(node->val);
18        preOrder(node->left ,ans);
19        preOrder(node->right ,ans);
20    }
21    vector<int> preorderTraversal(TreeNode* root) {
22        vector<int> ans;
23        preOrder(root,ans);
24        return ans;
25    }
26};