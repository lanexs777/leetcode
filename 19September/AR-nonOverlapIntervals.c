# 435
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        auto comp = [](const Interval& ia, const Interval& ib) {return ia.end < ib.end;};
        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0].end;
        int count=1;
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i].start >= end) {
                end = intervals[i].end;
                count++;
            }
        }
        
        return intervals.size()-count;
        
    }
};
