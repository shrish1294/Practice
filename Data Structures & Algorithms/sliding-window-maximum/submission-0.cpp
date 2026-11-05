class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int>st;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < k; i++)
            st.insert(nums[i]);
        
        int i = k; 
        ans.push_back(*st.rbegin());
        while(i < n){
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            ans.push_back(*st.rbegin());
            i++; 

        }



        return ans; 
    }
};
