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
14    bool isLeaf(TreeNode* node){
15        return (node->left==NULL && node->right==NULL);
16    }
17    TreeNode* min_right(TreeNode* node){
18        if(node==NULL) return NULL;
19        TreeNode* temp=node;
20        
21        while(temp->left){
22            temp=temp->left;
23        }
24        return temp;
25    }
26    TreeNode* max_left(TreeNode* node){
27        if(node==NULL) return NULL;
28        TreeNode* temp=node;
29        
30        while(temp->right){
31            temp=temp->right;
32        }
33        return temp;
34    }
35    bool check(TreeNode* node){
36        if(node==NULL) return true;
37        if(isLeaf(node)) return true;
38
39        bool l=false,r=false;
40        if(node->left==NULL) l = true;
41        else if(node->left && node->val > max_left(node->left)->val ) l = true;
42        else if(node->left && node->val < max_left(node->left)->val ) l = false;
43
44        if(node->right==NULL) r= true;
45        else if(node->right && node->val < min_right(node->right)->val) r= true;
46        else if(node->right && node->val > min_right(node->right)->val) r= false;
47
48        return l && r && check(node->left) && check(node->right);
49
50    }
51    bool isValidBST(TreeNode* root) {
52        if(isLeaf(root)) return true;
53
54        return check(root);
55        
56    }
57};