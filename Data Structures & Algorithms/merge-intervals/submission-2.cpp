class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>v; 
        stack<vector<int>>st;
        for(auto a: intervals){
            if(st.empty())
                st.push(a);
            else{
                auto it = st.top();
                if(it[1] < a[0])
                    st.push(a);
                else{
                    st.pop();
                    it[0] = min(it[0], a[0]);
                    it[1] = max(it[1], a[1]);
                    st.push(it);
                }
            }
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;

    }
};
