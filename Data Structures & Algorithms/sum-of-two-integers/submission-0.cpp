class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int c = 0;
        for(int i =0;  i < 32; i++){
            int k = a&b;
            int l = a|b;
            if(k&(1<<i)){
                if(c)
                    ans |= (1<<i);
                else
                    c = 1;
            }
            else if(l & (1<<i)){
                if(!c)
                    ans |=(1<<i);
                else
                    c = 1;
            }
            else{
                if(c)
               { ans |=(1<<i);
                c = 0;}
            }
        }
        return ans;
    }
};
