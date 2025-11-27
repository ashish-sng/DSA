// Meetings room 2 - Neetcode.io
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
        int n = intervals.size();
        vector<int> startTime;
        vector<int> endTime;
        for(auto& i:intervals){
            startTime.push_back(i.start);
            endTime.push_back(i.end);
        }

        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        int rooms = 0, maxRooms = 0;
        int startPtr = 0, endPtr = 0;

        while (startPtr < intervals.size()) {
            if (startTime[startPtr] < endTime[endPtr]) {
                rooms++;
                startPtr++;
            } else {
                rooms--;
                endPtr++;
            }
            maxRooms = max(maxRooms, rooms);
        }
        
        return maxRooms;
    }
};
