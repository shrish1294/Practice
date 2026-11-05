class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        map<string, vector<string>>mp; 
        for(int i = 0 ; i <n; i++){
            string cp = strs[i];
            sort(cp.begin(), cp.end());
            mp[cp].push_back(strs[i]);
        }
    
    vector<vector<string>>vec;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        vec.push_back(it->second);
    }
    return vec;
    }
};
