# 759
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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> res, v;
        for(auto a:schedule) {
            v.insert(v.end(), a.begin(), a.end());
        }
        
        sort(v.begin(), v.end(), [](Interval &a, Interval &b){return a.start<b.start;});
        
        Interval t=v[0];
        for(Interval i:v) {
            if(t.end < i.start) {
                res.push_back(Interval(t.end, i.start));
                t=i;
            }
            else {
                t=(t.end < i.end) ? i:t;
            }
        }
        return res;
    }
};
