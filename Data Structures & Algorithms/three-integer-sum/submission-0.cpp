class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>>st;
        map<int, int>mp;
        for(auto a: nums)
            mp[a]++;
        for(int i = 0; i < n; i++){
            mp[nums[i]]--;
            for(int j = i+1; j < n; j++){
                mp[nums[j]]--;
                int sum = nums[i] + nums[j];
                if(mp.find(-1*sum)!=mp.end() && mp[-sum]!=0){
                    vector<int>t(3);
                    t[0] = min(nums[i], min(nums[j], -1*sum));
                    t[2] =  max(nums[i], max(nums[j], -1*sum));
                    t[1] = -(t[0] + t[2]);
                    st.insert(t);
                }

                mp[nums[j]]++;                    
            }
            mp[nums[i]]++;
        }
        vector<vector<int>>ans;
        for(auto a: st){
            ans.push_back(a);
        }
        return ans;


    }
};
