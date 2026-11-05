class Solution {
public:
    bool is_palin(string &s, int i, int j){
       string tmp = s.substr(i, j);
       reverse(tmp.begin(), tmp.end());
       return (s.substr(i, j) == tmp);
    }



    string longestPalindrome(string s) {

        int n = s.length();
        cout<<n<<" ";
        for(int i = n; i>=1; i--){
            for(int j = 0; j <= n - i; j++){
                if(is_palin(s, j, i))
                    return s.substr(j, i);
            }
        }
        return s;
        

    }
};
