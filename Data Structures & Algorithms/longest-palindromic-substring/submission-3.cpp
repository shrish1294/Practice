class Solution {
public:
    bool is_palin(string &s, int i, int j){
       string tmp = s.substr(i, j);
       reverse(tmp.begin(), tmp.end());
       return (s.substr(i, j) == tmp);
    }
    map<pair<int,int>, string>mp;
    string fun(string &s, int l, int r){
        if(l>r)
            return "";
        if(mp.find({l, r})!=mp.end())
            return mp[{l, r}];
        if(s[l] == s[r] && is_palin(s, l, r-l+1))
            return mp[{l, r}] = s.substr(l, r-l + 1);
        string a = fun(s, l+1, r);
        string b = fun(s, l, r-1);
        if(a.length() > b.length())
            return mp[{l,r}] = a;
        return mp[{l, r}] = b;
    }



    string longestPalindrome(string s) {
        mp.clear();
        int n = s.length();

        return fun(s, 0, n-1);        

    }
};
