# 452
# my first way
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0) return 0;
        auto comp = [](const pair<int, int> v1, pair<int, int> v2) {return (v1.first < v2.first)||(v1.first==v2.first && v1.second < v2.second);};
        sort(points.begin(), points.end(), comp);
        int start=points[0].first;
        int end=points[0].second;
        int count=points.size();
        for(int i=1;i<points.size();i++) {
            if(points[i].first>=start && points[i].first<=end) {
                count--;
                start=max(start, points[i].first);
                end=min(end, points[i].second);
            }
            else {
                start=points[i].first;
                end=points[i].second;
            }
        }
        return count;
    }
};

