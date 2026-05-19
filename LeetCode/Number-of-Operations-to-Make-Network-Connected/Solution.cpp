1class Solution {
2public:
3    int Find(int i,vector<int> &parent){
4        if(i==parent[i]) return i;
5        return parent[i]=Find(parent[i],parent);
6    }
7    void Union(int x,int y,vector<int> &parent,int &count){
8        int x_parent=Find(x,parent);
9        int y_parent=Find(y,parent);
10
11        if(x_parent==y_parent) count++;//counts the number of redundant cables
12        else{//DO union
13            parent[x_parent]=y_parent;
14        }
15    }
16    int makeConnected(int n, vector<vector<int>>& connections) {
17        int no_of_edges= connections.size();
18        int count=0;
19        vector<int> parent(n);
20        for(int i=0;i<n;i++){
21            parent[i]=i;
22        }
23        if(no_of_edges<n-1) return -1;//not possible case
24        for(vector<int> &e:connections){
25            Union(e[0],e[1],parent,count);
26        }
27        //return count; this is wrong coz lets say count is 3 but we only needed 2 cables for connecting then it wont be medium. we need to find connected components first
28
29        //finding the number of components
30        int components=0;
31        for(int i=0;i<n;i++){
32            if(i==Find(i,parent)) components++;
33        }
34        int needed= components-1;
35
36        if(count>=needed) return needed;
37        return -1;
38        
39    }
40};