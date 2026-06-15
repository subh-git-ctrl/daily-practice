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
14    int depth_balanced(TreeNode* node){
15        if(node==NULL) return 0;
16
17        int lh=depth_balanced(node->left);
18        if(lh==-1) return -1;
19        int rh=depth_balanced(node->right);
20        if(rh==-1) return -1;
21        if(abs(lh-rh) > 1) return -1;
22        return 1+max(lh,rh);
23    }
24    bool isBalanced(TreeNode* root) {
25        if(depth_balanced(root)==-1) return false;
26        return true;
27    }
28};