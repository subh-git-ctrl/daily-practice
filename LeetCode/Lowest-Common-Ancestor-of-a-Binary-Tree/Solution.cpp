1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(root==NULL || root==p || root==q) return root;
14
15        TreeNode* leftN= lowestCommonAncestor(root->left,p,q);
16        TreeNode* rightN= lowestCommonAncestor(root->right,p,q);
17
18        if(leftN!= NULL && rightN!=NULL) return root;
19        else if(leftN==NULL) return rightN;
20        else return leftN;
21    }
22};