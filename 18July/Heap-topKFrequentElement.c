#347
class Solution {
public:
    //配合sort 自己寫一個sort func去比較
    struct Comp {
        bool operator() (pair<int, int>p1, pair<int, int>p2) {
            return p1.second > p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mymap;
        vector<int> res;
        //尚未initialize的key其value都會是0 for這個用法也要熟悉
        for(auto num:nums) {
            mymap[num]++;
        } 
        //轉乘vector 可以使用sort
        vector<pair<int, int>> vec(mymap.begin(), mymap.end());
        
        
        sort(vec.begin(), vec.end(), Comp());
        
        for(auto it=vec.begin();it!=vec.end();it++) {
            res.push_back(it->first);
            if(res.size()==k) break;
        }
        return res;
                
    }
};
