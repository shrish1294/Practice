class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int len = s.length();
        if(len == 0 || len == 1)
            return len; 

        int ans = 0;
        for(int i = 0; i < 26; i++){
            int l = 0, r = 0;
            int K = k;

            char C = 'A' + i;
            while(r < len){
                
                if(s[r] == C)
                    r++; 
                else if( K > 0)
                    K--, r++; 
                else{
                    while(l < r && s[l] == C)
                        l++; 
                    l++; 
                    r++; 
                }
                ans = max(ans, r - l);
            }
        }
        return ans; 
    }
};
