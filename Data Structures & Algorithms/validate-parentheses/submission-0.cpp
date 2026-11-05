class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char a: s){
            if(a=='{' || a == '(' || a == '[')
                st.push(a);
            else{
                if(a=='}')
                    if(st.empty() || st.top()!='{')
                        return false;
                
                if(a==']')
                    if(st.empty() || st.top()!='[')
                        return false;
                
                if(a==')')
                    if(st.empty() || st.top() != '(')
                        return false;
                
                st.pop();


            }
        }
        return st.empty();
    }
};
