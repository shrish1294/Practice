class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<vector<int>>&v, int i, int j){
        if(i>=v.size() || j>=v.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(v[i][1] <= v[j][0])
            return fun(v, j, j+1);
        int a = 1 + fun(v, j, j+1);
        int b = 1 + fun(v, i, j+1);
        return dp[i][j] = min(a, b);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        dp.clear();
        dp.resize(n, vector<int>(n, -1));
        sort(intervals.begin(), intervals.end());

        return fun(intervals, 0, 1);
    }
};
