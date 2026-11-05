class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded_str = "";

        for(auto a: strs){
            int n = a.length();
            encoded_str += to_string(n) + "#" + a; 
        }
        return encoded_str;
    }

    vector<string> decode(string s) {

        vector<string>ans;

        int len = s.length();
        int i =0;
        while(i < len){

            string l = "";
            while(i < len && s[i]!='#'){
                l.push_back(s[i]);
                i++;
            }
            int str_len = stoi(l);
            i+=1;
            l = "";
            while(i < len && str_len > 0)
            {
                l.push_back(s[i]);
                i++;
                str_len--;
            }
            ans.push_back(l);
        }
        return ans; 



    }
};
