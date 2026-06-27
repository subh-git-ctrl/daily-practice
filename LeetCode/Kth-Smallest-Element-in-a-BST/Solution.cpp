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
14    void inorder(TreeNode* root, int k,int &ans,int &count){
15        if(root==NULL) return ;
16        inorder(root->left,k,ans,count); //for kth smallest
17        //inorder(root->right,k,ans,count); //for kth greatest
18
19        count++;
20        if(count==k){
21            ans=root->val;
22            return ;
23        }
24
25        inorder(root->right,k,ans,count); //for kth smallest
26        //inorder(root->left,k,ans,count); //for kth greatest
27    }
28    int kthSmallest(TreeNode* root, int k) {
29        int count=0,ans=-1;
30        inorder(root,k,ans,count);
31        return ans;
32    }
33};