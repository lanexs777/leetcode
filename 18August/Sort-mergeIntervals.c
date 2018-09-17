#56
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
    struct Comp {
        bool operator() (Interval I1, Interval I2) {
            return I1.start < I2.start;
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>::iterator it,next,tmp;
        //First, sort the intervals withe the start.
        sort(intervals.begin(), intervals.end(), Comp());
        
        // merge
        for(it=intervals.begin();it!=intervals.end();it++) {
            //prepare
            tmp=it;
            tmp++;
            if(tmp != intervals.end()) {
                next=it;
                next++;
            }
            else break;
            
            //begin
            if(next->start < it->end || next->start == it->end ) {
                it->end=max(next->end, it->end);
                intervals.erase(next);
                it--;                
            }            
            
        }
        return intervals;
    }
    
    vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}
    
};

