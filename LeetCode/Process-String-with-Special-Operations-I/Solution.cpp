1class Solution {
2public:
3    string processStr(string s) {
4        int n = s.size();
5        string ans = "";
6        for(char c : s){
7         if(c >= 'a' && c <= 'z'){
8            ans.push_back(c);
9         }
10
11         else if(c == '*'){
12            if(!ans.empty()) ans.pop_back();
13         }
14         else if(c=='#'){
15            ans+=ans;
16         }else if(c == '%'){
17            reverse(ans.begin(),ans.end());
18         }
19        }
20        return ans;
21
22
23    }
24};