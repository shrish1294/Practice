class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int i =0;i<n; i++)
            dp[i][i] = true;
        int cnt = n;
        for(int i = 1; i<n; i++){
            int k = i; 
            for(int j = 0; j < n, k < n; j++, k++){
                if(s[j] == s[k]){
                    if(abs(j-k)==1)
                        dp[j][k] = true;
                    else
                        dp[j][k] = dp[j+1][k-1];
                }
               
                cnt+=dp[j][k];
            }
        }
        for(auto a: dp)
            for(auto b: a)
                cout<<b<<" ";


        return cnt;



    }
};
