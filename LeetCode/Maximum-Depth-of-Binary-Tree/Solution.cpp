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
14    int depth(TreeNode* node){
15        if(node==NULL) return 0;
16
17        int lh = depth(node->left);
18        int rh = depth(node->right);
19
20        return 1 + max(lh,rh);
21    }
22    int maxDepth(TreeNode* root) {
23        // //recursive method
24        //return depth(root);
25
26        //Using level order
27        if(!root) return 0;
28        queue<TreeNode*> qu;
29        qu.push(root);
30        int level=0;
31
32        while(!qu.empty()){
33            int size=qu.size();
34            while(size--){
35                auto p = qu.front();
36                qu.pop();
37
38                if(p->left != NULL) qu.push(p->left);
39                if(p->right != NULL) qu.push(p->right);
40            }
41            level++;
42        }
43        return level;
44    }
45};