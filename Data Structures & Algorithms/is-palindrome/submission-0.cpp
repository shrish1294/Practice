class Solution {
public:
    
    bool isPalindrome(string s) {

       s.erase(std::remove_if(s.begin(), s.end(), 
[]( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());

        for(int i = 0 ; i < s.size(); i++)
            s[i] = tolower(s[i]);
        string t = s;
        reverse(t.begin(), t.end());
        return s==t;
    }
};
