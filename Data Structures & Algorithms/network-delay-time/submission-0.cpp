class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<vector<int>>>gr;
        gr.resize(n+1);
        for(auto a: times)
            gr[a[0]].push_back({a[1], a[2]});
        
        set<vector<int>>st;
        st.insert({0 , k});
        vector<int>ans(n + 1, INT_MAX);
        ans[k] = 0;
        while(st.size()){
            auto it = *st.begin();
            st.erase(st.begin());
            if(it[0] > ans[it[1]])
                continue;
            for(auto a: gr[it[1]]){
                if(ans[a[0]] < it[0] + a[1])
                    continue;
                ans[a[0]] = it[0] + a[1];
                st.insert({ans[a[0]], a[0]});
            }
        }
        for(auto a: ans)
            cout<<a<<" ";
        int x = 0;
        for(int i = 1; i <= n; i++)
            x = max(x, ans[i]);
        if(x == INT_MAX)
            return -1;
        return x;
    }
};
