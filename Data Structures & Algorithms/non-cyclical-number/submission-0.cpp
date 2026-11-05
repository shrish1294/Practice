class Solution {
public:
    bool isHappy(int n) {
        
        map<int, bool>vis;
        while(true){
            int x = n;
            if(n == 1)
                return true; 
            if(vis.count(n))
                return 0;
            
            n = 0;
            vis[x] = true; 
            while(x){
                int d = x%10;
                x/=10;
                n += d*d;
            }
        }
        return false; 


    }
};

