class Solution {
public:
    int countSubstrings(string s) {
         
        int n = s.length();
        int cnt = 0;
        if(!n)
            return cnt;
        cnt = 0;
        for(int i = 0; i < n; i++){
            int l = i - 1;
            int r = i + 1;

            while(l>=0 && r<n && s[l] == s[r])
                l--, r++;
            cnt+=(i - l);
            l = i;
            r = i + 1;
             while(l>=0 && r<n && s[l] == s[r])
                l--, r++;
            cnt += (i - l);

        }
        return cnt;

    }
};
