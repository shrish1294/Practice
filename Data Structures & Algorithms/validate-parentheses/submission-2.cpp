class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        stack<char>st; 

        int cnt = 0;
        for(auto a: s)
        {
            if(a=='(' || a == '[' || a == '{')
                st.push(a);
            else
            {
                if(st.empty())
                    return false;
                if(st.top() == '{' && a != '}')
                    return false;
                else if(st.top() == '[' && a != ']')
                    return false;
                else if(st.top() == '(' && a != ')')
                    return false;
                else
                    st.pop();
            }
            
        }
        return st.size() == 0;
    }
};
