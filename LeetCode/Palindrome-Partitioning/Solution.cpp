1class Solution {
2public:
3    bool isPalindrome(int i,int j,string &s){
4        while(i<=j){
5            if(s[i]!=s[j]) return false;
6            i++;
7            j--;
8        }
9        return true;
10    }
11    void PalinPartition(string &s,int index,vector<string> &temp,vector<vector<string>> &result){
12        if(index==s.size()){
13            result.push_back(temp);
14            return;
15        }
16        for(int i=index;i<s.size();i++){
17            if(isPalindrome(index,i,s)){
18                temp.push_back(s.substr(index, i+1-index));
19                PalinPartition(s,i+1,temp,result);//shoulnt be index+1
20                temp.pop_back();
21            }
22        }
23    }
24    vector<vector<string>> partition(string s) {
25        vector<string> temp;
26        vector<vector<string>> result;
27        PalinPartition(s,0,temp,result);
28        return result;
29    }
30};