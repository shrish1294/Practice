class Solution {
public:
    int climbStairs(int n) {
        
        if(n <=2)
            return n;
        int last = 2;
        int scnd_last = 1;

        for(int i = 3; i<=n; i++){
            int curr = last;
            curr += scnd_last;
            
            scnd_last = last;
            last = curr;
        }
        return last;



    }
};
