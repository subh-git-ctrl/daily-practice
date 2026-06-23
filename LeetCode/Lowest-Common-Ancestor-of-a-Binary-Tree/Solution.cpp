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
12    bool path_root_to_node(TreeNode* root, TreeNode* node,vector<TreeNode*> &path){
13        if(root==NULL) return false;
14        path.push_back(root);
15        if(root==node) return true;
16
17        
18        if(path_root_to_node(root->left,node,path) || path_root_to_node(root->right,node,path) )
19            return true;
20        
21        path.pop_back();
22        return false;
23    }
24    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
25        if(root==NULL) return NULL;
26        vector<TreeNode*> path1,path2;
27        bool p1=path_root_to_node(root,p,path1);
28        bool p2=path_root_to_node(root,q,path2);
29
30        TreeNode* lca=root;
31        int mini_length= min(path1.size(),path2.size());
32
33        for(int i=1;i<mini_length;i++){
34            if(path1[i]==path2[i]) lca=path1[i];
35            else break;
36        }
37        return lca;
38    }
39};