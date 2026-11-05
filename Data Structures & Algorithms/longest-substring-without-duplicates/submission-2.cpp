class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        map<char, int>mp;
        int i =0;
        int ans = 0;
        int cnt = 0;
        while(i < n){
            cout<<i<<" "<<cnt<<"\n";
            if(mp.find(s[i])==mp.end() || mp[s[i]]==-1){
                mp[s[i]] = i; 
                i++;
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                int ind = mp[s[i]];
                int idx = i - cnt; 
                
                while(idx <= ind){
                    mp[s[idx]] = -1;
                    idx++;
                    cnt--;
                }

            }
            ans = max(ans, cnt);
  
        }
        return ans;

    }
};
