class Solution {
public:

    multiset<vector<string>>st;
    vector<string>v;
    vector<string>ans;
    map<string, vector<string>>mp; 
    void dfs(string i, vector<vector<string>>& tickets){

        // cout<<i<<" ";
        if(st.size() ==0)
        {
            if(ans.size() == 0)
            ans = v;
            return ;
        }
        if(!mp.count(i))
            return ;   

        for(auto a: mp[i]){
           
            if(st.find({i, a})==st.end())
                continue;
            v.push_back(a);
            st.erase(st.find({i, a}));

            dfs(a, tickets);
            if(st.size() == 0)
                return ;
            v.pop_back();
            st.insert({i, a});
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();
        v.clear();
        st.clear();
        mp.clear();
        sort(tickets.begin(), tickets.end());
        for(auto a: tickets){
            st.insert(a);
            mp[a[0]].push_back(a[1]);
        }

        v.push_back("JFK");
        dfs("JFK", tickets);
        return ans; 
    }
};
