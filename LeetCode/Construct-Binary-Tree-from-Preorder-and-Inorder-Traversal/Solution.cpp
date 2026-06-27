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
14    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
15        unordered_map<int,int> mp;
16        for(int i=0;i<inorder.size();i++){
17            mp[inorder[i]]=i;
18        }
19
20        TreeNode* root = build_tree(preorder,0,preorder.size()-1,
21                                    inorder, 0,inorder.size()-1,  mp);
22
23        return root;
24    }
25
26    TreeNode* build_tree(vector<int>& preorder, int preStart, int preEnd,
27                         vector<int>& inorder , int inStart , int inEnd,
28                         unordered_map<int,int> &mp){
29        
30        if(preStart>preEnd || inStart>inEnd) return NULL;
31
32        TreeNode* node = new TreeNode(preorder[preStart]);
33        
34        int inRoot= mp[node->val];
35        int numsleft= inRoot - inStart ;
36        
37        node->left = build_tree(preorder, preStart+1, preStart+numsleft,
38                                inorder , inStart, inRoot-1, mp);
39
40        node->right = build_tree(preorder, preStart+1+numsleft, preEnd,
41                                inorder , inRoot+1, inEnd, mp);
42
43        return node;
44    }
45};