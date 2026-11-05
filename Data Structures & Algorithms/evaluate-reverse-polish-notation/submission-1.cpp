class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;

        for(string a: tokens){
            if(a != "+" && a != "-" && a != "*" && a != "/")
                st.push(stoi(a));
            else{
                int x = st.top();
                int z ; 
                st.pop();
                int y = st.top();
                st.pop();
                if(a == "+")
                    z = x + y;
                else if(a == "-")
                    z = y - x;
                else if(a == "*")
                    z = x * y;
                else if(a == "/")
                    z = y / x;

                st.push(z);
            }
        }
        return st.top();


    }
};
