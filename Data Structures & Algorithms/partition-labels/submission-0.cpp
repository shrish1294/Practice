class Solution {
public:
    vector<int> partitionLabels(string s) {


       vector<int>ans; 
       int n = s.length();
       vector<int>v(26, 0);
       for(int i = 0; i < n; i++)
            v[s[i] -'a'] = max(v[s[i]-'a'], i);
        
        int i = 0;
        int curr_st = 0;
        int curr_en = v[s[0]-'a'];
        
        while( i < n){
            if(i > curr_en){
                ans.push_back(curr_en-curr_st + 1);
                curr_st = i;
                curr_en = v[s[i]-'a'];
            }
            else{
                curr_en = max(curr_en, v[s[i]-'a']);
            }
            i++;
        }
        ans.push_back(curr_en-curr_st + 1);
        return ans; 

    }
};
