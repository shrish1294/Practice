class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>>ans; 
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; i++){
            int target = -nums[i];

            int l = i + 1; 
            int r = len - 1;
            while(l < r){
                if(nums[l] + nums[r] == target){
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++, r--; 
                }
                else if(nums[l] + nums[r] > target)
                    r--;
                else
                    l++; 
            }
        }
        vector<vector<int>>v;
        for(auto a: ans)
            v.push_back(a);
        return v; 

    }
};
