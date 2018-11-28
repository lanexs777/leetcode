# 692
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> freq;
        map<int, set<string>> m;
        
        for(string word:words) ++freq[word];
        for(auto a:freq) m[a.second].insert(a.first);
        
        for(auto it=m.rbegin();it!=m.rend();it++) {
            if(k<=0) break;
            auto t=it->second;
            vector<string> v(t.begin(), t.end());
            if(k>=t.size()) {
                res.insert(res.end(), v.begin(), v.end());
            }
            else {
                res.insert(res.end(), v.begin(), v.begin()+k);
            }
            k -= t.size();
        }
        return res;
    }
};
