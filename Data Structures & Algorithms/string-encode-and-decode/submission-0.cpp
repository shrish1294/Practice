class Solution {
public:

    string encode(vector<string>& strs) {

        string s = "";
        for(auto a: strs){
            
            string str1 = a;
            string str2 = a;
            while(str1.length() < 200)
              {  str1.push_back('1');
                str2.push_back('9');
            }
            s = s + str1 + str2;
        }

       
        return s; 
    }

    vector<string> decode(string s) {
        int len = s.length();
        int n = len/400;
       
        vector<string>v;
        if(n==0)
            return v;

        int i =0;
        int j = 200;
        for(int k = 0 ; k < n; k++){
            string t = "";
            i = k*400;
            j = i + 200;
            cout<<i<<" "<<j<<" \n";
            while(j < len && i < len && s[i]==s[j]){
                t.push_back(s[i]);
            
                i++;
                j++;
            }
            v.push_back(t);
            
        }
        return v;
    }
};
