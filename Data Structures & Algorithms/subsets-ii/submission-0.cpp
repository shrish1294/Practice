class Solution {
public:

    vector<vector<int>>ans;

    void helper(vector<int>&v, int i, vector<int>&tmp){

        ans.push_back(tmp);

        for(int j = i ; j < v.size(); ){
            tmp.push_back(v[j]);
            helper(v, j + 1, tmp);
            tmp.pop_back();
            int prev = v[j];
            while(j < v.size() && v[j] == prev)
                j++; 
        }

    }





    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        ans.clear();
        
        sort(nums.begin(), nums.end());
        vector<int>tmp; 
        int n = nums.size();
        helper(nums, 0, tmp);
        



        return ans; 
    }
};
