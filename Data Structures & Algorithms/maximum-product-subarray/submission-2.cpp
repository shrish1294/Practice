class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int mini = 1, maxi = 1;
        int ans = INT_MIN;
      
        for(auto a: nums){
            ans = max(ans, a);
            int x = mini * a;
            int y = maxi * a;
            ans = max(ans, max(x, y));
            mini = min(a, min(x,y));
            maxi = max(a, max(x, y));

            if(a == 0)
                mini = 1, maxi = 1;
        }
        return ans; 
    }
};
