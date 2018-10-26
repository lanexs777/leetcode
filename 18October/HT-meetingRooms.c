# 253
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        map<int, int> a;
        for(auto in:intervals) {
            ++a[in.start];
            --a[in.end];
        }
        int rooms=0, res=0;
        for(auto it:a) {
            res=max(res, rooms+=it.second);
        }
               
        
        return res;
    }
};
