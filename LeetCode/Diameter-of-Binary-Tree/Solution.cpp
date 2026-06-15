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
14    int depth_diameter(TreeNode* node, int &diameter){
15
16        if(node==NULL) return 0;
17
18        int lh= depth_diameter(node->left,diameter);
19        int rh= depth_diameter(node->right,diameter);
20
21        diameter= max(diameter, lh+rh);
22        return 1+max(lh,rh);
23    }
24    int diameterOfBinaryTree(TreeNode* root) {
25        int diameter=0;
26        int lol= depth_diameter(root,diameter);
27        return diameter;
28    }
29};