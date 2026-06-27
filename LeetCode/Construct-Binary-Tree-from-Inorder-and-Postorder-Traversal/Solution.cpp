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
14    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
15        unordered_map<int,int> mp;
16        for(int i=0;i<inorder.size();i++){
17            mp[inorder[i]] = i ;
18        }
19
20        TreeNode* root = build_tree(inorder,0,inorder.size()-1,
21                                    postorder,0,postorder.size()-1, mp);
22
23        return root;
24    }
25
26    TreeNode* build_tree(vector<int>& inorder, int inStart, int inEnd,
27                         vector<int>& postorder,int postStart, int postEnd,
28                         unordered_map<int,int> &mp){
29            if(inStart>inEnd || postStart>postEnd) return NULL;
30
31            TreeNode* node= new TreeNode(postorder[postEnd]);
32            int inRoot= mp[node->val];
33            int nums= inRoot-inStart ;
34            node->left = build_tree(inorder, inStart, inRoot-1,
35                                    postorder,postStart, postStart+nums-1, mp);
36
37            node->right = build_tree(inorder,inRoot+1,inEnd,
38                                    postorder,postStart+nums, postEnd-1, mp);
39
40            return node;
41
42    }
43};