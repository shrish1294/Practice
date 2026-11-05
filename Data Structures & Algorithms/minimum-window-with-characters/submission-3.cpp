class Solution {
public:
    string minWindow(string s, string t) {
        
        int l1 = s.length();
        int l2 = t.length();
        if(l1 < l2)
            return "";
        
        map<char, int>mp;
        string ans = s + t; 

        for(auto a: t)
            mp[a]+=1;
        int len = mp.size();
        int l = 0; 
        int r = 0;
        int matched = 0;
        while(r < l1){

           if(mp.count(s[r])){
                mp[s[r]]-=1; 
                if(mp[s[r]] == 0)
                    matched+=1;
           }
           if(matched == len){

                if(ans.length() > r - l + 1)
                    ans = s.substr(l, r - l + 1);
                while(l <=r && matched == len){
                    if(mp.count(s[l])){
                        mp[s[l]]+=1;
                        if(mp[s[l]] > 0)
                            matched-=1;
                    }
                    l++;
                    if(matched==len && ans.length() > r-l + 1)
                        ans = s.substr(l, r - l + 1);
                }
           }
           r++;
        }
        if(ans.length() > l1)
            return "";
        return ans; 
        




    }
};
