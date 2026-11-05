class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp ;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
           int a = nums[i];
           if(mp.find(target-a)!=mp.end())
            return {mp[target-a], i};
            mp[a] = i;
        }

        return {};

    }
};
