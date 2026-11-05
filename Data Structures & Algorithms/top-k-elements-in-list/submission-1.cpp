class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int arr_len = nums.size();
        unordered_map<int, int>count_tracker; 


        for(auto a: nums)
            count_tracker[a] += 1;
        
        vector<vector<int>>buckets(arr_len + 1);

        for(auto it = count_tracker.begin(); it != count_tracker.end(); it ++ )
            buckets[it->second].push_back(it->first);

        vector<int>ans  ;
        for(int i = arr_len; i>=0; i--){
            

            if(buckets[i].size() > 0)
            {
                if(ans.size() == k)
                    break;
                for(auto a: buckets[i])
                    ans.push_back(a);
            }
        }
        return ans; 
        
        
    }
};
