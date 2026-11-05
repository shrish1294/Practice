class Solution {
public:


    int findMin(vector<int> &nums) {
        
        int n = nums.size();
        int l = 0, r = n-1;
        if(nums[0] < nums[n-1])
            return nums[0];

        while(l<=r){

            int mid =  (l + r )/ 2;
            int left = (mid -1)>=0?nums[mid-1]: INT_MAX;
            int right = (mid + 1) < n?nums[mid + 1]: INT_MAX;
            if(nums[mid] < left && nums[mid] < right)
                return nums[mid];
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid - 1; 

            
        }
        return -1;

    }
};
