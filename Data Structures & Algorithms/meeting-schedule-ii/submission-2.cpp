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
    int minMeetingRooms(vector<Interval>& intervals) {
          vector<pair<int,int>> pairs;

          int activeMeetings = 0;
          int maxActiveMeetings = 0;

          for(auto interval:intervals){
                pairs.push_back({interval.start,1});
                pairs.push_back({interval.end,-1});
          }
          
          sort(pairs.begin(),pairs.end());

          for(auto pair:pairs){
             activeMeetings+=pair.second;
             maxActiveMeetings = max(maxActiveMeetings,activeMeetings);
             
          }


       return maxActiveMeetings;
    }
};






    //    // [1,3] [2,9] [6,12] [15,20] - - 2
    //    // [1,3] [2,9] [6,12] [7,20] [15,20] - - 3
    //    // [1,3] [2,9] [6,12] [7,20] [15,20] [19,25] - - 3


    //     [1,3] [2,9] [6,12] [15,20]

    //      //my answer will be the maximum number of intervals that overlap at a single point
    //       [1,3][2,5] [4,8]
    //       [1,20] [2,5] [4,6]   [7,10] [18,20]

