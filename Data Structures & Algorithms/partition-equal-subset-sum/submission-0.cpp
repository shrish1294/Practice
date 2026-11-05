class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        
        
        int sum = 0;
        for(auto a: nums)
            sum += a;
        if(sum &1)
            return false;
        bitset<100000000>b;
        b[0] = 1;
        sum /= 2;
        
        for(auto a: nums){
            b|=(b<<a);
            if(b[sum])
                return true;
        }
        return false;
        
        
    }
};
