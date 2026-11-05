class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int>mp;
        for(auto a: nums)
            mp[a]+=1;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>,
         greater<pair<int,int>>>pq;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            if(pq.size()<k)
                pq.push({it->second, it->first});
            else if(pq.top().first < it->second){
                pq.pop();
                pq.push({it->second, it->first});
            }
        }
        vector<int>ans; 
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;

    }
};
