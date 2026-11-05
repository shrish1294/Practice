class Solution {
public:

    string longestPalindrome(string s) {
       
       int n = s.length();
       if(!n)
        return "";
        string ans = s.substr(0, 1);
        for(int i = 0; i < n; i++){
            int l = i - 1;
            int r = i + 1;
            while( l >= 0 && r < n && s[l] == s[r])
                l--, r++;
            if(ans.length() < (r - l - 1) && l < i-1)
                ans = s.substr(l+1, r-l - 1);
            cout<<s[i]<<" "<<l<<" "<<r<<"\n";
            l = i; 
            r = i+1;
            while( l >= 0 && r < n && s[l] == s[r])
                l--, r++;
            if(ans.length() < (r - l - 1) && l < i)
                ans = s.substr(l+1, r-l - 1);
            // cout<<s[i]<<" "<<l<<" "<<r<<"\n";
        }
        return ans; 
       
    }
};
