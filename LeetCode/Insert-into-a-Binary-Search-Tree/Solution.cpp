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
14    void new_BT(TreeNode* &node, int val){
15        if(node==NULL) {
16            node = new TreeNode(val);
17            return ;
18        }
19
20        if(node->val < val) new_BT(node->right,val);
21        else new_BT(node->left,val);
22
23    }
24    TreeNode* insertIntoBST(TreeNode* root, int val) {
25        
26        new_BT(root,val);
27        return root;
28
29        
30    }
31};