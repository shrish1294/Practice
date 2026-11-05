class Solution {
public:
    
    int pivot(vector<int>&v, int l , int r){
        if(r<l)
            return INT_MAX;
        if(l==r)
            return v[l];
        int m = (l+r)>>1;
        
        if(v[m] < v[l])
            r = m-1;
        else if(v[m] > v[l] && v[l] < v[r])
            r = m-1;
        else
            l = m + 1;
        return min(v[m], pivot(v, l , r));

    }
    int findMin(vector<int> &nums) {
        int n = nums.size();
        return pivot(nums, 0, n-1);
    }
};
