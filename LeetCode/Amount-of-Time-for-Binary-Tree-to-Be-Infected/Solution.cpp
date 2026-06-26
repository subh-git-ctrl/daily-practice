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
14    TreeNode* source(TreeNode* node, int start) {
15    if (node == nullptr) return nullptr;
16
17    if (node->val == start)
18        return node;
19
20    TreeNode* left = source(node->left, start);
21    if (left)
22        return left;
23
24    return source(node->right, start);
25}
26    void construct_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
27        queue<TreeNode*> qu;
28        qu.push(root);
29
30        while(!qu.empty()){
31            int size=qu.size();
32
33            while(size--){
34                auto parent_node= qu.front();
35                qu.pop();
36                if(parent_node->left) {
37                    parent[parent_node->left] = parent_node;
38                    qu.push(parent_node->left);
39                }
40                if(parent_node->right) {
41                    parent[parent_node->right] = parent_node;
42                    qu.push(parent_node->right);
43                }
44            }
45        }
46    }
47    int amountOfTime(TreeNode* root, int start) {
48        TreeNode* source_node = source(root,start);
49        unordered_map<TreeNode*,TreeNode*> parent;
50        construct_parent(root,parent);
51
52        int time=0;
53        unordered_map<TreeNode*,bool> visited;
54        visited[source_node] = true;
55        queue<TreeNode*> qu;
56        qu.push(source_node);
57        
58        while(!qu.empty()){
59            int size=qu.size();
60            while(size--){
61                auto node=qu.front();
62                qu.front();
63                qu.pop();
64
65                if(parent[node] && !visited[parent[node]]) {
66                    visited[parent[node]]=true;
67                    qu.push(parent[node]);
68                }
69                if(node->left && !visited[node->left]) {
70                    visited[node->left]=true;
71                    qu.push(node->left);
72                }
73                if(node->right && !visited[node->right]) {
74                    visited[node->right]=true;
75                    qu.push(node->right);
76                }
77                
78            }
79            time++;
80        }
81
82        return time-1;
83
84    }
85};