class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int x =0;
        for(auto a:  nums)
             x^=a;
      
        for(int i = 0; i <= nums.size(); i++){
            x^=i;
        }
        return x;
            
    }
};
