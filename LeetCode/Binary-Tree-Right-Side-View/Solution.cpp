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
14    vector<int> rightSideView(TreeNode* root) {
15        queue<TreeNode*> qu ;
16        if(root==NULL) return {};
17        qu.push(root);
18        vector<int> ans;
19        while(!qu.empty()){
20            int size = qu.size();
21            ans.push_back(qu.front()->val);
22            while(size--){
23                auto node=qu.front();
24                qu.pop();
25                if(node->right) qu.push(node->right);
26                if(node->left) qu.push(node->left);
27            }
28        }
29        return ans;
30    }
31};