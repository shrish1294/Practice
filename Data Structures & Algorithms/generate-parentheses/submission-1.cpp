class Solution {
public:


    vector<string>st; 
    void helper(int n1, int n2, string &s){
        if(n1 == 0 && n2 == 0){
            st.push_back(s);
            return ;
        }
        if(n2 == 0)
            return ; 
        if(n1 > 0){
            s.push_back('(');
            helper(n1-1, n2, s);
            s.pop_back();
        }
       if(n2 > n1){
            s.push_back(')');
            helper(n1, n2-1, s);
            s.pop_back();
       }
        
        return ;
    }
    vector<string> generateParenthesis(int n) {
        st.clear();
        vector<string>ans;
        string s = "";
        helper(n, n, s);
        // for(auto a: st)
        //     ans.push_back(a);
        return st; 
    }
};
