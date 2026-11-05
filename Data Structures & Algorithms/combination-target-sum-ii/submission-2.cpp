class Solution {
public:
    vector<vector<int>>ans; 

    void fun(int i, vector<int>&v, int t, vector<int>&temp){
        if(t == 0){
            ans.push_back(temp);
            return ; 
        }
        if(t < 0 || i >= v.size())
            return ; 
        temp.push_back(v[i]);
        fun(i + 1, v, t - v[i], temp);
        temp.pop_back(); 
        int j = i + 1;
        while(j < v.size() && v[j] == v[j - 1])
            j++; 
        fun(j, v, t, temp);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<int>temp; 
        fun(0, candidates, target, temp);
        return ans; 
    }
};
