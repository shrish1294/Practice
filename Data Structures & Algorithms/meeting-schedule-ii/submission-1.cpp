/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n<=1)
            return n;
        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 1;
        Interval last = Interval(-1, -1);
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(-1);

        for(Interval a: intervals){
            if(a.start >= pq.top()){
                pq.pop();
                pq.push(a.end);
            }
            else{
                pq.push(a.end);
                
            }
            cnt = max(cnt, int(pq.size()));
        }
        return cnt;
    }
};
