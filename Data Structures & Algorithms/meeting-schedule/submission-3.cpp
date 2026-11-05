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
    static bool customComparison(Interval a, Interval b)
        {
            // Custom comparison logic
            return a.start < b.start; // it sorts in ascending order
        }


    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), customComparison);

        
        int n = intervals.size();
        if(n == 0)
            return true; 
        Interval last = intervals[0];
        for(int i = 1; i < n; i++){
            if(last.end > intervals[i].start)
                return false;
            last = intervals[i];
        }
        return true; 
    }
};
