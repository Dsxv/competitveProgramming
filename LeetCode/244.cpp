class Solution {
public:
    bool isOperand(char ch){
        return ch >= '0' && ch <= '9' ;
    }
    
    vector<pair<int,int>> convertInfix_Postfix(vector<pair<int,int>>& s){
        vector<pair<int,int>> ans ;
        stack<int> st ;
        for(auto i : s){
            if(i.second == ' ') continue ;
            if(i.first){
                ans.push_back(i) ;
            } else {
                if(i.second == ')'){
                    while(st.top() != '('){
                        ans.push_back({0,st.top()}) ;
                        st.pop() ;
                    }
                    st.pop() ;
                } else {
                    while(st.size() && st.top() != '(' && i.second != '('){
                        ans.push_back({0,st.top()}) ;
                        st.pop() ;
                    }
                    st.push(i.second) ;
                }
            }
        }
        while(st.size()){
            ans.push_back({0,st.top()}) ;
            st.pop() ;
        }
        return ans ;
    }
    
    int solve(int x , int y , char ch){
        if(ch == '+') return x + y ;
        else return x - y ;
    }
    
    int evaluatePostfix(vector<pair<int,int>> s) {
        vector<int> v ;
        for(auto i : s){
            if(i.first){
                v.push_back(i.second) ;
            } else {
                int x = v.back() ; v.pop_back() ;
                int y = v.back() ; v.pop_back() ;
                v.push_back(solve(y,x,i.second)) ;
            }
        }
        return v.back() ;
    }
    
    int calculate(string s) {
        vector<pair<int,int>> v ;
        int cur = -1 ;
        for(auto i : s){
            if(isOperand(i)){
                if(cur == -1) cur = 0 ;
                cur *= 10 ;
                cur += i - '0' ;
            } else {
                if(~cur)
                    v.push_back({1,cur}) ;
                cur = -1 ;
                v.push_back({0,i}) ;
            }
        }
        if(~cur) v.push_back({1,cur}) ;
        v = convertInfix_Postfix(v) ;
        int ans = evaluatePostfix(v) ;
        return ans ;
    }
};

