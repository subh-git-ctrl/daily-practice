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
12    void make_parent(TreeNode* root,
13                     unordered_map<TreeNode*,TreeNode*> &mp){
14        queue<TreeNode*> qu;
15        qu.push(root);
16
17        while(!qu.empty()){
18            int size=qu.size();
19
20            while(size--){
21                auto main_node = qu.front();
22                qu.pop();
23                if(main_node->left){
24                    mp[main_node->left]=main_node;
25                    qu.push(main_node->left);
26                } 
27                if(main_node->right){
28                    mp[main_node->right]=main_node;
29                    qu.push(main_node->right);
30                } 
31            }
32        }
33    }
34    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
35        unordered_map<TreeNode*,TreeNode*> mp;
36        make_parent(root,mp);
37        
38        queue<TreeNode*> qu;
39        qu.push(target);
40        unordered_map<TreeNode*,bool> visited;
41        visited[target]=true;
42
43        while(k>0){
44            int size=qu.size();
45            while(size--){
46                auto node = qu.front();
47                qu.pop();
48                if(mp[node] && visited[mp[node]]==false) {
49                    qu.push(mp[node]);
50                    visited[mp[node]]=true;
51                }
52                if(node->left && visited[node->left]==false) {
53                    qu.push(node->left);
54                    visited[node->left]=true;
55                }
56                if(node->right && visited[node->right]==false) {
57                    qu.push(node->right);
58                    visited[node->right]=true;
59                }
60                
61                
62            }
63            k--;
64        }
65        vector<int> ans;
66        if(qu.empty()) return {};
67        while(!qu.empty()){
68            auto node=qu.front();
69            ans.push_back(node->val);
70            qu.pop();
71        }
72        return ans;
73    }
74};