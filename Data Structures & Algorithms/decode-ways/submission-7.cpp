class Solution {
public:

    vector<int>dp;

    int fun(int i , string &s){
        
        if(i >=s.length())
            return 1;
        int b = 0;
        int a = 0;
        cout<<i<<", "<<s[i]<<"; ";
        if(dp[i]!=INT_MAX)
            return dp[i];
        if(s[i] == '0')
            return 0;
        if(i == s.length()-1)
            return 1;
        if( i + 1 < s.length() && s[i+1] != '0')
            a = fun(i+1, s);
        if(i +1 < s.length() && ((s[i] <='2' && s[i+1] <='6') || (s[i] <='1')))
        b =  fun(i + 2, s);
      

        return dp[i] = a + b;
    }
    int numDecodings(string s) {
        
        dp.clear();
        dp.resize(s.length(), INT_MAX);
        int x =  fun(0, s);
        if(x == -1)
            return 0;
        return x;
    }
};
