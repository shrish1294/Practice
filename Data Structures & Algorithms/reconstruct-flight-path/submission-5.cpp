class Solution {
public:

    vector<string>ans; 


    void dfs(string s, map<string, vector<string>>&gr){
        
        while(!gr[s].empty()){
            auto it = gr[s].back();
            gr[s].pop_back();
            dfs(it, gr);
        }
        ans.push_back(s);
    }



    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();

       map<string, vector<string>>gr; 

       map<string, int>degree; 

        for(auto a: tickets)
            gr[a[0]].push_back(a[1]);

        for(auto &a: gr){
            // [a.first] = a.second.size(); 
            sort(a.second.begin(), a.second.end()); 
            reverse(a.second.begin(), a.second.end());
        }
        
        queue<string>pq;
        pq.push("JFK");

        int cnt = 0; 

        // while(!pq.empty()){
        //     auto it = pq.front();
        //     pq.pop();
        //     ans.push_back(it);
        //     if(gr[it].size() == 0)
        //         continue; 
            
            
        //     auto k = gr[it].back();
        //     if(gr[k].size() == 0 && gr[it].size() > 1){
        //         int n = gr[it].size();
        //         swap(gr[it][n-1], gr[it][n-2]);
        //         k = gr[it].back();
        //     }


        //     gr[it].pop_back();
        //     pq.push(k);
        //     if(gr[it].size() == 0)
        //         cnt++; 

        // }
        dfs("JFK", gr);
        reverse(ans.begin(), ans.end());
        return ans; 
        

        
    }
};
