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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(),intervals.end(),[](Interval i1, Interval i2){
            
            return i1.start<=i2.start;

        });
        
       
        for(int i=1;i<intervals.size();i++){

            Interval curr = intervals[i];
            Interval prev = intervals[i-1];
            if((curr.start)<(prev.end)){return false;}
           
        }


       

      return true;
    }
};
