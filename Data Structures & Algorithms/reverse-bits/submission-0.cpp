class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        for(int i =0; i < 32; i++){
            int d = 31 - i;
            if(n & (1<<i))
                x |=(1<<d);
        }
        return x;
    }
};
