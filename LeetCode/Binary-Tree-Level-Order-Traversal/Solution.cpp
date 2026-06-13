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
14    vector<vector<int>> levelOrder(TreeNode* root) {
15        if(root==NULL) return {};
16        queue<TreeNode*> qu;
17        qu.push(root);
18        vector<vector<int>> ans;
19        while(!qu.empty()){
20            int size=qu.size();
21            vector<int> level ;
22            while(size--){
23                auto node = qu.front();
24                qu.pop();
25                level.push_back(node->val);
26                if(node->left != NULL) qu.push(node->left) ;
27                if(node->right != NULL) qu.push(node->right) ;
28            }
29            ans.push_back(level);
30        }
31        return ans;
32    }
33};