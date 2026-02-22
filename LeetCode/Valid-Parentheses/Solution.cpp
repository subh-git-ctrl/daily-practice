1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        int len=s.size();
6        //st.push(s[0]);
7
8        for(int i=0;i<len;i++){
9            char ch=s[i];
10            if(ch=='(' || ch=='{' || ch=='[')
11                st.push(ch);
12            else if(ch==')'){
13                if(st.size()==0) return false;
14                if(st.top()!='(') return false;
15                else st.pop();
16            }
17            else if(ch=='}'){
18                if(st.size()==0) return false;
19                if(st.top()!='{') return false;
20                else st.pop();
21            }
22            else if(ch==']'){
23                if(st.size()==0) return false;
24                if(st.top()!='[') return false;
25                else st.pop();
26            }
27        }
28        if(st.size()!=0) return false;
29        else return true;
30    }
31};