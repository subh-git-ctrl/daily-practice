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
14    int depth(TreeNode* node){
15        if(node==NULL) return 0;
16
17        int lh = depth(node->left);
18        int rh = depth(node->right);
19
20        return 1 + max(lh,rh);
21    }
22    int maxDepth(TreeNode* root) {
23        return depth(root);
24    }
25};