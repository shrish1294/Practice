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
bool compareInterval(Interval i1, Interval i2)
    {
        return (i1.start < i2.start);
    }
 
class Solution {
public:
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareInterval);
        Interval last  = Interval(-1, -1);
        for(Interval a: intervals){
            cout<<a.start<<" "<<a.end<<"\n";
        }
        for(Interval a: intervals){
            if(last.end > a.start)   
                return false;
            last = a;
        }
        return true;
       
    }
};
