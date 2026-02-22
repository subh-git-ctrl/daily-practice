1class MinStack {
2public:
3    stack<int> stk;
4    stack<int> min_stk;
5    MinStack() {
6        
7    }
8    
9    void push(int val) {
10        if(stk.empty()) {
11            stk.push(val);
12            min_stk.push(val);
13        }
14        else {
15            stk.push(val);
16            min_stk.push(min(min_stk.top(),stk.top()));
17        }
18    }
19    
20    void pop() {
21        //if(stk.top()==min_stk.top()){
22            min_stk.pop();
23       // }
24        stk.pop();
25    }
26    
27    int top() {
28        return stk.top();
29    }
30    
31    int getMin() {
32        return min_stk.top();
33    }
34};
35
36/**
37 * Your MinStack object will be instantiated and called as such:
38 * MinStack* obj = new MinStack();
39 * obj->push(val);
40 * obj->pop();
41 * int param_3 = obj->top();
42 * int param_4 = obj->getMin();
43 */