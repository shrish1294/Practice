class Solution {
public:

    vector<vector<string>>ans;
    bool is_palin(string &s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] != s[j])
                return false;
            i++; 
            j--;
        }
        return true; 

    }

    void helper(string & s, int i, vector<string>&tmp){
        if(i >= s.length())
        {
            ans.push_back(tmp);
            return ;
        }
        string x = "";
        for(int j = i; j < s.length(); j++){
            x.push_back(s[j]);
            if(is_palin(x))
            {
                tmp.push_back(x);
                helper(s, j + 1, tmp);
                tmp.pop_back();
            }
        }


    }

    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string>tmp;
        helper(s, 0, tmp);
        return ans; 
    }
};
