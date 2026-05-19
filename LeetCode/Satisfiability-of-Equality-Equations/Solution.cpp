1class Solution {
2public:
3    int Find(int i,vector<int> &parent){
4        if(i==parent[i]) return i;
5        else return parent[i]=Find(parent[i],parent);
6    }
7
8    void Union(int x,int y,vector<int> &parent){
9        int x_parent=Find(x,parent);
10        int y_parent=Find(y,parent);
11
12        if(x_parent==y_parent) return;
13        else {
14            parent[x_parent]=y_parent;
15        }
16    }
17    bool equationsPossible(vector<string>& equations) {
18        //we need to map all the chars with array, so a-->0,b-->1,... so on
19        vector<int> parent(26);
20        for(int i=0;i<26;i++){
21            parent[i]=i;
22        }
23
24        for(string &s:equations){
25            if(s[1]=='='){
26                Union(s[0]-'a',s[3]-'a',parent);
27            }
28            
29        }
30        for(string &s:equations){
31            if(s[1]=='!'){
32                int first_parent=Find(s[0]-'a',parent);
33                int second_parent=Find(s[3]-'a',parent);
34
35                if(first_parent==second_parent) return false;
36            }
37        }
38        return true;
39    }
40};