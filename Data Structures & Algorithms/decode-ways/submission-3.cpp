class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int>vec(n+2, 0);
        vec[n+1] = 1;
        vec[n] =1; 
        vec[n-1] = (s[n-1]=='0')?0: 1;
        for(int i = n-2;i>=0; i--){
            int c1 = int(s[i] - '0');
            int c2 = int(s[i+1]-'0');
            int val = c1*10 + c2;
            int a =0;
            int b = 0;
            if(c1!=0)
                a = vec[i+1];
            if(val!=0 && val > c2 && val <= 26)
                b = vec[i+2];
           
            vec[i] = a + b;
        }
        
        return vec[0]; 
    }
};
