1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        int len=tokens.size();
5        stack<int> st;
6        for(int i=0;i<len;i++){
7            string ch=tokens[i];
8            
9            if(ch=="+"){
10                int n2=st.top();
11                st.pop();
12                int n1=st.top();
13                st.pop();
14                st.push((n1+n2));
15            }
16            else if(ch=="-"){
17                int n2=st.top();
18                st.pop();
19                int n1=st.top();
20                st.pop();
21                st.push((n1-n2));
22            }
23            else if(ch=="*"){
24                int n2=st.top();
25                st.pop();
26                int n1=st.top();
27                st.pop();
28                st.push((n1*n2));
29            }
30            else if(ch=="/"){
31                int n2=st.top();
32                st.pop();
33                int n1=st.top();
34                st.pop();
35                st.push((n1/n2));
36            }
37            else {
38                int num=stoi(ch);
39                st.push(num) ;
40            }
41            
42        }
43        return st.top();
44       
45    }
46};