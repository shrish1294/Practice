class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>>v;
        for(int i = 0; i < n; i++){
            auto a = intervals[i];
            v.push_back({a[0], 1, i});
            v.push_back({a[1], 0, i});
        }
        sort(v.begin(), v.end());
        for(auto a: v)
            cout <<a[0] <<" "<<a[1] <<" "<< a[2]<<"\n";

        
        
        int cnt = 0;
       
        map<int, bool> mp;
        int ans = 0;
        queue<int>pq; 

        for(auto a: v){
            // cout <<cnt<<" ";
            if(mp.find(a[2])!=mp.end())
                continue; 
            if(a[1] == 0){
                cnt--; 
                
                while(!pq.empty()){
                    auto it = pq.front();
                    cout <<it<<" "<<a[2]<<"  \n";
                    if(it != a[2])
                        mp[it] = true; 
                    pq.pop();
                }
                ans += cnt; 
                cnt = 0;
            }
            else{
                pq.push(a[2]);
                cnt++; 
            }
            
        }
       
        return ans; 
        
    }
};
