class Solution {
public:
    vector<vector<int>>gr;

    bool dfs(int i, vector<bool>&vis, vector<bool>&bis){
        // cout<<i<<" ";
        if(vis[i])
            return true;
        if(bis[i])
            return false;
        
        bis[i] = true;
        bool ans = true;
        for(auto a: gr[i]){
            if(vis[a])
                continue;
            if(bis[a])
                return false;
            ans &= dfs(a, vis, bis);
            if(!ans)
                return false;
        }
        bis[i] = false;
        vis[i] = true;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        gr.clear();
        gr.resize(numCourses + 1);

        for(auto a: prerequisites)
            gr[a[0]].push_back(a[1]);
        // for(auto a: gr){
        //     for(auto b: a)
        //         cout<<b<<" ";
        //     cout<<"\n";
        // }

        vector<bool>vis(numCourses + 1, false);
        vector<bool>bis(numCourses + 1, false);

        for(int i = 0; i <numCourses ; i++){
            if(vis[i])
                continue;
            bool a = dfs(i, vis, bis);
            if(!a)
                return a;
        }
        return true; 




        
    }
};
