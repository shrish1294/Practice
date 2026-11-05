class Solution {
public:

    int fun(vector<int>&v, int l , int r){
        
        if(l>r)
            return 0;

        if(l==r)
            return l;

        int m = (l+r)/2;
        if(v[m] >= v[l] && v[r] >= v[m]){
                r = m - 1;
        }
        else if(v[m] >= v[l])
            l = m + 1;
        else
            l = m + 1;


        int val =  fun(v, l , r);
        if(v[val] < v[m])
            return val;
        return m;
    }
    int f(vector<int>&v, int l , int r, int t){
        if(l>r)
            return -1;
        
        int m = (l+r)/2;
        if(v[m]==t)
            return m;
        else if(v[m] > t)
            r = m-1;
        else
            l = m + 1;
        return f(v, l , r, t);
    }
    int search(vector<int>& nums, int target) {

            int n = nums.size();
            int piv = fun(nums, 0, n-1);
            
            int a1 = f(nums, 0, piv-1, target);
            int a2 = f(nums, piv, n-1, target);
            if(a1!=-1)
                return a1;
            return a2;
    }
};
