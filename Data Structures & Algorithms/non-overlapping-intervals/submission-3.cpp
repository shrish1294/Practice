class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int cnt =0 ;
        int prev = intervals[0][1];
        for(int i = 1;  i < n; i++){
            auto st = intervals[i];
            if(st[0] >= prev)
                prev = st[1];
            else{
                cnt++;
                prev = min(prev, st[1]);
            }
        }
        return cnt;


    }
};
