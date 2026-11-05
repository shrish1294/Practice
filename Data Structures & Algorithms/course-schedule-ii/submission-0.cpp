class Solution {
public:

    vector<int>ans;
    vector<vector<int>>gr;
    bool helper(int i, vector<bool>&vis, vector<bool>&bis){
        if(vis[i])
            return true;
        if(bis[i])
            return false;
        
        bis[i] = true; 
        for(auto a: gr[i]){
            if(vis[a])
                continue;
            if(bis[a])
                return false;
            auto x = helper(a, vis, bis);
            if(!x)
                return x;
        }
        bis[i] = false;
        vis[i] = true;
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ans.clear();
        gr.clear();

        gr.resize(numCourses);
        vector<bool>vis(numCourses, 0), bis(numCourses, 0);
        for(auto a: prerequisites)
            gr[a[0]].push_back(a[1]);
        
        for(int i =0;i < numCourses; i++){
            if(vis[i])
                continue;
            auto x = helper(i, vis, bis);
            if(!x)
                return {};
        }




        return ans;
    }
};
