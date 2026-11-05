class Solution {
public:

    vector<vector<vector<int>>>dp;
    bool helper(int i, int j, int k, string &s1, string &s2, string &s3){

        if( k>=s3.size())
            return true;
        int a = 0, b = 0; 
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(i < s1.size() && s3[k] == s1[i])
            b = helper(i+1, j, k+1, s1, s2, s3);
        
        if(j < s2.size() && s3[k] == s2[j])
            a = helper(i, j + 1, k + 1, s1, s2, s3);

        return dp[i][j][k] = a | b; 
    }

    bool isInterleave(string s1, string s2, string s3) {
        dp.clear();
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 + n2  !=  n3)
            return false; 
        dp.resize(n1+1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        return helper(0, 0, 0, s1, s2, s3);    
    }

};
