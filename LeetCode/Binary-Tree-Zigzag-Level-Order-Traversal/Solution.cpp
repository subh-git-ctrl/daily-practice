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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        if(root==NULL) return {};
16        vector<vector<int>> result;
17
18        queue<TreeNode*> qu;
19        qu.push(root);
20        int flag=0; // 0,2,4,..--->normal order else reverse
21        while(!qu.empty()){
22            int size=qu.size();
23            vector<int> level;
24            while(size--){
25                auto node=qu.front();
26                qu.pop();
27                level.push_back(node->val);
28                if(node->left) qu.push(node->left);
29                if(node->right) qu.push(node->right);
30            }
31            if(flag==1) {
32                reverse(level.begin(),level.end());
33            }
34            flag= 1-flag;
35            result.push_back(level);
36        }
37        return result;
38    }
39};