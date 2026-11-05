class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return 0;
        
        int i = 0, j = 0;
        
        int cnt =0;

        while(j < n){

            int maxi = j;
            while(i <= j){
                maxi = max(maxi, i + nums[i]);
                i+=1;
            }
            cnt++; 
            j = maxi;

            if(maxi >=n-1)
                return cnt;
        }
        return cnt; 
        
    }
};
