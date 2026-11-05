class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();

        if(n <= k)
            return n; 

        int l = 0 , r = n;
        int ans = 0;
        while(l<=r){

            int m = (l+r)/2;
            int i = 0, j = 0;
            set<pair<int, int>>st;
            map<int, int>mp; 
            while(j < m && j < n){
                mp[int(s[j])]++;
                st.insert({mp[int(s[j])], int(s[j])});
                j++;
            }
            bool not_passed = true; 
            int maxi = (*st.rbegin()).first;
           
            if(m - maxi <=k){
                not_passed = false;
            }
            while(not_passed && j < n){
                
                if(st.find({mp[int(s[i])], int(s[i])})!=st.end())
                    st.erase(st.find({mp[int(s[i])], int(s[i])}));

                if(st.find({mp[int(s[j])], int(s[j])})!=st.end())
                    st.erase(st.find({mp[int(s[j])], int(s[j])}));
                mp[int(s[j])]++;
                mp[int(s[i])]--;
                
                st.insert({mp[int(s[j])], int(s[j])});
                st.insert({mp[int(s[i])], int(s[i])});
                i++; 
                j++;
                maxi = (*st.rbegin()).first;
               
                if(m - maxi <=k){
                not_passed = false;
                break;
                }
            }
            if(not_passed)
                r = m - 1;
            else{
                ans = max(ans, m);
                l = m + 1;
            }
          

        }
    return ans;

    }
};
