class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        int i = 0;
       while(true){

        if(i  >= n-1)
            return cnt;
        if(i + nums[i] >=n-1)
            return cnt + 1;
        int maxi = i;
        for(int j = i; j <= i + nums[i]; j++)
            if(maxi + nums[maxi] < j + nums[j])
                maxi = j ;
        i = maxi; 
        cnt++;
        
       }
    return -1; 
    }
};
