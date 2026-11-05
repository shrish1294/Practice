class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m > n)
            return "";

        string ans =  "";

        int l = m, r = n;
        

        set<int>st; 

        for(auto a: t)
            st.insert(int(a));
    
        while(l<=r){
            int k = (l+r)/2;
            vector<int>mp(300);
            for(auto a: t)
                mp[int(a)]++;
    
            int j = 0;
            int i = 0;
            while(j < k){  
                mp[int(s[j])]--;
                j++;
            }
            bool cov = true;

            for(auto a: st){
                    if(mp[a]>0)
                    {    cov = false;
                        break;
                    }
                }
            cout<<cov<<" ";
            while(!cov &&  j < n){
                mp[s[i]]++;
                mp[s[j]]--; 

                i++;
                j++;
                cov = true;
                for(auto a: st){
                    if(mp[a]>0)
                    {    
                        cov = false;
                        break;
                    }
                }
            }
            
            if(cov){
                ans = s.substr(i, j-i);
                cout<<j<<" "<<i<<"\n";
                r = k-1;
            }
            else
                l = k + 1;
        }

        return ans; 
        



    }
};
