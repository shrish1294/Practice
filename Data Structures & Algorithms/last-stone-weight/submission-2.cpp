class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>st; 
        for(auto a: stones)
            st.push(a);
        while(!st.empty() && st.size() > 1){
            int x = st.top();st.pop();
            int y = st.top(); st.pop();
            int d = x - y;
            if(d == 0)
                continue;
            st.push(abs(d));
        }
        if(st.empty())
            return 0; 
        return st.top();
    }
};
