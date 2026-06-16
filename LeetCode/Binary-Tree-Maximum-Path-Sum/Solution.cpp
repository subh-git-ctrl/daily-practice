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
14    int f(TreeNode* node, int &maxi){
15        if(!node) return 0;
16
17        int lh= max(0,f(node->left,maxi));
18        int rh= max(0,f(node->right,maxi));
19        maxi= max(maxi, node->val + lh + rh);
20        return node->val + max(lh,rh);  // jst check when we need to return to 20 which path is fav, i.e why we need to do the max(lh,rh) thing
21    }
22    int maxPathSum(TreeNode* root) {
23        int maxi=-1e9;
24        int help=f(root,maxi);
25        return maxi;
26    }
27};