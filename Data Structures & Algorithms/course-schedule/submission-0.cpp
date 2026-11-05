class Solution {
public:
    bool fun(int it, vector<bool>&vis, vector<bool>&dis, 
        map<int, vector<int>>&mp){
        bool ans = true;
        vis[it] = true;
        
        if(mp.find(it)==mp.end())
        {    dis[it] = true;
            return true; 
        }
        for(auto x: mp[it]){
            cout<<x<<" "
;            if(vis[x] && dis[x])
                ans &=true;
            else if(vis[x])
                return false;
            else
                ans &=fun(x, vis, dis,mp);
            if(!ans)
                return ans;
        }
        dis[it] = true;
        return true;
        

    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
       

        map<int, vector<int>>mp;
        for(auto a: pre)
            mp[a[0]].push_back(a[1]);
        
       
        vector<bool>vis(numCourses, false);
        vector<bool>dis(numCourses, false);
        bool ans = true;
        for(int i = 0; i < numCourses; i++){
            if(vis[i])
                continue;
            
            ans =fun(i, vis, dis, mp);
            if(!ans)
                return ans;
        }
        return ans;

    }
};
