class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        
        set<int> st(nums.begin(), nums.end());
        int ans = 0;

       for(auto it = st.begin(); it!=st.end(); ){
        int cnt = 1;
        int val = *it;
        val+=1; 
        it++;
        while(it!=st.end() && val == *it){
            cnt++;
            val+=1;
            it++;
        }
        ans = max(ans, cnt); 

       }
       
        return ans ;

        
    }
};
