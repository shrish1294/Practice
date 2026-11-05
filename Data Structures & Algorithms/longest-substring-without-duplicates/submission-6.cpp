class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.length();

        map<int, int>v; 
        int ans = 0;
        int l = 0;
        int r = 0;
        while(l < len && r < len){

            int x  = int(s[r] - '0');
            // cout<<x<<" ";
            if(v.find(x) == v.end() || v[x] == -1){
                v[x] = r; 
                r++; 
            }
            else{
                
                for(int i = l ; i < v[x]; i++)
                    v[int(s[i]-'0')] = -1;
                l = v[x] + 1;
                v[x] = r; 
                r++; 
            }
            // cout<<l << " "<<r<<"\n";

            ans = max(ans, r - l);                
        }
        return ans; 


    }
};
