class Solution {
public:
   


    double myPow(double x, int n) {
        
        double a = 0;
        double val = 1;
        int y = abs(n);
        while(y){

            if(y & 1)
                val*= x;
            y/=2;
            if(y)
                x = x*x;
        }
        if(n < 0)
            return 1.0 / val;
        return val; 
      
        
    }
 


     
};
