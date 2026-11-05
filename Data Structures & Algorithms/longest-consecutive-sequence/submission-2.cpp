class Solution {
public:


    int check( int i, vector<bool>&vis,
     unordered_map<int, int>&mp, vector<int>&left){

        if(mp.find(i) == mp.end())
            return 0; 
        int idx = mp[i]; 
        if(vis[idx])
            return left[idx];
        vis[idx] = true;
        left[idx] = 1 + check(i - 1, vis, mp, left);
        return left[idx];
    }

    int longestConsecutive(vector<int>& nums) {
        
        int len = nums.size();

      

        unordered_map<int, int>left_tracker;

        int ans = 0;

        for(int i = 0 ; i < len; i++){
            left_tracker[nums[i]] = i; 
        }

        vector<bool>vis(len, false);
        vector<int>left(len, 0);

        
        for(int i = 0; i < len; i++){
            if(vis[i])
                continue;
            ans = max(ans, check(nums[i], vis, left_tracker, left));
        }
        return ans; 


    }
};
