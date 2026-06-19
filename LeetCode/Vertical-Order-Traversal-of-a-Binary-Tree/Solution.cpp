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
14    vector<vector<int>> verticalTraversal(TreeNode* root) {
15        map<int,map<int,multiset<int>>> mp; // vertical, level , nodes
16        queue<pair <TreeNode*,pair<int,int>>> qu; //{node,vertical,level}
17        qu.push({root,{0,0}});
18
19        while(!qu.empty()){
20            int size=qu.size();
21            while(size--){
22                auto node= qu.front().first;
23                int x= qu.front().second.first ;
24                int y= qu.front().second.second ;
25                qu.pop();
26                (mp[x])[y].insert(node->val);
27                if(node->left) qu.push({node->left,{x-1,y+1}});
28                if(node->right) qu.push({node->right,{x+1,y+1}});
29            }
30        }
31        vector<vector<int>> result;
32        for(auto &m: mp){   // one vertical column
33            vector<int> ans;
34            for(auto &mapi: m.second) {   //levels in that column
35                for(auto &val: mapi.second) ans.push_back(val);
36                
37            }
38            result.push_back(ans);
39        }
40        return result;
41    }
42};