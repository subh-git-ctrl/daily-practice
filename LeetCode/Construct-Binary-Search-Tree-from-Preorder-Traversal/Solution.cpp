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
14    void build_tree(TreeNode* &root,int key){
15        
16        if(root==NULL) {
17            root=new TreeNode(key);
18            return ;
19        }
20
21        if(key < root->val) build_tree(root->left,key);
22        else build_tree(root->right,key);
23        
24    }
25    TreeNode* bstFromPreorder(vector<int>& preorder) {
26        TreeNode* root = new TreeNode(preorder[0]);
27        for(int i=1;i<preorder.size();i++){
28            int key=preorder[i];
29            build_tree(root,key);
30        }
31
32        return root;
33    }
34};