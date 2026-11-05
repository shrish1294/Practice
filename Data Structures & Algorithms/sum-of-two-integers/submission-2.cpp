class Solution {
public:
    int getSum(int a, int b) {
        
        int c = 0;
        int ans = 0;
        for(int i =0; i < 32; i++){
            int x = a & b;
            int y = a | b; 
            
            if(x & (1<<i))
            {
                if(c)
                    ans |= (1<<i);
                else
                    c = 1;
            }
            else if(y & (1<<i)){
                if(!c)
                    ans|=(1<<i);
                else
                    c = 1;
            }
            else{
                if(c)
                    ans |=(1<<i);
                    c = 0;
            }
        }

        return ans;
    }
};
